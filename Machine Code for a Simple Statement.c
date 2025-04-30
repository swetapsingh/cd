#include <stdio.h>

int main() {
    char expr[20];
    char op1, op2, op3, result;
    printf("Enter expression (e.g., a=b+c*d): ");
    scanf("%s", expr);

    result = expr[0];  // 'a'
    op1 = expr[2];     // 'b'
    op2 = expr[4];     // 'c'
    op3 = expr[6];     // 'd'

    printf("\nAssuming expression: %c = %c + %c * %c\n", result, op1, op2, op3);
    printf("\nGenerated Machine Code:\n");

    printf("LOAD R1, %c\n", op3);
    printf("MUL  R1, %c\n", op2);
    printf("ADD  R1, %c\n", op1);
    printf("STORE %c, R1\n", result);

    return 0;
}
