class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprize=INT_MAX;
        int maxprofit=0;
        for(int i = 0 ; i<prices.size();i++){
             minprize=min(minprize,prices[i]);
             maxprofit=max(maxprofit,prices[i]-minprize);
        }
        return maxprofit;
    }
};