#include<bits/stdc++.h>
using namespace std;
const int maxn=5e+10;
int r[maxn],l[maxn];
bool del[maxn];

void add1(int x,int y){ // 把 y 插到 x 左边
    r[l[x]]=y,l[y]=l[x];
    l[x]=y,r[y]=x;
}
void add2(int x, int y){ // 把 y 插到 x 右边
    l[r[x]]=y,r[y]=r[x];
    r[x]=y,l[y]=x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n, m, a, x, y;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        l[i]=i-1;
        r[i]=i+1;
    }
    r[n]=0;
    r[0]=1; // 虚拟头
    while(m--){
        cin>>a;
        if(a==1){
            cin>>x>>y;//x插y左侧
            if(x==y) continue;
            // 如果 x 已经在链表里，先摘除
            if(del[x]==false && (l[x]==true||r[x]==true)) {//x在链表中
                r[l[x]] = r[x];
                l[r[x]] = l[x];
            }
            add1(y,x);// 把 x 插到 y 左边
            del[x]=false;
        }
        else if(a==2){
            cin>>x>>y;
            if(x==y) continue;
            if(del[x]==false&&(l[x]==true||r[x]==true)) {
                r[l[x]]=r[x];
                l[r[x]]=l[x];
            }
            add2(y,x); // 把 x 插到 y 右边
            del[x]=false;
        }
        else if(a==3){
            cin>>x;
            if(del[x]) continue;
            r[l[x]]=r[x];
            l[r[x]]=l[x];
            del[x]=true;
        }
    }

    if(r[0]==0) cout<<"Empty!";
    else{
        int cur = r[0];
        while(cur != 0){
            cout << cur << " ";
            cur = r[cur];
        }
    }
    return 0;
}