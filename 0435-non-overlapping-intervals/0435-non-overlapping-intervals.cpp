class Solution {
public:
  static  bool comp(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int lst = intervals[0][1], c = 0;
        for(auto i : intervals){
            if(lst > i[0]){
                c++;
            }
            else{
                lst = i[1];
            }
            
        }
        return c - 1;
    }
};