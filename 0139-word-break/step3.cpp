class Solution {
public:
    bool FindWordRecursively(string s, const vector<string>& wordDict, unordered_map<string, bool>& memo) {
        if (s.size() == 0) {
            return true;
        }

        if (memo.count(s)) {
            return memo[s];
        }

        for (int i = 0; i < wordDict.size(); i++) {
            if (s.starts_with(wordDict[i])) {
                if (FindWordRecursively(s.substr(wordDict[i].size()), wordDict, memo)) {
                    return memo[s] = true;
                }
            }
        }
        return memo[s] = false;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> memo;
        return FindWordRecursively(s, wordDict, memo);
    }
};
