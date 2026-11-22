class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        
        vector<pair<int,int>> cars;
        //sort(cars.begin(), cars.end());
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        int cnt = 0;
        for (int i = cars.size()-1 ; i>=0; i--) {
            double rate = double((target - cars[i].first))/double(cars[i].second);
            //cout << "rate: " << rate << endl;
            if (!st.empty() && rate <= st.top()) {
                continue;
            } else {
                st.push(rate);
            }

        }

        return st.size();


    }
};
