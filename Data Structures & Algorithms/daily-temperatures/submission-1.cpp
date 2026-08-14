class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> track;
        vector<int> res;
        int left = 0;
        int cnt = 0;
        for (int right = 0; right < temperatures.size(); right++) {
            track.push_back(temperatures[right]);

            if (track.size() > 1) {
                int comp = track.back();
                cout << "LEFT: " << temperatures[left] << endl;
                cout << "COMP: " << comp << endl;
                
                while (comp <= temperatures[left] && right < temperatures.size()) {
                    right++;
                    cout << "right now: " << right << endl;
                    if (right < temperatures.size()) {
                        comp = temperatures[right];
                    }
                    cout << "NEW COMP: " << comp << endl;
                }
                if (right >= temperatures.size() ) {
                    cout << "THE RIGHT: " << right << endl;
                    res.push_back(0);
                    track.clear();
                    left++;
                    right=left-1;
                } else {
                    res.push_back(right-left);
                    track.clear();
                    left++;
                    right=left-1;
                }
                
            }


        }
        res.push_back(0);
        return res;
    }
};
