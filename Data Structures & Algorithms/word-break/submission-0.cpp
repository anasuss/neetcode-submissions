class Solution {
public:
    unordered_set<string> st;
    int dp[210];
    bool solve(const string& s, int mxLength, int p){
        if (p == s.size()) return dp[p] = 1;
        if (dp[p] != -1) return dp[p];

        for (int i = 1 ; i <= mxLength ; i++){
            if (p + i > s.size()) return dp[p] = 0;
            string cpy = s.substr(p,i);
            if (st.count(cpy) && solve(s,mxLength, p+i))
                return dp[p] = 1;
        }

        return dp[p] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int mxLength = 0;
        for (const string &word : wordDict){
            mxLength = max(mxLength, (int)word.size());
            st.insert(word);
        }
        for (int i = 0 ; i<=s.size() ; i++){
            dp[i] = -1;
        }
        return solve(s,mxLength,0);
    }
};
