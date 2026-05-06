#include <iostream>
using namespace std;

char matrix[5][5];

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

// Generate matrix
void generateMatrix(string key) {
    bool used[26] = {false};
    int r = 0, c = 0;

    for (char &ch : key) {
        ch = toupper(ch);
        if (ch == 'J') ch = 'I';

        if (!used[ch - 'A']) {
            matrix[r][c++] = ch;
            used[ch - 'A'] = true;
            if (c == 5) { r++; c = 0; }
        }
    }

    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue;

        if (!used[ch - 'A']) {
            matrix[r][c++] = ch;
            if (c == 5) { r++; c = 0; }
        }
    }
}

// Prepare text (for encryption only)
string prepareText(string text) {
    string s = "";

    for (char c : text) {
        if (isalpha(c)) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            s += c;
        }
    }

    string res = "";

    for (int i = 0; i < s.length(); i++) {
        res += s[i];

        if (i + 1 < s.length() && s[i] == s[i + 1]) {
            res += 'X';
        }
    }

    if (res.length() % 2 != 0)
        res += 'X';

    return res;
}

// Encrypt pair
string encryptPair(char a, char b) {
    int r1, c1, r2, c2;
    findPos(a, r1, c1);
    findPos(b, r2, c2);

    if (r1 == r2)
        return string(1, matrix[r1][(c1 + 1) % 5]) +
               string(1, matrix[r2][(c2 + 1) % 5]);

    else if (c1 == c2)
        return string(1, matrix[(r1 + 1) % 5][c1]) +
               string(1, matrix[(r2 + 1) % 5][c2]);

    else
        return string(1, matrix[r1][c2]) +
               string(1, matrix[r2][c1]);
}

// Decrypt pair
string decryptPair(char a, char b) {
    int r1, c1, r2, c2;
    findPos(a, r1, c1);
    findPos(b, r2, c2);

    if (r1 == r2)
        return string(1, matrix[r1][(c1 + 4) % 5]) +
               string(1, matrix[r2][(c2 + 4) % 5]);

    else if (c1 == c2)
        return string(1, matrix[(r1 + 4) % 5][c1]) +
               string(1, matrix[(r2 + 4) % 5][c2]);

    else
        return string(1, matrix[r1][c2]) +
               string(1, matrix[r2][c1]);
}

int main() {
    string key, text;
    int choice;

    cout << "1. Encrypt\n2. Decrypt\nEnter choice: ";
    cin >> choice;
    cin.ignore(); // clear buffer

    cout << "Enter key: ";
    getline(cin, key);

    generateMatrix(key);

    cout << "\n5x5 Matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    if (choice == 1) {
        cout << "\nEnter plaintext: ";
        getline(cin, text);

        string prepared = prepareText(text);
        cout << "Prepared Text: " << prepared << endl;

        string encrypted = "";
        for (int i = 0; i < prepared.length(); i += 2)
            encrypted += encryptPair(prepared[i], prepared[i + 1]);

        cout << "Encrypted: " << encrypted << endl;
    }
    else if (choice == 2) {
        cout << "\nEnter ciphertext: ";
        getline(cin, text);

        // assume input already valid pairs
        string decrypted = "";
        for (int i = 0; i < text.length(); i += 2)
            decrypted += decryptPair(text[i], text[i + 1]);

        cout << "Decrypted: " << decrypted << endl;
    }
    else {
        cout << "Invalid choice!\n";
    }

    return 0;
}