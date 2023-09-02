#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 8
#define MAX_LENGTH 50
char data[MAX_LENGTH];
char stack[MAX_STACK_SIZE][MAX_LENGTH];
int top = -1;
int isempty() {
    if(top == -1)
        return 1;
    else
        return 0;
}
int isfull() {
    if(top == MAX_STACK_SIZE)
        return 1;
    else
        return 0;
}
char *peek() {
    return stack[top];
}
char *pop() {
    if(!isempty()) {
        strcpy(data, stack[top]);
        top = top - 1;
        if (top == -1)
            printf("Pop \"%s\" off of stack. Stack is empty.\n", data);
        else
            printf("Pop \"%s\" off of stack. Top of stack contains: %s\n", data, stack[top]);
        return data;
    } else {
        printf("Error: Could not pop data. Stack is empty.\n");
    }
}
char *push(char *data) {
    if(!isfull()) {
        top = top + 1;
        strcpy(stack[top], data);
        printf("Push \"%s\" onto stack.\n", data);
    } else {
        printf("Error: Could not push \"%s\" onto stack. Stack is full.\n", data);
    }
}
int main() {
    push("Islands");
    push("Channel");
    printf("There are %d items on stack. Top of stack is: %s\n\n", top+1, peek());
    push("San");
    push("Diego");
    printf("There are %d items on stack. Top of stack is: %s\n\n", top+1, peek());
    pop();
    pop();
    printf("There are %d items on stack. Top of stack is: %s\n\n", top+1, peek());
    push("to CSU");
    push("Welcome");
    printf("There are %d items on stack. Top of stack is: %s\n\n", top+1, peek());
    printf("All done adding.\n");
    printf("Value at the top of the stack is: %s\n" ,peek());
    printf("Pop everything off stack.\n");
    printf("----------------------------\n");
    while(!isempty()) {
        pop();
        printf("%s\n",data);
    }
    printf("----------------------------\n");
    return 0;
}
