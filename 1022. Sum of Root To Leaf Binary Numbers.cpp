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
    hasLeft( TreeNode* n ) {
        return n->left != nullptr;
    }
    
    bool
    hasRight( TreeNode* n ) {
        return n->right != nullptr;
    }
    
    void 
    calcRootToLeaf( TreeNode* n, vector<int>& stack, int& tSum ) {

        //
        // Use in-order traversal
        // Left, node, right
        // Since we need to maintain the path, push the node into 
        // the stack first. After covering left/right, pop the node
        // to get back to parent.
        //
        
        if( n == nullptr ) {
            return;
        }
        
        stack.push_back( n->val );
        
        if( isLeaf(n) ) {
            int sum = 0;
            int i=0;
            for( auto it=stack.rbegin(); it!=stack.rend(); it++ ) {
                sum += (*it) << i;
                // cout << (*it) << " ";
                i++;
            }
            tSum += sum;
            // cout << ": " << sum << " " << tSum;
            // cout << endl;
        }
        
        if( hasLeft(n) ) {
            calcRootToLeaf( n->left, stack, tSum );
        }
        if( hasRight(n) ) {
            calcRootToLeaf( n->right, stack, tSum );
        }
        
        stack.pop_back();
        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
    
        vector<int> stack;
        int tSum = 0;
        calcRootToLeaf( root, stack, tSum );
        
        
    
        return tSum;
    }
};