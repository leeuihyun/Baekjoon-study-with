#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <int> v;

int cases;
int answer;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> cases;
    for(int i=0;i<cases;i++){
        int number;
        cin >> number;
        v.push_back(number);
    }
    cin >> answer;
    int left,right;
    left = 1;
    right = *max_element(v.begin(),v.end());
    int res=0;

    while(left<=right){
        int mid = (left+right)/2;
        int sum = 0;
        for(int i=0;i<v.size();i++){
            if(v[i] > mid){
                sum+=mid;
            }
            else
                sum+=v[i];
        }
        if(sum > answer){
            right = mid-1;
        }
        else{
            res = max(res,mid);
            left = mid+1;
        }
    }
    cout << res;
    return 0;
}