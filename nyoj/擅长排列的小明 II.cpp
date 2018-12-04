#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<fstream>
using namespace std;
int a[55];
int n, cnt;
//bool valid(int a[], int n) {
//  if (a[0] != 1) return false;
//  for (int i = 1; i < n; i++) {
//    if (abs(a[i] - a[i - 1]) > 2) return false;
//  }
//  return true;
//}
int vis[55];
void dfs(int index) {
  if (index == 1 && a[0] != 1) return;
  if (index > n) return;
  if (index == n) {

//    if (valid(a, n)) {
//    for (int i = 0; i < n; i++) cout << a[i] << " ";
//    cout << endl;
    cnt++;
//    }

  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      if (index > 0 && abs(i - a[index - 1]) > 2) continue;
      a[index] = i;

      vis[i] = 1;
      dfs(index + 1);
      vis[i] = 0;
    }
  }
}
int main() {
//  while (~scanf("%d", &n)) {
  ofstream fout("out.txt");
  for (n = 1; n <= 55; n++) {
    
    memset(vis, 0, sizeof(vis));
    memset(a, 0, sizeof(a));
    cnt = 0;
    dfs(0);
    printf("%d,", cnt);
//    fout << cnt << ",";
  }

//  }
  return 0;
}
/*
1˼·������
2������Ϊ�˼�������������Ai�����i������ �� ����A1һֱ��1������A2ֻ����2��3������dp[n]��ʾ1->n������еķ�����
?????????? 1.��A2=2ʱ����A2��An�����У�2~n���൱�ڴ�A1��An-1�����У�1~n-1������ÿ�����ֶ���1����һ����dp[n-1]�������
?????????? 2.��A2=3ʱ��A3����Ϊ2��4��5��
?????????????? 1����A3=2ʱ��A4һ������4����ʱ��A4��An�����У�4~n)�൱�ڴ�A1��An-3�����У���ÿ�����ֶ���3����һ����dp[n-3]�������
?????????????? 2����A3=4ʱ������A4ȡ��ȡ2���������γ�������������У��ʴ�����������ܷ�����
?????????????? 3����A3=5ʱ������ֻ������1 ,3, 5,7,9......10,8,6,4,2,����һ����1�������
?????????? 3����������dp[n]=dp[n-3]+dp[n-1]+1��(n>3)
--------------------- 


