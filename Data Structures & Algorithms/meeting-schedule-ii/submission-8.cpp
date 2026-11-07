/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
       if (intervals.size() == 0){
            return 0;
       }
        int mx = 0;
       for (int i = 0 ; i<intervals.size() ; i++){
            mx = max(mx,intervals[i].end);
       }
       vector<int> prefix(mx+10);
       for (int i = 0 ; i<intervals.size() ; i++){
            prefix[intervals[i].start] += 1;
            prefix[intervals[i].end] -= 1;
       }
       int ans = 1;
       for (int i = 1 ; i<=mx ; i++){
            prefix[i] += prefix[i-1];
            ans = max(ans,prefix[i]);
       }
       return ans; 
    }
};
