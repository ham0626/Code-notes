#include<bits/stdc++.h>
using namespace std;
void hanoi(int n,char from,char to,char thr){
    if(n==0) return;
    hanoi(n-1,from,thr,to);
    cout<<n<<" "<<from<<" -> "<<to<<'\n';
    hanoi(n-1,thr,to,from);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    hanoi(n,'A','C','B');
    return 0;
}