class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> key_to_strings;

        for (const string& _string : strs) {
            string key(26, '\0');
            for (char character : _string) {
                key[character - 'a']++;
            }
            key_to_strings[key].push_back(_string);
        }

        vector<vector<string>> answer;
        for (auto& _map : key_to_strings) {
            answer.push_back(_map.second);
        }
        return answer;
    }
};
