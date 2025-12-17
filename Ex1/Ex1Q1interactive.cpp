#include <stdio.h>
#include <math.h>

// Iterative Fibonacci
long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int N;
    printf("Enter N (>=2): ");
    scanf("%d", &N);

    long long FN = fibonacci(N);
    double bound = pow(2, (double)N / 2.0);

    printf("F_%d = %lld\n", N, FN);
    printf("2^(%d/2) = %.0f\n", N, bound);

    if (FN >= bound)
        printf("=> F_%d >= 2^(%d/2), inequality holds.\n", N, N);
    else
        printf("=> F_%d < 2^(%d/2), inequality does NOT hold.\n", N, N);

    return 0;
}

