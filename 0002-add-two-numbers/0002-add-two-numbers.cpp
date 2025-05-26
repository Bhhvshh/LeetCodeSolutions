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
int rem = 0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* st;
        ListNode* tmp = new ListNode();
        st = tmp;

        while(l1 != NULL || l2!= NULL){
             ListNode* prev= tmp;
             tmp = new ListNode();
             int a = 0, b=0;
             if(l1!=NULL) a = l1->val;
             if(l2!=NULL) b = l2->val;

             int sum = (a+b+rem);
             rem = sum/10;
             tmp->val = sum%10;
             prev->next = tmp;



            if(l1!=NULL) l1= l1->next;
            if(l2!=NULL) l2= l2->next;
        }
       if(rem>0)tmp->next = new ListNode(rem);
        return st->next;
        
    }
};