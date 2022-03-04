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
	택시의 정보, 지점들의 정보, 승객들의 정보를 담는 구조체를 생성
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
	int IDX; // 지점의 번호(없어도 됨)
	string D; // 지점의 이름
	LL Y, X; // 지점의 좌표
	bool isGarage = false; // 주유소라면 true, 아니라면 false(주유소 영어로 뭔지 모름)
	LL P = 0; // 주유소라면 연료 1갤런당 가격은 0이 아니고, 주유소가 아니라면 0
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
		cin을 사용하면 띄어쓰기를 하는 즉시 string의 입력이 종료된다.
		따라서 getline을 사용해서 지점들의 이름, 좌표를 한꺼번에 입력받도록 한다.
	*/
	getline(cin, STR);
	for (int i = 0; i < N; i++) {
		INFO Info;
		Info.IDX = i + 1;
		int Number_IDX = 0;
		getline(cin, STR);
		for (int j = 0; j < STR.size(); j++) {
			if ((STR[j] >= '0') && (STR[j] <= '9')) {
				// 숫자가 나오면 지점의 이름을 다 입력받은 것이므로
				Info.D = STR.substr(0, j - 1);
				Number_IDX = j;
				break;
			}
		}
		string Number = "";
		for (int j = Number_IDX; j < STR.size(); j++) {
			if (STR[j] == ' ') { // 숫자 뒤에 띄어쓰기가 나왔다면 띄어쓰기가 나오기 전의 숫자는 X좌표
				Info.Y = stoi(Number);
				Number_IDX = j + 1;
				break;
			}
			Number += STR[j];
		}
		Info.X = stoi(STR.substr(Number_IDX)); // 띄어쓰기가 나온 후의 숫자는 Y좌표
		if (Info.D == "Taxi Garage") {
			// 처음은 Taxi Garage에서 시작하므로 Taxi Garage의 좌표를 시작지점으로 하고, 다시 돌아와야 하므로 최종 목적지 역서 Taxi Garage로 지정한다.
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
			반복문을 사용해서 주유소로 지정된 지점을 찾는 방법 대신
			map을 사용해서 지점을 주유소로 바꾸도록 해서 코드의 길이를 줄였다.
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
		if (CMD.substr(0, 6) == "Go to ") { // 문장의 앞이 Go to로 시작한다면
			string Dest = CMD.substr(6); // Go to 다음의 문자열이 목적지다.
			int Move_Len = abs(Taxi_Pos.first - Point[UM[Dest]].Y) + abs(Taxi_Pos.second - Point[UM[Dest]].X);
			 // 맨해튼 거리를 통한 현재 택시의 지점과 목적지의 지점 간의 거리를 계산
			LD Used_Fuel = (LD)Move_Len / C;
			// 나눠질 때 우리가 원래 알고 있던 값과는 약간의 오차가 존재한다.
			Taxi.Fuel -= Used_Fuel;
			Taxi_Pos = make_pair(Point[UM[Dest]].Y, Point[UM[Dest]].X);
			if (Taxi.Fuel < -1e-12) { // OUT OF GAS : 이동 중 연료가 떨어졌을 때
				// 1e-12(10의 -12제곱, 즉 엄청나게 작은 수), 실수 오차 문제를 해결하기 위해 사용
				cout << "OUT OF GAS" << "\n";
				return 0;
			}
			for (int j = 0; j < Passenger.size(); j++) {
				Passenger[j].Len += Move_Len; // 탑승객들이 이동한 거리를 증가
				if (Passenger[j].Dest == Dest) { // 목적지에 도착했다면 이동해온 거리 * B만큼의 비용을 택시에게 지불 후 하차
					Taxi.Money += (Passenger[j].Len * B);
					Passenger.erase(Passenger.begin() + j);
					j--;
				}
			}
			if (Point[UM[Dest]].isGarage) { // 목적지가 주유소라면
				LL Price = Point[UM[Dest]].P;
				LD Diff = A - Taxi.Fuel;
				Diff = max(Diff, (LD)0.0); // 연료 용량과 현재 남은 연료의 차이
				LD Must_Pay = (LD)Price * Diff; // 그 차이 * 주유소의 가격 = 주유소에 지불해야 하는 금액
				LL Money = (LL)floor(Must_Pay + 1e-12);
				if (Taxi.Money < Must_Pay) { // 현재 가진 돈이 지불해야 할 금액보다 부족하다면
					Taxi.Fuel += (LD)Taxi.Money / Price; // 남은 금액 / 주유소의 1갤런당 가격 = 금액을 모두 지불하고 받는 연료
					Taxi.Fuel = min(Taxi.Fuel, (LD)A);
					Taxi.Money = 0;
				}
				else { // 현재 가진 돈이 지불해야 할 금액 이상이라면 금액만큼 지불하고 연료를 가득 채운다.
					Taxi.Money -= Money;
					Taxi.Fuel = A;
				}
			}
		}
		else if (CMD.substr(0, 28) == "Pickup a passenger going to ") { // 문장의 앞이 Pickup으로 시작한다면
			string Dest = CMD.substr(28); // 목적지
			Passenger.push_back({ Dest,0 });
			if (Passenger.size() > 3) { // CAPACITY FULL : 정원보다 많은 승객을 태우려고 할 때
				cout << "CAPACITY FULL" << "\n";
				return 0;
			}
		}
	}
	if (Taxi_Pos != Taxi_Garage_Pos) { // NOT IN GARAGE : 마지막 지점이 Taxi Garage가 아닐 때
		cout << "NOT IN GARAGE" << "\n";
		return 0;
	}
	else {
		if (!Passenger.empty()) { // REMAINING PASSENGER : 마지막 지점이 Taxi Garage이지만 아직 내리지 못한 승객이 있을 때
			cout << "REMAINING PASSENGER" << "\n";
			return 0;
		}
		else { // 규칙에 맞게 운행을 완료한 경우, 최종적으로 번 돈의 액수를 출력한다.
			cout << Taxi.Money << "\n";
		}
	}

	getchar();
	getchar();
	return 0;
}