/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    void parentMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent_track){

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){

            TreeNode* curr = q.front(); q.pop();

            if(curr->left){
                q.push(curr->left);
                parent_track[curr->left] = curr;
            }
            if(curr->right){
                q.push(curr->right);
                parent_track[curr->right] = curr;
            }

        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root || !target || k<0) return {};
        //1. parent track
        unordered_map<TreeNode*, TreeNode*>parent_track;
        parentMap(root, parent_track);

        //2. visited map and q 
        unordered_map<TreeNode*, bool>vis;
        queue<TreeNode*>q;

        q.push(target);
        vis[target] = true;

        int distance = 0;

        while(!q.empty()){

            //move all 3 dir: left, right, up simulteneously
            int size = q.size();
            if(distance == k) break;
            distance++;

            for(int i=0; i<size; i++){

                TreeNode* curr = q.front();
                q.pop();

                //left
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                //right
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                //up->parent
                if(parent_track[curr] && !vis[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]] = true;
                }
            }

        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};