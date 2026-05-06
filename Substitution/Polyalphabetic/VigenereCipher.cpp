#include <iostream>
using namespace std;

string generateKey(string text, string key) {
    for (int i = 0; key.length() < text.length(); i++)
        key += key[i];
    return key;
}

string encrypt(string text, string key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        result += char((text[i] + key[i]) % 26 + 'A');
    }
    return result;
}

string decrypt(string cipher, string key) {
    string result = "";
    for (int i = 0; i < cipher.length(); i++) {
        result += char((cipher[i] - key[i] + 26) % 26 + 'A');
    }
    return result;
}

int main() {
    string text = "WEAREDISCOVEREDSAVEYOURSELF";
    string key = "DECEPTIVE";

    key = generateKey(text, key);

    string enc = encrypt(text, key);
    cout << "Encrypted: " << enc << endl;

    string dec = decrypt(enc, key);
    cout << "Decrypted: " << dec << endl;

    return 0;
}