class Solution {
public:

    long long quadraticRoots(long long a, long long b, long long c){

        long long inter = b*b - 4LL*a*c;
        if(inter<0) return 0;
        long long r = sqrt(inter);
        // while((r + 1) * (r + 1) <= inter) r++;
        // while(r * r > inter) r--;


        long long root1 = (-b + r)/(2*a);
        // long long root2 = (-b - r)/(2*a);
        return root1> 0 ? root1 : 0;
        // if(root1 > root2 ) return root1>0 ? root1 : 0;
        // return root2>0 ? root2: 0;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long max_  = 0;
        for(auto x:workerTimes) 
            if(max_ < x) max_ = x;

        long long l = 1, r  = (1LL*mountainHeight*(mountainHeight + 1)/2) * max_;
        long long result = r;
        while(l<=r){

            long long mid = l + (r - l) /2;

            if(can(workerTimes, mid, mountainHeight)){
                result = mid;
                r = mid -1;
            }
            else{
                l = mid + 1;
            }
        }
  
        return result;
    }


    bool can(vector<int> &w, long long mid, long long mH){

        long long sum = 0;
        // cout << "mid" << mid << endl;
        for(auto x:w){
            // sum += ((mid)*(mid + 1)/ 2) * x;
            long long n = mid/x;
            
            sum+= quadraticRoots(1,1,-(n*2));
            // cout << quadraticRoots(1,1,-(n*2)) << endl;

            if(sum >= mH) return true;
        }

        return false;
    }
};