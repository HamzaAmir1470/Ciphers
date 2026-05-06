#include <iostream>
#include <vector>
using namespace std;

// Encryption
string encryptRailFence(string text, int rails) {
    if (rails == 1) return text;

    vector<string> rail(rails);
    int row = 0;
    bool down = false;

    for (char c : text) {
        rail[row] += c;

        if (row == 0 || row == rails - 1)
            down = !down;

        row += down ? 1 : -1;
    }

    string result = "";
    for (string r : rail)
        result += r;

    return result;
}

// Decryption
string decryptRailFence(string cipher, int rails) {
    if (rails == 1) return cipher;

    vector<vector<char>> rail(rails, vector<char>(cipher.length(), '\n'));

    // mark pattern
    bool down;
    int row = 0, col = 0;

    for (int i = 0; i < cipher.length(); i++) {
        if (row == 0) down = true;
        if (row == rails - 1) down = false;

        rail[row][col++] = '*';
        row += down ? 1 : -1;
    }

    // fill ciphertext
    int index = 0;
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < cipher.length(); j++)
            if (rail[i][j] == '*' && index < cipher.length())
                rail[i][j] = cipher[index++];

    // read pattern
    string result = "";
    row = 0, col = 0;

    for (int i = 0; i < cipher.length(); i++) {
        if (row == 0) down = true;
        if (row == rails - 1) down = false;

        if (rail[row][col] != '\n')
            result += rail[row][col++];

        row += down ? 1 : -1;
    }

    return result;
}

int main() {
    string text = "Universityofeducation";
    int rails = 3;

    string enc = encryptRailFence(text, rails);
    cout << "Encrypted: " << enc << endl;

    string dec = decryptRailFence(enc, rails);
    cout << "Decrypted: " << dec << endl;

    return 0;
}