#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int arr[10000001];
int n,m;
vector <int> v;
int main(){
    for(int i=2;i<=10000000;i++)arr[i] = i;
    for(int i=2;i<sqrt(10000000);i++){
        if(arr[i]==0) continue;
        for(int j=i+i;j<=10000000;j+=i){
            arr[j] = 0;
        }
    }
    cin >> n >> m;
    for(int i=n;i<=m;i++){
        if(arr[i]) cout << i << "\n";
    }
    return 0;
}