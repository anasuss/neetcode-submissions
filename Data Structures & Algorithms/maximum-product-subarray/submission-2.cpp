class Solution {
public:
    int maxProduct(vector<int>& nums) {
        set<int> positive, negative;
        int ans = *max_element(nums.begin(), nums.end()), p =1;
        for (int i = 0 ; i<nums.size() ; i++){
            if (nums[i] == 0){
                positive.clear();
                negative.clear();
                p = 1;
                continue;
            }
            p*=nums[i];
            ans = max(ans,p);
            if (p<0){
                if (negative.size() > 0){
                    int x = *negative.begin();
                    if (x != 1){
                        ans = max(ans,-p/x);
                    }
                }
                negative.insert(-p);
            }else{
                if (positive.size() > 0)
                    ans = max(ans,p/(*positive.begin()));
                positive.insert(p);
            }
        }
        return ans;
    }
};
