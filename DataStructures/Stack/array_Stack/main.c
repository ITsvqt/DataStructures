#include "header.h"


#define STACK_SIZE 10


int main(void)
{
    s_PtrStack stack = create_Stack(STACK_SIZE); // example stack with size define

    for(int i = 0; i < STACK_SIZE * 2; i++) // push to stack
    {   
        push(stack, i * 1.1);
    }

    while(!is_empty(stack))
    {
        printf("%lf\n", pop(stack));
    }

    printf("peeking %lf\n", peek(stack));
    free_StackMemory(stack);                //necessary

    return 0;
}


s_PtrStack create_Stack(size_t capacity)
{
    //s_PtrStack new_stack = (s_PtrStack)calloc(1, sizeof(s_Stack));
    s_PtrStack new_stack = (s_PtrStack)malloc(sizeof(s_Stack));
    memset(new_stack, 0, sizeof(s_Stack));
    //
    new_stack->capacity = capacity;
    new_stack->top = -1;
    new_stack->array = (double *)malloc(new_stack->capacity * sizeof(double));
    set_doubleArray(new_stack->array, capacity);

    return new_stack;
}

void resize_StackArray(s_PtrStack stack)
{
    double * new_arrPtr = (double *)realloc(stack->array, stack->capacity * 2);
    if(!new_arrPtr)
    {
        fprintf(stderr, "ERROR: Not enough memory for resized array.\n");
        free_StackMemory(stack);
        exit(1);
    }
    stack->array = new_arrPtr;
}

void set_doubleArray(double *array, size_t size)
{
    for(int i = 0 ; i < size; i++)
    {
        array[i] = 0.0;
    }
}


int is_full(s_PtrStack stack)
{
    return stack->top == stack->capacity - 1;
}

int is_empty(s_PtrStack stack)
{
    return stack->top == -1;
}


void push(s_PtrStack stack, double element)
{
    if(is_full(stack))
    {
        resize_StackArray(stack);
        //fprintf(stderr, "ERROR: Cannot push %lf to stack, it's full.\n", element);
        //return;
    }
    stack->array[++stack->top] = element;
    printf("%lf pushed to stack.\n", element);
}

double pop(s_PtrStack stack)
{
    if(is_empty(stack))
    {
        fprintf(stderr, "ERROR: Cannot pop from stack, it's empty.\n");
        return 0.0;
    }

    return stack->array[stack->top--];
}

double peek(s_PtrStack stack)
{
    if(is_empty(stack))
    {
        fprintf(stderr, "ERROR: Cannot peek in stack, it's empty.\n");
        return 0.0;
    }
    return stack->array[stack->top];
}

void free_StackMemory(s_PtrStack stack)
{
    free(stack->array);
    free(stack);
}
