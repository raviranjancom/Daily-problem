#include<bits/stdc++.h>
using namespace std;
class tree{
    public:
        int data;
        tree *left;
        tree *right;
        queue<tree *> q;
};
int count_nodes(tree *r){
    if(r){
        int x=count_nodes(r->left);
        int y=count_nodes(r->right);
        return x+y+1;
    }
    return 0;
}
int count_leaf_nodes(tree *r){
    if(r){
        int x=count_leaf_nodes(r->left);
        int y=count_leaf_nodes(r->right);
        if(!r->left && !r->right){
            return x+y+1;
        }
        else return x+y;
    }
    return 0;
}
int node_sum(tree *r){
    if(r){
        int x=node_sum(r->left);
        int y=node_sum(r->right);
        return x+y+r->data;
    }
    return 0;
}
int question(tree *r){ //height_count
    if(r){
        int x=question(r->left);
        int y=question(r->right);
        if(x>y) return x+1;
        else return y+1;
    }
    return 0;
}
tree *create(tree *p){
    p=new tree;
    cout<<"Enter root =";
    cin>>p->data;
    p->left=p->right=NULL;
    p->q.push(p);
    while(!p->q.empty()){
        int v;
        tree *r=p->q.front();
        p->q.pop();

        cout<<"Enter the left =";
        cin>>v;
        if(v!=-1){
            tree * t=new tree; 
            t->data=v;
            t->left=t->right=NULL;
            r->left=t;
            p->q.push(t);
        }

        cout<<"Enter the right =";
        cin>>v;
        if(v!=-1){
            tree * t=new tree;
            t->data=v;
            t->left=t->right=NULL;
            r->right=t;
            p->q.push(t);
        }
    }
    return p;
}
void preorder(tree *p){
    if(p){
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(tree *p){
    if(p){
        postorder(p->left);
        postorder(p->right);
        cout<<p->data<<" ";
    }
}
void inorder(tree *p){
    if(p){
        inorder(p->left);
        cout<<p->data;
        inorder(p->right);
    }
}
void loop_preorder(tree *p){
    stack<tree *> st;
    tree *t=p;
    
    while(!st.empty() || t){
        if(t){
            cout<<t->data<<" ";
            st.push(t);
            t=t->left;
        }
        else{
            t=st.top();
            st.pop();
            t=t->right;
        }
    }
}
void levelorder(tree *p){
    queue<tree *> q;
    q.push(p);
    while(!q.empty()){
        p=q.front();
        q.pop();
        cout<<p->data<<" ";
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
}
int main(){
    tree *root=nullptr;
    root=create(root);
    //system("cls");
    cout<<node_sum(root);
}
