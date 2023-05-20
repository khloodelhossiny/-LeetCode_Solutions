class Solution {
public:
    map<string, vector<pair<string,double>>>graph;
    map<string, int >vst;
    void dfs(string src, string end, double& res, double val){
      //  cout<<src<<endl;
        if(src == end){
            res = val;
            return ;
        }
        vst[src] = 1;
        for(auto i : graph[src]){
            if(vst[i.first] == 0){
                dfs(i.first, end, res, val* i.second);
            }
        }
        return ;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < equations.size(); i++){
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0] , 1 / values[i]});
            
        }
        vector<double>res;
        for(int i = 0; i < queries.size(); i++){   
            vst.clear();
            for(int j = 0; j < equations.size(); j++){
                vst[equations[j][0]] = 0;
                vst[equations[j][1]] = 0;
            }
            double ret = -1;
            if(graph[queries[i][0]].size() > 0){
                dfs(queries[i][0], queries[i][1], ret, 1);
            }
           
            res.push_back(ret);
        }
        return res;
    }
};