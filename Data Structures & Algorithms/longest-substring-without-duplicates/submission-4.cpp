class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        unordered_map<char,int> freq;
        int ans = 0, left = 0;
        int n = s.size();
        for (int right = 0 ; right < n ; right++){
            freq[s[right]]++;
            while(freq[s[right]] > 1){
                freq[s[left]]--;
                left+=1;
            }
            ans = max(ans, right - left +1);
        }
        return ans;
    }
};
