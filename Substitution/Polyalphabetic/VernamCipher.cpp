#include <iostream>
using namespace std;

string encryptDecrypt(string text, string key) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        result += char(text[i] ^ key[i]); // XOR
    }

    return result;
}

int main() {
    string text = "HELLO";
    string key  = "XMCKL"; // same length

    string enc = encryptDecrypt(text, key);
    cout << "Encrypted: " << enc << endl;

    string dec = encryptDecrypt(enc, key);
    cout << "Decrypted: " << dec << endl;

    return 0;
}