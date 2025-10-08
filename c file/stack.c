#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INILENGTH 20

typedef struct {
  int* base;  // bottom pointer
  int* top;
  int stacksize;
} SQStack;

void initialStack(SQStack* s);
void destroyStack(SQStack* s);
void clearStack(SQStack* s);
void stackEmpty(SQStack* s);
int stackLength(SQStack* s);
void getStackTop(SQStack* s);
void push(SQStack* s, int a);
void pop(SQStack* s);

int main() {
  SQStack* s;
  while (1) {
    printf(
        "1.initialization; 2.destroy; 3.clear stack; 4.empty or not; 5.length; "
        "6.get "
        "the top element; 7.push; 8.pop; 9.exit\n");

    int op = 0;
    scanf("%d", &op);
    switch (op) {
      case 1: {
        initialStack(s);
        break;
      }
      case 2: {
        destroyStack(s);
        break;
      }
      case 3: {
        clearStack(s);
        break;
      }
      case 4: {
        stackEmpty(s);
        break;
      }
      case 5: {
        printf("the length of the stack is %d\n", stackLength(s));
        break;
      }
      case 6: {
        getStackTop(s);
        break;
      }
      case 7: {
        printf("the number you want to push:");
        int a = 0;
        scanf("%d", &a);
        push(s, a);
        break;
      }
      case 8: {
        pop(s);
        break;
      }
      case 9: {
        return 0;
        break;
      }
    }
  }
  return 0;
}

void initialStack(SQStack* s) {
  s->base = (int*)malloc(sizeof(int) * INILENGTH);
  if (!s->base) {
    printf("malloc failure!\n");
    exit(0);
  }
  s->top = s->base;
  s->stacksize = INILENGTH;
}

void destroyStack(SQStack* s) {
  if (s->base) {
    free(s->base);
    s->base = NULL;
    s->top = NULL;
    s->stacksize = 0;
    printf("destroy success!\n");
  } else
    printf("destroy failure cuz no stack defined!\n");
}

void clearStack(SQStack* s) {
  if (s->base) {
    free(s->base);
    s->base = (int*)malloc(sizeof(int) * INILENGTH);
    s->top = s->base;
    s->stacksize = INILENGTH;
  } else
    printf("clear failure cuz no stack defined!\n");
}

void stackEmpty(SQStack* s) {
  if (s->base == s->top)
    printf("It is empty\n");
  else
    printf("It is not empty\n");
}

int stackLength(SQStack* s) {
  return s->top - s->base;
}

void getStackTop(SQStack* s) {
  if (s->top != s->base)
    printf("the top element is %d\n", *s->top);
  else
    printf("empty and no top elements\n");
}

void push(SQStack* s, int a) {
  if (s->top < s->base + INILENGTH) {
    s->top++;
    *s->top = a;
  } else
    printf("push failure! stack full!\n");
}

void pop(SQStack* s) {
  if (s->top != s->base) {
    printf("the number %d is popped out!\n", *s->top);
    s->top--;
  } else
    printf("the stack is empty!\n");
}
