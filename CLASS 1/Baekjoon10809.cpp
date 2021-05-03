#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
	string S;
	getline(cin, S);
	int len = S.length();
	char arr[100];
	strcpy_s(arr, S.c_str());
	for (int i = 0; i < len; i++) {
		if ((int(arr[i]) < 97) || ((int(arr[i]) > 122))) {
			exit(0);
		}
	}

	int alpha[26];
	for (int i = 0; i < 26; i++) {
		alpha[i] = -1;
		for (int j = 0; j < len; j++) {
			if ((char)(i + 97) == arr[j]) {
				alpha[i] = j;
				break;
			}
		}
		if (i < 25) {
			cout << alpha[i] << " ";
		}
		else if (i == 25) {
			cout << alpha[i];
		}
	}


	getchar();
	getchar();
	return 0;
}