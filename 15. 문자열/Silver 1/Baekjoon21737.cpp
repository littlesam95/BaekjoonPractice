#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 50001
#define LL long long
#define INF 1e9

using namespace std;
int N;
string Sentence;
queue<string> Q;
int Cur;
int Flag = 0;
vector<int> Answer;

int Calc(int A, int B, string OP) {
	if (OP == "S") {
		return (A - B);
	}
	else if (OP == "M") {
		return (A * B);
	}
	else if (OP == "U") {
		if (A >= 0) {
			return (A / B);
		}
		else {
			int res = (-A) / B;
			return -res;
		}
	}
	else if (OP == "P") {
		return (A + B);
	}
}

void Input() {
	cin >> N;
	cin >> Sentence;
}

void Settings() {
	string Number = "";
	for (int i = 0; i < Sentence.size(); i++) {
		char C = Sentence[i];
		if ((C >= '0') && (C <= '9')) {
			Number += C;
		}
		else {
			if (Number != "") {
				Q.push(Number);
				Number = "";
			}
			if (C == 'C') {
				Flag++;
			}
			Number += C;
			Q.push(Number);
			Number = "";
		}
	}
	if (Flag > 0) {
		while (!Q.empty()) {
			string QF = Q.front();
			Q.pop();
			if ((QF == "S") || (QF == "M") || (QF == "U") || (QF == "P")) {
				string QF2 = Q.front();
				Q.pop();
				int Next = stoi(QF2);
				Cur = Calc(Cur, Next, QF);
			}
			else if (QF == "C") {
				Answer.push_back(Cur);
				Flag--;
				if (Flag == 0) {
					break;
				}
			}
			else {
				Cur = stoi(QF);
			}
		};
	}
}

void Find_Answer() {
	if (Answer.size() > 0) {
		for (int i = 0; i < Answer.size(); i++) {
			cout << Answer[i] << " ";
		}
		cout << "\n";
	}
	else {
		cout << "NO OUTPUT\n";
	}
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}