# 🔢 Allocator Laboratory

**Status:** 🚧 In development

[Versión en español](README.es.md)

## 🧠 About this project

I recently decided to shift my focus from Android development toward low-level programming. This decision brought several challenges: I needed a language better suited to this environment, like C, and to build relevant projects that reflect this new professional direction.

**Allocator Laboratory** was born in response to these needs: a meaningful project through which I can reconnect with C programming, explore systems logic, and simultaneously present myself as a developer with strong analysis, design, and deep understanding of how memory works at a low level.

## 🧩 What is Allocator Laboratory?

Allocator Laboratory is a collection of **memory allocator simulators**, each designed to be independent. Every allocator implements a different memory management strategy, and all of them operate over a shared, simulated bitmap.

The goal is to functionally illustrate how each type of allocator behaves, its advantages, limitations, and how it compares to other models.

## 🧮 Expected features

Each allocator should be able to:

- Simulate the allocation of memory blocks on an abstract structure.
- Release previously allocated blocks.
- Maintain its own internal state to represent which parts of memory are free or occupied.
- Apply a consistent strategy for managing available space.

This project does not store or interpret real data — it focuses solely on the logic of memory allocation and release.

## 🛠️ Technologies used

- Language: **C**
- Development environment: **Visual Studio Code**
- Build system: **Makefile** (planned)
- Unit testing: Tests will be implemented to verify correct behavior of each allocator
- Design principles: Adaptation of **SOLID principles** to C programming to keep the code modular and readable

## ▶️ How to run the project

### System requirements

- C compiler (e.g., `gcc`)
- Make (optional but recommended)
- Git

Installation on Unix-based systems:

```bash
sudo apt install build-essential git
````

### Clone the project

```bash
git clone https://github.com/yourusername/allocator-laboratory.git
cd allocator-laboratory
make run
```

## 🗂️ Project structure

```text
Still to be decided
```

## 🎢 Allocator roadmap

Below is the roadmap I'm following to build my allocators, each with increasing complexity:

| Level | Name                        | Key concepts                                 | Status        |
| ----- | --------------------------- | -------------------------------------------- | ------------- |
| 1     | Fixed-size blocks + bitmap  | Internal fragmentation, bitmap, fixed blocks | ⏳ In progress |
| 2     | Free list (variable blocks) | External fragmentation, linked lists         | 🔜 Upcoming   |
| 3     | Coalescing                  | Compaction, merging free blocks              | 🔜 Upcoming   |
| 4     | Buddy allocator             | Powers of 2, recursion, splitting/merging    | 🔜 Upcoming   |
| 5     | Slab / Pool allocator       | Object-specific pools, efficiency            | 🔜 Upcoming   |
| 6     | Arena allocator             | Group deallocation, raw performance          | 🔜 Upcoming   |
| 7     | Hybrid allocator            | Multi-strategy, adaptive                     | 🔜 Upcoming   |

Each level will be accompanied by:

* Design explanation
* Visual memory diagram
* Implementation decisions
* Specific test cases

## 📖 Technical journal

I keep a narrative log of my decisions, discoveries, and thoughts throughout the project.
This journal documents both the technical progress and the personal journey behind it.

📍 [Technical journal index](./journal/en/journal_index.md)

## 🚀 Future plans

Once this roadmap is complete, I plan to develop an **Android application** to integrate these simulators as educational tools for teaching memory management from a systems perspective.

It will be a visual, interactive, and educational app designed for both students and anyone curious about low-level computing.

