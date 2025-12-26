class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> local_name_and_domain;
        for (string address : emails) {
            string local_name = address.substr(0, address.find('@'));
            string domain_name = address.substr(address.find('@') + 1);
            local_name.erase(std::remove(local_name.begin(), local_name.end(), '.'), local_name.end());
            local_name = local_name.substr(0, local_name.find('+'));
            local_name_and_domain.insert(local_name + '@' + domain_name);
        }
        return local_name_and_domain.size();
    }
};
