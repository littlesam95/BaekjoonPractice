#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;
int N, M; // 도감에 수록되어 있는 포켓몬의 개수, 맞춰야 하는 문제의 개수
map<string, int> pokemon;
string result[100001];

// vector로 일일히 찾으니 시간 초과가 떠서 map을 사용하였다.
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	char name[21];
	for (int number = 0; number < N; number++) {
		cin >> name;
		string str = name;
		pokemon.insert(pair<string, int>(str, number + 1)); // key, value를 map에 저장
		result[number] = str; // 번호로 찾기 위하여 번호순으로 배열에 포켓몬 이름을 저장
	}
	char ques[21];
	for (int number = 0; number < M; number++) {
		cin >> ques;
		if ((int(ques[0]) >= 65) && (int(ques[0]) <= 90)) { // 문제가 포켓몬 이름일 때
			cout << pokemon[ques] << "\n"; // 이름에 해당하는 value값 출력
		}
		else if ((int(ques[0]) >= 48) && (int(ques[0]) <= 57)) { // 문제가 번호일 때
			string tmp = ques;
			cout << result[stoi(tmp) - 1] << "\n"; // 번호 - 1에 해당하는 포켓몬 이름 출력
		}
	}

	getchar();
	getchar();
	return 0;
}