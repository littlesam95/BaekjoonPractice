#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1001

using namespace std;
double A, B, C, D, E, F;
double answer;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B >> C >> D >> E >> F;
	if (C < F) {
		swap(A, D);
		swap(B, E);
		swap(C, F);
	}
	double d = sqrt(((A - D) * (A - D)) + ((B - E) * (B - E)));
	if (d >= (C + F)) {
		answer = 0;
	}
	else if (C >= F + d) {
		answer = (F * F) * acos(-1);
	}
	else {
		double theta1 = acos(((C * C) + (d * d) - (F * F)) / (2 * C * d));
		double theta2 = acos(((F * F) + (d * d) - (C * C)) / (2 * F * d));
		double s1 = (C * C * theta1) - (C * C * sin(2 * theta1)) / 2;
		double s2 = (F * F * theta2) - (F * F * sin(2 * theta2)) / 2;
		answer = s1 + s2;
	}
	cout << fixed;
	cout.precision(3);
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}