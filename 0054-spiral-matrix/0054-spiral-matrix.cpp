class Solution {
public:
    vector<int>res;
    int vst[100][100], n, m;
    bool valid (int i, int j) {
        return i >= 0 && i < n && j >=0 && j < m && !vst[i][j];
    }
    void spiral_order(int i, int j, int dir, vector<vector<int>>& v){
        if (!valid(i, j)){
            return;
        }
        //cout<< i << " " << j << " "<< dir <<endl;
        res.push_back(v[i][j]);
        vst[i][j] = 1;
        if(dir == 0){
            if(!valid(i , j + 1)){
                spiral_order(i + 1, j, 1, v);     
            }
            else{                
                spiral_order(i, j + 1, 0, v); 
            }
        }
        else if(dir == 1){
             if(!valid(i + 1, j)){
                spiral_order(i, j - 1, 2, v);     
            }
            else{
                spiral_order(i + 1, j, 1, v); 
            }
        }
        else if(dir == 2){
            if(!valid(i , j - 1)){    
                spiral_order(i - 1, j, 3, v);     
            }
            else{
                spiral_order(i, j - 1, 2, v); 
            }
        }
        else{
            if(!valid(i - 1, j)){      
                spiral_order(i, j + 1, 0, v);     
            }
            else{
                spiral_order(i - 1, j, 3, v); 
            }
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        res.clear();
        memset(vst,0 ,sizeof (vst));
        n = matrix.size(); 
        m = matrix[0].size();
        spiral_order(0, 0, 0, matrix);
        return res;
    }
};