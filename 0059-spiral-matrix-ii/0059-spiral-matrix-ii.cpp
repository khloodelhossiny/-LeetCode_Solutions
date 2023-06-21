class Solution {
public:
    vector<vector<int>>res;
    int m, vst[105][105];
    bool valid (int i, int j){
        return (i >= 0 && i < m && j >=0 && j < m && vst[i][j] == 0);
    }
        
    void sprial(int i, int j, int dirc, int c = 1){
        if(!valid(i,j)){
            return ;
        }
        res[i][j] = c;
        vst[i][j] = 1;
        if(dirc == 0){
            if(valid(i,j + 1)){
                sprial(i, j + 1, 0, c + 1);
            }
            else{
                sprial(i + 1, j, 1, c + 1);
            }
        }
        if(dirc == 1){
            if(valid(i + 1,j)){
                sprial(i + 1, j, 1, c + 1);
            }
            else{
                sprial(i, j - 1, 2, c + 1);
            }
        }
        if(dirc == 2){
            if(valid(i,j - 1)){
                sprial(i, j - 1, 2, c + 1);
            }
            else{
                sprial(i - 1, j, 3, c + 1);
            }
        }
        if(dirc == 3){
            if(valid(i - 1,j)){
                sprial(i - 1, j, 3, c + 1);
            }
            else{
                sprial(i, j + 1, 0, c + 1);
            }
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        m = n;
        res.resize(n, vector<int>(n));
        memset(vst, 0, sizeof(0));
        sprial(0,0,0);
        return res;
    }
};