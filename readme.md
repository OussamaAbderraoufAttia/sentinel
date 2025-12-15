# SENTINEL 🛡️
### DSL for Data Audit and Sanitization

> **Module:** Compilation (COMPIL)  
> **Institution:** École Nationale Supérieure d'Informatique (ESI), Algiers  
> **Year:** 2025-2026  
> **Option:** 2CS - SIL (Systèmes Informatiques et Logiciels)

---

## 📖 Overview

**SENTINEL** is a Domain Specific Language (DSL) designed to automate secure data cleaning pipelines. In the era of Big Data and AI, the reliability of systems depends on the quality of injected data ("Garbage In, Garbage Out").

Unlike general-purpose scripts (Python/Bash) which can be non-deterministic or insecure, SENTINEL offers a **compiled**, **strongly-typed**, and **sandboxed** environment specifically for:
- Data Validation
- Toxicity Detection
- Anonymization (PII Protection)

This repository contains the full implementation of the compiler, from lexical analysis to intermediate code generation.

## 🚀 Key Features

### 1. Security by Design (Sandboxing)
SENTINEL applies the **Principle of Least Privilege**. It does not allow arbitrary file system access or network connections. The compiler ensures the program only reads defined inputs and writes to defined outputs.

### 2. Determinism
Guarantees 100% reproducible behavior. Unlike LLM-based cleaning which may "hallucinate," SENTINEL follows strict logical rules.

### 3. "Green IT" Performance
Compiled towards native code/intermediate representation, offering ultra-fast execution with minimal memory overhead compared to Python interpreters or heavy AI models.

---

## 🛠️ Technical Architecture

The compiler is built using standard UNIX tools and C.

### 1. Lexical Analysis (Flex)
*   **Tool:** Flex
*   **Role:** Tokenizes the source code.
*   **Highlights:** Handles specific types like `probability` (floats [0.0-1.0]), `verdict` states, and structural keywords (`PROCESS`, `PIPELINE`).

### 2. Syntax Analysis (Bison)
*   **Tool:** Bison (LALR Grammars)
*   **Role:** Validates the grammar and builds the Abstract Syntax Tree (AST).
*   **Structure:** Enforces the strict separation between the `CONFIG` (static resources) and `PIPELINE` (logic) blocks.

### 3. Semantic Analysis (Symbol Table)
*   **Implementation:** C
*   **Role:**
    *   **Type Safety:** Prevents illegal operations (e.g., `integer + text`).
    *   **Scope Management:** Handles Global (Config) vs Local (Pipeline) scopes.
    *   **Constraints:** Validates that `probability` literals are within bounds and that `dictionary` types are immutable in the pipeline.

### 4. Code Generation
*   **Output:** Quadruplets (Intermediate Code).
*   **Role:** Generates a linear sequence of instructions ready for a virtual machine or translation to C code.

---

## 📝 Language Syntax Example

A typical SENTINEL script looks like this:

```sentinel
PROCESS "Chat_Moderator_V1" {

    CONFIG {
        // Static resource declaration
        integer max_risk = 50
        probability confidence = 0.99
        text src = "/input/stream.log"
        text db_clean = "/output/validated.csv"
        dictionary toxic_words = ["idiot", "scam", "hate"]
    }

    PIPELINE {
        text msg = ""
        integer risk_score = 0
        verdict status = VALID

        // Read input stream
        INGEST msg FROM src

        WHILE (msg != NULL) {
            risk_score = 0
            NORMALIZE msg

            // Pattern matching
            SCAN msg WITH toxic_words {
                risk_score = risk_score + 25
            }

            // Decision logic
            IF (risk_score >= max_risk) {
                status = REJECT
                LOG "Message rejected (High Risk)" LEVEL 3
            } ELSE {
                // Anonymization
                IF (msg CONTAINS "@") {
                    MASK msg WITH "*"
                }
                DISPATCH msg TO db_clean
            }
            
            INGEST msg FROM src
        }
    }
}

## Installation & Usage

### Prerequisites

- GCC Compiler
- Flex
- Bison

### Build the Compiler

# Generate Lexer
flex sentinel.l

# Generate Parser
bison -d sentinel.y

# Compile the whole project
gcc lex.yy.c sentinel.tab.c main.c -o sentinel -lfl

### Run a Script

./sentinel script.sent

## Project Structure

├── src/
│   ├── sentinel.l       # Lexical rules (Flex)
│   ├── sentinel.y       # Grammar rules (Bison)
│   ├── sentinel.h       # Token definitions and structures
│   ├── symbol_table.c   # Semantic analysis logic
│   ├── symbol_table.h
│   ├── quad.c           # Quadruplet generation
│   └── main.c           # Entry point
├── tests/
│   ├── test_valid.sent  # Valid test script
│   └── test_error.sent  # Script with semantic errors
├── README.md
└── Makefile

## Authors

Realized by:  
**ATTIA Oussama Abderraouf**

Supervised by:  
**Mr. ABDMEZIEM Riyadh**

ESI 2025 - Mini-Projet Compilation