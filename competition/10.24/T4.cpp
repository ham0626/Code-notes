#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m;
long long suma,sumb,sumc;
int a[maxn],b[maxn],c[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],suma+=a[i];
    for(int i=1;i<=n;i++) cin>>b[i],sumb+=b[i];
    for(int i=1;i<=n;i++) cin>>c[i],sumc+=c[i];
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int x,y,z;
            cin>>x>>y>>z;
            for(int i=1;i<=n;i++){
                if(a[i]==x){
                    suma=suma-a[i]+x;
                    sumb=sumb-b[i]+y;
                    sumc=sumc-c[i]+z;
                    a[i]=x,b[i]=y,c[i]=z;
                }
            }
        }
        else if(op==2){
            int x,y,z;
            cin>>x>>y>>z;
            for(int i=1;i<=n;i++){
                if(b[i]==x){
                    suma=suma-a[i]+y;
                    sumb=sumb-b[i]+x;
                    sumc=sumc-c[i]+z;
                    a[i]=y,b[i]=x,c[i]=z;
                }
            }
        }
        else{
            int x,y,z;
            cin>>x>>y>>z;
            for(int i=1;i<=n;i++){
                if(c[i]==x){
                    suma=suma-a[i]+y;
                    sumb=sumb-b[i]+z;
                    sumc=sumc-c[i]+x;
                    a[i]=y,b[i]=z,c[i]=x;
                }
            }
        }
        cout<<suma<<" "<<sumb<<" "<<sumc<<'\n';
    }
    return 0;
}