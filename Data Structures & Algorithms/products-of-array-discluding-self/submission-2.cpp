class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> vec(61);
        vector<int> res;
        int iszero = 0;
        int p = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                p *= nums[i];
            else
                iszero++;
        }
        for (int num : nums) {
            if (iszero == 1) {
                if (num == 0)
                    res.push_back(p);
                else
                    res.push_back(0);
            } else if (iszero > 1) {
                res.push_back(0);
            } else {
                res.push_back(p / num);
            }
        }
        return res;
    }
};
