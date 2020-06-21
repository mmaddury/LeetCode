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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2;
        vector<int> va1, va2;
        ListNode* tmp;
        
        
        
        tmp = l1;
        while( tmp != nullptr ) {
            v1.insert(v1.begin(), tmp->val);
            tmp = tmp->next;
        }
        
        tmp = l2;
        while( tmp != nullptr ) {
            v2.insert(v2.begin(), tmp->val);
            tmp = tmp->next;
        }
        
        
        int n1 = v1.size();
        int n2 = v2.size();
        
        if( n1 > n2 ) {
            for( int i=0; i<(n1-n2); i++ ) {
                v2.insert(v2.begin(), 0);
            }
        } else if( n2 > n1 ) {
            for( int i=0; i<(n2-n1); i++ ) {
                v1.insert(v1.begin(), 0);
            }
        }
    
        
        vector<int> vr(v1.size(),0);
        int carry = 0;
        for( int i=(vr.size()-1); i>=0; i-- ) {
            int sum = v1[i] + v2[i] + carry;
            carry = (sum > 9) ? 1 : 0;
            vr[i] = sum % 10;
        }
        if( carry ) {
            vr.insert(vr.begin(),1);
        }
        
        
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        ListNode* next = nullptr;
        
        for( int i=vr.size()-1; i>=0; i-- ) {
            next = new ListNode(vr[i]);
            if( head == nullptr ) {
                head = next;
                curr = next;
            } else {
                curr->next = next;
                curr = next;
            }
        }
        
        
        return head;
    }
};