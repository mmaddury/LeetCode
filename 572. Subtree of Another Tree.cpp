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
    isLeaf( TreeNode* n ) {
        return (n->left == nullptr) && (n->right == nullptr);
    }
    
    bool
    isIdentical( TreeNode* m, TreeNode* n ) {
        
        if( m == nullptr && n == nullptr ) {
            return true;
        }
        
        if( m != nullptr && n != nullptr ) {
            if( ( m->val == n->val ) &&
                 isIdentical( m->left, n->left ) &&
                 isIdentical( m->right, n->right ) ) {
                return true;
            }
        }
        
        return false;

    }
    
   
    bool 
    isSubtree(TreeNode* s, TreeNode* t) {
        
        if( t == nullptr ) {
            return true;
        }
        
        if( s == nullptr ) {
            return false;
        }
        
        if( isIdentical(s, t) ) {
            return true;
        }
        
        if( isSubtree(s->left, t) ) {
                return true;
        }
        
        if( isSubtree(s->right, t) ) {
                return true;
        }
        
        return false;
        
    }
    
    
    
};