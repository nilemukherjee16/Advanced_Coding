#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int n;
    if (scanf("%d", &n) == EOF) return 0;
    long long a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    long long k;
    scanf("%lld", &k);
    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[0]) % k != 0) {
            printf("-1\n");
            return 0;
        }
    }
    qsort(a, n, sizeof(long long), compare);
    long long target = a[n / 2];
    long long total_operations = 0;
    for (int i = 0; i < n; i++) {
        long long diff = abs(a[i] - target);
        total_operations += (diff / k);
    }
    printf("%lld\n", total_operations);

    return 0;
}
