class Solution {
public:
    bool isPowerOfFour(int n) {
        bitset<32> s("1010101010101010101010101010101");
        int com = s.to_ulong();
        cout <<com<<endl;
       
       return n>0&& com&n &&!(n&n-1);
      
    }
};