class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>> timeStore;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeStore[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (timeStore.find(key) == timeStore.end()) {
            return "";
        }
        vector<pair<string,int>>& mapping = timeStore[key];

        int left = 0;
        int right = mapping.size()-1;
        string val = "";
        while (left <= right) {
            int mid = (right+left)/2;

            if (mapping[mid].second <= timestamp) {
                val = mapping[mid].first;
                left = mid+1;
            } else {
                right = mid-1;
            }


        }

        return val;

    }
};
