#include <iostream>

using namespace std;

int N;

int arr[15];
int answer = 0;

bool check(int cur){
    for(int i=0;i<cur;i++){
        if(arr[i]==arr[cur] || cur-i == abs(arr[cur]-arr[i])){
            return false;
        }
    }
    return true;
}

void solve(int cur){
    if(cur==N){
        answer+=1;
        return;
    }
    for(int i=0;i<N;i++){
        arr[cur] = i;
        if(check(cur)){
            solve(cur+1);
        }
        else{
            arr[cur] = 0;
        }
    }
}

int main(){
    cin >> N;
    solve(0);
    cout << answer;
    return 0;
}