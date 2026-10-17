#include<bits/stdc++.h>
using namespace std;
int n;
int fa[105];
vector<int> fam[105];
queue<int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int s;
    cin>>n;
    for(int i=1;i<=n;i++){
        while(cin>>s&&s!=0){
        fam[i].push_back(s);      
        fa[s]++;//s的父亲多了一个 每个父节点为0的才能入队
        }  
    }
    for(int i=1;i<=n;i++){
        if(fa[i]==0) q.push(i);
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        cout<<cur<<" ";
        for(int i=0;i<fam[cur].size();i++){
            fa[fam[cur][i]]--;
            if(fa[fam[cur][i]]==0) q.push(fam[cur][i]);
        }
    }
    return 0;
}