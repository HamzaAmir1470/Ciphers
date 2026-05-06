#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

/**
 * Clean input: removes non-alphabet characters and converts to uppercase.
 */
string cleanString(string input)
{
    string result = "";
    for (char c : input)
    {
        if (isalpha(c))
        {
            result += toupper(c);
        }
    }
    return result;
}

/**
 * OTP Function:
 * mode  1 = Encrypt (P + K)
 * mode -1 = Decrypt (C - K)
 */
string processOTP(string text, string key, int mode)
{
    string result = "";
    int keyLen = key.length();

    for (int i = 0; i < text.length(); i++)
    {
        int textVal = text[i] - 'A';
        int keyVal = key[i % keyLen] - 'A';

        // Formula: (Value + (mode * key)) mod 26
        // We add 26 to handle negative results during subtraction
        int outputVal = (textVal + (mode * keyVal) + 26) % 26;

        result += (char)(outputVal + 'A');
    }
    return result;
}

int main()
{
    string rawMessage = "Gold is under the carpet";
    string rawKey = "mosque";

    // 1. Prepare data
    string message = cleanString(rawMessage);
    string key = cleanString(rawKey);

    // 2. Encrypt
    string encrypted = processOTP(message, key, 1);

    // 3. Decrypt
    string decrypted = processOTP(encrypted, key, -1);

    // Output Results
    cout << "--- One-Time Pad ---" << endl;
    cout << "Original Message:  " << rawMessage << endl;
    cout << "Cleaned Key:       " << key << endl;
    cout << "-------------------------------------" << endl;
    cout << "Encrypted (Hex):   " << encrypted << endl;
    cout << "Decrypted (Plain): " << decrypted << endl;

    return 0;
}