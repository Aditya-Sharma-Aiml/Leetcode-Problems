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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // hd: horizontalDistance
        // vd : verticallDistance
        // map<hd, map<vd, setOfValuesINSortedAtSame hd>>>
        //queue<node, <hd, vd>>

        map<int, map<int, multiset<int>>>nodes;
        queue<pair<TreeNode* , pair<int, int>>>myQ;

        myQ.push({root, {0,0}});

        while(!myQ.empty()){
            auto data = myQ.front();
            myQ.pop();

            TreeNode* node = data.first;
            int hd = data.second.first;
            int vd = data.second.second;

            nodes[hd][vd].insert(node->val);

            if(node->left){
                myQ.push({node->left, {hd-1, vd+1}});
            }
            if(node->right){
                myQ.push({node->right, {hd+1, vd+1}});
            }

        }

        vector<vector<int>>ans;
        for(auto p : nodes){
            vector<int>col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;


    }
};