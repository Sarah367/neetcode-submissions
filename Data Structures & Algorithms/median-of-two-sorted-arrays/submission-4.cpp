class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = (nums1.size() + nums2.size())/2;

        int cnt = 0;
        int i = 0;
        int j = 0;
        vector<int> push; 

        while (cnt <= totalSize) {
            if (i < nums1.size() && j < nums2.size()) {
                if (nums1[i] <= nums2[j]) {
                    push.push_back(nums1[i]);
                    i++;
                } else if (nums2[j] < nums1[i] ) {
                    push.push_back(nums2[j]);
                    j++;
                }

            } else {
                if (i < nums1.size()) {
                    push.push_back(nums1[i]);
                    i++;
                } else if (j < nums2.size()) {
                    push.push_back(nums2[j]);
                    j++;
                }
            }
            cnt++;
        }
        //double middle = 0.0;
        int total = nums1.size() + nums2.size();
        if (total % 2 == 0) {
            double middle = (push[push.size()-1] + push[push.size()-2]) / 2.0;
            return middle;
        }

        return push[push.size()-1];
    }
};
