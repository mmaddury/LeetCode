class Solution {
public:
    int climbStairs(int n) {
        
        // To reach the ith step, you can take 1 step
        // from i-1 or two steps from i-2.
        // So steps[i] is steps[i-1] + steps[i-2]

		if( n==0 || n==1 )
			return n;

		vector<int> steps(n+1,0);
		steps[0] = 1;
		steps[1] = 1;
        for( int i=2; i<steps.size(); i++ )
	        steps[i] = steps[i-1] + steps[i-2];

		return steps.back();

    }
};


