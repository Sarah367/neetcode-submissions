class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>> timemap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        timemap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int left = 0;
        int right = timemap[key].size()-1;
        int mid = 0; int resIndex = -1;
        while (left <= right) {

            mid = (left+right)/2;

            if (timemap[key][mid].second <= timestamp) {
                resIndex = mid;
                left = mid +1;
            } else {
                right=mid-1;
            }
        }
        if (resIndex == -1) {
            return "";
        } 


        return timemap[key][resIndex].first;

        
    }
};
