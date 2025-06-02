class Solution
{
    public:
        int snakesAndLadders(vector<vector < int>> &board)
        {
            int n = board.size();
            vector<int> visited(n *n);
            queue<pair<int, int>> q;
            q.push({ 0,
                0 });;

            while (!q.empty())
            {
                auto[pos, step] = q.front();
                q.pop();

                for (int j = 1; j <= 6; j++)
                {
                    int next = pos + j;
                    if (next >= n *n) continue;
                    int row = n - 1 - next / n;
                    int col = ((next / n) % 2) ? n - 1 - next % n : next % n;

                    if (board[row][col] != -1)
                    {
                        next = board[row][col]-1 ;
                    }
                    if (next == n *n - 1) return step + 1;

                    if (!visited[next])
                    {
                        visited[next] = true;
                        q.push({ next,
                            step + 1 });
                    }
                }
            }

            return -1;
        }
};