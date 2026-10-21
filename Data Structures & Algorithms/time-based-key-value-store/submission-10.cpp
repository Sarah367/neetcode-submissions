class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mapping;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mapping[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mapping.find(key) == mapping.end()) {
            return "";
        }

        int left = 0;
        int right = mapping[key].size()-1;
        string ans = "";
        while (left <= right) {
            int mid = (left+right)/2;

            if (mapping[key][mid].first <= timestamp) {
                ans = mapping[key][mid].second;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        if (ans == "") {
            return "";
        }

        return ans;
        
    }
};
