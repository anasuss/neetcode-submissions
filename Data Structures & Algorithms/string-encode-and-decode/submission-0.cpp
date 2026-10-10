class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for (string &s : strs){
            string size = to_string(s.size());
            reverse(size.begin(),size.end());
            string sub = size + '#' + s;
            ans += sub;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        int n = s.size();
        while (i < n){
            int length = 0;
            int p = 1;
            while(i<s.size() && s[i] != '#'){
                int x = s[i] - '0';
                length += x * p;
                p *= 10; 
                i++;
            }
            string k = s.substr(i+1, length);
            ans.push_back(k);
            i+= length + 1;
        }
        return ans;
    }
};
