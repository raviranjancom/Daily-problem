#include<iostream>
#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;

class node{
  public:
    int data;
    int height;
    node *left, *right;

    node(int v){
      data=v;
      left=right=nullptr;
    }
};

node *create(){
    queue<node *> q;
    cout<<"Enter root node = ";
    int v;
    cin>>v;
    node *root=new node(v);
    q.push(root);
    while(!q.empty()){
      node *t=q.front();
      q.pop();
      cout<<"Enter the left child = ";
      cin>>v;
      if(v!=-1){
	      node *leftnode=new node(v);
        t->left=leftnode;
        q.push(leftnode);
      }
      cout<<"Enter the right child = ";
      cin>>v;
      if(v!=-1){
        node *rightnode=new node(v);
        t->right=rightnode;
        q.push(rightnode);
      }
   }
  return root;
}

void Inorder(node *r){
  if(r){
    Inorder(r->left);
    cout<<r->data<<" ";
    Inorder(r->right);
  }
}

void preorder(node *r){
  if(r!=nullptr){
    cout<<r->data<<" ";
    preorder(r->left);
    preorder(r->right);
  }
}

void Ipreorder(node* r){
  stack<node *> st;
  while(r || !st.empty()){
    if(r){
      cout<<r->data<<" ";
      st.push(r);
      r=r->left;
    }
    else{
      r=st.top();
      st.pop();
      r=r->right;
    }
  }
}

void IInorder(node *r){
    stack<node *> st;
    while(r || !st.empty()){
        if(r){
            st.push(r);
            r=r->left;
        }
        else{
            r=st.top();
            st.pop();
            cout<<r->data<<" ";
            r=r->right;
        }
    }
}

void Ilevelorder(node *r){
  queue<node *> q;
  q.push(r);
  while(!q.empty()){
    node *t=q.front();
    q.pop();
    cout<<t->data<<" ";
    if(t->left) q.push(t->left);
    if(t->right) q.push(t->right);
  }
}

int countnode(node* r){
  if(r==nullptr) return 0;
  int x=countnode(r->left);
  int y=countnode(r->right);
  return x+y+1;
}

int value(node* r){
  if(r==nullptr) return 0;
  int x=value(r->left);
  int y=value(r->right);
  return x+y+r->data;
}

int binarynode(node *r){
  if(r==nullptr) return 0;
  if(r->left && r->right) return binarynode(r->left) + binarynode(r->right) + 1;
}

int height(node* r){
  if(r==nullptr) return 0;
  int x=height(r->left);
  int y=height(r->right);
  if(x>y) return x+1;
  else return y+1;
}

int leafnode(node* r){
  if(r==nullptr) return 0;
  if(!r->left && !r->right){
    return 1;
  }
  return leafnode(r->left) + leafnode(r->right);
}

bool BIsearch(node* r, int key){
  while(r){
    if(r->data==key) return true;
    else if(r->data<key){
      r=r->right;
    }
    else{
      r=r->left;
    }
  }
  return false;
}

bool BRsearch(node *r, int key){
  if(r==nullptr){
    return false;
  }
  else if(r->data==key) return true;
  else if(r->data<key){
    return BRsearch(r->right,key);
  }
  else{
    return BRsearch(r=r->left,key);
  }
}

node *Binsert(node* r,int key){
  node *t=new node(key),*root=r;
  if(r==nullptr) return t;
  node *last=r;
  while(r){
    if(r->data>key){
      last=r;
      r=r->left;
    }
    else{
      last=r;
      r=r->right;
    }
  }
  if(r==nullptr){
    if(last->data>key){
      last->left=t;
    }
    else{
      last->right=t;
    }
  }
  return root;
}

node* RBinsert(node *r, int key){
  if(r==nullptr){
    node* temp=new node(key);
    return temp;
  }
  else if(r->data>key){
    node* t=RBinsert(r->left,key);
    if(r->data>t->data){
      r->left=t;
      return r;
    }
    else{
      r->right=t;
      return r;
    }
  }
  else{
    node *t=RBinsert(r->right,key);
    if(r->data>t->data){
      r->left=t;
      return r;
    }
    else{
      r->right=t;
      return r;
    }
  }
}

node *inorderpredecesor(node *r){
  r=r->left;
  while(r->right){
    r=r->right;
  }
  return r;
}

node *Bdelete(node *r, int key){
  if(r==nullptr){
    return nullptr;
  }
  else if(!r->left && !r->right && r->data==key){
    delete r;
    return nullptr;
  }
  else if((!r->left && r->right && r->data==key) || (r->left && !r->right && r->data==key)){
    return (r->left)?r->left:r->right;
  }
  else if(key < r->data){
    r->left=Bdelete(r->left,key);
  }
  else if(key > r->data){
    r->right=Bdelete(r->right,key);
  }
  else{
    node * p=inorderpredecesor(r);
    r->data=p->data;
    r->left=Bdelete(r->left,p->data);
  }
  return r;
}

node* bst_from_preorder(vector<int> arr){
  node *root=nullptr;
  stack<node *> st;
  if(root==nullptr){
    root=new node(arr[0]);
  }
  unsigned i=1;
  node *last=root;
  while(!st.empty() || i<arr.size()){
    if(last->data > arr[i]){
      node *t=new node(arr[i]);
      st.push(last);
      last->left=t;
      st.push(last);
      last=t;
      i++;
    }
    else if(st.empty()){
      node *t=new node(arr[i]);
        last->right=t;
        last=t;
        i++;
    }
    else{
      node *x=st.top();
      if(x->data > arr[i]){
        node *t=new node(arr[i]);
        last->right=t;
        last=t;
        i++;
      }
      else{
        last=x;
        st.pop();
      }
    }
  }
  return root;
}

int calculateHeight(node *r){
  int x=(r && r->left)?r->left->height:0;
  int y=(r && r->right)?r->right->height:0;

  return (x>y)?x+1:y+1;
}

int balancefactor(node *r){
  return calculateHeight(r->left) - calculateHeight(r->right);
}

node *LLrotation(node *r){
  node *rl=r->left;
  r->left=r->left->right;
  rl->right=r;
  r->height=calculateHeight(r);
  rl->height=calculateHeight(rl);
  return rl;
}

node *LRrotation(node *r){
  node* rl=r->left,*rlr=r->left->right;
  rl->right=rlr->left;
  rlr->left=rl;
  r->left=rlr;
  r->height=calculateHeight(r);
  rl->height=calculateHeight(rl);
  rlr->height=calculateHeight(rlr);
  return LLrotation(r);
}

node *RRrotation(node *r){
  node* rr=r->right;
  r->right=rr->left;
  rr->left=r;
  r->height=calculateHeight(r);
  rr->height=calculateHeight(rr);
  return rr;
}

node *RLrotation(node *r){
  node* rr=r->right, *rrl=r->right->left;
  rr->left=rrl->right;
  rrl->right=rr;
  r->right=rrl;
  r->height=calculateHeight(r);
  rrl->height=calculateHeight(rrl);
  rr->height=calculateHeight(rr);
  return RRrotation(r);
}

node *InsertAVL(node *root, int key){
  if(!root){
    node *t=new node(key);
    t->height=1;
    return t;
  }
  else if(key > root->data){
    root->right=InsertAVL(root->right, key);
  }
  else if(key < root->data){
    root->left=InsertAVL(root->left, key);
  }
  root->height=calculateHeight(root);

  if(balancefactor(root)==2 && balancefactor(root->left)==1){
    // LL rotation
    return LLrotation(root);
  }
  else if(balancefactor(root)==2 && balancefactor(root->left)==-1){
    // LR rotation
    return LRrotation(root);
  }
  else if(balancefactor(root)==-2 && balancefactor(root->right)==1){
    // RL rotation
    return RLrotation(root);
  }
  else if(balancefactor(root)==-2 && balancefactor(root->right)==-1){
    // RR rotation
    return RRrotation(root);
  }

  return root;
}

int main(){
  node* r=nullptr;

  vector<int> v={100, 20, 150, 120, 200, 250};
  // vector<int> arr={30 ,20, 10, 25, 40, 35, 38, 45, 42, 43};
  // node *p=bst_from_preorder(arr);
  for(unsigned i=0;i<v.size();i++){
    r=InsertAVL(r,v[i]);
  }
  Ilevelorder(r);
  return 0;
}
