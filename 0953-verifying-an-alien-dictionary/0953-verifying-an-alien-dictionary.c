bool in_order(char * s, char * t, char * order){
    int i;
    for( i = 0; s[i] != 0 && t[i] != 0; i++){
        int a ,b;
        for(int j = 0; order[j] != 0; j++){
            if(order[j] == s[i]){
                a = j;
            }
            if(order[j] == t[i]){
                b = j;
            }
        }
        if(b < a){
            return 0;
        }
        if(a < b){
            return 1;
        }
    }
    printf("%d\n", i);
    if(s[i] != 0 && t[i]== 0){
        return 0;
    }
    return 1;
}
bool isAlienSorted(char ** words, int wordsSize, char * order){
    for(int i = 0; i < wordsSize - 1; i++){
        if(!in_order(words[i],words[i + 1], order)){
            return 0;
        }
    }
    return 1;
}