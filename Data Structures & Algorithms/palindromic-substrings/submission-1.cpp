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
        for (int i = 0 ; i<=n ; i++){
            for (int j = 0 ; j<=n ; j++){
                palindroms[i][j] = -1;
            }
        }
        possiblePalindroms(s,0,n-1);
        int ans = 0;
        for (int i = 0 ; i<n ; i++){
            for (int j = i ; j<n ; j++){
                if (i == j){
                    ans+=1;
                }
                else if (possiblePalindroms(s,i,j) == j-i+1){
                    ans+=1;
                }
            }
        }
        return ans;
    }
};
