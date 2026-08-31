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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result={-1,-1};
       int mindistance=INT_MAX;
       ListNode*curr=head->next;
       ListNode*prev=head;

       int prevcritical=0;
       int currindex=1;
       int firstcritical= 0;


       while(curr->next!=NULL){
        if((curr->val<prev->val&&curr->val<curr->next->val)||(curr->val>prev->val&&curr->val>curr->next->val)){
            if(prevcritical==0){
                prevcritical=currindex;
                firstcritical=currindex;
            }
            else{
                mindistance=min(mindistance,currindex-prevcritical);
                prevcritical=currindex;
            }  

        }
        currindex++;
        prev=curr;
        curr=curr->next;
        
       }
       if(mindistance!=INT_MAX){
        int maxdistance= prevcritical-firstcritical;
        result={mindistance,maxdistance};
       }
       return result;
    }
};