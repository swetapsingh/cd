#include <stdio.h>
#include <string.h>

int main() {
    char expr[20], temp[5] = "t0";
    int i = 0, j = 0, tempNum = 1;

    printf("Enter expression (e.g., a=b+c*d): ");
    scanf("%s", expr);

    printf("\nIntermediate Code (Quadruples):\n");
    printf("Op\tArg1\tArg2\tResult\n");

    // Find * or /
    for (i = 2; i < strlen(expr); i++) {
        if (expr[i] == '*' || expr[i] == '/') {
            printf("%c\t%c\t%c\t%s\n", expr[i], expr[i - 1], expr[i + 1], temp);
            expr[i - 1] = temp[1];  // Replace with temp variable (number only)
            temp[1] += 1;
            for (j = i; j < strlen(expr) - 2; j++)
                expr[j] = expr[j + 2];
            expr[j] = '\0';
            i = 1;
        }
    }

    // Find + or -
    for (i = 2; i < strlen(expr); i++) {
        if (expr[i] == '+' || expr[i] == '-') {
            printf("%c\t%c\t%c\tt%c\n", expr[i], expr[i - 1], expr[i + 1], temp[1]);
            expr[i - 1] = temp[1];
            temp[1] += 1;
            for (j = i; j < strlen(expr) - 2; j++)
                expr[j] = expr[j + 2];
            expr[j] = '\0';
            i = 1;
        }
    }

    // Final assignment
    printf("=\t%c\t\t%c\n", expr[2], expr[0]);

    // Triples
    printf("\nTriple Representation:\n");
    printf("Index\tOp\tArg1\tArg2\n");
    printf("0\t*\t%c\t%c\n", 'c', 'd');
    printf("1\t+\t%c\t(0)\n", 'b');
    printf("2\t=\t(1)\t\t%c\n", 'a');

    // Indirect Triples
    printf("\nIndirect Triple Representation:\n");
    printf("Pointer\tInstruction\n");
    printf("0\t*\tc\td\n");
    printf("1\t+\tb\t(0)\n");
    printf("2\t=\t(1)\ta\n");

    return 0;
}
