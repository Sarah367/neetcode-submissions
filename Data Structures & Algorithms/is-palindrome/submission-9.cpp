class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;

        while (left <= right) {
            if (isAlphaNum(s[left]) && isAlphaNum(s[right])) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                right--;
                left++;
            } 
            if (!isAlphaNum(s[right])) {
                right--;
            }
            if (!isAlphaNum(s[left])) {
                left++;
            }

        }

        return true;
    }

    bool isAlphaNum(char c) {
        if (c >= 'A' && c <= 'Z') {
            return true;
        } else if (c >= 'a' && c <= 'z') {
            return true;
        } else if ((c-'0') >= 0 && (c-'0') <= 9) {
            return true;
        }
        return false;
    }
};
