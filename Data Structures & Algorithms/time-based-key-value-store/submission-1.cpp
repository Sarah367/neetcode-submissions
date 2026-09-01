class TimeMap {
   public:
    unordered_map<string, vector<pair<string, int>>> time_map;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        time_map[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        vector<pair<string, int>>& pairs = time_map[key];

        int left = 0;
        int right = pairs.size() - 1;
        int mid = 0;
        int index = -1;
        if (time_map.find(key) != time_map.end()) {
            // binary search

            while (left <= right) {
                int mid = (left + right) / 2;

                if (pairs[mid].second <= timestamp) {
                    index = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        if (index == -1) {
            return "";
        }

        return pairs[index].first;
    }
};
