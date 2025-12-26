// Naoto Iwaseさんの実装を参考にしたもの

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> counter;
        deque<pair<char, int>> characters;

        for (int index = 0; index < (int)s.size(); ++index) {
            char character = s[index];
            counter[character]++;

            if (counter[character] == 1) {
                characters.emplace_back(character, index);
            }

            while (!characters.empty() && counter[characters.front().first] >= 2) {
                characters.pop_front();
            }
        }

        return characters.empty() ? -1 : characters.front().second;
    }
};

// GPTにstep1を修正してもらったもの

class Solution {
public:
    int firstUniqChar(string s) {

        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
