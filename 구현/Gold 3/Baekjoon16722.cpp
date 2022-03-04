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
	// �� �Ӽ� ���ΰ� ��� �������� ������.
	if ((X == Y) && (Y == Z) && (Z == X)) {
		return true;
	}
	return false;
}

bool All_Not_Same(string X, string Y, string Z) {
	// �� �Ӽ� ���ΰ� ��� �ٸ����� ������.
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
				// �� �Ӽ� ���ΰ� ���ų� ���� �ٸ� ��� true, �ƴϸ� false
				if ((!All_Same(Picture[i].S, Picture[j].S, Picture[k].S)) && (!All_Not_Same(Picture[i].S, Picture[j].S, Picture[k].S))) {
					Flag = false;
				}
				if ((!All_Same(Picture[i].C, Picture[j].C, Picture[k].C)) && (!All_Not_Same(Picture[i].C, Picture[j].C, Picture[k].C))) {
					Flag = false;
				}
				if ((!All_Same(Picture[i].B, Picture[j].B, Picture[k].B)) && (!All_Not_Same(Picture[i].B, Picture[j].B, Picture[k].B))) {
					Flag = false;
				}
				if (Flag) { // �� �Ӽ� ���ΰ� ���ų� ���� �ٸ� ��쿡�� �� �׸��� ���� �ȴ�.
					HAP.push_back({ i,j,k });
				}
			}
		}
	}
}

bool Find_HAP(int X, int Y, int Z) {
	for (int i = 0; i < HAP.size(); i++) {
		if ((HAP[i].A == X) && (HAP[i].B == Y) && (HAP[i].C == Z) && (!visited[i])) {
			// �̹� ã�� ���� �ٽ� ã���� �� �Ǳ� ������, ã�Ҵٴ� ǥ�ø� ���ش�.
			visited[i] = true;
			return true;
		}
	}
	return false;
}

bool Find_G() {
	for (int i = 0; i < HAP.size(); i++) {
		if (!visited[i]) { // �ϳ��� ã�� ���� ���� �ִٸ� false�� return�Ѵ�.
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
	Picture_Setting(); // �켱 9���� �׸��� ���ǿ� ���缭 ������ �����ش�.
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
			if (b) { // ��ģ ��ȣ�� �׸� �� ���� ���̶�� ����+1
				answer += 1;
			}
			else { // �ƴ϶�� ����-1
				answer -= 1;
			}
		}
		else if (A == "G") {
			bool b = Find_G();
			if (b && !G_Flag) { // ���� �� ã��, ���� ��ġ�鼭 3���� ���� ���� ���ٸ� ����+3
				G_Flag = true;
				answer += 3;
			}
			else { // �װ� �ƴ϶�� ����-1
				answer -= 1;
			}
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}