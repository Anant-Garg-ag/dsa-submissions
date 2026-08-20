class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, string>> sorted;
        for (int i = 0; i< strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            sorted.push_back({temp, strs[i]});
        }
        unordered_map <string, vector<string>> mp;
        for (int i = 0; i< strs.size(); i++) {
            mp[sorted[i].first].push_back(sorted[i].second);
        }
        vector<vector<string>> res;
        for(auto& [key, str_vector] : mp) {
            res.push_back(str_vector);
        }
        return res;
    }
};
