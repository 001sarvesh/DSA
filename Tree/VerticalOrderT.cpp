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
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->val);

            if(node->left != NULL){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right != NULL){
                q.push({node->right,{x+1,y}});
            }
        }
        vector<vector<int>>ans;
        for(auto &p : nodes){
            vector<int>VerticalCol;
            for(auto &col: p.second){
                VerticalCol.insert(VerticalCol.end(), col.second.begin(), col.second.end());
            }
            ans.push_back(VerticalCol);
        }
        return ans;
    }
};