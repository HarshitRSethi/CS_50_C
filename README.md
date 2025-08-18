# CS_50_C

This repository contains my solutions to Week 1 and Week 2 of Harvard's [CS50: Introduction to Computer Science](https://cs50.harvard.edu/x/) course. All programs are written in C and compiled using the `make` command with `cs50.c` and `cs50.h`.

Each folder includes the source code, CS50 library, and (where applicable) an executable generated during testing.

---

## 📁 Folder Structure

### 1. `plurality/`

This program simulates a plurality voting election where each voter casts one vote for a candidate. It tracks votes, validates inputs, and prints the candidate(s) with the most votes as the winner(s).

**Files:**

- `plurality.out`
- `plurality.c`
- `cs50.h`
- `cs50.c`

---

### 2. `substitution/`

This program encrypts text using a user-provided 26-letter substitution key. It validates the key for correctness, preserves letter case, and leaves non-letters unchanged.

**Files:**

- `substitution.out`
- `substitution.c`
- `cs50.h`
- `cs50.c`

---

### 3. `caesar/`

This program encrypts text using the Caesar cipher algorithm with a user-provided numeric key. It preserves letter case while shifting alphabetic characters, leaving non-letters unchanged.

**Files:**

- `caesar.out`
- `caesar.c`
- `cs50.h`
- `cs50.c`

---

### 4. `readability/`

This program analyzes a block of text and calculates its U.S. grade-level readability using the Coleman-Liau index. It counts letters, words, and sentences, then outputs the corresponding reading grade.

**Files:**

- `readability.out`
- `readability.c`
- `cs50.h`
- `cs50.c`

---

### 5. `scrabble/`

A simple word point game played between two players, whose scoring is based on non-typical alphabets of english language used in your word. Player scoring more points win.

**Files:**

- `scrabble.out`
- `scrabble.c`
- `cs50.h`
- `cs50.c`

---

### 6. `credit/`

Implements a credit card validator using Luhn's Algorithm. Takes a credit card number as input and prints the card type (AMEX, MASTERCARD, VISA, or INVALID). Currently only the original (US Based Version) is made, I'm working on an Indian version and will update it soon.

**Files:**

- `credit`
- `credit.c` - Orignal Solution / Submitted solution
- `credit2.c` - Revised Solution
- `credit2.out`
- `cs50.h`
- `cs50.c`

---

### 7. `cash/`

Implements a greedy algorithm to calculate the minimum number of coins needed to make change for a given dollar amount. Again, I'm also working on an Indian equivalent of this program.

**Files:**

- `cash.c` – Original solution
- `cash`
- `cash2.c` – Revised solution / Submitted solution
- `cash2`
- `cs50.h`
- `cs50.c`

---

### 8. `mario-less/`

Prints a right-aligned pyramid of hashes (#) similar to Mario from Super Mario Bros., using user-defined height.

**Files:**

- `mario.c`
- `mario`
- `cs50.h`
- `cs50.c`

---

### 9. `mario-more/`

Prints a right-aligned pyramid and a left-aligned pyramid with a gap in the middle, a more advanced version of the Mario pyramid.

**Files:**

- `mario.c`
- `mario`
- `cs50.h`
- `cs50.c`

---

### 10. `me/`

A simple program that prints your name using formatted input and output functions.

**Files:**

- `hello.c`
- `hello`
- `cs50.h`
- `cs50.c`

---

### 11. `world/`

My first "Hello, World!" program in C to get familiar with syntax and compilation.

**Files:**

- `hello.c`
- `hello`
- `cs50.h`
- `cs50.c`

---

## 🛠 How to Compile and Run

> ⚠️ All folders already contain precompiled executable files. You can simply run them directly without recompiling.

### ✅ To Run a Program (on macOS or Linux):

Open a terminal, `cd` into the folder you want, then run:

```bash
./program_name
```

### 🖥️ Windows Instructions

If you want to compile the code on Windows:

1. Install [MinGW-w64](https://www.mingw-w64.org/) to get `gcc`.
2. Use Command Prompt or PowerShell to compile:

```bash
gcc program_name.c cs50.c -o program_name.exe
program_name.exe
```

## 👨‍💻 Author

**Harshit R. Sethi**  
B.Tech IT, First Year @ IIIT Allahabad  
[GitHub](https://github.com/HarshitRSethi) | [LinkedIn](https://linkedin.com/in/harshitrsethi)
