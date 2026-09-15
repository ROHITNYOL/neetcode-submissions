class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n1 = matrix.size();
        int n2 = matrix[0].size();

        int s = 0;
        int e = n1 - 1;

        while (s <= e) {
            int m = s + (e - s) / 2;

            if (target >= matrix[m][0] && target <= matrix[m][n2 - 1]) {
                int st = 0;
                int end = n2 - 1;

                while (st <= end) {
                    int mid = st + (end - st) / 2;

                    if (matrix[m][mid] == target)
                        return true;
                    else if (matrix[m][mid] > target)
                        end = mid - 1;
                    else
                        st = mid + 1;
                }
                return false;
            } else if (target < matrix[m][0])
                e = m - 1;
            else
                s = m + 1;
        }

        return false;
    }
};
