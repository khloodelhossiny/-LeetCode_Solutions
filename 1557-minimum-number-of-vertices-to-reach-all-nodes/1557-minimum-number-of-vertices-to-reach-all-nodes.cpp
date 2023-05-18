class Solution {
public:
    bool vst[100005];
    vector<vector<int>>v;
    void dfs(int node){
        vst[node] = 1;
        for(auto i : v[node]){
            if(!vst[i]){
                dfs(i);
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        v.resize(n);
        for(int i = 0; i < edges.size(); i++){
            v[edges[i][0]].push_back(edges[i][1]);
        }
        memset(vst,0, sizeof(vst));
        vector<int>node, res;

        for(int i = 0; i < n;i++){
            if(!vst[i]){
                dfs(i);
                node.push_back(i);
            }
        }
        memset(vst,0, sizeof(vst));

        for(int i = node.size() - 1; i >= 0; i--){
             if(!vst[node[i]]){
                dfs(node[i]);
                res.push_back(node[i]);
            }
        }
        return res;
    }
};