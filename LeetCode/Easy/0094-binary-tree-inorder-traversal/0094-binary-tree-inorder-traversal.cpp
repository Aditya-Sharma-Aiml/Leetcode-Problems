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
    //optional sc - O(1) not O(N)
    private:
    void morrisTraversal(TreeNode* root, vector<int>&inorder){
        TreeNode* curr = root;
        while(curr != NULL){

            //case 1
            if(curr->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            //case 2
            else{
                // i). if thread does not exist make and move left
                //ii). if exist then remove add root to ans and move right
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{ //prev->right != curr
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr= curr->right;
                }
            }
        }
    }
public:
    void solve(TreeNode* root, vector<int>&ans){
        
        if(!root) return;

        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        // solve(root, ans);
        morrisTraversal(root, ans);
        return ans;
    }
};