class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.size();
        for (char c = 'A' ; c <= 'Z' ; c++){
            int nbReplacement = 0;
            int left = 0;
            for (int i = 0 ; i < n ; i++){
                int ci = s[i] - 'A';
                if (s[i] != c)
                    nbReplacement += 1;
                while (nbReplacement > k){
                    if (s[left] != c){
                        nbReplacement -= 1;
                    }
                    left += 1;
                }
                ans = max(ans, i - left + 1);
            }
        }
        return ans;
    }
};
