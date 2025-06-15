class Solution {
public:
    int maxDiff(int num) {
         int cp = num;
        int maxMap = cp%10;
        int minMap = cp%10;
        int last = cp%10;
        cp/=10;
        

        while(cp){
            int curr = cp%10;
            if(curr!=9) maxMap = curr;
            if(curr!=1 && curr!=0) minMap= curr;
            last = curr;
            
            cp/=10;
           

            
        }


        cp = num;
        int min_ = 0,max_ =0;
        int multiplier= 1;

  if(last!=1){
        while(cp){
            int curr = cp%10;
            min_ += (curr==last) ? 1*multiplier: multiplier*curr;
            max_ += (curr==maxMap) ? 9*multiplier: curr*multiplier;
            multiplier*=10;
            cp/=10;
        }
  }
else if(minMap>1){
    while(cp){
            int curr = cp%10;
            min_ += (curr==minMap) ? 0: multiplier*curr;
            max_ += (curr==maxMap) ? 9*multiplier: curr*multiplier;
            multiplier*=10;
            cp/=10;
        }
}
 else{
    while(cp){
            int curr = cp%10;
            max_ += (curr==maxMap) ? 9*multiplier: curr*multiplier;
            multiplier*=10;
            cp/=10;
        }
        min_ = num;

 

}


        return max_ - min_;
        
    }
};