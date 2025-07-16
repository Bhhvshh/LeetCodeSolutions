class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        unordered_map<int,int> umap;
        for(auto x:hand) umap[x]++;

        priority_queue<int> pq;
        for(auto x:umap) pq.push(x.first);

        while(!pq.empty()){
            int last = pq.top();
            pq.pop();
            int size = umap[last];
            // umap[last] = 0;
            queue<int> q;
            // cout << last << endl;

            if(pq.size()<groupSize-1) return false;

            for(int i = 0;i<groupSize -1;i++){
                int curr = pq.top(); pq.pop();
                if(abs(curr-last)!=1 || umap[curr]<size) return false;
               
                last = curr;
            
                if(umap[curr]-=size) q.push(curr); 

                


            }
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }

        }

        return true;
    }
};