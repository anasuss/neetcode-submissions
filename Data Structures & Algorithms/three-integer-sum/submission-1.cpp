class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> mp;
        set<vector<int>> s;
        vector<vector<int>> ans;
        for (int i = 0 ; i<n ; i++){
            for (int j = i+1 ; j<n ; j++){
                int target = nums[i]+nums[j];
                if (mp.count(-target)){
                    vector<int> temp = {-target,nums[i],nums[j]};
                    sort(temp.begin(),temp.end());
                    if (!s.count(temp))
                        s.insert(temp);
                }
            }
            mp.insert(nums[i]);
        }
        for (auto it : s){
            ans.push_back(it);
        }
        return ans;
    }
};
