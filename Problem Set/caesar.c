#include <cs50.h>
#include <stdio.h>
#include <string.h>

string Coded (string Word, int Key);

int main()
{
    string Original = get_string("Enter the phrase that you want to be a code:\n");
    int Key = get_int("Enter a number that represent your key:\n");
    Coded(Original, Key);
}

string Coded(string Word, int Key)
{
   for (int i = 0, n = strlen(Word); i < n; i++)
    {
        if (Word[i] >= 32 && Word[i] <= 64)
        {
            printf("%c", Word[i]);
        }
        else if (Word[i] >= 65 && Word[i] <= 90 && (Word[i] + Key) > 90)
        {
            printf("%c", (((Word[i] - 65) + Key % 26) + 65));
        }
        else if (Word[i] >= 97 && Word[i] <= 122 && (Word[i] + Key) > 122)
        {
            printf("%c", (((Word[i] - 97) + Key) % 26) + 97);
        }
        else
        {
            printf("%c", Word[i] + Key);
        }
    }
    printf("\n");
    return 0;
}
