#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;

int N;
string sequence;
bool flag = false;

bool check(string s) {
	int length = s.length();

	for (int i = 1; i <= length / 2; i++) {
		if (s.substr(length - i * 2, i) == s.substr(length - i))
			return false;
	}
	return true;
}

void good_sequence(string s) {
	if (flag) return;

	if (s.length() == N) {
		sequence = s;
		flag = true;
		return;
	}
	for (char i = '1'; i <= '3'; i++) {
		if (check(s + i))
			good_sequence(s + i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	string tmp = "1";

	good_sequence(tmp);

	cout << sequence;

	return 0;
}