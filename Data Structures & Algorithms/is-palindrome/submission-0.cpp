class Solution {
   public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left <= right) {
            if (isAlphaNum(s[left])== false) {
                left++;
            }
            if (isAlphaNum(s[right]) == false) {
                right--;
            }
            if (isAlphaNum(s[left]) && isAlphaNum(s[right])) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }


            
        }
        return true;
    }

    bool isAlphaNum(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
};
