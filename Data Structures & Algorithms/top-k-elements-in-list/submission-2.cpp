class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        for(int i =0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector <pair<int, int>> res(mp.begin(), mp.end());
        sort (res.begin(), res.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });
        vector <int> arr;
        int i = 0;
        while (k > 0) {
            arr.push_back(res[i].first);
            i++;
            k--;
        }
        return arr;
    }
};
