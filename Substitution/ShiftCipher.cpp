#include <iostream>
using namespace std;

string encrypt(string text, int key) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        if (isupper(ch))
            result += char((ch - 'A' + key) % 26 + 'A');
        else if (islower(ch))
            result += char((ch - 'a' + key) % 26 + 'a');
        else
            result += ch; 
    }

    return result;
}

string decrypt(string text, int key) {
    return encrypt(text, 26 - key);
}

int main() {
    string text = "ATTACK";
    int key = 5;

    string encrypted = encrypt(text, key);
    cout << "Encrypted: " << encrypted << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}