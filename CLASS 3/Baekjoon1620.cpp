#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;
int N, M; // ������ ���ϵǾ� �ִ� ���ϸ��� ����, ����� �ϴ� ������ ����
map<string, int> pokemon;
string result[100001];

// vector�� ������ ã���� �ð� �ʰ��� ���� map�� ����Ͽ���.
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	char name[21];
	for (int number = 0; number < N; number++) {
		cin >> name;
		string str = name;
		pokemon.insert(pair<string, int>(str, number + 1)); // key, value�� map�� ����
		result[number] = str; // ��ȣ�� ã�� ���Ͽ� ��ȣ������ �迭�� ���ϸ� �̸��� ����
	}
	char ques[21];
	for (int number = 0; number < M; number++) {
		cin >> ques;
		if ((int(ques[0]) >= 65) && (int(ques[0]) <= 90)) { // ������ ���ϸ� �̸��� ��
			cout << pokemon[ques] << "\n"; // �̸��� �ش��ϴ� value�� ���
		}
		else if ((int(ques[0]) >= 48) && (int(ques[0]) <= 57)) { // ������ ��ȣ�� ��
			string tmp = ques;
			cout << result[stoi(tmp) - 1] << "\n"; // ��ȣ - 1�� �ش��ϴ� ���ϸ� �̸� ���
		}
	}

	getchar();
	getchar();
	return 0;
}