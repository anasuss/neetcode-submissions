class Solution {
public:
    int dp[1005][1005];
    int lengthOfLIS(vector<int> &nums, int p, int prv){
        int &res = dp[p+1][prv+1];
        if (res != -1) return res;
        res = 0;
        for (int i = p ; i<nums.size() ; i++){
            if (prv == -1){
                res = max(res, 1+lengthOfLIS(nums, i+1, i));
            }else if (nums[i] > nums[prv]){
                res = max(res, 1+lengthOfLIS(nums,i+1,i));
            }
        }
        return res;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0 ; i<=n+1 ; i++){
            for (int j = 0 ; j<=n+1 ; j++){
                dp[i][j] = -1;
            }
        }
        return lengthOfLIS(nums,0,-1);
    }
};
