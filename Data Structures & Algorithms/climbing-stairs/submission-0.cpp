class Solution {
public:
    int dp[50];
    int climb(int n , int step = 0){
        if (step > n) return dp[step] = 0;
        if (step == n) return dp[step] = 1;
        if (dp[step] != -1) return dp[step];

        return dp[step] = climb(n,step + 1) + climb(n, step + 2);
    }
    int climbStairs(int n) {
        for (int i = 0 ; i<=n ; i++) dp[i] = -1;
        return climb(n);
    }
};
