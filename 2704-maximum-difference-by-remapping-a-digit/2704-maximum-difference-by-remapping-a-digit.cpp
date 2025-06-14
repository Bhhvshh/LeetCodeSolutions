class Solution {
public:
    int minMaxDifference(int num) {
      
        int cp = num;
        int maxMap = cp%10;
        int minMap = cp%10;
        cp/=10;

        while(cp){
            int curr = cp%10;
            if(curr!=9) maxMap = curr;
            cp/=10;
           if(cp == 0) minMap= curr;

            
        }
        cp = num;
        int min_ = 0,max_ =0;
        //    cout << minMap<<  maxMap;
        int multiplier= 1;

        while(cp){
            int curr = cp%10;
            min_ += (curr==minMap) ? 0: multiplier*curr;
            max_ += (curr==maxMap) ? 9*multiplier: curr*multiplier;
            multiplier*=10;
            cp/=10;
        }


        return max_ - min_;


        
    }
};