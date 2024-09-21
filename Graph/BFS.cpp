 void bfs(vector<int> adj[], int u, vector<bool>&visited, vector<int>&result){
        queue<int>q;
        visited[u] = true;
        q.push(u);
        result.push_back(u);
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(auto &v: adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int,vector<int>>mp;
        
        for(int u=0; u<V; u++){
            for(auto v = mp[u].begin(); v != mp[u].end(); v++){
                adj[u].push_back(*v);
            }
        }
        vector<bool>visited(V,false);
        vector<int>result;
        
        bfs(adj,0,visited,result);
        
        return result;
        
    }