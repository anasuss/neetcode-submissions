class Solution {
public:
    int dp[105];
    int work(const string &s, int i = 0){
        if (i == s.size()){
            return 1;
        }
        if (s[i] == '0'){
            return 0;
        }
        int &res = dp[i];
        if (res != -1) return res;
        res = 0;
        if (i + 1 < s.size()){
            int k = stoi(s.substr(i, 2));
            if (k >= 10 && k<=26){
                res += work(s, i + 2);
            }
        }
        int k = stoi(s.substr(i, 1));
        if (k >= 1 && k<=9){
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
