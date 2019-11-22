#include<vector>
#include<map>
#include<iostream>
using namespace std;
// 同一条直线上 不一定连续 相同的点算多个 
class Solution {
private:
    int gcd(int a,int b){
       return (b == 0) ? a : gcd(b, a % b);
    }
public:
    int maxPoints(vector<vector<int> >& points) {
        int res=0;
        map<pair<int,int>, int> map;
        //mac上如果使用i<=points.size()-1 points.size()-1=18446744073709551615 超时？？？
        for(int i=0;i<points.size();i++){
            map.clear();
            int duplicated=1;
            for(int j=i+1;j<points.size();j++){
                if(points[i][0]==points[j][0]&&
                points[i][1]==points[j][1]){
                    duplicated++;
                    continue;
                }
                int dx=points[j][0]-points[i][0];
                int dy=points[j][1]-points[i][1];
                
                if(dx<0){
                    dx=-dx;
                    dy=-dy;
                }
                int div=gcd(dx,dy);
                dx/=div;
                dy/=div;
                map[make_pair(dx,dy)]++;
            }
            //仅存在重复点没有其他共线点的case
            res=max(res,duplicated);
            for(auto pair:map){
                if(duplicated+pair.second>res){
                    res=duplicated+pair.second;
                }
            }
        }
        return res;
    }
};