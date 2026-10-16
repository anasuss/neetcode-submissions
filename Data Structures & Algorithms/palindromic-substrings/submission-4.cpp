class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = n;
        for (int center = 0 ; center<n ; center++){
            int i = center-1, j = center+1;
            while (i>=0 && j<n && s[i] == s[j]){
                ans+=1; i-=1; j+=1;
            }
            i = center, j = center+1;
            while(i>=0 && j<n && s[i] == s[j]){
                ans += 1; i-=1; j+=1;
            }
        }   
        return ans;
    }
};
