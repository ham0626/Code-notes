#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    int c,m,e,t;
};
vector<node> grade;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int c,m,e,t;
        cin>>c>>m>>e;
        t=c+m+e;
        grade.push_back({c,m,e,t});
    }
    for(int i=0;i<=n-1;i++)
        for(int j=i+1;j<=n-1;j++){
            if(abs(grade[i].t-grade[j].t)<=10&&abs(grade[i].c-grade[j].c)<=5&&abs(grade[i].m-grade[j].m)<=5&&abs(grade[i].e-grade[j].e)<=5)
            cnt++;
        }
    cout<<cnt;
    return 0;
}