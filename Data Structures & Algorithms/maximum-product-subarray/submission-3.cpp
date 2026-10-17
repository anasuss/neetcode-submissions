class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = *max_element(nums.begin(), nums.end());
        int p = 1, firstNeg = 0;
        for (int x : nums) {
            if (x == 0) { p = 1; firstNeg = 0; continue; }
            p *= x;
            if (p > 0) ans = max(ans, p);
            else if (firstNeg != 0) ans = max(ans, p / firstNeg);
            else firstNeg = p;
        }
        return ans;
    }
};
