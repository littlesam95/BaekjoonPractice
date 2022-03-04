#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define LL long long
#define INF 1e9

using namespace std;
int N;
bool Flag;
vector<string> Query;
vector<LL> Stack;

void init() { // ��ɾ �����ϴ� vector �ʱ�ȭ
	Flag = true;
	Query.clear();
}

bool Command_Play() {
	for (int i = 0; i < Query.size(); i++) {
		string cmd = Query[i];
		int size = Stack.size();
		if (cmd.substr(0, 3) == "NUM") {
			// X�� ������ ���� ���� �����Ѵ�.
			LL X = stoll(cmd.substr(4));
			Stack.push_back(X);
		}
		else if (cmd == "POP") {
			// ���� ���� ���� ���ڸ� �����Ѵ�. ������ ����ִµ� �� ��ɾ ���´ٸ� �����̴�.
			if (Stack.size() > 0) {
				Stack.erase(Stack.begin() + (size - 1));
			}
			else {
				return false;
			}
		}
		else if (cmd == "INV") {
			// ���� ���� ���� ������ ��ȣ�� �ٲ۴�. ������ ����ִµ� �� ��ɾ ���´ٸ� �����̴�.
			if (Stack.size() > 0) {
				Stack[size - 1] = -Stack[size - 1];
			}
			else {
				return false;
			}
		}
		else if (cmd == "DUP") {
			// ���� ���� ���� ���ڸ� �ϳ� �� ���ÿ� �����Ѵ�. ������ ����ִµ� �� ��ɾ ���´ٸ� �����̴�.
			if (Stack.size() > 0) {
				Stack.push_back(Stack[size - 1]);
			}
			else {
				return false;
			}
		}
		else if (cmd == "SWP") {
			// ù ��°�� �� ��° ���ڸ� �ٲ۴�. ���ÿ� ���ڰ� 1�� ������ �� �� ��ɾ ���´ٸ� �����̴�.
			if (Stack.size() >= 2) {
				LL tmp = Stack[size - 1];
				Stack[size - 1] = Stack[size - 2];
				Stack[size - 2] = tmp;
			}
			else {
				return false;
			}
		}
		else if (cmd == "ADD") {
			// ù ��°�� �� ��° ���ڸ� ���Ѵ�. ���ÿ� ���ڰ� 1�� ������ �� �� ��ɾ ���´ٸ� �����̴�.
			if (Stack.size() >= 2) {
				LL A = Stack[size - 1];
				LL B = Stack[size - 2];
				Stack.erase(Stack.begin() + (size - 1));
				Stack.erase(Stack.begin() + (size - 2));
				if (abs(B + A) <= INF) {
					// ���� ����� ������ 10^9�� �Ѿ�ٸ� �����̴�.
					Stack.push_back(B + A);
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else if (cmd == "SUB") {
			// ù ��°�� �� ��° ���ڸ� ����. ���ÿ� ���ڰ� 1�� ������ �� �� ��ɾ ���´ٸ� �����̴�.
			if (Stack.size() >= 2) {
				LL A = Stack[size - 1];
				LL B = Stack[size - 2];
				Stack.erase(Stack.begin() + (size - 1));
				Stack.erase(Stack.begin() + (size - 2));
				if (abs(B - A) <= INF) {
					// ���� ����� ������ 10^9�� �Ѿ�ٸ� �����̴�.
					Stack.push_back(B - A);
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else if (cmd == "MUL") {
			// ù ��°�� �� ��° ���ڸ� ���Ѵ�. ���ÿ� ���ڰ� 1�� ������ �� �� ��ɾ ���´ٸ� �����̴�.
			if (Stack.size() >= 2) {
				LL A = Stack[size - 1];
				LL B = Stack[size - 2];
				Stack.erase(Stack.begin() + (size - 1));
				Stack.erase(Stack.begin() + (size - 2));
				if (abs(A * B) <= INF) {
					// ���� ����� ������ 10^9�� �Ѿ�ٸ� �����̴�.
					Stack.push_back(A * B);
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else if (cmd == "DIV") {
			// ù ��°�� �� ��° ���ڸ� ������. ���ÿ� ���ڰ� 1�� ������ �� �� ��ɾ ���´ٸ� �����̴�.
			if (Stack.size() >= 2) {
				LL A = Stack[size - 1];
				LL B = Stack[size - 2];
				Stack.erase(Stack.begin() + (size - 1));
				Stack.erase(Stack.begin() + (size - 2));
				if (A != 0) { // ������ 0�̸� ����
					if (A > 0) {
						if (B >= 0) { // �Ѵ� ����� ��� ���� ���
							Stack.push_back(B / A);
						}
						else { // �������� ������ ��� ���� ����
							A = abs(A);
							B = abs(B);
							LL R = B / A;
							Stack.push_back(-R);
						}
					}
					else if (A < 0) {
						if (B >= 0) { // ������ ������ ��� ���� ����
							A = abs(A);
							B = abs(B);
							LL R = B / A;
							Stack.push_back(-R);
						}
						else { // �Ѵ� ������ ��� ���� ���
							A = abs(A);
							B = abs(B);
							LL R = B / A;
							Stack.push_back(R);
						}
					}
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else if (cmd == "MOD") {
			// ù ��°�� �� ��° ���ڸ� ���� �������� �����Ѵ�. ���ÿ� ���ڰ� 1�� ������ �� �� ��ɾ ���´ٸ� �����̴�.
			if (Stack.size() >= 2) {
				LL A = Stack[size - 1];
				LL B = Stack[size - 2];
				Stack.erase(Stack.begin() + (size - 1));
				Stack.erase(Stack.begin() + (size - 2));
				if (A != 0) { // ������ 0�̸� ����
					if (B >= 0) { // �������� ����� �������� ���
						A = abs(A);
						B = abs(B);
						LL R = B % A;
						Stack.push_back(R);
					}
					else { // �������� ������ �������� ����
						A = abs(A);
						B = abs(B);
						LL R = B % A;
						Stack.push_back(-R);
					}
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
	}
	return true;
}

int main() {
	FIRST
	while (1) {
		init();
		while (1) {
			string cmd;
			getline(cin, cmd);
			if (cmd == "END") {
				break;
			}
			if (cmd == "QUIT") {
				Flag = false;
				break;
			}
			Query.push_back(cmd);
		};
		if (!Flag) {
			break;
		}
		cin >> N;
		for (int i = 0; i < N; i++) {
			Stack.clear();
			int V;
			cin >> V;
			Stack.push_back(V);
			bool res = Command_Play();
			if (res) {
				if (Stack.size() == 1) {
					cout << Stack[0] << "\n";
				}
				else {
					cout << "ERROR" << "\n";
				}
			}
			else {
				cout << "ERROR" << "\n";
			}
		}
		cout << "\n";
	};

	getchar();
	getchar();
	return 0;
}