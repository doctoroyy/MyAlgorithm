#include<iostream>
using namespace std;
struct StuScores {
  int index;
  int grades;
}stuScores[5];
int main() {
  string gradeClass[] = {"����", "�Ϻ�", "��"}; 
  string courseName[] = {"����", "��ѧ", "Ӣ��", "����", "��ѧ"}; 
  string name[] = {"С��", "С��", "С��", "С��", "С��"}; 
  int grade[5][5] = {        //ѧ�����Ƴɼ��� 
    70, 95, 92, 80, 87,
    81, 82, 85, 91, 95,
    85, 88, 65, 72, 63,
    71, 74, 63, 77, 64, 
    95, 92, 96, 93, 90  
  };
  
  int courseSituation[5][3] = {0};//������������� 
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      stuScores[i].grades += grade[i][j];//ͳ��ÿ��ѧ���ܷ� 
      stuScores[i].index = i;
      //ͳ�Ƹ�����Ŀ�ɼ�������� 
      if (grade[j][i] >= 90) {
        courseSituation[i][0]++;
      } else if (grade[j][i] >= 80) {
        courseSituation[i][1]++;
      } else if (grade[j][i] >= 70){
        courseSituation[i][2]++;
      }
    }
  }
  //��ӡ���鿴ÿ��ͬѧ�ܷ� 
  for (int i = 0; i < 5; i++) cout << name[stuScores[i].index] << stuScores[i].grades << endl;
  //int rank[3]; 
  //ɸѡǰ������ͬѧ 
  for (int i = 0; i < 3; i++) {
    int index = i; 
    for (int j = i + 1; j < 5; j++) {
      if (stuScores[j].grades > stuScores[index].grades) index = j;
    }
    //rank[i] = stuScores[index].index;
    swap(stuScores[index], stuScores[i]);
  }
  //��ӡ���� 
  for (int i = 0; i < 3; i++) {
    cout << "��" << i + 1 << "��" << ":" << name[stuScores[i].index] << " "; 
  }
  cout << endl;
  for (int i = 0; i < 5; i++) {//��ӡ������� 
    cout << courseName[i] << ":";
    for (int j = 0; j < 3; j++) {
      cout << gradeClass[j] << courseSituation[i][j] << " ";
    }
    cout << endl; 
  }
}
