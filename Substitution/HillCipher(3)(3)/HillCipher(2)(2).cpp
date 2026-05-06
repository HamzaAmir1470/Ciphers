#include <iostream>
using namespace std;

// Key matrix
int key[2][2] = {{3, 3}, {2, 5}};

// Encrypt
string encrypt(string text) {
    string result = "";

    for (int i = 0; i < text.length(); i += 2) {
        int a = text[i] - 'A';
        int b = text[i+1] - 'A';

        int c1 = (key[0][0]*a + key[0][1]*b) % 26;
        int c2 = (key[1][0]*a + key[1][1]*b) % 26;

        result += char(c1 + 'A');
        result += char(c2 + 'A');
    }

    return result;
}

// Modular inverse of determinant (for this key det = 9 → inverse = 3)
int modInverse(int det) {
    for (int i = 1; i < 26; i++) {
        if ((det * i) % 26 == 1)
            return i;
    }
    return -1;
}

// Decrypt
string decrypt(string text) {
    string result = "";

    int det = (key[0][0]*key[1][1] - key[0][1]*key[1][0]) % 26;
    if (det < 0) det += 26;

    int invDet = modInverse(det);

    // Inverse matrix
    int inv[2][2];
    inv[0][0] = ( key[1][1] * invDet) % 26;
    inv[0][1] = (-key[0][1] * invDet) % 26;
    inv[1][0] = (-key[1][0] * invDet) % 26;
    inv[1][1] = ( key[0][0] * invDet) % 26;

    // Fix negatives
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(inv[i][j] < 0) inv[i][j] += 26;

    for (int i = 0; i < text.length(); i += 2) {
        int a = text[i] - 'A';
        int b = text[i+1] - 'A';

        int p1 = (inv[0][0]*a + inv[0][1]*b) % 26;
        int p2 = (inv[1][0]*a + inv[1][1]*b) % 26;

        result += char(p1 + 'A');
        result += char(p2 + 'A');
    }

    return result;
}

int main() {
    string text = "HI";

    string enc = encrypt(text);
    cout << "Encrypted: " << enc << endl;

    string dec = decrypt(enc);
    cout << "Decrypted: " << dec << endl;

    return 0;
}