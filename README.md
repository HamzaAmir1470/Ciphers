# Classical Encryption Techniques

A comprehensive implementation and study of **Classical Encryption Techniques**, covering both **Substitution Ciphers** and **Transposition Ciphers**. This repository demonstrates the core principles of early cryptographic systems that laid the foundation for modern encryption.

---

## Overview

Classical encryption techniques transform plaintext into ciphertext using systematic methods. These techniques are broadly divided into:

* **Substitution Techniques** – Replace characters with other characters
* **Transposition Techniques** – Rearrange the positions of characters

This project includes implementations, explanations, and examples of the most important classical ciphers.

---

##  Substitution Ciphers

### 1. Caesar Cipher

A simple shift cipher where each letter is shifted by a fixed number of positions in the alphabet.

**Example:**

```
Plaintext:  HELLO
Shift:      +3
Ciphertext: KHOOR
```

---

### 2. Monoalphabetic Cipher

Each letter in the plaintext is mapped to a unique letter in the ciphertext.

* Fixed substitution for entire message
* More secure than Caesar, but vulnerable to frequency analysis

---

### 3. Playfair Cipher

A **digraph substitution cipher** that encrypts pairs of letters using a 5x5 matrix.

* Reduces frequency analysis weakness
* Handles plaintext in pairs instead of single characters

---

### 4. Hill Cipher

A mathematical cipher based on **matrix multiplication**.

* Uses linear algebra
* Encrypts blocks of letters
* Requires invertible key matrix

---

### 5. Polyalphabetic Ciphers

#### a. Vigenère Cipher

Uses multiple Caesar ciphers based on a repeating keyword.

**Formula:**

```
Ci = (Pi + Ki) mod 26
```

#### b. Vernam Cipher (One-Time Pad when key is random)

* Uses a random key equal in length to plaintext
* Theoretically **unbreakable** if:

  * Key is truly random
  * Key is used only once

---

### 6. One-Time Pad (OTP)

An extension of Vernam Cipher with perfect secrecy.

✔ Advantages:

* Impossible to crack mathematically

Limitations:

* Key distribution problem
* Requires very long random keys

---

## Transposition Ciphers

### 1. Rail Fence Cipher

Writes plaintext in a zig-zag pattern across multiple rows.

**Example (Depth = 3):**

```
H   L   O
 E L W R D
  L   O
```

---

### 2. Row-Column Transposition Cipher

Plaintext is written in rows and read column-wise using a key.

* Key determines column order
* Can be single or double transposition

---

### 3. General Transposition (One-line Definition)

A cipher that rearranges the **positions of characters** without changing their actual values.

---

## Comparison

| Feature       | Substitution Cipher | Transposition Cipher |
| ------------- | ------------------- | -------------------- |
| Operation     | Replace characters  | Rearrange positions  |
| Security      | Moderate            | Moderate             |
| Vulnerability | Frequency analysis  | Pattern detection    |
| Complexity    | Low to Medium       | Low                  |

---

## Features

* Implementation of multiple classical ciphers
* Encryption and Decryption support
* Clean modular code structure
* Educational examples and explanations

---

## 🛠️ Technologies Used

* C++ / JavaScript / Python (depending on your implementation)
* Basic Linear Algebra (for Hill Cipher)
* String manipulation techniques

---

## Project Structure

```
/ciphers
    caesar.cpp
    monoalphabetic.cpp
    playfair.cpp
    hill.cpp
    vigenere.cpp
    vernam.cpp
    otp.cpp
    railfence.cpp
    rowcolumn.cpp

README.md
```

---

## How to Run

### C++ Example:

```bash
g++ caesar.cpp -o caesar
./caesar
```

---

## Learning Outcomes

* Understanding historical encryption systems
* Difference between substitution and transposition
* Basics of cryptanalysis
* Foundation for modern cryptography

---

## Disclaimer

These techniques are **not secure for modern applications** and are implemented strictly for **educational purposes**.

---

## Contribution

Contributions are welcome. Feel free to:

* Improve implementations
* Add new ciphers
* Optimize algorithms

---

## Contact

**Hamza Amir**
[hamzaamir9733@gmail.com](mailto:hamzaamir9733@gmail.com)

---

## ⭐ Support

If you found this useful, consider giving this repo a ⭐ and sharing it with others.
