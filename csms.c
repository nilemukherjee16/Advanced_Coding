#include <stdio.h>
#include <string.h>
int main() {
    char s[100005];
    if (scanf("%s", s) == EOF) return 0;
    int n = strlen(s);
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        int visited[26] = {0};
        for (int j = 0; j < n; j++) {
            int idx = (i + j) % n;
            int val = s[idx] - 'a' + 1;
            if (visited[s[idx] - 'a']) {
                break;
            }
            visited[s[idx] - 'a'] = 1;
            current_sum += val;
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }
    printf("%d\n", max_sum);
    return 0;
}
