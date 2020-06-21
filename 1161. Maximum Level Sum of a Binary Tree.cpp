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
    int maxLevelSum(TreeNode* root) {
        
        struct MyT {
            TreeNode* n;
            int l;
            MyT( TreeNode* _n, int _l ) { n=_n; l=_l; };
        };
        
        // Use level order search to compute the 
        // sum per level
        map<int,int> levelSum;
        
        queue<MyT> q;
        MyT tmp(root, 1);
        q.push(tmp);
        
        while( q.size() ) {
            MyT curr = q.front();
            q.pop();
            int l = curr.l;
            TreeNode* n = curr.n;
            if( levelSum.find(l) == levelSum.end() )
                levelSum[l] = n->val;
            else 
                levelSum[l] += n->val;
            if( n->left != nullptr ) {
                MyT tmp1(n->left,l+1);
                q.push(tmp1);
            }
            if( n->right != nullptr ) {
                MyT tmp1(n->right,l+1);
                q.push(tmp1);
            }
        }
        
        int maxLevel = 0;
        int maxSum = numeric_limits<int>::min();
        for( auto const& [k,v] : levelSum ) {
            if( v > maxSum ) {
                maxSum = v;
                maxLevel = k;
            }
        }
        
        return maxLevel;
                
    }
        
};