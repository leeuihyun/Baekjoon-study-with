#include <iostream>
#include <vector>
#include <map>

using namespace std;

map <long, long> maps;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n;
	for (long long i = 0; i < n; i++) {
		long long number;
		cin >> number;
		maps[number] += 1;
	}
	cin >> m;
	for (long long i = 0; i < m; i++) {
		long long number;
		cin >> number;
		cout << maps[number] << " ";
	}
	return 0;
}