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
#define MAX 55
#define INF 1e9

using namespace std;
int N, A, B;
int MAP[MAX];
int answer = 0;

bool Calc(int X, int Y, int Z) {
	if ((Y - Z) % (X - Y) != 0) { // A�� ���⼭ ������ �����ȴٸ� B�� �����̴�.
		return false;
	}
	A = (Y - Z) / (X - Y);
	B = Y - (X * A);
	return true;
}

int new_Number() {
	return ((MAP[N - 1] * A) + B);
}

int main() {
	FIRST
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> MAP[i];
	}
	if (N == 1) {
		/*
			���ڰ� 1���� �־����� ��쿡�� ���� ���� �� �� ����. ������ ���� ���� ���� �� �� �����Ƿ� A�� ����Ѵ�.
		*/
		cout << "A" << "\n";
	}
	else if (N == 2) { // ���ڰ� 2���� �־����� ��
		if (MAP[0] == MAP[1]) { // �� ���� ���ٸ� ���� �� ���� �Ȱ��� ���̴�.
			cout << MAP[0] << "\n";
		}
		else { // ������ �� ���� �ٸ��ٸ� ���� ���� ���� �� ����.
			cout << "A" << "\n";
		}
	}
	else if (N >= 3) { // ���ڰ� 3�� �̻� �־��� ��
		if (MAP[0] == MAP[1]) { // �տ� �� ���� ������ 
			bool Flag = true;
			for (int i = 0; i < N; i++) {
				if (MAP[0] != MAP[i]) {
					Flag = false;
				}
			}
			if (Flag) { // i��° ���� ���� ��� 
				cout << MAP[0] << "\n";
			}
			else { // i��° ���� �ٸ� ��� �߸��� �Է��̴�.
				cout << "B" << "\n";
			}
		}
		else { // ���� �� ���� �ٸ� ���
			if (Calc(MAP[0], MAP[1], MAP[2])) { // A, B�� ������ �������� �� �������� üũ
				// A, B�� �������
				bool Flag = true;
				for (int i = 0; i < (N - 1); i++) { // ������ ��Ģ(�� �� * A + B == �� ��)��� ���ڵ��� �����ƴ��� üũ
					if ((MAP[i] * A) + B != MAP[i + 1]) {
						Flag = false; // �ƴ϶�� false
						break;
					}
				}
				if (Flag) { // N���� ���� ������ ��Ģ��� �����ƴٸ� N+1��° ���� ���Ѵ�.
					cout << new_Number() << "\n";
				}
				else { // ��Ģ��� �������� �ʾҴٸ� �߸��� �Է��̴�.
					cout << "B" << "\n";
				}
			}
			else { // A, B�� ������ �ƴ϶�� �߸��� �Է��̴�.
				cout << "B" << "\n";
			}
		}
	}

	getchar();
	getchar();
	return 0;
}