# Data Structures & Algorithms

> A comprehensive collection of DSA implementations, documenting my deep dive into efficient problem-solving and algorithmic thinking.

---

## 📁 Programs

### 1. Stack Expression Validator — `stack/`

**What it does:**
- Validates mathematical expressions for balanced delimiters (`(`, `{`, `[`).
- Uses a stack to ensure every opening bracket has a corresponding closing bracket in the correct order.

**Implementations:**
- `StackExpressionValidator.cpp`: C++ modern implementation using `std::stack`.
- `StackExpressionValidator.c`: Pure C implementation for low-level understanding.

**Concepts covered:**
- Stack Data Structure (LIFO)
- String Parsing
- Template classes (`std::stack` in C++)
- Error handling for unbalanced expressions

**Sample Input/Output:**
```text
Enter the expression: {[()]}
Valid Expression

Enter the expression: {[(])}
Invalid Expression
```

---

## 🚀 How to Compile & Run

### C++ Programs
```bash
# Compile
g++ stack/StackExpressionValidator.cpp -o validator

# Run
./validator
```

### C Programs
```bash
# Compile
gcc stack/StackExpressionValidator.c -o validator_c

# Run
./validator_c
```

---

## 🧠 Topics Covered So Far

- [x] Stack (Array/Linked List representation)
- [x] Balanced Parentheses Problem
- [ ] Queue Implementations
- [ ] Singly/Doubly Linked Lists
- [ ] Binary Search Trees
- [ ] Sorting Algorithms

---

> "Logic will get you from A to B. Algorithms will get you there efficiently."

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&customColorList=6,11,20&height=120&section=footer&animation=twinkling" width="100%"/>
