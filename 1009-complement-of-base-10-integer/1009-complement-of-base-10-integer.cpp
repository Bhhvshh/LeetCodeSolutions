class Solution {
public:
    int bitwiseComplement(int n) {
  
        int a = (n<=1) ? 0: log2(n);
        return  n ^  ((1<<(a+1)) - 1);

        
        
    }
};