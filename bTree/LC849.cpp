/*
 * In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. There is at least one empty seat, and at least one person sitting.
 * Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. Return that maximum distance to closest person.
 *
 */


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int max = 0;
        vector<int> ret (seats.size(),0);
        if(seats.front()==0) ret[0] = INT_MAX-seats.size();
        
        for(int i=1; i<seats.size(); i++) {
            
            if(seats[i] == 0) {
                if(seats[i-1] == 0)ret[i] = 1 + ret[i-1];
                else ret[i] = 1;
            }
        }
        
        for(int i = seats.size()-2;i>=0;i--) {
            
            if(seats[i] == 0){
                if(seats[i+1] != 1) {
                 //cout << ret[i] << ret[i+1] << i << seats[i] << endl;
                    ret[i] = min(ret[i],1+ret[i+1]);
                    //cout << ret[i] << endl;
                }
                else ret[i] = 1;
                max = ::max(max,ret[i]);   
            }
        }
        
        max = ::max(ret.back(),max);
        
        return max;
    }
};
