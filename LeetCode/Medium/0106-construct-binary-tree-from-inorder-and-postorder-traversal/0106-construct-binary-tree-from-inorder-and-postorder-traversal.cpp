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

    TreeNode* buildTreeHelper(vector<int>&postorder, int postStart, int postEnd,
                        vector<int>&inorder, int inStart, int inEnd, 
                        unordered_map<int, int>&inorderIndexMap )

    {
        if(inStart > inEnd || postStart > postEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inorderIndexMap[root->val];
        int leftSize = inRoot- inStart;

        root->left = buildTreeHelper(postorder, postStart, postStart+leftSize-1,
                                    inorder, inStart, inRoot - 1, inorderIndexMap);
        root->right = buildTreeHelper(postorder, postStart+leftSize, postEnd-1, 
                                    inorder, inRoot+1, inEnd, inorderIndexMap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int> inorder, vector<int>postorder) {
        
        unordered_map<int, int>inorderIndexMap;
        for(int i=0; i<inorder.size(); i++){
            inorderIndexMap[inorder[i]] = i;
        }
        int inStart = 0, inEnd = inorder.size()-1;
        int postStart = 0, postEnd = postorder.size()-1;

        TreeNode* root = buildTreeHelper(postorder, postStart, postEnd, 
                                        inorder, inStart, inEnd, inorderIndexMap);
        return root;
    }
};