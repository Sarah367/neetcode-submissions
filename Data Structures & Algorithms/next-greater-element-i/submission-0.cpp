class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        stack<int> st; int j = 0;
        unordered_map<int, int> freq;
        // next greater element --> monotonic stack
        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && nums2[i] > nums2[st.top()]) {
                freq[nums2[st.top()]] = nums2[i];
                int index = st.top();
                st.pop();
                int val = nums2[index];
                
            } 
            st.push(i);
            
        }
        
        for (int i = 0; i < nums1.size(); i++) {
            if (freq.count(nums1[i]) > 0 ) {
                res[i] = freq[nums1[i]];
            } else if (freq.count(nums1[i]) == 0) {
                res[i] = -1;
            }
        } 
        return res;
    }
};