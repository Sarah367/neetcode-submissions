class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right=s.size()-1;


        while (left < right) {
            if (alphaNum(s[left]) && alphaNum(s[right])) {
                //cout << "s[left]: " << s[left] << endl;
                //cout << "s[right]: " << s[right] << endl;
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            } else if (alphaNum(s[left]) == false) {
                left++;
            } else if (alphaNum(s[right]) == false) {
                right--;
            }

            
        }
        return true;

    }

    bool alphaNum(char c) {
        
        if (c >= '0' && c <= '9') {
            return true;
        } else if (c >= 'a' && c <= 'z') {
            return true;
        } else if (c >= 'A' && c <= 'Z') {
            return true;
        }
        return false;
    }
};
