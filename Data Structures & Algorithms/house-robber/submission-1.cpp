class Solution {
public:
    int dp[105];
    int rob(vector<int>& nums, int n, int step){
        if (step >= n) return 0;
        if (dp[step] != -1) return dp[step];
        return dp[step] = max(nums[step]+rob(nums,n,step+2), rob(nums,n,step+1));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0 ; i<=n ; i++){
            dp[i] = -1;
        }
        return rob(nums,n,0);
    }
};
