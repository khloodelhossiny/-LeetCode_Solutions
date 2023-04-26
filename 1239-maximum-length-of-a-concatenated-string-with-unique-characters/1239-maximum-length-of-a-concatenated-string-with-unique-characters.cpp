class Solution {
public:
    int maxLength(vector<string>& x) {
       vector<vector<int>>frq(x.size(),vector<int>(26,0));
       vector<bool>valid(x.size(),0);
       for(int i=0;i<x.size();i++){
           for(auto j:x[i]){
               frq[i][j-'a']++;
           }
           bool p=1;
           for(int j=0;j<26;j++){
               if(frq[i][j]>1){
                   p=0;break;
               }
           }
           if(p){
               valid[i]=1;
           }

       }
       vector<string>arr;
      
      for(int i=0;i<valid.size();i++){
          if(valid[i]){
              sort(x[i].begin(),x[i].end());
              arr.push_back(x[i]);
          }
      }
       frq.clear();
       sort(arr.begin(),arr.end());
       frq.resize(arr.size(),vector<int>(26,0));
         for(int i=0;i<arr.size();i++){
           for(auto j:arr[i]){
               frq[i][j-'a']++;
           }
         }
       int res = 0;
       for(int i =0;i<(1<<arr.size());i++){
           vector<int>idx;int c=0;
           for(int j=0;j<arr.size();j++){
               if(((i>>j)&1)){
                   idx.push_back(j);
               }
           }
           vector<int>frq_all(26,0);
           for(auto k:idx){
               for(int l=0;l<26;l++){
                   frq_all[l]+=frq[k][l];
                   if(frq_all[l]>1){
                       c=-1;
                       break;
                   }
               }
               if(c==-1){
                   break;
               }
           }
        /*   if(idx.size()==1&&idx[0]==1){
                  for(auto k:frq_all){
                  cout<<k<<" ";
                  }
                  cout<<endl;
           }*/
          /* for(auto k:frq_all){
               if(k>1){
                   c=-1;break;
               }
           }*/
           if(c!=-1){
               c =0;
                 for(auto k:idx){
                     c+=arr[k].size();
                 }
           }
          /* if(idx.size()==1&&idx[0]==1){
               cout<<"hhhhhhh"<<c<<endl;
           }*/
           //["zog","nvwsuikgndmfexxgjtkb","nxko"]

           res= max(res,c);
       }
       return res;
    }
};