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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> umap;

        while(headA || headB){
            if(headA and umap[headA]) return headA;
            umap[headA] = true;
            if(headB and umap[headB]) return headB;
            umap[headB] = true;

            if(headA) headA= headA->next;
            if(headB) headB = headB->next;
        }
        cout <<"here";

        return  nullptr;
    }
};