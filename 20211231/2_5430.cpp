#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#define SWAP(x, y, z) (z = x, x = y, y = z)
using namespace std;
int T, N;
string p;

vector<string> result;

void AC_function(string f, string data) {
	bool direction = true;

	data.pop_back();
	data.erase(data.begin());
	string stringBuffer;
	vector<string> x;
	istringstream ss(data);

	while (getline(ss, stringBuffer, ',')) {
		x.push_back(stringBuffer);
	}
	int size = x.size();

	for(int i = 0; i < f.size(); i++) {
		if (f[i] == 'R') {
			direction = !direction;
		}
		else if (f[i] == 'D') {
			if (size == 0) {
				result.push_back("error");
				break;
			}
			else {
				if (direction)
					x.erase(x.begin());
				else
					x.pop_back();
				size--;
			}
		}
	}

	if (size > 0) {
		string tmp = "[";
		if (direction) {
			for (int i = 0; i < size - 1; i++)
				tmp = tmp + x.at(i) + ",";
			tmp = tmp + x.back() + "]";
		}
		else {
			for (int i = size - 1; i > 0; i--)
				tmp = tmp + x.at(i) + ",";
			tmp = tmp + x.front() + "]";
		}
		result.push_back(tmp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> p;
		cin >> N;
		string data;
		cin >> data;
		AC_function(p, data);
	}

	for (int i = 0; i < T; i++) {
		cout << result.at(i) << "\n";
	}

	return 0;
}