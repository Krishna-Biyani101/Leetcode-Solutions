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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) 
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        int flag= 0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>level;
            while(n--)
            {
                TreeNode* x = q.front();
                q.pop();
                level.push_back(x->val);
                if(x->left) 
                    q.push(x->left);
                if(x->right) 
                    q.push(x->right);
            }
            if(flag) 
                reverse(level.begin(),level.end());
            ans.push_back(level);
            flag=1^flag;
        }
        return ans;
    }
};