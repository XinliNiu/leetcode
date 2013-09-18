class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (prices.size() <= 1)
            return 0;
        int D[prices.size()];
        int best_buy=0,best_sell=0;
        int current_buy=0,current_sell=0;
        D[0] = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < prices[current_sell]){
                if(prices[i] < prices[current_buy])
                    current_buy = i;
                current_sell = i; 
                D[i] = D[i-1];
            }
            else{
                if(prices[i] - prices[current_buy] >= D[i-1])
                {
                    best_buy = current_buy;
                    best_sell = i;
                    current_sell = i;
                    D[i] = prices[best_sell] - prices[best_buy];
                    
                }
                else
                {
                    current_sell = i;
                    D[i] = D[i-1];
                }
            }
        }
        return D[prices.size()-1];
    }
};
