// // #include <iostream>
// // using namespace std;

// // string encryptDecrypt(string text, string key) {
// //     string result = "";

// //     for (int i = 0; i < text.length(); i++) {
// //         result += char(text[i] ^ key[i]); // XOR
// //     }

// //     return result;
// // }

// // int main() {
// //     string text = "OAk";
// //     string key  = "SON"; // same length

// //     string enc = encryptDecrypt(text, key);
// //     cout << "Encrypted: " << enc << endl;

// //     string dec = encryptDecrypt(enc, key);
// //     cout << "Decrypted: " << dec << endl;

// //     return 0;
// // }

// #include <iostream>
// #include <iomanip>
// #include <sstream>
// using namespace std;

// // Convert string → HEX
// string toHex(string input) {
//     stringstream ss;

//     for (unsigned char c : input) {
//         ss << hex << setw(2) << setfill('0') << (int)c;
//     }

//     return ss.str();
// }

// // Convert HEX → string
// string fromHex(string hexStr) {
//     string output = "";

//     for (int i = 0; i < hexStr.length(); i += 2) {
//         string byte = hexStr.substr(i, 2);
//         char chr = (char)stoi(byte, nullptr, 16);
//         output += chr;
//     }

//     return output;
// }

// // XOR function
// string xorEncrypt(string text, string key) {
//     string result = "";

//     for (int i = 0; i < text.length(); i++) {
//         result += char(text[i] ^ key[i]);
//     }

//     return result;
// }

// int main() {
//     string text = "OAk";
//     string key  = "SON";

//     // Encrypt (XOR)
//     string encrypted = xorEncrypt(text, key);

//     // Convert to HEX (safe output)
//     string hexOutput = toHex(encrypted);

//     cout << "Encrypted (HEX): " << hexOutput << endl;

//     // Convert back from HEX
//     string raw = fromHex(hexOutput);

//     // Decrypt (XOR again)
//     string decrypted = xorEncrypt(raw, key);

//     cout << "Decrypted: " << decrypted << endl;

//     return 0;
// }

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