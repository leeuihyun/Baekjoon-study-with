#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

#define MAX_NUMBER 4000000
using namespace std;

int number;
int answer;

int arr[MAX_NUMBER+1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=2;i<=MAX_NUMBER;i++) arr[i]=i;
    for(int i=2;i<=sqrt(MAX_NUMBER);i++){
        if(arr[i]==0)continue;
        for(int j=i+i;j<=MAX_NUMBER;j+=i){
            arr[j] = 0;
        }
    }
    cin >> number;
    if(number==1){
        cout << 0 << endl;
        exit(0);
    }
    
        for(int i=2;i<=number;i++){
            if(!arr[i]) continue;
            int sum = 0;
            for(int j=i;j<=number;j++){
                if(!arr[j])continue;
                sum += arr[j];
                if(sum > number) break;
                else if(sum==number){
                    answer+=1;
                    break;
                }
            }
        }
    
    cout << answer;
    return 0;
}