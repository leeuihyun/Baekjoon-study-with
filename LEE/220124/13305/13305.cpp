#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
#include<vector>

using namespace std;
long long int road_length[100001];
long long int oil_price[100001];

int number; // 도시의 개수

int main() {
	long long int result = 0;
	long long int max = 1000000001;
	scanf("%d", &number);
	for (int i = 0; i < number - 1; i++)
		scanf("%lld", &road_length[i]);
	for (int i = 0; i < number; i++)
		scanf("%d", &oil_price[i]);
	for (int i = 0; i < number-1; i++) {
		max = max > oil_price[i] ? oil_price[i] : max;
		result += max * road_length[i];
	}
	printf("%lld", result);
	return 0;
}