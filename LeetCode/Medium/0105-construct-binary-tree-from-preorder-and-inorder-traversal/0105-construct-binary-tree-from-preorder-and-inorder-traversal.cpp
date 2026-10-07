/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    TreeNode* buildTreeHelper(vector<int>&preorder, int preStart, int preEnd,
                        vector<int>&inorder, int inStart, int inEnd, 
                        unordered_map<int, int>&inorderIndexMap )

    {
        if(inStart > inEnd || preStart > preEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inorderIndexMap[root->val];
        int leftSize = inRoot- inStart;

        root->left = buildTreeHelper(preorder, preStart+1, preStart+leftSize,
                                    inorder, inStart, inRoot - 1, inorderIndexMap);
        root->right = buildTreeHelper(preorder, preStart+leftSize+1, preEnd, 
                                    inorder, inRoot+1, inEnd, inorderIndexMap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int>inorderIndexMap;
        for(int i=0; i<inorder.size(); i++){
            inorderIndexMap[inorder[i]] = i;
        }
        int inStart = 0, inEnd = inorder.size()-1;
        int preStart = 0, preEnd = preorder.size()-1;

        TreeNode* root = buildTreeHelper(preorder, preStart, preEnd, 
                                        inorder, inStart, inEnd, inorderIndexMap);
        return root;
    }
};