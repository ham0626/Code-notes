#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x){//构造函数->初始化
        data=x;
        next=NULL;
    }
};
int len(Node* p){//链表长度
    int n=0;
    while(p){
        p=p->next;
        n++;
    }
    return n;
}
void show(Node* head){//链表遍历
    while(head){
        cout<<head->data<<" ";
        head=head->next;//指针移动
    }
    cout<<'\n';
}
Node* del(Node* head,int x){
    if(head==NULL) return NULL;//给野指针
    if(head->data==x){//删除头指针
        Node* t=head->next;
        head->next=t->next;
        delete t;
        return head;
    }
    Node* p=head;
    while(p->next){
        if(p->data==x){
            Node* q=p->next;
            p->next=q->next;
            delete q;//释放内存
            return head;
        }
        p=p->next;
    }
    return head;//当前元素不存在
}
Node* add(Node* head,int x,int y){
    Node* p=head;
    if(head->data==x){
        Node* q=p->next;
        Node* newNode=new Node(y);
        newNode->next=q;
        head->next=newNode;
        return head;
    }
    while(p->next){
        if(p->next->data==x){
            Node* q=p->next;
            Node* newNode=new Node(y);
            newNode->next=q->next;//和后面的连上
            q->next=newNode;//和前面的连上
        }
        p=p->next;
    }
    return head;
}
Node* query(Node* head,int x){
    Node* p=head;
    if(head->data==x){
        cout<<p->next->data<<'\n';
        return head;
    }
    while(p->next){
        if(p->next->data==x){
            Node* q=p->next;
            if(q->next!=NULL){
                cout<<q->next->data<<'\n';
            return head;
        }
        else{
            cout<<"0"<<'\n';
            return head;
        }
    }
    p=p->next;
    }
}
翻转链表
head(100)->2(在100，指向200)->4(在200，指向150)->6(在150，指向0)->NULL
NULL<-2(在100，指向0)<-4(在200，指向100)<-6(在150，指向200)<-head
迭代
Node* reverse(Node* head){
    if(head==NULL||head->next==NULL) return head;
    Node* cur=head;
    Node* prev=NULL;
    Node* nxt=head->next;
    while(cur!=NULL){
        cur->next=prev;
        prev=cur;
        cur=nxt;
        if(nxt!=NULL){
            nxt=nxt->next;
        }
    }
    return prev;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int q,a,x,y;
    cin>>q;
    Node* head=new Node(1);
    Node* tail=head;
    for(int i=2;i<=10;i++){
        tail->next=new Node(i); tail=tail->next;
    }
    head=reverse(head);
    show(head);
    for(int i=1;i<=q;i++){
        cin>>a;
        if(a==1){
            cin>>x>>y;
            add(head,x,y);
        }
        else if(a==2){
            cin>>x;
            query(head,x);
        }
        else{
            cin>>x;
            del(head,x);
        }
        continue;
    }
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// const int maxn = 1000005;
// int nxt[maxn];
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0),cout.tie(0);
//     nxt[1]=0;
//     int q,a,x,y;
//     cin>>q;
//     for(int i=1;i<=q;i++){
//         cin>>a;
//         if(a==1){
//             cin>>x>>y;
//             nxt[y]=nxt[x];
//             nxt[x]=y;
//         }
//         else if(a==2){
//             cin>>x;
//             cout<<nxt[x]<<'\n';
//         }
//         else {
//             cin>>x;
//             nxt[x] = nxt[nxt[x]];
//         }
//     }
//     return 0;
// }