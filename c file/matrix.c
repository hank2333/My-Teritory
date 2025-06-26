#include<stdio.h>
#include<math.h>
int main()
{
    while(1)
    {
        int rn1,rn2,rn3,cn1,cn2,cn3;
        printf("the size of matrix:");
        scanf("%d%d%d%d",&rn1,&cn1,&rn2,&cn2);
        int a[rn1][cn1],b[rn2][cn2],c[100][100];
        printf("the first matrix:\n");
        for(int i=0;i<=rn1-1;i++)
        {
            for(int j=0;j<=cn1-1;j++)
        {
                scanf("%d",&a[i][j]);
            }
        }
        printf("the second matrix:\n");
        for(int i=0;i<=rn2-1;i++)
        {
            for(int j=0;j<=cn2-1;j++)
            {
                scanf("%d",&b[i][j]);
            }
        }
        char op;
        printf("the operation is:");
        getchar();
        scanf("%c",&op);
        if(op=='+')
        {
            if(rn1!=rn2||cn1!=cn2)
                {
                    printf("incorrect size,please try again\n");
                    continue;
                }
                rn3=rn1;cn3=cn1;
                for(int i=0;i<=rn1-1;i++)
                {
                    for(int j=0;j<=cn1-1;j++)
                    {
                        c[i][j]=a[i][j]+b[i][j];
                    }
                }

        }
        else if(op=='-')
        {
            if(rn1!=rn2||cn1!=cn2)
                {
                    printf("incorrect size,please try again\n");
                    continue;
                }
                rn3=rn1;cn3=cn1;
                for(int i=0;i<=rn1-1;i++)
                {
                    for(int j=0;j<=cn1-1;j++)
                    {
                        c[i][j]=a[i][j]-b[i][j];
                    }
                }

        }
        else if(op=='*')
        {
            if(cn1!=rn2)
                {
                    printf("incorrect size,please try again\n");
                    continue;
                }
                rn3=rn1;cn3=cn2;
                  for(int i=0;i<=rn3-1;i++)
                {
                    for(int j=0;j<=cn3-1;j++)
                    {
                        for(int x=0;x<=cn1-1;x++)
                        {
                            c[i][j]+=a[i][x]*b[x][j];
                        }
                    }
                }

        }
        for(int i=0;i<=rn3-1;i++)
        {
            for(int j=0;j<=cn3-1;j++)
            {
                printf("%d ",c[i][j]);
                if (j==cn3-1)
                {
                    printf("\n");
                }
            }
        }
        break;
    }
}
