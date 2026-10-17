#include<bits/stdc++.h>
using namespace std;
int n,m,k;//题数，队伍数，提交数
vector<string> name;
struct{
    int na;//队名索引
    int solve;//当前过了哪些题->题数排名
    int first_seen;//最早提交是第几条->同罚时决定排名
    int penality;//当前罚时
    int remaining;//封榜以后还有多少题没判
    int state[21];//封榜前过没过：0=未过,1=已过,2=封后待判
    int fail[21];//失败提交次数->罚时
    int actime[21];//封榜后AC题的时间
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;

    return 0;
}