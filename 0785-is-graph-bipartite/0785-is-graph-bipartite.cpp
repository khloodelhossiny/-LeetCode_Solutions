class Solution {
public:
    int vst[105];
    bool fun(int node, int bit, vector<vector<int>>& graph){
        vst[node] = bit;
        for(auto i: graph[node]){
            if(vst[i] == -1){
                if(fun(i, !bit, graph)){
                    return 1;
                }
                
            }
           else if(vst[i] == bit){
                return 1;
            }
        }
        return 0;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        memset(vst, -1, sizeof(vst));
        for(int i = 0; i < graph.size(); i++){
           memset(vst, -1, sizeof(vst));
            if(fun(i, 0, graph) == 1){
                return 0;
            }
        }
        return 1;
    }
};