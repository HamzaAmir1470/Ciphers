#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Encryption
string encrypt(string text, int cols) {
    vector<vector<char>> grid;
    int rows = (text.length() + cols - 1) / cols;

    grid.resize(rows, vector<char>(cols, 'X'));

    int k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (k < text.length())
                grid[i][j] = text[k++];

    string result = "";

    for (int j = 0; j < cols; j++)
        for (int i = 0; i < rows; i++)
            result += grid[i][j];

    return result;
}

// Decryption
string decrypt(string cipher, int cols) {
    int rows = cipher.length() / cols;

    vector<vector<char>> grid(rows, vector<char>(cols));

    int k = 0;

    for (int j = 0; j < cols; j++)
        for (int i = 0; i < rows; i++)
            grid[i][j] = cipher[k++];

    string result = "";

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result += grid[i][j];

    return result;
}

int main() {
    string text = "Univerityofeducation";
    int cols = 4;

    string enc = encrypt(text, cols);
    cout << "Encrypted: " << enc << endl;

    string dec = decrypt(enc, cols);
    cout << "Decrypted: " << dec << endl;

    return 0;
}