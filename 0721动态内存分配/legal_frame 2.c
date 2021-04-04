#include <stdio.h>
#include <string.h>
char *legal_frame(char *src)
{
    char *head = strstr(src, "head");
    char *tail = strstr(src, "tail");
    char *src_o = src;

    if (head == NULL || tail == NULL)
    {
        printf("flame is destoryed\n");
    }

    while (head < (tail + 4))
    {
        *src++ = *head++;
    }
    *src = '\0';
    return src_o;
}

int main()
{
    char a[] = "abcdhead abcdef tail";


    printf("%s\n", legal_frame(a));
    return 0;
}
