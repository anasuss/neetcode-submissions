class Solution {
public:
    int palindroms[1005][1005];
    int possiblePalindroms(string &s, int i, int j){
        if (i == j) return 1;
        if (i>j) return 0;
        int &res = palindroms[i][j];
        if (res != -1) return res;
        if (s[i] == s[j] && possiblePalindroms(s,i+1,j-1) == j-i-1)
            return res = j-i+1;
        return res = max(possiblePalindroms(s,i+1,j),possiblePalindroms(s,i,j-1));
    }
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
