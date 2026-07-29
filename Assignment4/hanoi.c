#include <stdio.h>

long moveCount = 0;

void hanoi(int n, char from, char aux, char to) {
    if (n == 0) return;
    hanoi(n - 1, from, to, aux);
    moveCount++;
    // printf("Move disc %d from %c to %c\n", n, from, to); 
    hanoi(n - 1, aux, from, to);
}

int main() {
    printf("discs,moves\n");
    for (int n = 1; n <= 25; n++) {
        moveCount = 0;
        hanoi(n, 'A', 'B', 'C');
        printf("%d,%ld\n", n, moveCount);
    }
    return 0;
}