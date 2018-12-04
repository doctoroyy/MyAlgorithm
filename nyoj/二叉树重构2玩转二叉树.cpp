#include<iostream>
#include<queue>
using namespace std;  
const int maxsize = 30;  
struct node {  
  int data;  
  node *lchild, *rchild;  
  node(int x) {
    data = x; 
    lchild = rchild = NULL;
  }  
};
node* build(int *InOrder, int *PreOrder, int len) {
  if (len == 0) {
    return NULL;
  }
  node *root = new node(PreOrder[0]);
  int root_pos;
  for (int i = 0; i < len; i++) {
    if (*PreOrder == InOrder[i]) {
      root_pos = i;
      break;
    }
  }
  //һ��Ҫע���ж���������Ԫ�ظ���(���Ӵ�����)�Ƿ�����㣬������ʵ����ɷ��ʵ�
  //�ڴ�����ᷢ���ϴ��� Segmentation fault
  if (root_pos > 0) { //root_posΪ���Ӵ�����
    root->lchild = build(InOrder, PreOrder + 1, root_pos);
  }
  if (len - root_pos - 1 > 0) { // len - root_pos - 1 Ϊ���Ӵ����� 
    root->rchild = build(InOrder + root_pos + 1, PreOrder + root_pos + 1, len - root_pos - 1);
  }
  return root;
}
void levelOrder(node *root) {
  queue <node*> sq;
  sq.push(root);
  bool flag = false;
  while (!sq.empty()) {
    node *p = sq.front();
    if (!flag) {
      cout << p->data;
      flag = true;
    } else {
      cout << " " << p->data;
    }
    sq.pop();
    if (p->rchild != NULL) sq.push(p->rchild);
    if (p->lchild != NULL) sq.push(p->lchild);
  }
} 
int main() {  
  int n;
  cin >> n;  
  int InOrder[maxsize+10];
  int preOrder[maxsize+10]; 
  for(int i = 0; i < n; i++)  
    cin >> InOrder[i];  
  for(int i = 0; i < n; i++)  
    cin >> preOrder[i];  
  node *root = build(InOrder, preOrder, n); 
  levelOrder(root);   
  return 0;
}
