#include <iostream>
using namespace std;

char matrix[5][5];

// Generate matrix
void generateMatrix(string key) {
    bool used[26] = {false};
    int i = 0, j = 0;

    for (char c : key) {
        if (c == 'J') c = 'I';
        if (!used[c - 'A']) {
            matrix[i][j++] = c;
            used[c - 'A'] = true;
            if (j == 5) { i++; j = 0; }
        }
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue;
        if (!used[c - 'A']) {
            matrix[i][j++] = c;
            if (j == 5) { i++; j = 0; }
        }
    }
}

// Find position
void findPos(char c, int &row, int &col) {
    if (c == 'J') c = 'I';
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
            if (matrix[row][col] == c)
                return;
        }
    }
}

// Encrypt pair
string encryptPair(char a, char b) {
    int r1, c1, r2, c2;
    findPos(a, r1, c1);
    findPos(b, r2, c2);

    if (r1 == r2) // same row
        return string(1, matrix[r1][(c1 + 1) % 5]) +
               string(1, matrix[r2][(c2 + 1) % 5]);

    else if (c1 == c2) // same column
        return string(1, matrix[(r1 + 1) % 5][c1]) +
               string(1, matrix[(r2 + 1) % 5][c2]);

    else // rectangle
        return string(1, matrix[r1][c2]) +
               string(1, matrix[r2][c1]);
}

// Decrypt pair
string decryptPair(char a, char b) {
    int r1, c1, r2, c2;
    findPos(a, r1, c1);
    findPos(b, r2, c2);

    if (r1 == r2) // same row → shift LEFT
        return string(1, matrix[r1][(c1 + 4) % 5]) +
               string(1, matrix[r2][(c2 + 4) % 5]);

    else if (c1 == c2) // same column → shift UP
        return string(1, matrix[(r1 + 4) % 5][c1]) +
               string(1, matrix[(r2 + 4) % 5][c2]);

    else // rectangle (same as encryption)
        return string(1, matrix[r1][c2]) +
               string(1, matrix[r2][c1]);
}

// Prepare plaintext
string prepareText(string text) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        result += text[i];
        if (i + 1 < text.length() && text[i] == text[i + 1])
            result += 'X';
    }

    if (result.length() % 2 != 0)
        result += 'X';

    return result;
}

int main() {
    string key = "MONARCHY";
    string text = "HELLO";

    generateMatrix(key);

    string prepared = prepareText(text);

    // Encryption
    string encrypted = "";
    for (int i = 0; i < prepared.length(); i += 2)
        encrypted += encryptPair(prepared[i], prepared[i + 1]);

    cout << "Encrypted: " << encrypted << endl;

    // Decryption
    string decrypted = "";
    for (int i = 0; i < encrypted.length(); i += 2)
        decrypted += decryptPair(encrypted[i], encrypted[i + 1]);

    cout << "Decrypted: " << decrypted << endl;

    return 0;
}