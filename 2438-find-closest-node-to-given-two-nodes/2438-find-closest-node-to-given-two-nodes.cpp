class Solution
{
    public:
        int closestMeetingNode(vector<int> &edges, int n1, int n2)
        {
            int n = edges.size();

            vector<int> distn1(n, -1), distn2(n, -1);

            vector<bool> visited(n);
           	// distn1[n1] = 0;

            int path = 0;

            while (n1 != -1 && !visited[n1])
            {
                visited[n1] = true;
                distn1[n1] = path++;

                n1 = edges[n1];
            }

            vector<bool> visited2(n);
            path = 0;
            while (n2 != -1 && !visited2[n2])
            {
                visited2[n2] = true;
                distn2[n2] = path++;
                n2 = edges[n2];
            }

            int ans = INT_MAX;
            int node = -1;

            for (int i = 0; i < n; i++)
            {

                if (distn1[i] != -1 && distn2[i] != -1)
                {
                   	// cout<<i<<endl;
                    if (ans > max(distn1[i], distn2[i]))
                    {
                        node = i;
                        ans = max(distn1[i], distn2[i]);
                    }
                }
            }

            return node;
        }
};