class Solution {
public:
    bool checkDivisibility(int n) {
        int sum= 0 ,pro = 1;

        int tmp = n;

        while(tmp){
            sum+= (tmp%10);
            pro*= (tmp%10);
            tmp/=10;
        }

        return (n%(sum+pro))==0;
        
    }
};