#include<iostream>
#include<cmath>
using namespace std;
int f(int x, int y) {
	if (x == -1 && y == 0) return 1;
	if (x == 0 && y == 0) return 0;
	//��1,2����
	if ((x > 0 && y >= 0) || (x < 0 && y >= 0)) {

		if (abs(x) <= abs(y)) {
			return f(x-1, y) + 1;
		} else if ((x > 0 && y >= 0)) {
			return f(x, y+1) + 1;
		} else if ((x < 0 && y >= 0)) {
			return f(x, y-1) + 1;
		}
	}

//  if (x > 0 && y == 0) {
//    return f(x, y+1) + 1;
//  }

	//�ڶ�����
//	if (x <= 0 && y > 0) {
//		if (abs(x) == abs(y)) {
//			return f(x, y-1) + 1;
//		}
//		return f(x-1, y) + 1;
//	}

//  if (x == 0 && y > 0) {
//
//    return f(x-1, y) + 1;
//  }

	//��3,4����
	if ((x < 0 && y <= 0) || (x >= 0 && y < 0)) {
		cout << "*" << endl;
		if (abs(x) >= abs(y) + 1) {
			return f(x+1, y) + 1;

		} else if ((x < 0 && y <= 0) ) {
			return f(x, y-1) + 1;
		} else if ((x >= 0 && y < 0)) {
			return f(x, y+1) + 1;
		}

	}

//  if (x < 0 && y == 0) {
//    return f(x, y-1) + 1;
//  }

	//��������
//	if (x >= 0 && y < 0) {
//		cout << "*" << endl;
//
//		if (abs(x) == abs(y)) {
//			return f(x, y+1) + 1;
//		}
//		return f(x+1, y) + 1;
//	}

//  if (x == 0 && y < 0) {
//    return f(x+1, y) + 1;
//  }

}
int main() {
	int x, y;
	while (cin >> x >> y) {
		cout << f(x, y) << endl;
	}
}
