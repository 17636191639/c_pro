#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_arr(int a[9])
{
    int i;
    for(i = 0; i < 9; i++)
    {
        printf("%d ", a[i]);

    }
    printf("\n");
}

void file_to_arr(FILE *stream,int *a)
{
    char text[10];
    int i;

    while (fscanf(stream,"%s\n", text) == 1 )
    {
        if (strcmp(text, "begin") == 0 )
        {
            i = 0;
        }
        else if (strcmp(text, "end") == 0)
        {
            break;
        }
        else
        {
            a[i] = atoi(text);
            //printf("%d\n", a[i]);
            i++;
        }
    }
}
int main()
{
    int buf1[9];
    int buf2[9];
    int i = 0;
    int num = 0;

    FILE *fp_first = fopen("./1.txt", "r");
    if(fp_first == NULL)
    {
        perror("open");
        exit(1);
    }
    FILE *fp_sec = fopen("./2.txt", "r");
    if(fp_sec == NULL)
    {
        perror("open");
        exit(1);
    }
    FILE *fp_dest = fopen("./dest.txt", "w");
    if(fp_dest == NULL)
    {
        perror("open");
        exit(1);
    }

    char text1[10];
    char text2[10];
    //fscanf(fp_first,"%d\n",&buf[0]);

    file_to_arr(fp_first, buf1);
    file_to_arr(fp_sec, buf2);

    fprintf(fp_dest, "%s\n", "begin");
    for(i = 1; i <= 9; i++)
    {
        fprintf(fp_dest, "%d ",buf1[i - 1] + buf2[i - 1]);
        if(i %3 == 0)
        {
            fprintf(fp_dest, "\n");
        }
    }
    fprintf(fp_dest, "%s\n", "end");



    fclose(fp_first);
    fclose(fp_sec);
    fclose(fp_dest);

    return 0;
}
