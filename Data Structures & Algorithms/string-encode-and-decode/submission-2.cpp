class Solution {
   public:
    string encode(vector<string>& strs) {
        string s = "";
        for (const auto& str : strs) {
        s += to_string(str.length()) + "#" + str;
    }
        return s;
    }

    vector<string> decode(string s) {
        vector <string> words;
        size_t i = 0;
        while (i < s.length()) {
            size_t hashPos = s.find('#', i);
            if (hashPos == string::npos) break;

            int len = stoi(s.substr(i, hashPos - i));

            i = hashPos + 1;

            words.push_back(s.substr(i, len));

            i += len;
        }
        return words;
    }
};
