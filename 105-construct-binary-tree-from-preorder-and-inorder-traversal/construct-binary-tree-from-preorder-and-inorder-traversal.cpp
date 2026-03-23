class Solution {
public:

    int findIndex(vector<int>& inorder, int left, int right, int val){
        for(int i = left; i <= right; i++){
            if(inorder[i] == val){
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int& preIdx, int left, int right){

        if(left > right) return NULL;

        int rootVal = preorder[preIdx];
        TreeNode* root = new TreeNode(rootVal);

        int idx = findIndex(inorder, left, right, rootVal);

        preIdx++;

        root->left = solve(preorder, inorder, preIdx, left, idx-1);
        root->right = solve(preorder, inorder, preIdx, idx+1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return solve(preorder, inorder, preIdx, 0, inorder.size()-1);
    }
};