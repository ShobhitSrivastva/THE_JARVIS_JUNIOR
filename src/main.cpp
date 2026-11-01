
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

// 1. GLOBAL CONVERSATION MEMORY

vector<json> conversation = {
    {
        {"role", "system"},
        {"content", "You are JARVIS, a helpful personal AI assistant. Give clear and friendly answers."}
    }
};

// 2. SAVE MEMORY TO FILE

void saveMemory() {
    ofstream file("memory.json");

    if (file.is_open()) {
        file << json(conversation).dump(4);
        file.close();
    }
}

// 3. LOAD MEMORY FROM FILE

void loadMemory() {
    ifstream file("memory.json");

    if (file.is_open()) {
        try {
            json savedConversation;
            file >> savedConversation;

            if (savedConversation.is_array() &&
                !savedConversation.empty() &&
                savedConversation[0]["role"] == "system") {

                conversation.clear();

                for (const auto& message : savedConversation) {
                    conversation.push_back(message);
                }
            }
        }
        catch (...) {
            cout << "Could not load previous memory.\n";
        }

        file.close();
    }
}

// 4. RECEIVE DATA FROM OLLAMA

size_t WriteCallback(void* contents, size_t size,
                     size_t nmemb, string* output) {

    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);

    return totalSize;
}

// 5. ASK JARVIS

string askJarvis(const string& question) {

    CURL* curl = curl_easy_init();

    if (!curl) {
        return "Could not initialize connection.";
    }

    conversation.push_back({
        {"role", "user"},
        {"content", question}
    });

    string response;

    json request;
    request["model"] = "qwen2.5:1.5b";
    request["messages"] = conversation;
    request["stream"] = false;

    string requestData = request.dump();

    curl_easy_setopt(curl, CURLOPT_URL,
                     "http://localhost:11434/api/chat");

    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestData.c_str());

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    struct curl_slist* headers = nullptr;

    headers = curl_slist_append(
        headers, "Content-Type: application/json"
    );

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    CURLcode result = curl_easy_perform(curl);

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    if (result != CURLE_OK) {
        return "Connection error: " +
               string(curl_easy_strerror(result));
    }

    try {
        json answer = json::parse(response);

        string reply =
            answer["message"]["content"].get<string>();

        conversation.push_back({
            {"role", "assistant"},
            {"content", reply}
        });

        saveMemory();

        return reply;
    }
    catch (...) {
        return "Could not understand AI response.";
    }
}

// 6. MAIN FUNCTION

int main() {

    loadMemory();

    cout << "================================\n";
    cout << "       JARVIS AI ASSISTANT\n";
    cout << "================================\n";

    cout << "Local AI is ready!\n";
    cout << "Type 'exit' to quit.\n";

    string question;

    while (true) {

        cout << "\nYou: ";
        getline(cin, question);

        if (question == "exit") {
            cout << "JARVIS: Goodbye!\n";
            break;
        }

        if (question.empty()) {
            continue;
        }

        cout << "\nJARVIS: ";
        cout << askJarvis(question) << endl;
    }

    return 0;
}
