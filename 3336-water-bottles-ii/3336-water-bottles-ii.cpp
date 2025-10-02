class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        
       int ans = numBottles;

       if(numExchange<=numBottles){
        ans++;
        numBottles-=numExchange;
       }
    //    if(numBottles<numExchange) return ans;
    //    cout<< numBottles<<endl;
       int l = 1,r = numBottles;

       int result = 0;
       while(l<=r){
        int mid = l + (r-l)/2;
        int total = (mid)*numExchange + ((mid)*(mid-1))/2;
        if(total<=numBottles){
            result = mid;
            l = mid+1;

        }
        else{
            r = mid-1;
        }

       }

       return ans+result;
    }
};