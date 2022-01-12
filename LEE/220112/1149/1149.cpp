#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int cases;
int arr[1001][3];

int main(){
    cin >>cases;
    for(int i=0;i<cases;i++){
        for(int j=0;j<3;j++){
            cin >>arr[i][j];
        }
    }

    for(int i=1;i<cases;i++){
        arr[i][0] += min(arr[i-1][1],arr[i-1][2]);
        arr[i][1] += min(arr[i-1][0],arr[i-1][2]);
        arr[i][2] += min(arr[i-1][1],arr[i-1][0]);
    }

    int answer = INT_MAX;
    for(int i=0;i<3;i++){
        answer = min(answer,arr[cases-1][i]);
    }

    cout <<answer;
}