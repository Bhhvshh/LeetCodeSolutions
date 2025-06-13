class Solution {
public:
  bool possible(vector<int> & piles,int h, int k){
    long long  needHour =0;
    for(auto x:piles){
        needHour +=(long long) x/k;
        needHour += (x%k) ? 1:0;

    }
    return needHour<=h;
  }
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1, r = *max_element(piles.begin(),piles.end());
        int result =-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(possible(piles,h,mid)) {
                result=  mid;
                r = mid -1;

            }
            else{
                l = mid + 1;

            }
        }

        return result;
        
    }
};