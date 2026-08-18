class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int arr[51]={0};

        for(int i  = 0 ; i<= nums.size()-k;i++){
            bool seen[51]={false};
            for(int j = i ; j<=i+k-1; j++){
                seen[nums[j]]=true;
            }
            for(int  j =  0 ; j<51 ; j++){
                if(seen[j]){
                    arr[j]++;
                }
            }
        }
        for(int i = 50; i>=0;i--){
            if(arr[i]==1){
                return i;
            }
        }
        return -1;
    }
};