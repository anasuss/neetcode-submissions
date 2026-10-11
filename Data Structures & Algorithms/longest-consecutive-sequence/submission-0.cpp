class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> elements;
        int ans = 0;
        for (int &num : nums){
            elements[num] = 1;
        }
        for (int &num : nums){
            int cnt = 1;
            if (elements.count(num+1) && !elements.count(num-1)){
                for (int i = num+1 ; elements.count(i) ; i++)
                    cnt++;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};
