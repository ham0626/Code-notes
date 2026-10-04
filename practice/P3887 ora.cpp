#include<bits/stdc++.h>
using namespace std;
int k,d,m,f,q;
priority_queue<int> qk;
priority_queue<int> qd;
priority_queue<int> qm;
priority_queue<int> qf;
//普通队列
//队列大小:q.size()
// 放入元素:q.push(x)
// 弹出元素:q.pop(x)(不给值)
// 查看队头:q.front()
// 查看队尾:q.back()
// 检查是否为空:q.empty()
//优先队列（元素大在队头）
//查看队头q.top()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int op;
    cin>>k>>d>>m>>f;
    int temp;
    for(int i=1;i<=k;i++) cin>>temp,qk.push(temp);//守门员
    for(int i=1;i<=d;i++) cin>>temp,qd.push(temp);//后卫
    for(int i=1;i<=m;i++) cin>>temp,qm.push(temp);//中场
    for(int i=1;i<=f;i++) cin>>temp,qf.push(temp);//前锋
    cin>>op;
    for(int i=1;i<=op;i++){
        int a,b,c;//后-中-前
        double ans=0,res=0;
        cin>>a>>b>>c;
        temp=qk.top(),ans+=temp,qk.pop();
        for(int j=1;j<=a;j++) temp=qd.top(),ans+=temp,qd.pop();
        for(int j=1;j<=b;j++) temp=qm.top(),ans+=temp,qm.pop();
        for(int j=1;j<=c;j++) temp=qf.top(),ans+=temp,qf.pop();
        res=ans*1.0/11;
        cout<<fixed<<setprecision(2)<<res<<'\n';
    }
    return 0;
}