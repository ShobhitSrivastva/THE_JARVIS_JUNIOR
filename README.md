# THE JARVIS JUNIOR

**A Personal AI Assistant · C++17 · Local LLM**

An experimental personal AI assistant built in modern C++, powered by Ollama and Qwen 2.5. Designed around conversational intelligence, persistent memory, and a lightweight local architecture.

[Repository](https://github.com/ShobhitSrivastva/THE_JARVIS_JUNIOR) · [Report an Issue](https://github.com/ShobhitSrivastva/THE_JARVIS_JUNIOR/issues)

---

## 01 / Overview

JARVIS JUNIOR explores the development of a personal AI assistant without relying on a hosted AI platform.

The application communicates with a locally running language model through Ollama, processes conversational input, and maintains conversation history between sessions.

The project focuses on three engineering principles:

- **Local inference** — Run language models through a local Ollama instance.
- **Persistent context** — Retain conversation history across sessions.
- **Native performance** — Build the application using C++17.

## 02 / System Architecture
<p align="center">
  <img src="./The%20Jarvis%20Junior%20Ai%20Architecture.png"
       alt="The Jarvis Junior AI Architecture"
       width="100%">
</p>
## 03 / Technology Stack

| Component | Technology |
|---|---|
| Language | C++17 |
| LLM Runtime | Ollama |
| Language Model | Qwen 2.5 1.5B |
| HTTP Communication | libcurl |
| Data Processing | nlohmann/json |
| Build System | CMake |

## 04 / Core Capabilities

**Conversational AI**

Processes natural-language input and generates responses using a locally hosted language model.

**Persistent Conversation Memory**

Stores conversation history in a local JSON file, allowing context to be retained between application sessions.

**Local Model Integration**

Connects to Ollama through its HTTP API, avoiding the need for a remote hosted inference service.

**C++ Application Architecture**

Uses C++ for application logic, HTTP communication, and data handling.

## 05 / Getting Started

### Prerequisites

- macOS or a compatible development environment
- C++17 compiler
- CMake
- Ollama
- Required C++ dependencies

### Installation

Clone the repository:

```bash
git clone https://github.com/ShobhitSrivastva/THE_JARVIS_JUNIOR.git

cd THE_JARVIS_JUNIOR
```

Install dependencies on macOS:

```bash
brew install cmake curl nlohmann-json
```

Install Ollama from:

https://ollama.com/

Download the required model:

```bash
ollama pull qwen2.5:1.5b
```

### Build

```bash
cmake -S . -B build
cmake --build build
```

### Run

Start Ollama, then launch the compiled executable:

```bash
./build/jarvis
```

## 06 / Development Roadmap

| Feature | Status |
|---|---|
| C++ assistant core | Implemented |
| Ollama integration | Implemented |
| Qwen 2.5 integration | Implemented |
| Persistent conversation memory | Implemented |
| Voice interaction | Planned |
| Wake-word detection | Planned |
| Speech synthesis | Planned |
| Desktop interface | Planned |
| System automation | Planned |

## 07 / Project Direction

JARVIS JUNIOR is an evolving engineering project focused on bringing together local language models, native application development, conversational memory, and eventually voice-driven interaction.

The objective is to move beyond a basic chatbot and develop a capable personal computing assistant.

---

**AUTHOR**

**Shobhit Srivastva**

Computer Science & Engineering

[GitHub Profile](https://github.com/ShobhitSrivastva) · [Project Repository](https://github.com/ShobhitSrivastva/THE_JARVIS_JUNIOR)

*Built with C++ and a curiosity for intelligent systems.*
