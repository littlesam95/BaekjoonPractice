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
	string Name; // �����
	int R, Vote; // ������ �Ǽ�, ��ʴ�ǥ��ȸ�ǿ����� ��ǥ��
	double Vote_Rate; // ��ʵ�ǥ��
	bool Flag1 = true; // �Ǽ� �Ҵ� �����̶�� true, �ƴ϶�� false
	double P; // ��ʵ�ǥ��
	int S_Appo = 0, S = 0, T = 0; // ���� ��� �Ǽ�, ������ ��ʴ�ǥ �Ǽ�, ���� ��� �Ǽ�
	int Total = 0;
};

int P, V;
int True_R = 0;
vector<INFO> Party;
int S_Appo_Sum = 0;
int True_Vote = 0; // ��ȿ ��ǥ �� ��
int Total_True_Vote;

void init() {
	Total_True_Vote = True_Vote;
	// ��ȿ ��ǥ �� ���� 3% �̸��� ��ǥ�߰ų�, ������ ��ȸ�ǿ� ���ſ��� 5�� �̸��� �Ǽ��� ������ ������ ��ʴ�ǥ �Ǽ��� ��й��� �� ����.
	for (int i = 0; i < Party.size(); i++) {
		double Rate = (double)Party[i].Vote / (double)True_Vote;
		Party[i].Vote_Rate = Rate;
		if ((Party[i].R < 5) && (Party[i].Vote_Rate < 0.03)) {
			Party[i].Flag1 = false;
			Total_True_Vote -= Party[i].Vote; // �Ǽ� �Ҵ� ������ �ƴ� ������ ��ǥ ���� �� ��ǥ ������ ���ܽ�Ų��.
		}
	}
	for (int i = 0; i < Party.size(); i++) {
		// i�� ��ȣ�� ������ ��ʴ�ǥ ��ȸ�ǿ� ���� ��ǥ������ ���Ѵ�. �� �Ǽ� �Ҵ� ������ ��ǥ���� ��� �Ǽ� �Ҵ� ������ ��ǥ���� �հ�� ������ �ٽ� �����Ѵ�.
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
	vector<pair<int, double> > Vec; // (��ȣ, �Ҽ��� ������ ��)
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
	vector<pair<int, double> > Vec; // (��ȣ, �Ҽ��� ������ ��)
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
			// ������� 1���� ���� ��� 0�̸�, �̿��� ��� �Ҽ��� ù° �ڸ����� �ݿø��Ѵ�.
			if (Res < 1) {
				Party[i].S_Appo = 0;
			}
			else {
				Party[i].S_Appo = round(Res);
			}
			S_Appo_Sum += Party[i].S_Appo;
		}
	}
	if (S_Appo_Sum < 30) { // ���� ��� �Ǽ� ���� ���� 30 ������ ��� 2-1�ܰ�� �����Ѵ�.
		Second_Step_First();
	}
	else if (S_Appo_Sum > 30) { // ���� ��� �Ǽ� ���� ���� 30 �ʰ��� ��� 2-2�ܰ�� �����Ѵ�.
		Second_Step_Second();
	}
}

void Third_Step() {
	int Now_Total_T = 0;
	vector<pair<int, double> > Vec; // (��ȣ, �Ҽ��� ������ ��)
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
		// �����, ������ �Ǽ�(R). ��ʴ�ǥ��ȸ�ǿ����� ��ǥ���� �Է¹޴´�.
		cin >> A >> B >> C;
		Party[i].Name = A;
		Party[i].R = B;
		Party[i].Vote = C;
		Party[i].IDX = i + 1;
		True_Vote += Party[i].Vote; // �ǵ�ǥ ���� ���� ���Ѵ�.
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