class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<double, vector<double>, greater<double>> minHeap;
        double distance = 0.0;
        unordered_map<double, vector<vector<int>>> distanceToCoords; 
        for (const auto& innervec : points) {
            cout << innervec[0] << innervec[1] << std::endl;
            distance = sqrt((innervec[0]*innervec[0]) + (innervec[1]*innervec[1]));
            minHeap.push(distance);
            distanceToCoords[distance].push_back({innervec});
        }

        vector<vector<int>> res;
        int cnt = 0; double mappingDistance = 0;
        while (cnt < k) {
            mappingDistance = minHeap.top();
            minHeap.pop();
            cout << "size: " <<  distanceToCoords[mappingDistance].size() << endl;
            vector<vector<int>> mapping = distanceToCoords[mappingDistance];
            for (int i = 0; i < mapping.size(); i++) {
                if (cnt == k) return res;
                res.push_back(mapping[i]);
                cnt++;
            }
            distanceToCoords.erase(mappingDistance);

            //res.push_back(distanceToCoords[distance]);
        }


        return res;
    }
};
