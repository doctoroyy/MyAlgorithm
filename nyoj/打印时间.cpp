
//0代表" ", 1代表"_", 2代表"|"
#include<cstdio>
int a[10][3][3] = {
{{0, 1, 0}, {2, 0, 2}, {2, 1, 2}},

{{0, 0, 0}, {0, 0, 2}, {0, 0, 2}}, 

{{0, 1, 0}, {0, 1, 2}, {2, 1, 0}},

{{0, 1, 0}, {0, 1, 2}, {0, 1, 2}},

{{0, 0, 0}, {2, 1, 2}, {0, 0, 2}},

{{0, 1, 0}, {2, 1, 0}, {0, 1, 2}},

{{0, 1, 0}, {2, 1, 0}, {2, 1, 2}}, 

{{0, 1, 0}, {0, 0, 2}, {0, 0, 2}},

{{0, 1, 0}, {2, 1, 2}, {2, 1, 2}}, 

{{0, 1, 0}, {2, 1, 2}, {0, 1, 2}}

};
void print(int type) {
  if (type == 0) {
    printf(" ");
  } else if (type == 1) {
    printf("_");
  } else {
    printf("|");
  }
}
int main() {
  int num[4];
  while (~scanf("%d%d%d%d", &num[0], &num[1], &num[2], &num[3])) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 3; k++) {
          print(a[num[j]][i][k]);
        }
      }
      printf("\n");
    }
  }
} 
