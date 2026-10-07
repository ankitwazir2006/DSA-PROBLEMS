class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=0,num2=0,count1=0,count2=0;
        for(int element:nums){
            if(num1==element){
                count1++;
            }
            else if(num2==element){
                count2++;
            }
            else if(count1==0){
                num1=element;
                count1=1;
            }
            else if(count2==0){
                num2=element;
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int>arr;
        int n=nums.size()/3;
        count1=0,count2=0;
        for(int element:nums){
            if(num1==element){
                count1++;
            }
            if(num2==element){
                count2++;
            }
        }
       
        if(count1>n){
            arr.push_back(num1);
           
        }
         if(count2>n){
            arr.push_back(num2);
        }
         if(num1==num2){
            arr.pop_back();
        }
        return arr;
    }
};