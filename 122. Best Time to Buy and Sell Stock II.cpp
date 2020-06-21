class Solution {
public:
    int 
    maxProfit(vector<int>& prices) {
     
        // Use b & s as buy and sell index
		// Use buyDone flag

		// Buy when prices start rising
	
	    // Sell when prices start decreasing
     	// Reset buyDone flag  
        
        
		bool buyDone = false;
		int b=0;
		int s=0;
		int totalProfit = 0;
        int sales = 0;

		for( int i=0; i<prices.size()-1; i++ ) {
			if( prices[i] < prices[i+1] && !buyDone ) {
				b = i;
                cout << "b = " << i;
				buyDone = true;
			}
			if( prices[i] > prices[i+1] && buyDone ) {
                cout << ", s = " << i << endl;
				totalProfit += prices[i] - prices[b];
				buyDone = false;
                sales++;
			}
		}
        // Residual case
        if( buyDone && prices.back() > prices[b] ) {
            totalProfit += prices.back() - prices[b];
            buyDone = false;
            sales++;
        }

        cout << sales << " sales" << endl;
		return totalProfit;
        
    }
};


