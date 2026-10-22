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
 class compare{
    public:
    bool operator()(ListNode*d1 ,ListNode*d2 ){
        return d1->val>d2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        ListNode*head=NULL;
        ListNode*tail=NULL;
        for(int i =0 ; i<lists.size();i++){
           if (lists[i] != NULL) {
                 pq.push(lists[i]);
                                }  
        }
        while(!pq.empty()){
            ListNode*temp=pq.top();
            pq.pop();

            if(head==NULL){
                head=temp;
                tail=temp;
            }
            else{
                tail->next=temp;
                tail=tail->next;
            }
            if(temp->next!=NULL){
                pq.push(temp->next);
            }
           
        }
        if(tail!=NULL){
        tail->next=NULL;
        }
        return head;
    }
};