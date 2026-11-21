class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mapping;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mapping[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (mapping.find(key) == mapping.end()) {
            return "";
        }

        int left = 0;
        int right = mapping[key].size()-1;
        int largestTimestamp = 0;
        int vec = 0;
        while (left <= right) {
            int mid = (right+left)/2;

            if (mapping[key][mid].second <= timestamp) {
                vec = mid;
                left = mid+1;
            } else {
                right = mid - 1;
            }
        }
        if (right < 0) return "";

        return mapping[key][vec].first;
    } 
};
