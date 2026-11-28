class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;

        // n = 4
        for (vector<int> flight : flights) {
            int s = flight[0]; // source
            int d = flight[1]; // destination
            int w = flight[2]; // weight or cost
            adj[s].push_back(make_pair(d,w));
        }
        int stops = 0;
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> minHeap;
        // {cost so far, node, stops used so far}
        cout << flights[0][2] << endl;
        minHeap.push({{0, src}, 0});
        vector<int> fewestFlights(n, INT_MAX);
        while (!minHeap.empty()) {
            pair<pair<int, int>, int> p = minHeap.top();
            minHeap.pop();
            
            int weight = p.first.first;
            int n1 = p.first.second;
            if (n1 == dst) {
                return weight;
            }
            if (p.second >= fewestFlights[n1]) {
                continue;
            }
            fewestFlights[n1] = p.second;
            if (p.second > k) {
                continue;
            }

            for (pair<int,int> f : adj[n1]) {
                int n2 = f.first; int weight2 = f.second;
                minHeap.push({{weight + weight2, n2}, p.second+1});
            }



        }

        return -1;
    }
};
