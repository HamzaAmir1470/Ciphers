#include <iostream>
using namespace std;

string encrypt(string text, int shift) {
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i]))
            text[i] = char((text[i] + shift - 65) % 26 + 65);
        else if (islower(text[i]))
            text[i] = char((text[i] + shift - 97) % 26 + 97);
    }
    return text;
}

string decrypt(string text, int shift) {
    return encrypt(text, 26 - shift);
}

int main() {
    string text = "HELLO";
    int shift = 3;

    string encrypted = encrypt(text, shift);
    cout << "Encrypted: " << encrypted << endl;

    string decrypted = decrypt(encrypted, shift);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}