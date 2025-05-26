class Solution {
public:
   bool isPrime(long long num){
    if(num<=1) return false;
    for(long long i = 2;i*i<=num;i++){
        if(num%i==0)  return false;

    }

    return true;
   }
    long long sumOfLargestPrimes(string s) {
        priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
        int n = s.size();
        unordered_map<long long , bool> vis;
        for(int i = 0;i<n;i++){
            long long tmp = 0;
            for(int j = i;j<n;j++){
                tmp = tmp*10+ (s[j]-'0');
                if( !vis[tmp] && isPrime(tmp) && (pq.size()<3 || pq.top()<tmp)){
                if(pq.size()==3) pq.pop();
                pq.push(tmp);
                vis[tmp] = true;
                }
            }

            }
           


        

        long long ans = 0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }

        return ans;
    }
};