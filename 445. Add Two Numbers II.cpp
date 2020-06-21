/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* 
    addTwoNumbers(ListNode* l1, ListNode* l2) {
    
        if( l2 == nullptr ) {
            return l1;
        }
        if( l1 == nullptr ) {
            return l2;
        }
        
        vector<int> v1;
        vector<int> v2;
        ListNode* curr;
        
        curr = l1;
        while( curr != nullptr ) {
            v1.push_back(curr->val);
            curr = curr->next;
        }

        curr = l2;
        while( curr != nullptr ) {
            v2.push_back(curr->val);
            curr = curr->next;
        }
        
        // set up v2 to be smaller
        if( v2.size() > v1.size() ) {
            swap(v2, v1);
        }

        cout << v1.size() << endl;
        cout << v2.size() << endl;
        int count = v1.size() - v2.size();
        if( count ) {
            for( int i=0; i<count; i++ ) {
                v2.insert(v2.begin(),0);
            }
        }

        /*        
        for( auto const& i : v1 )
            cout << i << " ";
        cout << endl;
        for( auto const& i : v2 )
            cout << i << " ";
        cout << endl;
        */
        
        
        vector<int> s;
        int carry = 0;
        for( int i=v1.size()-1; i>=0; i-- ) {
            int sum = v1[i] + v2[i] + carry;
            s.insert(s.begin(), sum%10);
            carry = sum/10;
        }
        if( carry ) 
            s.insert(s.begin(), carry);
        
        ListNode* newHead = nullptr;;
        curr = nullptr;
        for( auto const& i : s ) {
            ListNode* tmp = new ListNode(i);
            if( newHead == nullptr ) {
                newHead = tmp;
                curr = tmp;
            } else {
                curr->next = tmp;
                curr = tmp;
            }
        }
        
        return newHead;
        
    }
};