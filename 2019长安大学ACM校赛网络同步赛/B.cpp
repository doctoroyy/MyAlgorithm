#include<iostream>
using namespace std;
int main() {
  int t;
  cin >>t;
  while (t--) {
    int n;
    cin >> n;
    int sum = 0; 
    if (n % 2 == 0) { // ���n��ż�� �ͽ����Ϊ���� ���� ��������Ҫ��1 
      sum = 1;
      n--;
    }
    while (n > 2) {
      n /= 2;
      sum++;
    }
    sum += n;
    cout << sum << endl;
  }

  return 0;
}

