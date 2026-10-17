#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> grade;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int s;
    double ans=0,re;
    for(int i=1;i<=n;i++) cin>>s,grade.push_back(s);
    sort(grade.begin(),grade.end());
    for(int i=1;i<=n-2;i++) ans=ans+grade[i];
    re=ans*1.0/(n-2);
    cout<<fixed<<setprecision(2)<<re;
    return 0;
}