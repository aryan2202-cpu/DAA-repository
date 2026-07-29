#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int N = 100000;

    int fairHeads = 0;
    for (int i = 0; i < N; i++) {
        if (rand() % 2 == 0) fairHeads++;
    }
    printf("Fair coin: P(HEAD) = %.4f\n", (double)fairHeads / N);

    double bias = 0.7;
    int biasedHeads = 0;
    for (int i = 0; i < N; i++) {
        double r = (double)rand() / RAND_MAX;
        if (r < bias) biasedHeads++;
    }
    printf("Biased coin (bias=%.1f): P(HEAD) = %.4f\n", bias, (double)biasedHeads / N);

    return 0;
}