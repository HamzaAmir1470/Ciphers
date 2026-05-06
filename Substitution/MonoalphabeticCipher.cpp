#include <iostream>
using namespace std;

string encrypt(string text, string key) {
    string result = "";

    for (char ch : text) {
        if (isupper(ch))
            result += key[ch - 'A'];
        else if (islower(ch))
            result += tolower(key[ch - 'a']);
        else
            result += ch;
    }

    return result;
}

string decrypt(string text, string key) {
    string result = "";

    for (char ch : text) {
        if (isupper(ch)) {
            for (int i = 0; i < 26; i++) {
                if (key[i] == ch) {
                    result += char(i + 'A');
                    break;
                }
            }
        }
        else if (islower(ch)) {
            for (int i = 0; i < 26; i++) {
                if (tolower(key[i]) == ch) {
                    result += char(i + 'a');
                    break;
                }
            }
        }
        else {
            result += ch;
        }
    }

    return result;
}

int main() {
    string key = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string text = "HELLO";

    string enc = encrypt(text, key);
    cout << "Encrypted: " << enc << endl;

    string dec = decrypt(enc, key);
    cout << "Decrypted: " << dec << endl;

    return 0;
}