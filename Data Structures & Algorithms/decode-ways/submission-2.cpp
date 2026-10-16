class Solution {
public:
    int dp[105];
    int work(const string &s, int i = 0){
        int &res = dp[i];
        if (res != -1) return res;
        if (i == s.size()){
            return res = 1;
        }
        if (s[i] == '0'){
            return res = 0;
        }
        res = 0;
        if (i + 1 < s.size()){
            string cpy = s.substr(i, 2);
            if (cpy >= "10" && cpy <= "26"){
                res += work(s, i + 2);
            }
        }
        string cpy = s.substr(i, 1);
        if (cpy >= "1" && cpy <= "9"){
            res += work(s, i + 1);
        }
        return res;
    }
    int numDecodings(string s) {
        int n = s.size();
        for (int i = 0 ; i<=n ; i++){
            dp[i] = -1;
        }
        return work(s);
    }
};
