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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,bool> umap;
        for(auto x:nums) umap[x] = true;

        ListNode* fakehead = new ListNode();

        ListNode* curr = fakehead;

        while(head){
            if(umap.find(head->val) ==umap.end()) {
                curr->next = head;
                curr = curr->next;
            }

            head = head->next;
        }
        
        
        curr->next = nullptr;

        return fakehead->next;
        
    }
};