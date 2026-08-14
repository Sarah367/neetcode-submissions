class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int carFleets = 0;
        stack<double> st;
        int j = 0;
        int cnt = 0;
        int num = 0;
        
        vector<pair<int,int>> car;
        for (int i = 0; i < position.size(); i++) {
            car.push_back({position[i], speed[i]});
        }
        sort(car.begin(), car.end());
        for (int i = car.size()-1; i >= 0; i--) {
            double timeToTarget = double(target-car[i].first) / double(car[i].second);
            
            if (!st.empty() && timeToTarget <= st.top()) {

                continue;
            } else {
                carFleets++;

            }
            st.push(timeToTarget);
            
        }


        return carFleets;
    }
};
