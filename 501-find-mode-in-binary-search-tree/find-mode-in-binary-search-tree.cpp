class Solution {
public:
    void traverse(TreeNode* root, map<int,int>& mp){
        if(!root) return;

        mp[root->val]++;  // count frequency

        traverse(root->left, mp);
        traverse(root->right, mp);
    }

    vector<int> findMode(TreeNode* root) {
        map<int,int> mp;
        traverse(root, mp);

        int maxFreq = 0;

        // Step 1: find max frequency
        for(auto it : mp){
            maxFreq = max(maxFreq, it.second);
        }

        vector<int> ans;

        // Step 2: collect modes
        for(auto it : mp){
            if(it.second == maxFreq){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};