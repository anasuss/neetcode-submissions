class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_set<int> mp;
       for (int &num : nums){
            if (mp.count(num)) return true;
            mp.insert(num);
       } 
       return false;
    }
};