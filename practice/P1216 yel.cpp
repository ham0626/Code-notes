#include<bits/stdc++.h>
using namespace std;
int n,cnt,num;
int ans[20];
//"/"x+y=2~12(2~2n) "\"x-y=-(n-1)~n
// (1,1) (1,2) (1,3) (1,4) (1,5) (1,6)
// (2,1) (2,2) (2,3) (2,4) (2,5) (2,6)
// (3,1) (3,2) (3,3) (3,4) (3,5) (3,6)
// (4,1) (4,2) (4,3) (4,4) (4,5) (4,6)
// (5,1) (5,2) (5,3) (5,4) (5,5) (5,6)
// (6,1) (6,2) (6,3) (6,4) (6,5) (6,6)
bool line[20],d1[40],d2[40];
void dfs(int x){//在放第一行
    if(x>n){
        cnt++;
        num++;
        if(num<=3){
            for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
            cout<<"\n";
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(line[i]==false&&d1[x-i+n]==false&&d2[i+x]==false){
            line[i]=true;
            d1[x-i+n]=true;
            d2[i+x]=true;
            ans[x]=i;
            dfs(x+1);//带着所有的true标记dfs下去
            line[i]=false;
            d1[x-i+n]=false;
            d2[i+x]=false;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    dfs(1);
    cout<<cnt;
    return 0;
}
