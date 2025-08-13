class Solution {
public:
    bool isPowerOfThree(int n) {
        // cout << n <<endl;
        if(n==1) return true;
        if(n<1 || n%3) return false;
        // if(n%3) return false;

        
        return isPowerOfThree(n/3);
        
    }
};