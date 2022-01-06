#include <iostream>
#include <vector>

using namespace std;

int board[10][10];//int board[81];
vector <pair<int,int>> v;
bool find_answer;

bool check(int x,int y){
    for(int i=0;i<9;i++){
        if(board[x][y] == board[x][i] && i!=y){
            return false;
        }
        if(board[x][y] == board[i][y] && i!=x){
            return false;
        }
    }
    for(int i=x/3*3;i<x/3*3+3;i++){
        for(int j=y/3*3;j<y/3*3+3;j++){
            if(board[x][y]==board[i][j] && i!=x && j!=y){
                return false;
            }
        }
    }
    return true;
}

void solve(int cur){
    if(find_answer) return;
    if(cur == v.size()){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        find_answer = true;
        return;
    }
    for(int i=1;i<=9;i++){
        int first = v[cur].first;
        int second = v[cur].second;
        board[first][second]=i;
        if(check(first,second)){
            solve(cur+1);
        }
        board[first][second] = 0;
    }
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> board[i][j];
            if(!board[i][j])v.push_back(make_pair(i,j));
        }
    }
    solve(0);
    return 0;
}