/*
        This is my own implementation of stack in C. current date (21st./November/2021)
    
    In this example i'm using array of doubles to store data.
    + Saves memory .
    (- Array stack gives us limitation to the number of elements in the stack.)
    Successfuly implemented array resize func.
 
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack s_Stack;
typedef s_Stack *s_PtrStack;

struct Stack
{
    int top;
    size_t capacity;
    double *array;
};


s_PtrStack create_Stack(size_t capacity);
void resize_StackArray(s_PtrStack stack);
void set_doubleArray(double *array, size_t size); // You can memset for int array

int is_full(s_PtrStack stack);
int is_empty(s_PtrStack stack);

void push(s_PtrStack stack, double element);
double pop(s_PtrStack stack);
double peek(s_PtrStack stack);


void free_StackMemory(s_PtrStack stack);
