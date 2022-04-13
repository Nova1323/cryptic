#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int key_check(string);
string substitution(string, string);

int main(int argc, string argv[])
{
    // End program with exit status 1 and error message if argc is not equal to 2
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        int key_len = strlen(argv[1]);
        //printf("%i\n", key_len);

        // End program with exit status 1 and error message if key length is not equal to 26
        if (key_len != 26)
        {
            printf("Invalid key\n");
            return 1;
        }
        else
        {
            // Call function check to check if key is valid.
            int check = key_check(argv[1]);
            if (check == 1)
            {
                // End program with exit status 1 and error message if key is not valid
                printf("Invalid Key\n");
                return 1;
            }
            else
            {
                // Get user input
                string text = get_string("Plain Text: ");

                // Call function cipher to encrypt the data and print it
                string cipher = substitution(argv[1], text);
                printf("ciphertext: %s\n", cipher);
                return 0;
            }
        }
    }
}

// Checks if the key is valid
int key_check(string key)
{

    for (int i = 0; i < 26; i++)
    {
        // Check if key is alphabetic or not
        if (!(('a' <= key[i] && key[i] <= 'z') || ('A' <= key[i] && key[i] <= 'Z')))
        {
            return 1;
        }
        else
        {
            for (int j = i + 1; j < 26; j++)
            {
                // Check for duplicate alphabets
                if (toupper(key[i]) == toupper(key[j]))
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

// Encrypts the data
string substitution(string key, string text)
{
    int len = strlen(text);
    char cipher[len];
    // For comparing or detectig the letters
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < len; i++)
    {
        // If the input is Upper case
        if (isupper(text[i]) != 0)
        {
            for (int j = 0; j < 26; j++)
            {
                if (text[i] == letters[j])
                {
                    cipher[i] = toupper(key[j]);
                    break;
                }
            }
        }
        // If the input is Lower case
        else if (islower(text[i]) != 0)
        {
            for (int j = 0; j < 26; j++)
            {
                if (text[i] == tolower(letters[j]))
                {
                    cipher[i] = tolower(key[j]);
                    break;
                }
            }
        }
        else
        {
            // If the input is not a alphabet
            cipher[i] = text[i];
        }
    }

    // store cipher in text as we are returning a string and not a char array
    text = cipher;

    return text;
}
