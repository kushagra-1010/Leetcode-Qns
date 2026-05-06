class Solution {
public:

    bool valid(string s) {
        int cnt = 0;

        for (char ch : s) {

            if (ch == '(')
                cnt++;
            else
                cnt--;

            if (cnt < 0)
                return false;
        }

        return cnt == 0;
    }

    void solve(int n,
               string& curr,
               vector<string>& ans) {

        if (curr.size() == 2 * n) {

            if (valid(curr))
                ans.push_back(curr);

            return;
        }

        curr.push_back('(');
        solve(n, curr, ans);
        curr.pop_back();

        curr.push_back(')');
        solve(n, curr, ans);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string curr = "";

        solve(n, curr, ans);

        return ans;
    }
};