#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cases;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> cases;
    while(cases--){
        int answer;
        int size;
        int idx;
        queue <pair<int,int>> q;
        priority_queue <int> pq;
        cin >> size >> idx;
        for(int i=0;i<size;i++){
            int number;
            cin >> number;
            q.push(make_pair(i,number));    
            pq.push(number);       
        }
        int count = 1;
        while(!q.empty()){
            int first = q.front().first;
            int second = q.front().second;
            q.pop();
            if(second != pq.top()){                
                q.push({first,second});    
            }
            else{
                pq.pop();
                if(first==idx){
                    answer = count;
                    break;
                }
                else{
                    count+=1;
                }      
            }
        }
        cout << answer << "\n";
    }
    
    return 0;
}