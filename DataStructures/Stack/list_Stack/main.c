#include "header.h"

#define STACK_SIZE 5


int main(void)
{
    s_PtrStack stack = create_Stack();

    for(int i = 0; i < STACK_SIZE; i++) // push to stack
    {
        push(stack, 1.11 * i);
        //printf("root : %lf\n", stack->root);
    }

    for(int i = 2; i < STACK_SIZE; i++) // pop some of it
    {
        printf("popping %lf\n", pop(stack));
    }


    printf("empty:? %d\n", is_empty(stack));

    free_StackMemory(stack);            // pop until empty(frees all nodes) 
                                        // and then free the stack struct

    return 0;
}


s_PtrStack create_Stack()
{
    s_PtrStack new_stack = (s_PtrStack)malloc(sizeof(s_Stack));
    if(!new_stack)
    {
        fprintf(stderr, "ERROR: Not enough memory for stack.");
        exit(1);
    }
    
    new_stack->root = NULL; // seems more reliable
    //memset(new_stack, 0, sizeof(s_Stack));

    return new_stack;
}

s_PtrNode create_Node(double value)
{
    s_PtrNode new_node = (s_PtrNode)malloc(sizeof(s_Node));
    if(!new_node)
    {
        fprintf(stderr, "ERROR: Not enough memory for node.");
        exit(1);
    }

    new_node->data = value;
    new_node->next = NULL;

    return new_node;
}

int is_empty(s_PtrStack stack)
{
    return !stack->root; // if NULL return non-zero / is_empty(yes)
}

void push(s_PtrStack stack, double value)
{
    s_PtrNode new_node = create_Node(value);
    if(stack->root == NULL)
    {
        stack->root = new_node;
    }
    else
    {
        new_node->next = stack->root;
        stack->root = new_node;
    }

    printf("%lf pushed to stack.\n", value);
}

double pop(s_PtrStack stack)
{
    if(is_empty(stack))
    {
        fprintf(stderr,"ERROR: Stack is empty.\n");
        return 0.0;
    }
    s_PtrNode temp = stack->root; // need to save it in temp. 
    stack->root = temp->next;     // need to asign root to its next and not lose track of it to be able to free it
    double popped = temp->data;
    free(temp);

    return popped;
}

double peek(s_PtrStack stack)
{
    if(is_empty(stack))
    {
        fprintf(stderr,"ERROR: Stack is empty.\n");
        return 0.0;
    }

    return stack->root->data;
}


void free_StackMemory(s_PtrStack stack)
{
    while(!is_empty(stack))
    {
        pop(stack);
    }
    printf("empty:? %d\n", is_empty(stack));

    free(stack);

}