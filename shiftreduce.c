#include <stdio.h>
#include <string.h>

char input[100], stack[100];
int top = -1, ip = 0;

void push(char c) {
    stack[++top] = c;
    stack[top + 1] = '\0';
}

void reduce() {
    // Check if top 3 symbols are E+E
    if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '+' && stack[top - 2] == 'E') {
        top -= 2;
        stack[top] = 'E';
        stack[top + 1] = '\0';
        printf("REDUCE E+E -> E\n");
    }
    // Check if top symbol is i
    else if (stack[top] == 'i') {
        stack[top] = 'E';
        printf("REDUCE i -> E\n");
    }
}

int main() {
    printf("Enter the input (e.g., i+i): ");
    scanf("%s", input);

    printf("Stack\tInput\tAction\n");

    while (input[ip] != '\0') {
        push(input[ip++]);
        printf("%s\t%s\tSHIFT\n", stack, &input[ip]);
        reduce();
    }

    while (top > 0) {
        reduce();
    }

    if (strcmp(stack, "E") == 0)
        printf("%s\t\tACCEPTED\n", stack);
    else
        printf("%s\t\tREJECTED\n", stack);

    return 0;
}
