class Solution {
public:
    static constexpr int UNKNOWN = -1;
    static constexpr int UNBREAKABLE = 0;
    static constexpr int BREAKABLE = 1;

    bool FindWordRecursively(
        int start,
        string_view s,
        const vector<string>& wordDict,
        vector<int>& word_idx_is_breakable) {

        if (start == s.size()) {
            return true;
        }

        if (word_idx_is_breakable[start] != UNKNOWN) {
            return word_idx_is_breakable[start] == BREAKABLE;
        }

        for (string_view word : wordDict) {
            int size = word.size();

            if (start + size <= s.size() && s.compare(start, size, word) == 0) {
                if (FindWordRecursively(start + size, s, wordDict, word_idx_is_breakable)) {
                    word_idx_is_breakable[start] = BREAKABLE;
                    return true;
                }
            }
        }
        word_idx_is_breakable[start] = UNBREAKABLE;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> word_idx_is_breakable(s.size(), UNKNOWN);
        return FindWordRecursively(0, s, wordDict, word_idx_is_breakable);
    }
};
