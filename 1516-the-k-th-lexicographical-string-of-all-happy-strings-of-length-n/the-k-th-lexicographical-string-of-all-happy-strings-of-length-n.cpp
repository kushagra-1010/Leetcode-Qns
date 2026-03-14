class Solution {
public:
    string ans = "";
    int count = 0;

    void dfs(int n, int k, string &cur) {
        if (cur.size() == n) {
            count++;
            if (count == k) {
                ans = cur;
            }
            return;
        }

        for (char c : {'a', 'b', 'c'}) {
            if (!cur.empty() && cur.back() == c) continue;

            cur.push_back(c);
            dfs(n, k, cur);
            cur.pop_back();

            if (!ans.empty()) return; // stop early when found
        }
    }

    string getHappyString(int n, int k) {
        string cur = "";
        dfs(n, k, cur);
        return ans;
    }
};