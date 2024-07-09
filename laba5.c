#include <stdio.h>

#define MOD 12345

int count_sequences(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    if (n == 2) return 4;

    int dp[n+1];
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }

    return dp[n];
}

int main() {
    int n;
    printf("Vvedit dovzhinu poslidovnoctei n: ");
    scanf("%d", &n);

    if (n <= 1 || n >= 10000) {
        printf("Chislo n povinno buti v diapazoni 1 < n < 10000\n");
        return 1;
    }

    int result = count_sequences(n);
    printf("Kilkist shukanih poslidovnostei: %d\n", result);

    return 0;
}
