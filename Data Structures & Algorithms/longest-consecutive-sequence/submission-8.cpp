class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0) {
            return 0;
        }
        unordered_map<int,int> lookup;

        for (int num : nums) {
            lookup[num]++;
        } int maxi = 1; int longest = 1;
        int cons = 0; bool flag = true;
        for (const auto& pair : lookup) {
            cons = pair.first;
            if (lookup.find(cons-1) != lookup.end()) {
                continue;
            }

            while (flag) {
                cons += 1;
                
                if (lookup.find(cons) != lookup.end()) {
                    maxi++;
                } else {
                    flag = false;
                }
            }
            longest = max(maxi, longest);
            maxi=1;
            flag=true;
            
            
        }

        return longest;
    }
};
