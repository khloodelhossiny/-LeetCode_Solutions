class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        stack<vector<int>>st;
        sort(intervals.begin(), intervals.end());
        st.push(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0]>= st.top()[0] && intervals[i][0] <= st.top()[1]){
                st.top()[1] = max(st.top()[1], intervals[i][1]);
            }
            else{
                st.push(intervals[i]);
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};