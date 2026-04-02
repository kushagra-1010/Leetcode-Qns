class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans){
        if(!root){
            return;
        }

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    TreeNode* bst(int l, int r, vector<int>& ans){
        if(l > r){
            return nullptr;
        }

        int mid = l + (r - l) / 2;

        TreeNode* root = new TreeNode(ans[mid]);

        root->left = bst(l, mid - 1, ans);
        root->right = bst(mid + 1, r, ans);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);

        return bst(0, ans.size() - 1, ans);
    }
};