class Solution {
public:
    int dp[12][10005];
    int work(const vector<int>& coins, int amount, int i = 0){
        int &res = dp[i][amount];
        if (res != -1) return res;
        if (amount == 0) return res = 0;
        if (i == coins.size()) return res = 1e9;
        if (amount - coins[i] < 0) return res = 1e9;

        return res = min(work(coins, amount, i+1),1 + min(work(coins, amount-coins[i], i),work(coins, amount-coins[i], i+1)));
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        for (int i = 0 ; i<=n ; i++){
            for (int j = 0; j<=amount ; j++){
                dp[i][j] = -1;
            }
        }
        int res = work(coins,amount);
        return res >= 1e9 ? -1 : res;
    }
};
