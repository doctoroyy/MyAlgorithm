#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 110;
int e[maxn][maxn];
vector<vector<int> > v;
int n, m, min_cnt = 0x3f3f3f3f;
int room[maxn][maxn], psn_in_room[maxn], si; //room[i][j] = k ��ʾ����i�ĵ�j��λ����k, 
// psn_in_room[i] = j ��ʾ i �ŷ���������j�� 
int valid(int sno, int index) {
  for (int i = 0; i < psn_in_room[index]; i++) {
    if (e[sno][room[index][i]]) return 0;
  }
  return 1;
}
void dfs(int sno) {
  cout << "*\n";
  if (sno == n + 1) {
    int sz = v.size();
    cout << sz << endl;
    if (v.size() > min_cnt) min_cnt = v.size();
    return;
  }
  for (int i = 0; i < v.size(); i++) {
    if (valid(sno, i)) { //����������û���뿼��sno��ʶ����
      v[i].push_back(sno); //��i�ſ������뿼��sno
      dfs(sno + 1);
      v[i].erase(v[i].end());
    }
  }
  vector<int> v1;
  v1.push_back(sno);
  v.push_back(v1);
  dfs(sno + 1);
  v.erase(v.begin() + v.size() - 1);
}
int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    e[a][b] = e[b][a] = 1;
  }
  if (m == n * (n - 1) / 2) {
    printf("%d\n", n);
  } else {
    dfs(1);
    printf("%d\n", min_cnt);
  }
  return 0;
}
