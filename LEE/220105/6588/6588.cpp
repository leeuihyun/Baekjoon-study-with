#include <iostream>
#include <cmath>
#define MAX_NUM 1000000

using namespace std;

int number;
int arr[MAX_NUM+1];

int main(){
    for(int i=2;i<=MAX_NUM;i++)arr[i] = i;
    for(int i=2;i<=MAX_NUM;i++){
        if(!arr[i])continue;
        for(int j=i+i;j<=MAX_NUM;j+=i){
            arr[j]=0;
        }
    }
    arr[2] = 0;
    while(true){
        scanf("%d", &number);
        if(number==0) break;
        for(int i=3;i<number;i++){
            if(arr[i] && arr[number-i]){
                printf("%d = %d + %d\n", number,i,number-i);
                break;
            } 
        }   
    }
    return 0;
}