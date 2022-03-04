#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 51

using namespace std;
string Identification;
int N;
string Region_Code[MAX];

bool Region_Check() {
	string Id_Region = Identification.substr(0, 6);
	bool res = false;
	for (int i = 0; i < N; i++) {
		if (Id_Region == Region_Code[i]) {
			res = true;
			break;
		}
	}

	return res;
}

bool Birthday_Check() {
	int Year = stoi(Identification.substr(6, 4));
	int Month = stoi(Identification.substr(10, 2));
	int Day = stoi(Identification.substr(12, 2));
	
	if ((Year >= 1900) && (Year <= 2011)) {
		if ((Month >= 1) && (Month <= 12)) {
			if ((Month == 1) || (Month == 3) || (Month == 5) || (Month == 7) || (Month == 8) || (Month == 10) || (Month == 12)) {
				if ((Day >= 1) && (Day <= 31)) {
					return true;
				}
				else {
					return false;
				}
			}
			else if ((Month == 4) || (Month == 6) || (Month == 9) || (Month == 11)) {
				if ((Day >= 1) && (Day <= 30)) {
					return true;
				}
				else {
					return false;
				}
			}
			else if (Month == 2) {
				bool Flag = false;
				if (Year % 4 == 0) {
					if ((Year % 100 != 0) || (Year % 400 == 0)) {
						Flag = true;
					}
				}
				if (Flag) {
					if ((Day >= 1) && (Day <= 29)) {
						return true;
					}
					else {
						return false;
					}
				}
				else {
					if ((Day >= 1) && (Day <= 28)) {
						return true;
					}
					else {
						return false;
					}
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

bool Male_Female_Check() {
	int Id_Male_Female = stoi(Identification.substr(14, 3));
	if (Id_Male_Female % 2 == 0) { // 여자라면 true
		return true;
	}
	return false; // 남자라면 false
}

string Find_Checksum() {
	int C = 0;
	for (int i = 17; i >= 1; i--) {
		int A = Identification[17 - i] - '0';
		C += (A * pow(2, i));
	}
	int X;
	for (int i = 0; i <= 10; i++) {
		if ((C + i) % 11 == 1) {
			X = i;
			break;
		}
	}
	if (X < 10) {
		return to_string(X);
	}
	return "X";
}

int main() {
	FIRST
	cin >> Identification;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Region_Code[i];
	}
	if (Region_Check() && Birthday_Check() && (Identification.substr(14, 3) != "000") && (Identification.substr(17, 1) == Find_Checksum())) {
		if (Male_Female_Check()) {
			cout << "F" << "\n";
		}
		else {
			cout << "M" << "\n";
		}
	}
	else {
		cout << "I" << "\n";
	}

	getchar();
	getchar();
	return 0;
}