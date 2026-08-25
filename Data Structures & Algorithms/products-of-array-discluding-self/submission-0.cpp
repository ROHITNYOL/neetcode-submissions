class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int product = 1;
        int zeros = 0;
        int zeroIdx = -1;

        for (int i=0;i<n;i++) {
            if (nums[i] == 0) {
                zeros++;
                zeroIdx = i;
            } else
                product *= nums[i];
        }

        vector<int> ans(n, 0);
        if (zeros > 1) return ans;

        if (zeros == 1) {
            ans[zeroIdx] = product;
            return ans;
        }

        for(int i=0;i<n;i++){

            ans[i] = product/nums[i];
        }

        return ans;
    }
};
