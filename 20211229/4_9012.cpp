#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string A(string vps) {
	int top = 0;
	for (int i = 0; i < vps.size(); i++) {
		if (vps[i] == '(')
			top++;
		else
			top--;
		if (top < 0)
			return "NO";
	}

	if (top == 0)
		return "YES";
	else
		return "NO";
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T;
	vector<string> vps;
	vector<string> result;

	cin >> T;

	for (int i = 0; i < T; i++) {
		string data;
		cin >> data;
		vps.push_back(data);
		result.push_back(A(vps.at(i)));
	}

	for (int i = 0; i < T; i++) {
		cout << result.at(i) << "\n";
	}

	return 0;
}