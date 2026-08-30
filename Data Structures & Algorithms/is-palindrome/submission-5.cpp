class Solution {
public:
    bool isPalindrome(string s) {
        
        int left = 0;
        int right = s.size()-1;

        while (left < right) {
            if (isAlphaNum(s[left]) && isAlphaNum(s[right])) {
                cout << s[left] << endl;
                cout << s[right] << endl;
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                right--;
                left++;
            }
            cout << s[left] << endl;
                cout << s[right] << endl;

            if (!isAlphaNum(s[left])) {
                left++;
            }
            if (!isAlphaNum(s[right])) {
                right--;
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
