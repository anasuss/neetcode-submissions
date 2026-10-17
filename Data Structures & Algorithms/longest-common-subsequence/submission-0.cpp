class Solution {
public:
    int dp[1005][1005];
    int longestCommonSubsequence(string &text1, string &text2, int i, int j){
        if (i == text1.size()) return 0;
        if (j == text2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i] == text2[j]){
            return dp[i][j] = 1 + longestCommonSubsequence(text1,text2,i+1,j+1);
        }

        return dp[i][j] = max(longestCommonSubsequence(text1,text2,i+1,j),longestCommonSubsequence(text1,text2,i,j+1));
    }

    int longestCommonSubsequence(string &text1, string &text2) {
        int n = text1.size();
        int m = text2.size();
        for (int i = 0 ; i<=n ; i++){
            for (int j = 0 ; j<=m ; j++){
                dp[i][j] = -1;
            }
        }
        return longestCommonSubsequence(text1,text2,0,0);
    }
};
