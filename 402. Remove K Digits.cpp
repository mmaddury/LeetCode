class Solution {
public:
    string 
    removeKdigits(string num, int k) {
        
        //
        // Did not get this
        //
        // Use a stack for the greedy algorithm
        // Start from the left
        //  1. push an element on the stack
        //  2. check if the top of stack is > next element
        //     a. If so, pop from the stack 
        //        Use greedy and pop till one of the following is true
        //        i) k is reached
        //        ii) stack is empty
        //        iii) top of stack is smaller
        //     b. Push the element
        //  3. Complete pushing till end of string and create result
        //  4. If all the values are equal, nothing will happen!
        //     But the greater than condition is correct to handle 
        //     strings like "112"
        //  5. Since k is not zero, loop through k and remove k elements
        //
    
        
        stack<char> stack;
        if( k == num.size() )
            return "0";
        
        // Part 1 of greedy algo (>)
        int i=0;
        while( i < num.size() ) {
            
            while( (k>0) && (!stack.empty()) && (stack.top() > num[i]) ) {
                stack.pop();
                k--;
            }
            stack.push(num[i]);
            i++;
            
        }
        
        // Part 2 of greedy algo (=)
        while( k > 0 && !stack.empty() ) {
            stack.pop();
            k--;
        }
            
        // Create result
        string r = "";
        while( !stack.empty() ) {
            r = stack.top() + r;
            stack.pop();
        }
        
        // Clean up leading zeros
        bool foundNz = false;
        i = 0;
        int  nzIdx = 0;
        while( !foundNz ) {
            if( r[i] == '0' ) {
                i++;
            } else {
                foundNz = true;
                nzIdx = i;
            }
        }           
        r.erase(0, nzIdx);          
        
        // Set to "0" if empty
        if( r.size() == 0 )
            r = "0";
            
        return r;
        
    }
};