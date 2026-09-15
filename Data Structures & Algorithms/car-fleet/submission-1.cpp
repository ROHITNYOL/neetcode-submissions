class Solution {
   public:
// claude
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) cars[i] = {position[i], speed[i]};

        sort(cars.begin(), cars.end(), greater<>());  // closest to target first

        int fleets = 0;
        double lastTime = -1;

        for (auto& [pos, spd] : cars) {
            double time = (double)(target - pos) / spd;
            if (time > lastTime) {
                fleets++;
                lastTime = time;
            }
            // else: this car merges into the fleet ahead, don't update lastTime
        }

        return fleets;
    }
};
