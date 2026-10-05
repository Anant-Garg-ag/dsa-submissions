class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int sum = 1;

        for (int i = 0, k = 1, j = nums.size() - 1; k < nums.size() - 1;) {
            sum = nums[i] + nums[j] + nums[k];
            int flag = 0;
            if (sum == 0) {
                for (int c = 0; c < result.size(); c++) {
                    if (result[c] == vector<int>{nums[i], nums[j], nums[k]}) flag = 1;
                }
                if (flag == 0) result.push_back({nums[i], nums[j], nums[k]});
                if ((i + 1) == k || (j - 1) == k) {
                    k++;
                    i = 0;
                    j = nums.size() - 1;
                } else {
                    i++;
                    j--;
                }
            } else if (sum < 0) {
                i++;
                if (i == k) {
                    i = 0;
                    k++;
                    j = nums.size() - 1;
                    continue;
                }
            } else {
                j--;
                if (j == k) {
                    i = 0;
                    j = nums.size() - 1;
                    k++;
                    continue;
                }
            }
        }
        return result;
    }
};
