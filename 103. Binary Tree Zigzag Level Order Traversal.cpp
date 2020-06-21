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
    vector<vector<int>> 
    zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> r;

        if( root == nullptr ) {
            return r;
        }
        
        // Use breadth first search
        // Store level and node in queue
        struct qT {
            int         l;
            TreeNode*   n;
            void show() { cout << n->val << " @ " << l << endl;};
        };
        list<qT> q;
        
        qT tmp{1, root};
        q.push_back( tmp );

        int l=1;
        vector<int> t;
        while( q.size() ) {
            qT cur = q.front();
            q.pop_front();
            
            if( l+1 == cur.l ) {
                r.push_back(t);
                t.clear();
                l++;
            }
            t.push_back(cur.n->val);
            
            if( cur.n->left != nullptr ) {
                qT tmp1{cur.l+1, cur.n->left};
                q.push_back(tmp1);
            }
            if( cur.n->right != nullptr ) {
                qT tmp1{cur.l+1, cur.n->right};
                q.push_back(tmp1);
            }
        }
        r.push_back(t);
        t.clear();
        
        for( int i=0; i<r.size(); i++ ) {
            if( i%2 ) {
                reverse(r[i].begin(), r[i].end());
            }
        }
        
        return r;
        
    }
};