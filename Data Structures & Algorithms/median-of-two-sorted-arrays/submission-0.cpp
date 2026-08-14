class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = (nums1.size() + nums2.size()) / 2;
        cout << "total size: " << totalSize << endl;
        int cnt = 0;
        int i = 0;
        int j = 0;
        vector<double> push;
        while (cnt <= totalSize) {
            if (i < nums1.size() && j < nums2.size()) {
                if (nums1[i] < nums2[j]) {
                    push.push_back(nums1[i]);
                    i++;
                } else {
                    push.push_back(nums2[j]);
                    j++;
                }
                
            } else if (i < nums1.size()) {
                push.push_back(nums1[i]);
                i++;
            } else if (j < nums2.size()) {
                push.push_back(nums2[j]);
                j++;
            }

            cnt++; // 1, 2, 3
        }
        int evenOrOddSize = nums1.size() + nums2.size();

        if (evenOrOddSize % 2 == 0) {
            double med = double((push[push.size()-2] + push[push.size()-1]) / 2);
            cout << "MED: " << med << endl;
            return med;
        }


        return push[push.size()-1];
    }
};
