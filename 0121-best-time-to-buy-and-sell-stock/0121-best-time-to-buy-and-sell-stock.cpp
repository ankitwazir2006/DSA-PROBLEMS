class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprize=INT_MAX;
        int maxprofit=0;
        for(int price : prices){
             minprize=min(minprize,price);
             maxprofit=max(maxprofit,price-minprize);
        }
        return maxprofit;
    }
};