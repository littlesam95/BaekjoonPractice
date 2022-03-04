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
#define MAX 10005
#define LL long long
#define INF 1e9

using namespace std;
struct INFO {
	int IDX;
	string Name; // 정당명
	int R, Vote; // 지역구 의석, 비례대표국회의원선거 득표수
	double Vote_Rate; // 비례득표율
	bool Flag1 = true; // 의석 할당 정당이라면 true, 아니라면 false
	double P; // 비례득표율
	int S_Appo = 0, S = 0, T = 0; // 연등 배분 의석, 조정된 비례대표 의석, 연등 배분 의석
	int Total = 0;
};

int P, V;
int True_R = 0;
vector<INFO> Party;
int S_Appo_Sum = 0;
int True_Vote = 0; // 유효 투표 총 수
int Total_True_Vote;

void init() {
	Total_True_Vote = True_Vote;
	// 유효 투표 총 수의 3% 미만을 득표했거나, 지역구 국회의원 선거에서 5석 미만의 의석을 차지한 정당은 비례대표 의석을 배분받을 수 없다.
	for (int i = 0; i < Party.size(); i++) {
		double Rate = (double)Party[i].Vote / (double)True_Vote;
		Party[i].Vote_Rate = Rate;
		if ((Party[i].R < 5) && (Party[i].Vote_Rate < 0.03)) {
			Party[i].Flag1 = false;
			Total_True_Vote -= Party[i].Vote; // 의석 할당 정당이 아닌 정당의 득표 수를 실 득표 수에서 제외시킨다.
		}
	}
	for (int i = 0; i < Party.size(); i++) {
		// i번 기호의 정당의 비례대표 국회의원 선거 득표비율을 구한다. 즉 의석 할당 정당의 득표수를 모든 의석 할당 정당의 득표수의 합계로 나누어 다시 산출한다.
		if (Party[i].Flag1) {
			Party[i].P = (double)Party[i].Vote / (double)Total_True_Vote;
			True_R += Party[i].R;
		}
	}
}

bool Comp(pair<int, double> A, pair<int, double> B) {
	return (A.second > B.second);
}

void Second_Step_First() {
	int Now_Total_S = 0;
	vector<pair<int, double> > Vec; // (기호, 소수점 이하의 수)
	for (int i = 0; i < Party.size(); i++) {
		if (Party[i].Flag1) {
			double Res = Party[i].S_Appo + (30 - S_Appo_Sum) * Party[i].P;
			double Remain = Res - floor(Res);
			Party[i].S = floor(Res);
			Now_Total_S += Party[i].S;
			Vec.emplace_back(make_pair(i, Remain));
		}
	}
	if (Now_Total_S < 30) {
		sort(Vec.begin(), Vec.end(), Comp);
		for (int i = 0; i < Vec.size(); i++) {
			int X = Vec[i].first;
			Party[X].S++;
			Now_Total_S++;
			if (Now_Total_S == 30) {
				break;
			}
		}
	}
}

void Second_Step_Second() {
	int Now_Total_S = 0;
	vector<pair<int, double> > Vec; // (기호, 소수점 이하의 수)
	for (int i = 0; i < Party.size(); i++) {
		if (Party[i].Flag1) {
			double Res = 30.0 * Party[i].S_Appo / (double)S_Appo_Sum;
			double Remain = Res - floor(Res);
			Party[i].S = floor(Res);
			Now_Total_S += Party[i].S;
			Vec.emplace_back(make_pair(i, Remain));
		}
	}
	if (Now_Total_S < 30) {
		sort(Vec.begin(), Vec.end(), Comp);
		for (int i = 0; i < Vec.size(); i++) {
			int X = Vec[i].first;
			Party[X].S++;
			Now_Total_S++;
			if (Now_Total_S == 30) {
				break;
			}
		}
	}
}

void First_Step() {
	for (int i = 0; i < Party.size(); i++) {
		if (Party[i].Flag1) {
			double Res = (((47 + True_R) * Party[i].P) - Party[i].R) / 2.0;
			// 결과값은 1보다 작은 경우 0이며, 이외의 경우 소수점 첫째 자리에서 반올림한다.
			if (Res < 1) {
				Party[i].S_Appo = 0;
			}
			else {
				Party[i].S_Appo = round(Res);
			}
			S_Appo_Sum += Party[i].S_Appo;
		}
	}
	if (S_Appo_Sum < 30) { // 연등 배분 의석 수의 합이 30 이하인 경우 2-1단계로 진입한다.
		Second_Step_First();
	}
	else if (S_Appo_Sum > 30) { // 연등 배분 의석 수의 합이 30 초과인 경우 2-2단계로 진입한다.
		Second_Step_Second();
	}
}

void Third_Step() {
	int Now_Total_T = 0;
	vector<pair<int, double> > Vec; // (기호, 소수점 이하의 수)
	for (int i = 0; i < Party.size(); i++) {
		if (Party[i].Flag1) {
			double Res = 17.0 * Party[i].P;
			double Remain = Res - floor(Res);
			Party[i].T = floor(Res);
			Now_Total_T += Party[i].T;
			Vec.emplace_back(make_pair(i, Remain));
		}
	}
	if (Now_Total_T < 17) {
		sort(Vec.begin(), Vec.end(), Comp);
		for (int i = 0; i < Vec.size(); i++) {
			int X = Vec[i].first;
			Party[X].T++;
			Now_Total_T++;
			if (Now_Total_T == 17) {
				break;
			}
		}
	}
}

bool Comp2(INFO A, INFO B) {
	if (A.Total == B.Total) {
		return (A.Name < B.Name);
	}
	return (A.Total > B.Total);
}

void Final_Calc() {
	for (int i = 0; i < Party.size(); i++) {
		Party[i].Total = Party[i].R + Party[i].S + Party[i].T;
	}
	sort(Party.begin(), Party.end(), Comp2);
}

void Print() {
	for (int i = 0; i < Party.size(); i++) {
		cout << Party[i].Name << " " << Party[i].Total << "\n";
	}
}

int main() {
	FIRST
	cin >> P >> V;
	Party.resize(P);
	for (int i = 0; i < P; i++) {
		string A;
		int B, C;
		// 정당명, 지역구 의석(R). 비례대표국회의원선거 득표수를 입력받는다.
		cin >> A >> B >> C;
		Party[i].Name = A;
		Party[i].R = B;
		Party[i].Vote = C;
		Party[i].IDX = i + 1;
		True_Vote += Party[i].Vote; // 실득표 수의 합을 구한다.
	}
	init();
	First_Step();
	Third_Step();
	Final_Calc();
	Print();

	getchar();
	getchar();
	return 0;
}