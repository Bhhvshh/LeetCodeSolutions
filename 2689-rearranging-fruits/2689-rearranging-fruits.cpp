using ll = long long;
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {

        map<int,int> m;
        long long min_ = INT_MAX;

        for(auto x:basket1) m[x]++;
        for(auto x:basket2){if( m[x]) min_ = min(min_,(ll)x); m[x]--;}

        vector<pair<ll,ll>> vp;
        long long count = 0;
        for(auto &x:m) {
            if(x.second%2) return -1;
            count+=x.second;
            if(x.second==0){ 
            // min_ = min(min_,(ll)x.first);
                
                 continue;}
            vp.push_back({x.second/2,x.first});}

            if(count) return -1;
//           sort(vp.begin(), vp.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
//     return a.second < b.second;
// });


        int l = 0, r= vp.size() - 1;
        long long ans = 0;

        while(l<r){
            if(vp[l].first<=0){l++;continue;}
            if(vp[r].first>=0){r--;continue;}
            // cout << vp[l].first << " "<<vp[l].second << " "<<vp[r].first << " "<< vp[r].second<<endl;


            if(vp[l].first>(-vp[r].first)){
                ans+= min(vp[l].second,min(vp[r].second,2*min_))*(-vp[r].first);
                min_ = min(min_,min(vp[r].second,vp[l].second));
                   
                vp[l].first+=vp[r].first;
                vp[r].first = 0;

                r--;
            }
            else if(vp[l].first<(-vp[r].first)){
                ans+= min(vp[l].second,min(vp[r].second,2*min_))*vp[l].first;
                 min_ = min(min_,min(vp[r].second,vp[l].second));
                  
                vp[r].first+=vp[l].first;
                vp[l].first = 0;

                l++;
            }
            else{
                ans+= min(vp[l].second,min(vp[r].second,2*min_))*vp[l].first;
                min_ = min(min_,min(vp[r].second,vp[l].second));
                     
                vp[r--].first=0;
                vp[l++].first=0;


            }



        }
        // cout << ans <<endl;

         l = 0, r= vp.size() - 1;

        while(l<r){
            if(vp[l].first>=0){l++;continue;}
            if(vp[r].first<=0){r--;continue;}
            // cout << vp[l].first << " "<<vp[l].second << " "<<vp[r].first << " "<< vp[r].second<<endl;

            if((-vp[l].first)>(vp[r].first)){
                ans+= min(vp[l].second,min(vp[r].second,2*min_))*(vp[r].first);
                                min_ = min(min_,min(vp[r].second,vp[l].second));
                   
                vp[l].first+=vp[r].first;
                vp[r].first = 0;


                r--;
            }
            else if(-vp[l].first<(vp[r].first)){
                ans+= min(vp[l].second,min(vp[r].second,2*min_))*(-vp[l].first);
                                min_ = min(min_,min(vp[r].second,vp[l].second));
                       
                vp[r].first+=vp[l].first;
                vp[l].first = 0;

                l++;
            }
            else{
                ans+= min(vp[l].second,min(vp[r].second,2*min_))*vp[r].first;
                min_ = min(min_,min(vp[r].second,vp[l].second));
                
                vp[r--].first=0;
                vp[l++].first=0;


            }



        }
       
       return ans;

         
        
    }
};