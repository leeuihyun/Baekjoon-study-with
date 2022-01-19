#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n,m;
vector<int> v;
int max_num;

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int number;
        cin >> number;
        v.push_back(number);
        max_num = max(max_num, v[i]);
    }
    int start = 0;
    int end = max_num;
    int result = 0;
    while(start <= end){
        long long sum = 0;
        int mid = (start+end)/2;
        for(int i=0;i<n;i++){
            if(v[i] > mid) sum+=v[i]-mid; 
        }
        if(sum < m){
            end = mid-1;
        }
        else{
            start = mid+1;
            result = max(result,mid);
        }
    }
    cout << result;
    return 0;
}