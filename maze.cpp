#include<bits/stdc++.h>
using namespace std;
void maze(int cr, int cc, int er, int ec, string ans, vector<vector<int>> v){
    if(cr==er && cc==ec) cout<<ans<<endl;
    if(cr>er || cr<0 || cc<0 || cc>ec || v[cr][cc]==0) return ;

    v[cr][cc]=0;
    ans.push_back('R');
    maze(cr+1, cc, er, ec, ans, v);
    ans.pop_back();

    ans.push_back('L');
    maze(cr-1, cc, er, ec, ans, v);
    ans.pop_back();

    ans.push_back('U');
    maze(cr, cc-1, er, ec, ans, v);
    ans.pop_back();

    ans.push_back('D');
    maze(cr, cc+1, er, ec, ans, v);
    ans.pop_back();

    v[cr][cc]=1;
}
int main(){
    vector<vector<int>> v={{1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1}};
    maze(0, 0, 3, 3, "", v);
}
