/*
        This is my own implementation of stack in C. current date (21st./November/2021)
    
    In this example i'm using list of doubles to store data.
    + Can grown and shrink at runtime.   
    - Requeres extra memory due to involvement of pointers.
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node s_Node;
typedef s_Node *s_PtrNode;

typedef struct Stack s_Stack;
typedef s_Stack *s_PtrStack;


struct Node
{
    double data;
    s_PtrNode next;
};

struct Stack
{
    s_PtrNode root;
};


s_PtrStack create_Stack(); // allocates memory for 1 pointer (to Node). Node is not yet alocated.
s_PtrNode create_Node(double value);

int is_empty(s_PtrStack stack); 

void push(s_PtrStack stack, double value);
double pop(s_PtrStack stack);
double peek(s_PtrStack stack);

void free_StackMemory(s_PtrStack stack);

