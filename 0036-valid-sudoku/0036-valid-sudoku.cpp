class Solution {
public:
    bool fun(int x,int y, int n, int m,vector<vector<char>>& board){
        vector<int>frq(10, 0);
        for(int i = x; i < n; i++){
            for(int j = y; j < m; j++){
                cout<<board[i][j];
                if(board[i][j] >= '0' && board[i][j] <= '9')
                    frq[board[i][j] - '0']++;
            }  
            cout<<endl;
       }
        for(auto j : frq){
             if(j > 1){
                   return 0;
               }
            }
        return 1;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // count rows
        for(int i = 0; i < 9; i++){
            vector<int>frq(20, 0);
            for(int j = 0; j < 9; j++){
                if(board[i][j] >= '0' && board[i][j] <= '9')
                    frq[board[i][j] - '0']++;
            }
            for(auto j : frq){
                if(j > 1){
                    return 0;
                }
            }
        }
        for(int i = 0; i < 9; i++){
            vector<int>frq(10, 0);
            for(int j = 0; j < 9; j++){
               if(board[j][i] >= '0' && board[j][i] <= '9')
                    frq[board[j][i] - '0']++;
            }
            for(auto j : frq){
                if(j > 1){
                    return 0;
                }
            }
        }
     //   cout<<fun(  6, 3, 9, 6,board) ;
        //return 1;
        bool res = fun(0, 0, 3, 3,board) & fun( 0, 3, 3, 6,board)&fun(  0, 6, 3, 9,board)
        &fun( 3, 0, 6, 3,board)  & fun( 3, 3, 6, 6,board) & fun(  3, 6, 6, 9,board)
       &fun(  6, 0, 9, 3,board) &fun(  6, 3, 9, 6,board) &fun(  6, 6, 9, 9,board);
        
        return res;
    }
};