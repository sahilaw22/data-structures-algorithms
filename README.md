# Data Structures & Algorithms Lab

Beginner-friendly implementations of core DSA practicals in both C and C++. Each program is written from scratch (no STL `stack`, `queue`, etc.) and kept simple for learning.

---

## Program Index (Clean Table)

| Topic | Folders | Programs |
| --- | --- | --- |
| Stack | `stack/C`, `stack/C++` | parenthesis check, postfix eval, infix to postfix/prefix, prefix to postfix, basic stack |
| Queue | `queue/C`, `queue/C++` | basic queue, circular queue, priority queue |
| Linked List | `linklist/C`, `linklist/C++` | singly list, ordered list, polynomial add, doubly list |
| Tree | `tree/C`, `tree/C++` | BST traversals, BST sort, duplicate in BST, threaded binary tree |
| Algorithms | `algorithm/C`, `algorithm/C++` | dijkstra, prim, kruskal, quick sort, shell sort, merge sort |

---

## Folder Layout

- [stack/](stack)
- [queue/](queue)
- [linklist/](linklist)
- [tree/](tree)
- [algorithm/](algorithm)

---

## How to Compile & Run

From the repo root, compile any file you want. Examples:

```bash
# C
gcc stack/C/basicStack.c -o basicStack
gcc queue/C/priorityQueue.c -o priorityQueue

# C++
g++ tree/C++/basicTree.cpp -o basicTree
g++ algorithm/C++/mergeSort.cpp -o mergeSort
```

Run the executable and follow the menu or input prompts shown on screen.

---

## Notes

- All programs are kept minimal and readable for beginners.
- Each file includes a short header comment describing the goal.
- If you want more step-by-step comments in any program, tell me the filename.
