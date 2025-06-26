#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INILENGTH 20
typedef struct
{
    int *base;//bottom pointer
    int *top;
    int stacksize;
}sqstack;
void initialstack(sqstack *s);
void destroystack(sqstack *s);
void clearstack(sqstack *s);
void stackempty(sqstack *s);
int stacklength(sqstack *s);
void gettop(sqstack *s);
void push(sqstack *s,int a);
void pop(sqstack *s);

int main()
{
    sqstack *s;
    while(1)
    {
        printf("1.initialization 2.destroy 3.clearstack 4.empty or not 5.length 6.get the top element 7.push 8.pop 9.exit\n");
        int ans=0;
        scanf("%d",&ans);
        switch(ans)
        {
            case 1:
                {
                    initialstack(s);
                    break;
                }
            case 2:
                {
                    destroystack(s);
                    break;
                }
            case 3:
                {
                    clearstack(s);
                    break;
                }
            case 4:
                {
                    stackempty(s);
                    break;
                }
            case 5:
                {
                    printf("the length of the stack is %d\n",stacklength(s));
                    break;
                }
            case 6:
                {
                   gettop(s);
                   break;
                }
            case 7:
                {
                    printf("the number you want to push:");
                    int a=0;
                    scanf("%d",&a);
                    push(s,a);
                    break;
                }
            case 8:
                {
                    pop(s);
                    break;
                }
            case 9:
                {
                    return 0;
                    break;
                }
        }
    }
    return 0;
}
void initialstack(sqstack *s)
{
    s->base=(int*)malloc(sizeof(int)*INILENGTH);
    if(!s->base)
    {
        printf("malloc failure!\n");
        exit(0);
    }
    s->top=s->base;
    s->stacksize=INILENGTH;
}
void destroystack(sqstack* s)
{
    if(s->base)
    {
        free(s->base);
        s->base=NULL;
        s->top=NULL;
        s->stacksize=0;
        printf("destroy success!\n");
    }
    else
    {
        printf("destroy failure cuz no stack defined!\n");
    }

}
void clearstack(sqstack *s)
{
    if(s->base)
    {
        free(s->base);
        s->base=(int *)malloc(sizeof(int)*INILENGTH);
        s->top=s->base;
        s->stacksize=INILENGTH;
    }
    else
    {
        printf("clear failure cuz no stack defined!\n");
    }
}
void stackempty(sqstack *s)
{
    if(s->base==s->top)
    {
        printf("It is empty\n");
    }
    else
    {
        printf("It is not empty\n");
    }
}
int stacklength(sqstack *s)
{
    return s->top-s->base;
}
void gettop(sqstack *s)
{
    if(s->top!=s->base)
    {
        printf("the top element is %d\n",*s->top);
    }
    else
    {
        printf("empty and no top elements\n");
    }
}
void push(sqstack *s,int a)
{
    if(s->top<s->base+INILENGTH)
    {
        s->top++;
        *s->top=a;
    }
    else
    {
        printf("push failure! stack full!\n");
    }
}
void pop(sqstack *s)
{
    if(s->top!=s->base)
    {
        printf("the number %d is popped out!\n",*s->top);
        s->top--;
    }
    else
    {
        printf("the stack is empty!\n");
    }
}
