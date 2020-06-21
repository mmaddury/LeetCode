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
public:
    bool 
    isUnivalTree(TreeNode* root) {
        
        // BFS and check each value with uniVal
        // uniVal initialized from root
        
        if( root == nullptr ) {
            return true;
        }
        
        int uniVal = root->val;
        list<TreeNode*> q;
        q.push_back(root);
        
        while( q.size() ) {
            TreeNode* curr = q.front();
            q.pop_front();
            
            if( curr->val != uniVal ) {
                return false;
            }
            
            if( curr->left != nullptr )
                q.push_back(curr->left);
            if( curr->right != nullptr) 
                q.push_back(curr->right);
        }
        
        return true;
        
    }
};