class Solution {
public:
    int smallestNumber(int n) {

        while(true){
            if(valid(n)) return n;
            n++;
        }

        return n;
        
    }

    bool valid(int num){
        while(num){
            if(num%2==0) return false;
            num/=2;
        }

        return true;
    }
};