#include <stdio.h>

int main()
{
    char text[100];
    scanf("%s", text);
    while(strcmp(text, "exit") != 0)
    {
        printf("%s\n", text);
        scanf("%s", text);
    }
    return 0;
}