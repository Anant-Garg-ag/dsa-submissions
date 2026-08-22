class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int zeroCount = 0;
        int p = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                p *= nums[i];
            else
                zeroCount++;
        }

        if (zeroCount > 1) return vector<int>(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount == 1) {
                res[i] = (nums[i] == 0) ? p : 0;
            } else {
                res[i] = p / nums[i];
            }
        }
        return res;
    }
};
