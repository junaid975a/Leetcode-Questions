class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy) return t!=1;
        int d = max(abs(fy-sy), abs(fx-sx));
        // d = max({d, sy-fy,sx-fx});
        // cout<<d<<t;
        if(t>=d) return true;
        return false;
    }
};