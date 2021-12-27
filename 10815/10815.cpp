#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

vector <int> v;
vector <int> v2;

int solve(int idx){
    int left = 0;
    int right = n-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(v2[idx] < v[mid]){
            right = mid-1;
        }
        else if(v2[idx] > v[mid]){
            left = mid+1;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int number;
        cin >> number;
        v.push_back(number);
    }
    sort(v.begin(),v.end());
    cin >> m;
    for(int i=0;i<m;i++){
        int number;
        cin >> number;
        v2.push_back(number);
    }
    for(int i=0;i<v2.size();i++){
        cout << solve(i) << " ";
    }
    return 0;
}