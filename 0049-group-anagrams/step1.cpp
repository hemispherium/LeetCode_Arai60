class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sorted_string_to_string;
        for (string str : strs) {
            string _string = str;
            sort(str.begin(), str.end());
            sorted_string_to_string[str].push_back(_string);
        }

        vector<vector<string>> answer;
        for (auto [sorted_string, string_vector] : sorted_string_to_string) {
            answer.push_back(string_vector);
        }
        return answer;
    }
};
