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
        int count = 0;
        ListNode* prev=nullptr;
        ListNode* back = head;
        ListNode* nex = head;

        while(nex){
            nex = nex->next;
            // count++;
            if(++count>n){
                prev = back;
                back = back->next;
                count--;
            } 
        }
        if(prev==nullptr) return back->next;
        prev->next = back->next;

        return head;


        
    }
};