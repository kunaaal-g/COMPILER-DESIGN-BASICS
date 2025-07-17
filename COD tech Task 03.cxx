#include <stdio.h>
#include <string.h>
#include <ctype.h>
int isKeyword(char *word) 
{
    char *keywords[] = {"int", "float", "if", "else", "while", "return", "for", "char", "double"};
    for (int i = 0; i < 9; i++) 
    {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}
int main() 
{
    char input[] = "int a = b + 10;";
    char token[20];
    int i = 0, j = 0;
    printf("Lexical Analysis Output:\n");
    while (input[i] != '\0') 
    {
        if (isalnum(input[i])) 
        {
            token[j++] = input[i];
        } else 
        {
            token[j] = '\0';
            j = 0;
            if (strlen(token) > 0) 
            {
                if (isKeyword(token))
                    printf("Keyword: %s\n", token);
                else
                    printf("Identifier: %s\n", token);
            }
            if (input[i] == '+' || input[i] == '-' || input[i] == '=' || input[i] == ';')
                printf("Operator/Symbol: %c\n", input[i]);
        }
        i++;
    }
    return 0;
}
