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
    vector<TreeNode*> f(int l, int r) 
    {
        if(l>r) 
            return {NULL};
        vector<TreeNode*> ans;
        for(int i = l;i<=r;i++) 
        {
            vector<TreeNode*> lf = f(l,i - 1);
            vector<TreeNode*> rt = f(i + 1,r);
            for(TreeNode* l : lf) 
            {
                for(TreeNode* r : rt) 
                {
                    TreeNode* tree = new TreeNode(i);
                    tree->left = l;
                    tree->right = r;
                    ans.push_back(tree);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return f(1,n);
    }
};