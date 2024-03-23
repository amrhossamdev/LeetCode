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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* tmp = head;
        int sz = 0;
        while(tmp != nullptr){
            ++sz;
            tmp = tmp->next;
        }
        
        if(n == sz){
            ListNode *toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
    
        }
        tmp = head;
        int idx = 0;
        while(idx != sz - n - 1){
            idx++;
            tmp = tmp->next;
        }
        
        ListNode *toDelete = tmp->next;
        tmp->next = tmp->next->next;
        delete toDelete;
       
        return head;
        
    }
};