#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int key[3][3];

// Function to find GCD
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// Modular inverse
int modInverse(int a)
{
    a %= 26;
    for (int x = 1; x < 26; x++)
        if ((a * x) % 26 == 1)
            return x;
    return -1;
}

// Determinant of 3x3
int determinant()
{
    int det = key[0][0] * (key[1][1] * key[2][2] - key[1][2] * key[2][1]) - key[0][1] * (key[1][0] * key[2][2] - key[1][2] * key[2][0]) + key[0][2] * (key[1][0] * key[2][1] - key[1][1] * key[2][0]);

    det %= 26;
    if (det < 0)
        det += 26;
    return det;
}

// Cofactor matrix
void getCofactor(int cof[3][3])
{
    cof[0][0] = (key[1][1] * key[2][2] - key[1][2] * key[2][1]);
    cof[0][1] = -(key[1][0] * key[2][2] - key[1][2] * key[2][0]);
    cof[0][2] = (key[1][0] * key[2][1] - key[1][1] * key[2][0]);

    cof[1][0] = -(key[0][1] * key[2][2] - key[0][2] * key[2][1]);
    cof[1][1] = (key[0][0] * key[2][2] - key[0][2] * key[2][0]);
    cof[1][2] = -(key[0][0] * key[2][1] - key[0][1] * key[2][0]);

    cof[2][0] = (key[0][1] * key[1][2] - key[0][2] * key[1][1]);
    cof[2][1] = -(key[0][0] * key[1][2] - key[0][2] * key[1][0]);
    cof[2][2] = (key[0][0] * key[1][1] - key[0][1] * key[1][0]);
}

// Transpose
void transpose(int mat[3][3], int trans[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            trans[i][j] = mat[j][i];
}

// Encryption
string encrypt(string text)
{
    string result = "";

    // Convert to uppercase & remove non-letters
    string clean = "";
    for (char c : text)
        if (isalpha(c))
            clean += toupper(c);

    // Padding
    while (clean.length() % 3 != 0)
        clean += 'X';

    for (int i = 0; i < clean.length(); i += 3)
    {
        int p[3];
        for (int j = 0; j < 3; j++)
            p[j] = clean[i + j] - 'A';

        int c[3] = {0};

        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
                c[row] += key[row][col] * p[col];

            c[row] %= 26;
        }

        for (int j = 0; j < 3; j++)
            result += char(c[j] + 'A');
    }

    return result;
}

// Decryption
string decrypt(string text)
{
    string result = "";

    int det = determinant();

    // Validate invertibility
    if (gcd(det, 26) != 1)
    {
        cout << "Matrix not invertible mod 26. Choose another key.\n";
        return "";
    }

    int invDet = modInverse(det);

    int cof[3][3], adj[3][3], inv[3][3];

    getCofactor(cof);
    transpose(cof, adj);

    // Build inverse matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            inv[i][j] = (adj[i][j] * invDet) % 26;
            if (inv[i][j] < 0)
                inv[i][j] += 26;
        }
    }

    for (int i = 0; i < text.length(); i += 3)
    {
        int c[3];
        for (int j = 0; j < 3; j++)
            c[j] = text[i + j] - 'A';

        int p[3] = {0};

        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
                p[row] += inv[row][col] * c[col];

            p[row] %= 26;
        }

        for (int j = 0; j < 3; j++)
            result += char(p[j] + 'A');
    }

    return result;
}

int main()
{
    cout << "Enter 3x3 key matrix (values 0-25):\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> key[i][j];

    cin.ignore();

    string text;
    cout << "Enter plaintext: ";
    getline(cin, text);

    string enc = encrypt(text);
    cout << "Encrypted: " << enc << endl;

    string dec = decrypt(enc);
    if (dec != "")
        cout << "Decrypted: " << dec << endl;

    return 0;
}