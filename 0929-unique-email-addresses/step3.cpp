class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;

        for (const string& address : emails) {
            int atPosition = address.find('@');
            string domain = address.substr(atPosition);

            string local;
            for (int i = 0; i < atPosition; i++) {
                if (address[i] == '+') {
                    break;
                }
                if (address[i] == '.') {
                    continue;
                }
                local += address[i];
            }
            uniqueEmails.insert(local + domain);
        }
        return uniqueEmails.size();
    }
};
