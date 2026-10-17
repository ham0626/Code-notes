#include<bits/stdc++.h>
using namespace std;
int len,n;
int d[200010];
struct node{
    int sou,nor;
}city[200010];
bool comp(node x,node y){
    return x.sou<y.sou;//x在y前面
}
/*!!关于二分的d[mid]<x的等号问题
    以d数组升序为例：
    我们要寻找第一个>=x的位置进行插入
    1.等号放在if里：
    if(d[mid]>=x) r=mid-1;
    else l=mid+1;(l减很容易越界，可以这么记)
    d[mid]==x时进入if 这个相同元素会被r卡掉=>严格单增
    2.等号放在else里：
    if(d[mid]>x) r=mid-1;
    else l=mid+1;(l=mid-1很容易越界，可以这么记)
    d[mid]==x时进入else 这个相同元素不会被r卡掉=>单调不减
*/
int find_pos(int x){
    int l=0,r=len-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(d[mid]<x) l=mid+1;
        else r=mid-1;//严格增
    }
    return l;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>city[i].sou>>city[i].nor;
    sort(city,city+n,comp);
    for(int i=0;i<n;i++){
        int temp=find_pos(city[i].nor);
        d[temp]=city[i].nor;
        if(temp==len) len++;//插最后了 
    }
    cout<<len;
    return 0;
}