class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);
        v[0].push_back(1);
        if(numRows == 1){
            return v;
        }
        v[1].push_back(1);
        v[1].push_back(1);
        for(int i = 2; i < numRows; i++){
            v[i].push_back(1);
            for(int j = 1; j < i; j++){  // 1 -> 2
               int x = v[i - 1][j - 1] + v[i - 1][j]; // v[1][0] + v[1][1]
                v[i].push_back(x);

            }
            v[i].push_back(1);

        }
    return v;
    }
};