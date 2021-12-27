#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector <int> v;
vector <int> answer;

long long solve(int number){
    int left = 0;
    int right = n-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(number < v[mid]){
            right = mid-1;
        }
        else if(number > v[mid]){
            left = mid+1;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int main(){
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
        answer.push_back(number);
    }
    for(int i=0;i<answer.size();i++){
        cout << solve(answer[i]) << "\n";
    }
    return 0;
}