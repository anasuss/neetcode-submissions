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
        if (n == 1){
            return nums[0];
        }
        for (int i = 0 ; i<=n ; i++){
            dp[i] = -1;
        }
        int option1 = rob(nums,n,1);
        for (int i = 0 ; i<=n ; i++){
            dp[i] = -1;
        }
        int option2 = rob(nums,n-1,0);
        return max(option1,option2);
    }
};
