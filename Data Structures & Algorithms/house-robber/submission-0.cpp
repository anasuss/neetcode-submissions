class Solution {
public:
    int dp[105];
    int solve(vector<int>& nums, int n, int step){
        if (step >= n) return 0;
        if (dp[step] != -1) return dp[step];
        return dp[step] = max(nums[step]+solve(nums,n,step+2), solve(nums,n,step+1));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0 ; i<=n ; i++){
            dp[i] = -1;
        }
        return solve(nums,n,0);
    }
};
