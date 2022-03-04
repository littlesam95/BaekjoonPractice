#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 500
#define INF 1e9

using namespace std;
struct INFO {
	string S, C, B;
};

struct GROUP {
	int A, B, C;
};

int N;
vector<INFO> Picture;
vector<GROUP> HAP;
bool G_Flag = false;
bool visited[MAX];
int answer = 0;

bool All_Same(string X, string Y, string Z) {
	// 세 속성 전부가 모두 같은지를 따진다.
	if ((X == Y) && (Y == Z) && (Z == X)) {
		return true;
	}
	return false;
}

bool All_Not_Same(string X, string Y, string Z) {
	// 세 속성 전부가 모두 다른지를 따진다.
	if ((X != Y) && (Y != Z) && (Z != X)) {
		return true;
	}
	return false;
}

void Picture_Setting() {
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			for (int k = j + 1; k < 9; k++) {
				bool Flag = true;
				// 세 속성 전부가 같거나 전부 다른 경우 true, 아니면 false
				if ((!All_Same(Picture[i].S, Picture[j].S, Picture[k].S)) && (!All_Not_Same(Picture[i].S, Picture[j].S, Picture[k].S))) {
					Flag = false;
				}
				if ((!All_Same(Picture[i].C, Picture[j].C, Picture[k].C)) && (!All_Not_Same(Picture[i].C, Picture[j].C, Picture[k].C))) {
					Flag = false;
				}
				if ((!All_Same(Picture[i].B, Picture[j].B, Picture[k].B)) && (!All_Not_Same(Picture[i].B, Picture[j].B, Picture[k].B))) {
					Flag = false;
				}
				if (Flag) { // 세 속성 전부가 같거나 전부 다른 경우에만 세 그림은 합이 된다.
					HAP.push_back({ i,j,k });
				}
			}
		}
	}
}

bool Find_HAP(int X, int Y, int Z) {
	for (int i = 0; i < HAP.size(); i++) {
		if ((HAP[i].A == X) && (HAP[i].B == Y) && (HAP[i].C == Z) && (!visited[i])) {
			// 이미 찾은 합은 다시 찾으면 안 되기 때문에, 찾았다는 표시를 해준다.
			visited[i] = true;
			return true;
		}
	}
	return false;
}

bool Find_G() {
	for (int i = 0; i < HAP.size(); i++) {
		if (!visited[i]) { // 하나라도 찾지 않은 합이 있다면 false를 return한다.
			return false;
		}
	}
	return true;
}

int main() {
	FIRST
	for (int i = 0; i < 9; i++) {
		string S, C, B;
		cin >> S >> C >> B;
		Picture.push_back({ S,C,B });
	}
	Picture_Setting(); // 우선 9개의 그림을 조건에 맞춰서 합으로 묶어준다.
	cin >> N;
	for (int i = 0; i < N; i++) {
		string A;
		cin >> A;
		if (A == "H") {
			int X, Y, Z;
			cin >> X >> Y >> Z;
			int tmp[3] = { X,Y,Z };
			sort(tmp, tmp + 3);
			bool b = Find_HAP(tmp[0] - 1, tmp[1] - 1, tmp[2] - 1);
			if (b) { // 외친 번호의 그림 세 장이 합이라면 점수+1
				answer += 1;
			}
			else { // 아니라면 점수-1
				answer -= 1;
			}
		}
		else if (A == "G") {
			bool b = Find_G();
			if (b && !G_Flag) { // 합을 다 찾고, 결을 외치면서 3점을 받은 적이 없다면 점수+3
				G_Flag = true;
				answer += 3;
			}
			else { // 그게 아니라면 점수-1
				answer -= 1;
			}
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}