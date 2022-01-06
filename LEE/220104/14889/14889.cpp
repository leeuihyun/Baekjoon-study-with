#include <iostream>
#include <cmath>

using namespace std;

int cases;

int arr[21][21];
bool team[21]; // 숫자가 true이면 start-team, false이면 link-team

int answer = 1101;

void solve(int cur,int cnt){
    if(cnt == cases/2){
        int start = 0;
        int link = 0;
        for(int i=1;i<=cases;i++){
            for(int j=1;j<=cases;j++){
                if(team[i]&&team[j]) start+=arr[i][j];
                if(!team[i]&&!team[j]) link+=arr[i][j];
            }
        }
        answer = min(answer,abs(start-link));
        return;
    }
    for(int i=cur;i<=cases;i++){
        team[i] = true;
        solve(i+1,cnt+1);
        team[i] = false;
    }
}

int main(){
    cin >>cases;
    for(int i=1;i<=cases;i++){
        for(int j=1;j<=cases;j++){
            cin >> arr[i][j];
        }
    }
    solve(1,0);
    cout << answer;
    return 0;
}