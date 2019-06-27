#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int n, m, k;

int main() {
  cin >> n >> m >> k;
  while (k--) {
    stack<int> s;
    int flag = 1, cnt = 1;
    for (int i = 1; i <= n; i++) {
      int num;
      cin >> num;
      if (num != cnt) {//����Ⱦ�ֱ�ӷ��뻺�� 
        s.push(num);
        if (s.size() > m) flag = 0;
      } else {//��Ⱦ��ж���һ���� 
        cnt++;
        while (!s.empty() && flag && s.top() == cnt) {
          s.pop();
          cnt++;
        }
      }
    }
    cout << (s.empty() ? "YES\n" : "NO\n");
  }
  return 0;
}
