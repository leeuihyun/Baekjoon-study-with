#include <iostream>
#include <algorithm>

using namespace std;

int cases;

int dp[501][501];
int answer;
int main(){
    cin >> cases;
    for(int i=0;i<cases;i++){
        for(int j=0;j<=i;j++){
            cin >> dp[i][j];
        }
    }
    for(int i=1;i<cases;i++){
        for(int j=0;j<=i;j++){
            if(j!=0 || j!=i){
                dp[i][j] += max(dp[i-1][j],dp[i-1][j-1]);
            }
            else{
                dp[i][j]+=dp[i-1][j];
            }
        }
    }
    for(int i=0;i<cases;i++){
        answer = max(answer,dp[cases-1][i]);
    }
    cout <<answer;
    return 0;
}