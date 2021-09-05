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
		if ((S[i] == '+') || (S[i] == '-') || (S[i] == '*') || (S[i] == '/')) { // 연산자일 때
			if (s.empty()) { // stack이 empty라면 그냥 push
				s.push(S[i]);
			}
			else { // stack이 empty가 아니라면, 해당 연산자보다 우선순위가 높거나 같은 연산자라면 출력 후 pop, 그게 아니라면 pop을 멈추고 해당 연산자를 push
				if ((S[i] == '*') || (S[i] == '/')) { // 가장 우선순위가 높은 *, / 연산자
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
		else if (S[i] == '(') { // 여는 괄호라면 stack에 push
			s.push(S[i]);
		}
		else if (S[i] == ')') { // 닫는 괄호라면 여는 괄호가 나올 때까지 stack의 top을 출력한 후 pop
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
		else { // 피연산자라면 stack에 push하지 말고 그냥 출력
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