#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    FILE *fp1,*fp2;
    char ele[100],ele1[100],temp[100];
    printf("enter word to be replaced\n");
    scanf("%s",ele);
    printf("to be replaced with\n");
    scanf("%s",ele1);
    fp1=fopen("word.txt","r");
    fp2=fopen("word1.txt","w");
    while(!feof(fp1))
    {
        fscanf(fp1,"%s",temp);
        if(strcmp(temp,ele)==0)
        {
            fprintf(fp2," %s",ele1);
        }

        else
        {
            fprintf(fp2," %s",temp);
        }

    }
    fclose(fp1);
    fclose(fp2);
}
