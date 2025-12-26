class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> character_to_num;
        for (char character : s) {
            character_to_num[character - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (character_to_num[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
