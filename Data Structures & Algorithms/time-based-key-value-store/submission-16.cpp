class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>> mapping;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mapping[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (mapping.find(key) == mapping.end()) {
            return "";
        }

        vector<pair<string,int>>& pairing = mapping[key];

        int left = 0;
        int right = pairing.size()-1;
        string val = "";
        while (left <= right) {
            int mid = (left+right)/2;

            if (pairing[mid].second <= timestamp) {
                val = pairing[mid].first;
                left = mid+1;
            } else {
                right = mid-1;
            }


        }
        
        return val; 
    }
};
