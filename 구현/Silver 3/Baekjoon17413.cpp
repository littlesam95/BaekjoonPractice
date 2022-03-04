#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1001

using namespace std;
string S;
stack<char> st;
bool Flag = false;
string answer = "";

int main() {
	FIRST
	getline(cin, S);
	for (int i = 0; i <= S.size(); i++) {
		if (i < S.size()) {
			if (S[i] == '<') {
				while (!st.empty()) {
					answer += st.top();
					st.pop();
				};
				Flag = true;
			}
			else if (S[i] == '>') {
				Flag = false;
				st.push(S[i]);
				string tmp = "";
				while (!st.empty()) {
					tmp += st.top();
					st.pop();
				};
				reverse(tmp.begin(), tmp.end());
				answer += tmp;
				continue;
			}
			if (Flag) {
				st.push(S[i]);
			}
			else {
				if (S[i] == ' ') {
					while (!st.empty()) {
						answer += st.top();
						st.pop();
					};
					answer += ' ';
				}
				else {
					st.push(S[i]);
				}
			}
		}
		else if (i == S.size()) {
			string tmp = "";
			while (!st.empty()) {
				tmp += st.top();
				st.pop();
			};
			answer += tmp;
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}