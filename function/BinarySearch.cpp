int binarySearch(int a[], int len, int key) {//���ص�һ�����ڹؼ��ֵ�����
  int l = 0, r = len - 1, mid, pos = -1;
  while (l <= r) {
    mid = (l + r) / 2;
    if (a[mid] <= key) {
      l = mid + 1;
      pos = l;
    } else {
      r = mid - 1;
      pos = mid;
    }
  }
  return pos;
}
