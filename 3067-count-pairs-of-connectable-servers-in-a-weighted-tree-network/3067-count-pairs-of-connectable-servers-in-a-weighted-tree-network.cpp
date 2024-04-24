
void dfs(unordered_map<int, vector<pair<int,int>>> &adj, int node, int &count, int dis, int signalSpeed, vector<int> &vis){
    if(vis[node] == 1)return;
    if(dis % signalSpeed == 0)count++;
    vis[node] = 1;
    for(auto i: adj[node]){
        if(vis[i.first] == 0){
            dfs(adj, i.first, count, dis + i.second, signalSpeed, vis);
        }
    }
}

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size();
        unordered_map<int, vector<pair<int,int>>> adj;
        for(int i = 0; i < n; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        int size = adj.size();
        vector<int> ans;
        for(int i = 0; i < size; i++){
            vector<int> vis(size, 0);
            vis[i] = 1;
            int res = 0;
            if(adj[i].size() <= 1){
                ans.push_back(0);
                continue;
            }
            vector<int> temp;
            for(auto j: adj[i]){
                int count = 0;
                dfs(adj, j.first, count, j.second, signalSpeed, vis);
                temp.push_back(count);
            }
            for(int k = 0; k < temp.size(); k++){
                for(int l = k + 1; l < temp.size(); l++){
                    res = res + temp[k] * temp[l];
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};