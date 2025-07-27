class Solution {
public:
    bool isprime(int n) {
    // Numbers less than or equal to 1 are not prime.
    if (n <= 1) {
        return false;
    }
    // 2 is the only even prime number.
    if (n == 2) {
        return true;
    }
    // All other even numbers are not prime.
    if (n % 2 == 0) {
        return false;
    }
    // Check for divisibility from 3 up to the square root of n,
    // incrementing by 2 to only check odd numbers.
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false; // Found a divisor, so not prime.
        }
    }
    return true; // No divisors found, so it's prime.
}
    int minJumps(vector<int>& nums) {

        queue<int> q;
        q.push(0);
        if(nums.size()==1) return 0;
        vector<int> visited(nums.size(),0);
        visited[0] = true;
        unordered_map<int,vector<int>> umap;
        for(int i = 0;i<nums.size();i++){
            umap[nums[i]].push_back(i);
        }

        int l = 0;
        int max_ = *max_element(nums.begin(),nums.end());

        while(!q.empty()){
            int level = q.size();
            l++;
            for(int k = 0;k<level;k++){
            int i = q.front();
            q.pop();
                // cout << i << ' '<< l <<endl;
          
            if(i<nums.size()-1 &&!visited[i+1]){if(i+1==nums.size()-1) return l; q.push(i+1); visited[i+1] = true;}
            if(i>0 && !visited[i-1]){
                q.push(i-1);
                visited[i-1] = true;
            }

            if(isprime(nums[i])){
                // cout << "i"<<i<< " "<<l<<endl;
                for(int  j  = nums[i];j<=max_;j+=nums[i]){
                    for(auto z:umap[j]){
                    if(z==nums.size()-1) return l;
                    if(!visited[z]){q.push(z); visited[z] = true;} 
                    }
                } 
                
            }
            }
            
        }
        // cout << "here"<<endl;

        return nums.size()-1;
        
    }
};