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
#define LD long double
#define INF 1e9


using namespace std;
/*
	�ý��� ����, �������� ����, �°����� ������ ��� ����ü�� ����
*/
struct TAXI {
	LD Fuel;
	LL Money = 0;
};

struct PASSENGER {
	string Dest;
	LL Len;
};

struct INFO {
	int IDX; // ������ ��ȣ(��� ��)
	string D; // ������ �̸�
	LL Y, X; // ������ ��ǥ
	bool isGarage = false; // �����Ҷ�� true, �ƴ϶�� false(������ ����� ���� ��)
	LL P = 0; // �����Ҷ�� ���� 1������ ������ 0�� �ƴϰ�, �����Ұ� �ƴ϶�� 0
};

int A, B, C, N, K;
string STR, CMD;
TAXI Taxi;
pair<LL, LL> Taxi_Pos;
pair<LL, LL> Taxi_Garage_Pos;
vector<INFO> Point;
vector<PASSENGER> Passenger;
unordered_map<string, LL> UM;

int main() {
	FIRST
	cin >> A >> B >> C;
	Taxi.Fuel = A;
	cin >> N;
	/*
		cin�� ����ϸ� ���⸦ �ϴ� ��� string�� �Է��� ����ȴ�.
		���� getline�� ����ؼ� �������� �̸�, ��ǥ�� �Ѳ����� �Է¹޵��� �Ѵ�.
	*/
	getline(cin, STR);
	for (int i = 0; i < N; i++) {
		INFO Info;
		Info.IDX = i + 1;
		int Number_IDX = 0;
		getline(cin, STR);
		for (int j = 0; j < STR.size(); j++) {
			if ((STR[j] >= '0') && (STR[j] <= '9')) {
				// ���ڰ� ������ ������ �̸��� �� �Է¹��� ���̹Ƿ�
				Info.D = STR.substr(0, j - 1);
				Number_IDX = j;
				break;
			}
		}
		string Number = "";
		for (int j = Number_IDX; j < STR.size(); j++) {
			if (STR[j] == ' ') { // ���� �ڿ� ���Ⱑ ���Դٸ� ���Ⱑ ������ ���� ���ڴ� X��ǥ
				Info.Y = stoi(Number);
				Number_IDX = j + 1;
				break;
			}
			Number += STR[j];
		}
		Info.X = stoi(STR.substr(Number_IDX)); // ���Ⱑ ���� ���� ���ڴ� Y��ǥ
		if (Info.D == "Taxi Garage") {
			// ó���� Taxi Garage���� �����ϹǷ� Taxi Garage�� ��ǥ�� ������������ �ϰ�, �ٽ� ���ƿ;� �ϹǷ� ���� ������ ���� Taxi Garage�� �����Ѵ�.
			Taxi_Pos = make_pair(Info.Y, Info.X);
			Taxi_Garage_Pos = make_pair(Info.Y, Info.X);
		}
		Point.push_back(Info);
		UM.insert(make_pair(Info.D, i));
	}
	for (int i = 0; i < 3; i++) {
		string STR;
		string STR2 = "";
		int Number_IDX = 0;
		getline(cin, STR);
		for (int j = 0; j < STR.size(); j++) {
			if ((STR[j] >= '0') && (STR[j] <= '9')) {
				STR2 = STR.substr(0, j - 1);
				Number_IDX = j;
				break;
			}
		}
		/*
			�ݺ����� ����ؼ� �����ҷ� ������ ������ ã�� ��� ���
			map�� ����ؼ� ������ �����ҷ� �ٲٵ��� �ؼ� �ڵ��� ���̸� �ٿ���.
		*/
		Point[UM[STR2]].isGarage = true;
		Point[UM[STR2]].P = stoi(STR.substr(Number_IDX));
	}
	cin >> K;
	getline(cin, CMD);
	for (int i = 0; i < K; i++) {
		getline(cin, CMD);
		int Len = CMD.size();
		CMD = CMD.substr(0, Len - 1);
		if (CMD.substr(0, 6) == "Go to ") { // ������ ���� Go to�� �����Ѵٸ�
			string Dest = CMD.substr(6); // Go to ������ ���ڿ��� ��������.
			int Move_Len = abs(Taxi_Pos.first - Point[UM[Dest]].Y) + abs(Taxi_Pos.second - Point[UM[Dest]].X);
			 // ����ư �Ÿ��� ���� ���� �ý��� ������ �������� ���� ���� �Ÿ��� ���
			LD Used_Fuel = (LD)Move_Len / C;
			// ������ �� �츮�� ���� �˰� �ִ� ������ �ణ�� ������ �����Ѵ�.
			Taxi.Fuel -= Used_Fuel;
			Taxi_Pos = make_pair(Point[UM[Dest]].Y, Point[UM[Dest]].X);
			if (Taxi.Fuel < -1e-12) { // OUT OF GAS : �̵� �� ���ᰡ �������� ��
				// 1e-12(10�� -12����, �� ��û���� ���� ��), �Ǽ� ���� ������ �ذ��ϱ� ���� ���
				cout << "OUT OF GAS" << "\n";
				return 0;
			}
			for (int j = 0; j < Passenger.size(); j++) {
				Passenger[j].Len += Move_Len; // ž�°����� �̵��� �Ÿ��� ����
				if (Passenger[j].Dest == Dest) { // �������� �����ߴٸ� �̵��ؿ� �Ÿ� * B��ŭ�� ����� �ýÿ��� ���� �� ����
					Taxi.Money += (Passenger[j].Len * B);
					Passenger.erase(Passenger.begin() + j);
					j--;
				}
			}
			if (Point[UM[Dest]].isGarage) { // �������� �����Ҷ��
				LL Price = Point[UM[Dest]].P;
				LD Diff = A - Taxi.Fuel;
				Diff = max(Diff, (LD)0.0); // ���� �뷮�� ���� ���� ������ ����
				LD Must_Pay = (LD)Price * Diff; // �� ���� * �������� ���� = �����ҿ� �����ؾ� �ϴ� �ݾ�
				LL Money = (LL)floor(Must_Pay + 1e-12);
				if (Taxi.Money < Must_Pay) { // ���� ���� ���� �����ؾ� �� �ݾ׺��� �����ϴٸ�
					Taxi.Fuel += (LD)Taxi.Money / Price; // ���� �ݾ� / �������� 1������ ���� = �ݾ��� ��� �����ϰ� �޴� ����
					Taxi.Fuel = min(Taxi.Fuel, (LD)A);
					Taxi.Money = 0;
				}
				else { // ���� ���� ���� �����ؾ� �� �ݾ� �̻��̶�� �ݾ׸�ŭ �����ϰ� ���Ḧ ���� ä���.
					Taxi.Money -= Money;
					Taxi.Fuel = A;
				}
			}
		}
		else if (CMD.substr(0, 28) == "Pickup a passenger going to ") { // ������ ���� Pickup���� �����Ѵٸ�
			string Dest = CMD.substr(28); // ������
			Passenger.push_back({ Dest,0 });
			if (Passenger.size() > 3) { // CAPACITY FULL : �������� ���� �°��� �¿���� �� ��
				cout << "CAPACITY FULL" << "\n";
				return 0;
			}
		}
	}
	if (Taxi_Pos != Taxi_Garage_Pos) { // NOT IN GARAGE : ������ ������ Taxi Garage�� �ƴ� ��
		cout << "NOT IN GARAGE" << "\n";
		return 0;
	}
	else {
		if (!Passenger.empty()) { // REMAINING PASSENGER : ������ ������ Taxi Garage������ ���� ������ ���� �°��� ���� ��
			cout << "REMAINING PASSENGER" << "\n";
			return 0;
		}
		else { // ��Ģ�� �°� ������ �Ϸ��� ���, ���������� �� ���� �׼��� ����Ѵ�.
			cout << Taxi.Money << "\n";
		}
	}

	getchar();
	getchar();
	return 0;
}