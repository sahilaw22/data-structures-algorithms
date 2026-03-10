# Data Structures & Algorithms

Small, focused implementations as I practice core DSA ideas. Current focus: stack-based utilities.

---

## Programs (folder `stack/`)

1) **Stack Expression Validator**  
   - Files: `StackExpressionValidator.c`, `StackExpressionValidator.cpp`  
   - Purpose: Checks whether an expression has balanced parentheses/braces/brackets using a stack (`push`/`pop` helpers in C, `std::stack` in C++).

2) **Postfix Evaluator**  
   - Files: `PostfixEval.c`, `PostfixEval.cpp`  
   - Purpose: Evaluates a postfix (Reverse Polish) arithmetic expression with operators `+ - * /` and single-digit operands. Uses an explicit stack in C and `std::stack<int>` in C++. Example input: `23*54*+9-` -> result `17`.

Supporting file: `stack/cmd.txt` contains `cl` commands for building with the Visual Studio Developer Command Prompt.

---

## How to Compile & Run (GCC/Clang)

From the repo root:

```bash
# C versions
gcc stack/StackExpressionValidator.c -o validator_c
gcc stack/PostfixEval.c -o postfix_c

# C++ versions
g++ stack/StackExpressionValidator.cpp -o validator_cpp
g++ stack/PostfixEval.cpp -o postfix_cpp
```

Run the executables (`./validator_c`, `./validator_cpp`, `./postfix_c`, `./postfix_cpp`) and enter the expression when prompted.

---

## Notes and Next Steps

- Current postfix evaluator accepts only single-digit non-negative operands and no spaces; division is integer division without zero checks.
- The validator treats any closing bracket without a prior opening as invalid but does not enforce matching types across pairs (e.g., `(]` passes length-wise). Improving type-matching and error messaging is a good next enhancement.
- Upcoming topics: queues, linked lists, binary search trees, sorting algorithms.
