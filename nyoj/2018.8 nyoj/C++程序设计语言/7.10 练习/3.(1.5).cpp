#include<iostream>
#include<cstdarg>
using namespace std;
void printStr(int n, ...) {
  va_list ap;
  va_start(ap, n);
  for (int i = 0; i < n; i++) {
    char* p = va_arg(ap, char*);
    cout << "hello: " << p << endl;
  }
  va_end(ap);
}
//int max(int n, ...) { // ���� n ��ʾ�����������������ã�����ʱ������
//  va_list ap;       // ����һ�� va_list ָ�������ʲ�����
//  va_start(ap, n);     // ��ʼ�� ap������ָ���һ�����
//  int maximum = -0x7FFFFFFF;   // ����һ����С������
//  int temp;
//  for(int i = 0; i < n; i++) {
//    temp = va_arg(ap, int);   // ��ȡһ�� int �Ͳ��������� ap ָ����һ������
//    if (maximum < temp)
//      maximum = temp;
//  }
//  va_end(ap);       // �ƺ������ر� ap
//  return maximum;
//}


int main() {
//  cout << max(4, 1, -1, 0, 7, 3);
  printStr(3, "fsdgv", "swef", "ef");
  return 0;
}

