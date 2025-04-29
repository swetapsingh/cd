#include <stdio.h>
#include <string.h>

typedef struct {
    char lhs;
    char rhs[10];
    int dot_pos;
} Item;

void display(Item items[], int count) {
    printf("LR(0) Items:\n");
    for (int i = 0; i < count; i++) {
        printf("%c -> ", items[i].lhs);
        for (int j = 0; j < strlen(items[i].rhs); j++) {
            if (j == items[i].dot_pos)
                printf(".");
            printf("%c", items[i].rhs[j]);
        }
        if (items[i].dot_pos == strlen(items[i].rhs))
            printf(".");
        printf("\n");
    }
}

int main() {
    Item items[10];
    int count = 0;

    printf("Enter production (e.g., E->E+T): ");
    scanf(" %c->%s", &items[count].lhs, items[count].rhs);
    items[count].dot_pos = 2;
    count++;

    display(items, count);
    return 0;
}
