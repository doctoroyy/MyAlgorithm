
//DFS����ͨ��
//��������ַ�'@'���ڣ�����б8������,����������һ����ͨ�� 
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100 + 10;
char pic[maxn][maxn];
int m, n, vis[maxn][maxn];
void dfs(int r, int c, int id) {
  if (r < 0 || r >= m || c < 0 || c >= n) return; //Խ��
  if (vis[r][c] > 0 || pic[r][c] != '@') return; //����'@'���ӻ����Ѿ����ʹ�
  vis[r][c] = id;//��ͨ�������
  for (int dr = -1; dr <= 1; dr++) {//����8������ 
    for (int dc = -1; dc <= 1; dc++) {
      if (dr != 0 || dc != 0) {
        dfs(r+dr, c+dc, id);
      }
    }
  } 
}
int main() {
  while (cin >> m >> n) {
    
    for (int i = 0; i < m; i++) cin >> pic[i];
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (vis[i][j] == 0 && pic[i][j] == '@') {
          dfs(i, j, ++cnt);
        }
      }
    }
    cout << cnt << endl;
  }
}
