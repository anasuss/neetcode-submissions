class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> elements;
        int ans = nums.size() > 0;
        for (int &num : nums){
            elements.insert(num);
        }
        for (int &num : nums){
            if (!elements.count(num+1) || elements.count(num-1)) continue;
            int cnt = 1;
            int cnum = num+1;
            while(elements.count(cnum)){
                cnum+=1;
                cnt++;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};
