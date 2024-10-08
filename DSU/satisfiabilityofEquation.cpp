class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[y_parent] > rank[x_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);

        for(int i=0; i<26; i++){
            parent[i] = i;
        }
        //union for equal chars
        for(string &s: equations){
            if(s[1] == '='){ // a == b
                Union(s[0]-'a',s[3]-'a');
            }
        }
        // now to handle != case
        for(string &s: equations){
            if(s[1] == '!'){
                char first = s[0];
                char second = s[3];

                int parent_first = find(first - 'a');
                int parent_second = find(second - 'a');

                if(parent_first == parent_second){
                    return false;
                }
            }
        }
        return true;
    }
};
