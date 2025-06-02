class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        long long max = *max_element(piles.begin(),piles.end());

        long long l = 1, r = max;

        while(l<=r){
            long long  mid = l+ (r-l)/2;
            bool flag = canEat(piles,h,mid);

            if(flag) r = mid-1;
            else l = mid +1;


        }
        return l;
        
    }

    bool canEat(vector<int>& piles,int h , int k){
       long long hourTook = 0;
        for(auto x: piles){
            hourTook += (long long)(x + k -1)/k;
        }
        
        return (hourTook<=h);

    }
};