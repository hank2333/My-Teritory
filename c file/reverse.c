#include<stdio.h>
#include<string.h>
int main()
{
    char strread[100];
    gets(strread);
    char word[10][10];
    char temstr[100];
    int wordnum=0,n=0,m=0;
    for (int i=0;i<=strlen(strread);i++)
    {
        if(strread[i]==' ')
        {
            strcpy(word[m],temstr);
            m++;
            for(int j=0;j<=n;j++)
            {
                temstr[j]='\0';
            }
            n=0;
        }
        else
        {
            temstr[n]=strread[i];
            n++;
        }
    }
    strcpy(word[m++],temstr);
    m-=1;
    for(;m>=0;m--)
    {
        printf("%s ",word[m]);
    }
}
