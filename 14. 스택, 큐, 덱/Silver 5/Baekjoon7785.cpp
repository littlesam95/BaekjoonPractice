#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int get_array_size(char arr[]) {
	return sizeof arr / sizeof arr[0];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	map<string, bool> m;
	vector<string> vec;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str, str2;
		cin >> str >> str2;
		if (m.count(str)) {
			if (str2 == "enter") {
				m[str] = true;
			}
			else {
				m[str] = false;
			}
			continue;
		}
		vec.push_back(str);
		m[str] = true;
	}

	sort(vec.begin(), vec.end(), greater<string>());
	int size = vec.size();
	for (int i = 0; i < size; i++) {
		if (m[vec[i]]) {
			cout << vec[i] << "\n";
		}
	}

	getchar();
	getchar();
	return 0;

}