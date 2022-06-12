#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letter(string text);
int count_words(string text);
int count_sentences(string text);



int main(void) 
{
    string Text = get_string("text: ");
    
    int L = 100 * count_letter(Text) / count_words(Text);
    int S = 100 * count_sentences(Text) / count_words(Text);
    
    float index = 0.0588 * L - 0.296 * S - 15.8;
    
    printf("Grade %i", (int) round(index));
    printf("\n");
}


int count_letter(string text)
{
    int x;
    int alphabet = 0;

    for (x = 0; x < strlen(text); x++)
    {
        if (isalpha(text[x]) != 0)
        {
            alphabet++;
        }
    }
    
    return alphabet;
}

int count_words(string text)
{
    int y;
    int words = 1;
    for (y = 0; y < strlen(text); y++)
    {
        if (text[y] == 32)
        {
           words++;
        }
    }

    return words;
}

int count_sentences(string text)
{
    int z;
    int sentences = 0;
    for (z = 0; z < strlen(text); z++)
    {
        if (text[z] == '.' || text[z] == '!' || text[z] == '?')
        {
           sentences++;
        }
    }

    return sentences;
}
