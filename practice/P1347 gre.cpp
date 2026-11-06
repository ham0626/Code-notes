#include<bits/stdc++.h>
using namespace std;
int n,m;
int in[30],head[30];
string res;
struct Node{
    int fro,to,nxt;
}edge[700];
int topo(){
    int tmp[30];
    queue<int> q;
    for(int i=0;i<n;i++) tmp[i]=in[i];
    for(int i=0;i<n;i++){
        if(tmp[i]==0)
        q.push(i);
    }
    int cnt=0;
    int flag=1;//目前唯一
    while(!q.empty()){
        if(q.size()>1) flag=0;
        int cur=q.front();
        q.pop();
        res+=(char)(cur+'A');
        cnt++;//弹出的个数
        for(int i=head[cur];i;i=edge[i].nxt){
            int v=edge[i].to;
            tmp[v]--;
            if(tmp[v]==0)
            q.push(v);
        }
    }
    if(cnt<n) return -1;//有环
    if(flag==1) return 1;//唯一
    else return 0;//不确定
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        char op1,ch,op2;
        cin>>op1>>ch>>op2;
        int num1=op1-'A';
        int num2=op2-'A';
        edge[i].fro=num1,edge[i].to=num2;
        edge[i].nxt=head[num1];
        head[num1]=i;
        in[num2]++;
        res="";//清空
        int f=topo();
        if(f==-1){
            cout<<"Inconsistency found after "<<i<<" relations.";
            return 0;
        }
        if(f==1){
            cout<<"Sorted sequence determined after "<<i<<" relations: "<< res<<".\n";
            return 0;
        }
    }
    cout<<"Sorted sequence cannot be determined.";
    return 0;
}