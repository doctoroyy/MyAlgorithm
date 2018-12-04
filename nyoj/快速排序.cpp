#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void quickSort(int a[], int left, int right) {
	int i, j, temp;
	if (left >= right) return;
	temp = a[left];
	i = left, j = right;
	while (i != j) {
		while (a[j] >= temp && i < j) j--; //�ҵ�һ���Ȼ�׼��tempС����Ϊֹ
		while (a[i] <= temp && i < j) i++;//�ҵ�һ���Ȼ�׼��temp�����Ϊֹ
		swap(a[i], a[j]);
	}
	// �� i==j ʱ��a[i]���׼������
	if (i <= j) {
		a[left] = a[i];
		a[i] = temp;
		quickSort(a, left, i-1);
		quickSort(a, i+1, right);
	}

}

int main() {
	int a[100];
	srand(time(0));
	for (int i = 0; i < 20; i++) {
		a[i] = rand() % 100;
	}
	for (int i = 0; i < 20; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	quickSort(a, 0, 20);
	for (int i = 0; i < 20; i++) {
		cout << a[i] << " ";
	}
}
