class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> adj[n + 1];
        for(int i = 1; i < n; i++){
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }
        adj[x].push_back(y);
        adj[y].push_back(x);
        vector<vector<int>> temp(n + 1, vector<int> (n + 1, INT_MAX));
        for(int i = 1; i < n + 1; i++){
            queue<pair<int,int>> q;
            q.push({i, 0});
            vector<int> vis(n + 1, 0);
            vis[i] = 1;
            while(!q.empty()){
                int node = q.front().first;
                int dis = q.front().second;
                q.pop();
                temp[i][node] = min(temp[i][node], dis);
                for(auto i : adj[node]){
                    if(vis[i] == 0){
                        vis[i] = 1;
                        q.push({i, dis + 1});
                    }
                }
            }
        }
        vector<int> ans;
        for(int i = 1; i < n + 1; i++){
            int count = 0;
            for(auto j : temp){
                for(auto k : j){
                    if(i == k)count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};