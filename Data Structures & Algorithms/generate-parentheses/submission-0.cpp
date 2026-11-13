class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> comb;
        string currComb = "";
        int open = 0;
        int closed = 0;


        helper(comb, currComb, n, open, closed);

        return comb;
    }


    void helper(vector<string>& comb, string currComb, int& n, int open, int closed) {
        if (currComb.size() == (n*2)) {
            comb.push_back(currComb);
            return;
        }

        if (open < n) {
            currComb.push_back('(');
            open++;
            helper(comb, currComb, n, open, closed);
            currComb.pop_back();
            open--;
        }

        
        
        if (closed < open) {
            currComb.push_back(')');
            closed++;
            helper(comb, currComb, n, open, closed);
            currComb.pop_back();
            closed--;
        }




    }
};
