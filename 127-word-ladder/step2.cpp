class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.count(endWord)) {
            return 0;
        }

        queue<pair<string, int>> wordToCount;
        wordToCount.push({ beginWord, 1 });

        while (!wordToCount.empty()) {
            auto [word, steps] = wordToCount.front();
            wordToCount.pop();
            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (temp == endWord) {
                        return steps + 1;
                    }
                    if (wordSet.count(temp)) {
                        wordToCount.push({ temp, steps + 1 });
                        wordSet.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};
