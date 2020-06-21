/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if( head == nullptr ) 
            return head;
        
        if( head->next == nullptr )
            return head;
       
        /*
        // Works for sorted/unsorted list
        
        set<int> listSet;
        
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* next=nullptr;
        
        while( curr != nullptr ) {
            next = curr->next;
            if( listSet.count(curr->val) == 0 ) {
                listSet.insert(curr->val);
                prev = curr;
                curr = next;
            } else {
                prev->next = next;
                curr->next = nullptr;
                delete curr;
                curr = next;
            }
        }
        */
        
        // Optimize for sorted list 
        ListNode* curr = head;
        while( curr != nullptr ) {
            if( curr->next == nullptr )
                break;
            // One check since it is sorted
            // Stay here till all duplicates are
            // removed
            if( curr->val == curr->next->val )
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        
        return head;
    }
};