class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
		// Use two pointers and start from the end
		// of the array. Reset both indices when a
		// new sell point is discovered. Ow, try to
		// find the lowest buy point

    	int b = prices.size()-1;		// Buy idx
		int s = prices.size()-1;		// Sell idx
		int currProfit = 0;
		int maxProfit = 0;

		for(int i=prices.size()-1; i>=0; i-- ) {

			if( prices[i] > prices[s] ) {
				// Reset buy/sell idx
				b = i; 
                s = i;
			}
            if( prices[i] < prices[b] ) {
				// Reset buy idx
				b = i;
			}
			currProfit = prices[s] - prices[b];
			maxProfit = maxProfit > currProfit ? maxProfit : currProfit;
		}

		return maxProfit;
    }
};


