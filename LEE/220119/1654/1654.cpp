#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int n,m;
vector<long long> v;
long long max_number;

int main(){
    std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        long long number;
        cin >> number;
        v.push_back(number);
        max_number = max(max_number, v[i]);
    }
    long long start = 1;
    long long end = max_number;
    long long answer;

    while(start<=end){
        long long mid = (start+end)/2;
        long long sum = 0;
        for(int i=0;i<n;i++){
            if(v[i] >= mid)  sum += v[i]/mid;
        }
        if(sum >= m){
            start = mid+1;
            answer = max(answer, mid);
        }
        else{
            end=mid-1;   
        }
    }
    cout << answer;

    return 0;
}