#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 101

using namespace std;
string S;
stack<char> s;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if ((S[i] == '+') || (S[i] == '-') || (S[i] == '*') || (S[i] == '/')) { // �������� ��
			if (s.empty()) { // stack�� empty��� �׳� push
				s.push(S[i]);
			}
			else { // stack�� empty�� �ƴ϶��, �ش� �����ں��� �켱������ ���ų� ���� �����ڶ�� ��� �� pop, �װ� �ƴ϶�� pop�� ���߰� �ش� �����ڸ� push
				if ((S[i] == '*') || (S[i] == '/')) { // ���� �켱������ ���� *, / ������
					while (!s.empty()) {
						if ((s.top() == '*') || (s.top() == '/')) {
							cout << s.top();
							s.pop();
						}
						else {
							break;
						}
					};
					s.push(S[i]);
				}
				else if ((S[i] == '+') || (S[i] == '-')) {
					while (!s.empty()) {
						if (s.top() != '(') {
							cout << s.top();
							s.pop();
						}
						else {
							break;
						}
					};
					s.push(S[i]);
				}
			}
		}
		else if (S[i] == '(') { // ���� ��ȣ��� stack�� push
			s.push(S[i]);
		}
		else if (S[i] == ')') { // �ݴ� ��ȣ��� ���� ��ȣ�� ���� ������ stack�� top�� ����� �� pop
			while (!s.empty()) {
				if (s.top() != '(') {
					cout << s.top();
					s.pop();
				}
				else {
					s.pop();
					break;
				}
			};
		}
		else { // �ǿ����ڶ�� stack�� push���� ���� �׳� ���
			cout << S[i];
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	};

	getchar();
	getchar();
	return 0;
}