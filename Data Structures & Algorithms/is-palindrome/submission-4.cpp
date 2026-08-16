class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;

        while (left < right) {
            if (isAlphaNum(s[left]) && isAlphaNum(s[right])) {
                cout << s[left] << endl;
                cout << tolower(s[right]) << endl;
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            } else if (!isAlphaNum(s[right])) {
                right--;
            } else if (!isAlphaNum(s[left])) {
                left++;
            }
            
        }


        return true;
    }

    bool isAlphaNum(char c) {
        if (c >= '0' && c <= '9') {
            return true;
        } else if (c >= 'A' && c <= 'Z') {
            return true;
        } else if (c >= 'a' && c <= 'z') {
            return true;
        }
        return false;
    }
};
