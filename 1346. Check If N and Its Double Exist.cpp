class Solution {
public:
    bool 
    checkIfExist(vector<int>& arr) {
        
        /*
        sort(arr.begin(), arr.end());
        
        for( int i=0; i<arr.size(); i++ ) {
            for( int j=i+1; j<arr.size(); j++ ) {
                if( (2*arr[i] == arr[j]) || (2*arr[j] == arr[i]) ) {
                    cout << arr[i] << " " << arr[j] << endl;
                    return true;
                }
            }
        }
        */
        
        
        map<int,int> m;
        for( int i=0; i<arr.size(); i++ ) {
            m[arr[i]] = i;
        }
        for( int i=0; i<arr.size(); i++ ) {
            if(m.find(2*arr[i]) != m.end()) {
                if( i != m[2*arr[i]] ) {
                    return true;
                }
            }
        }
        
        
        return false;
        
    }
};