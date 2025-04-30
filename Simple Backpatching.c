#include <stdio.h>
#include <string.h>

int instr = 100;  // instruction starting number
int stack[10];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

void backpatch(int address) {
    int temp = pop();
    printf("Backpatching: Instruction at %d now jumps to %d\n", temp, address);
}

int main() {
    char stmt[10];
    int index;

    printf("Enter simple statement (e.g., if E then): ");
    scanf("%s", stmt);

    if (strcmp(stmt, "if") == 0) {
        printf("%d: if E goto ?\n", instr);
        push(instr);  // Save the jump instruction index
        instr++;

        printf("%d: S1 (dummy true block)\n", instr);
        instr++;

        // Simulate target now known
        backpatch(instr);
        printf("%d: S2 (next statement)\n", instr);
    } else {
        printf("Only 'if' supported for demo.\n");
    }

    return 0;
}
