class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> used(26, false);
        vector<char> ans;

        for(char c : s){
            freq[c - 'a']++;
        }

        for(char c : s){
            freq[c - 'a']--;

            if(used[c - 'a'])
                continue;

            while(!ans.empty() && ans.back() > c && freq[ans.back() - 'a'] > 0){
                used[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            used[c - 'a'] = true;
        }

        return string(ans.begin(), ans.end());
    }
};