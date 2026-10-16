class Solution {
public:
    int dp[1005][1005];
    int work(const string &s, int i, int j){
        if (i>j) return 0;
        if (i == j) return 1;
        int &res = dp[i][j];
        if (res != -1) return res;

        if (s[i] == s[j] && work(s,i+1,j-1) == j-i-1){
            return res = j-i+1;
        }
        return res = max(work(s,i+1,j),work(s,i,j-1));
    }

    string buildAnswer(const string &s){
        int i = 0, j = s.size()-1;
        string left = "", right = "";
        while (i<=j){
            if (i == j){
                left+=s[i]; break;
            }
            int cur = work(s,i,j);
            if (s[i] == s[j] && cur == j-i+1){
                left+=s[i];
                right+=s[j];
                i+=1; j-=1;
            }else if (cur == work(s,i+1,j)){
                i+=1;
            }else{
                j-=1;
            }
        }
        reverse(right.begin(),right.end());
        return left+right;
    }

    string longestPalindrome(const string &s) {
        int n = s.size();
        for (int i = 0; i<=n ; i++){
            for (int j = 0; j<=n ; j++){
                dp[i][j] = -1;
            }
        }
        int res = work(s,0,n-1);
        cout << res << endl;
        return buildAnswer(s);
    }
};
