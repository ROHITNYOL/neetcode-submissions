class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int st = 1;
        int end = *max_element(piles.begin(), piles.end());

        int mini;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            int count = 0;

            for (int i = 0; i < n; i++) {
                count += (piles[i] + mid - 1) / mid;

            }

            if (count <= h) {
                mini = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return mini;
    }
};
