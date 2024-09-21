//     void DFS(vector<int> adj[], int u, vector<bool>& visited, vector<int>& result) {
//     if (visited[u]) return; // Node has already been visited
    
//     visited[u] = true;
//     result.push_back(u);
    
//     for (int v : adj[u]) {
//         if (!visited[v]) {
//             DFS(adj, v, visited, result);
//         }
//     }
// }

// // Function to perform DFS of the graph and return the result
// vector<int> dfsOfGraph(int V, vector<int> adj[]) {
//     vector<int> result;
//     vector<bool> visited(V, false);
    
//     // Start DFS from node 0
//     DFS(adj, 0, visited, result);
//     return result;
// }
    void DFS(unordered_map<int,vector<int>>&adj, int u,vector<bool>&visited, vector<int>&result){
        if(visited[u] == true) return;
    
        visited[u] = true;
        
        result.push_back(u);
        
        for(auto &v: adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited,result);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> mpp[]) {
        unordered_map<int,vector<int>>adj;
        
        for(int u=0; u<V; u++){
            for(auto v = mpp[u].begin(); v != mpp[u].end(); v++){
                adj[u].push_back(*v);
            }
        }
        vector<int>result;
        vector<bool>visited(V,false);
        
        DFS(adj,0,visited,result);
        return result;
    }