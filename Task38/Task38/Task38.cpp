#include <iostream>
using namespace std;

const int MOD = 1000000009;

int main() {
    const int N = 40;
    int A = 2, B = 3;
    int dp[N + 1];
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        if (i % 13 == 0) {
            dp[i] = 0;
        }
        else {
            dp[i] = (i - A >= 0 ? dp[i - A] : 0) + (i - B >= 0 ? dp[i - B] : 0);
            dp[i] %= MOD;
        }
    }
    cout << dp[N] << endl;
    return 0;
}