#include <iostream>
using namespace std;

// Convert char to A=0..Z=25
int toNum(char c) {
    return toupper(c) - 'A';
}

// Convert back to char
char toChar(int x) {
    return char(x + 'A');
}

string vernamCipher(string text, string key) {
    string result = "";

    if (key.length() < text.length()) {
        cout << "❌ Key must be at least as long as text\n";
        return "";
    }

    for (int i = 0; i < text.length(); i++) {

        int p = toNum(text[i]);
        int k = toNum(key[i]);

        // XOR step (as you requested)
        int xorValue = p ^ k;

        // MOD 26 step
        int cipher = xorValue % 26;

        cout << text[i] << " (" << p << ") XOR "
             << key[i] << " (" << k << ") = "
             << xorValue << " -> mod26 = "
             << cipher << " -> " << toChar(cipher)
             << endl;

        result += toChar(cipher);
    }

    return result;
}

int main() {
    string text = "OAK";
    string key  = "SON";

    cout << "Encryption Process:\n";
    string enc = vernamCipher(text, key);

    cout << "\nFinal Encrypted: " << enc << endl;

    return 0;
}