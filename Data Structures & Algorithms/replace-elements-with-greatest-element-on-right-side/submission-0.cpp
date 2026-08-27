class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        int maximum = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (j <= arr.size()) {
                    maximum = max(arr[j], maximum);
                }
            }
            arr[i] = maximum;
            maximum=INT_MIN;
        }

        arr[arr.size()-1] = -1;

        return arr;
    }
};