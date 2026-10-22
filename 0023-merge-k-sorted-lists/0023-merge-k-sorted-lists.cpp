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
        //creating min heap
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        //initializing the head and tail pointer 
        ListNode*head=NULL;
        ListNode*tail=NULL;
        //inserting the head of all the linked list in heap
        for(int i =0 ; i<lists.size();i++){
           if (lists[i] != NULL) {
                 pq.push(lists[i]);
                                }  
        }
        //connecting all the smallest pointer in heap to make a sorted merged linked list 
        while(!pq.empty()){
            ListNode*temp=pq.top();//smallest  node of k list 
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
                pq.push(temp->next);//pushing the value of the next node in  min heap
            }
           
        }
        if(tail!=NULL){
        tail->next=NULL;
        }
        return head;
    }
};