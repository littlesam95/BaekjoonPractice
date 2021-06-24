#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string S;

int main() {
	getline(cin, S);
	char arr[4] = { 'U','C','P','C' };
	int idx = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == arr[idx]) {
			idx++;
		}
	}
	if (idx == 4) {
		cout << "I love UCPC" << "\n";
	}
	else {
		cout << "I hate UCPC" << "\n";
	}

	getchar();
	getchar();
	return 0;
}