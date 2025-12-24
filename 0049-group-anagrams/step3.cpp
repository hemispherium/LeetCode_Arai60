class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sorted_string_to_strings;
        for (string str : strs) {
            string _string = str;
            sort(str.begin(), str.end());
            sorted_string_to_strings[str].push_back(_string);
        }
        vector<vector<string>> answer;
        for (auto [sorted_strings, string_vector] : sorted_string_to_strings) {
            answer.push_back(string_vector);
        }
        return answer;
    }
};
