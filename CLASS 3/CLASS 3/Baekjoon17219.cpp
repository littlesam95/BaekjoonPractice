#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;
int N, M;
map<string, string> password;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	char url[21];
	char pass[21];
	for (int i = 0; i < N; i++) {
		cin >> url >> pass;
		string tmp = url;
		string tmp2 = pass;
		password.insert(pair<string, string>(tmp, tmp2)); // ����Ʈ �ּҿ� ��й�ȣ�� map���� insert
	}

	char url2[21];
	for (int i = 0; i < M; i++) {
		cin >> url;
		string tmp = url;
		cout << password[tmp] << "\n"; // ����Ʈ �ּ�(key��)�� ��й�ȣ(value��)�� ã�´�.
	}

	getchar();
	getchar();
	return 0;
}