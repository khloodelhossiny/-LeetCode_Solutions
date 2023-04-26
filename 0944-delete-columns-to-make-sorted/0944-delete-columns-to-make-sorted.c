int minDeletionSize(char ** strs, int strsSize){
    int c = 0;
        for(int j = 0; j < strlen(strs[0]); j++){
            for(int i = 1; i <strsSize; i++){
                if(strs[i][j] < strs[i - 1][j]){
                    c++;
                    break;
                }
            }
        }
        return c;
    
}