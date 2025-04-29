#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return -1;
}

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

void infixToPostfix(char* infix, char* postfix) {
    int i, k = 0;
    char c;
    for (i = 0; infix[i]; i++) {
        c = infix[i];
        if (isalnum(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop();  // discard '('
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }
    while (top != -1)
        postfix[k++] = pop();
    postfix[k] = '\0';
}

void reverse(char* exp) {
    int i = 0, j = strlen(exp) - 1;
    while (i < j) {
        if (exp[i] != '(' && exp[i] != ')') {
            char temp = exp[i];
            exp[i] = exp[j];
            exp[j] = temp;
        }
        i++; j--;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    char rev[SIZE], post[SIZE];
    strcpy(rev, infix);
    reverse(rev);
    for (int i = 0; i < strlen(rev); i++) {
        if (rev[i] == '(') rev[i] = ')';
        else if (rev[i] == ')') rev[i] = '(';
    }
    infixToPostfix(rev, post);
    reverse(post);
    strcpy(prefix, post);
}

int main() {
    char infix[SIZE], postfix[SIZE], prefix[SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);
    printf("Postfix: %s\n", postfix);
    printf("Prefix: %s\n", prefix);
    return 0;
}
