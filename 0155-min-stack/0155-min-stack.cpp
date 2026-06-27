 class node{
    public:
  long long data;
    node *next;
   };
class MinStack { 
  node *topnode;
  long long minele;

public:
    MinStack() {
        topnode=NULL;
    }
    
    void push(int value) {
        node *newnode= new node;
        if(topnode==NULL){
            newnode->data= value;
            newnode->next=NULL;
            topnode=newnode;
            minele=value;
        }
        else if( value>=minele){
            newnode->data=value;
            newnode->next=topnode;
            topnode=newnode;

        }
        else{
            newnode->data=2LL*value-minele;
            newnode->next=topnode;
            topnode=newnode;
            minele=value;
        }
        
    }
    
    void pop() {
        if(topnode==NULL){
            return ;
        }
        if(topnode->data<minele){
            minele=2LL*minele-topnode->data;
        }
        node* nextelement=topnode;
        topnode=topnode->next;
         delete nextelement;
            
        
    }
    
    int top() {
         if (topnode == NULL) return -1;

        if (topnode->data >= minele)
            return topnode->data;

        return minele;
    }
    
    int getMin() {
        if (topnode == NULL) return -1;
        return minele;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */