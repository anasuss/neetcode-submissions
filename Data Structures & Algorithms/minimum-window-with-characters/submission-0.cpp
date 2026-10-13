class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> freq;
        for(char c : t) freq[c]++;
        int left = 0, cnt = 0;
        int minLength = 1e6;
        int start = -1;
        for (int i = 0 ; i<s.size() ; i++){
            if (freq.find(s[i]) != freq.end()){
                if (freq[s[i]] > 0){
                    cnt+=1; 
                }
                freq[s[i]]--;
            }
            while (left <= i){
                if (freq.find(s[left]) == freq.end()){
                    left++; continue;
                }
                if (freq[s[left]] >= 0){
                    break;
                }    
                freq[s[left]]++;
                left++;
            }
            if (cnt >= t.size()){
                if (i - left + 1 < minLength){
                    minLength = i - left + 1;
                    start = left;
                }
            }
        }
        return start == -1 ? "" : s.substr(start, minLength);
    }
};
