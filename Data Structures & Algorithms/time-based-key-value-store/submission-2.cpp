class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> timeBased;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        timeBased[key].push_back({value, timestamp});      
    }
    
    string get(string key, int timestamp) {
        auto it = timeBased.find(key);
        if (it == timeBased.end()) {
            return "";
        }

        vector<pair<string,int>>& vec = it->second;
        int left = 0;
        int right = vec.size()-1;

        string value = "";
        while (left <= right) {
            int mid = (left+right)/2;

            if (vec[mid].second <= timestamp) {
                value = vec[mid].first;
                left = mid + 1;
            } else {
                right = mid-1;
            }
        }

        return value;
    }
};
