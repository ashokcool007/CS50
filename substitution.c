#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool validate_key(char *KEY);
void encipher_text(char *KEY, char *text);

// get key
// validate key
// get plaintext
// encipher
// print ciphertext

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("\n Please follow the format ./substitution KEY(26 Letters) and Try Again \n");
        return 1;
    }

    char *KEY = argv[1];

    while (!validate_key(KEY))
    {
        KEY = get_string("\n Please Enter a Correct Key Value : ");
    }

    // input plain text

    char *input_text = get_string("\n Enter the Text to Cipher: ");
    for (int i=0; i < strlen(input_text); i++)
    {
        while(((!isalpha(input_text[i])) && (!isspace(input_text[i])) && 
        (!ispunct(input_text[i]))))
        
        {
            printf("Broken Character: %c", input_text[i]);
            input_text = get_string("\n Only Alphabets allowed, Please Enter the Correct Text to Cipher: ");
        }
    }
    encipher_text(KEY, input_text);

    return 0;
}

bool validate_key(char *KEY)
{
    int key_len = strlen(KEY);

    if (key_len != 26)
    {
        printf("\n Key Should be of Length 26, Please try Again with a Valid Cipher Key \n");
        return false;
    }

    for (int i = 0; i < key_len; i++)
    {
        if ((KEY[i] <= 'a' && KEY[i] >= 'z') || (KEY[i] <= 'A' && KEY[i] >= 'Z'))
        {
            printf("\n Text Should only contain alphabets and not any other characters, Please try again with a valid key \n");
            return false;
        }

        KEY[i] = toupper(KEY[i]);
    }

    for (int i = 0; i < key_len; i++)
    {

        for (int j = i + 1; j < key_len; j++)
        {
            if (KEY[i] == KEY[j])
            {
                printf("\n All the characters in the key should be distinct, please try again \n");
                return false;
            }
        }
    }

    return true;
}

void encipher_text(char *KEY, char *text)
{
    char *abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int abc_len = strlen(abc);
    int text_len = strlen(text);
    int key_len = strlen(KEY);

    printf("\n Cipher Text: ");
    for (int i = 0; i < text_len; i++)
    {
        if ((isspace(text[i]) || (ispunct(text[i]))))
        {
            printf("%c", text[i]);
        }
        for (int j = 0; j < abc_len; j++)
        {

            if (toupper(text[i]) == abc[j])
            {
                if (islower(text[i]))
                {
                    printf("%c", tolower(KEY[j]));
                }

                else
                {
                    printf("%c", KEY[j]);
                }
            }
        }
    }
    printf("\n");
}

