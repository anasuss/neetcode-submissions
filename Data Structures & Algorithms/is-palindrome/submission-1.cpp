class Solution {
public:
    bool isAlphanumeric(char &c){
        return (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'); 
    }
    bool isPalindrome(string &s) {
        int i = 0;
        int j = s.size()-1;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        while (i <= j){
            if (!isAlphanumeric(s[i])){
               i++; continue; 
            }
            if (!isAlphanumeric(s[j])){
               j--; continue; 
            }
            if (s[i] != s[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }
};
