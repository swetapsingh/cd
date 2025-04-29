#include <stdio.h>
#include <string.h>
#include <ctype.h>  // Required for isupper()

#define MAX 10

char prod[MAX][10];
char leading[MAX], trailing[MAX];
int n;

void findLeading(char ch, int k) {
    for (int i = 0; i < n; i++) {
        if (prod[i][0] == ch) {
            if (!isupper(prod[i][3]))  // Use 3 to skip A-> (RHS starts at index 3)
                leading[k] = prod[i][3];
            else
                findLeading(prod[i][3], k);
        }
    }
}

void findTrailing(char ch, int k) {
    for (int i = 0; i < n; i++) {
        if (prod[i][0] == ch) {
            int len = strlen(prod[i]);
            if (!isupper(prod[i][len - 1]))
                trailing[k] = prod[i][len - 1];
            else
                findTrailing(prod[i][len - 1], k);
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter production %d (like E->+T): ", i + 1);
        scanf("%s", prod[i]);
    }

    for (int i = 0; i < n; i++) {
        findLeading(prod[i][0], i);
        findTrailing(prod[i][0], i);
    }

    for (int i = 0; i < n; i++) {
        printf("LEADING(%c) = %c\n", prod[i][0], leading[i]);
        printf("TRAILING(%c) = %c\n", prod[i][0], trailing[i]);
    }

    return 0;
}
