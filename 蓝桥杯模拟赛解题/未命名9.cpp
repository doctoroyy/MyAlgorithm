#include<iostream>  
using namespace std;  
class data{  
public:  
    int x,y;  
    int* b;  
    data(){  
        x = 0;  
        y = 0;  
        b = NULL;  
    }  
};  
int static A[9][9] = {  
    0,2,6,0,0,0,0,0,0,
0,0,0,5,0,2,0,0,4,
0,0,0,1,0,0,0,0,7,
0,3,0,0,2,0,1,8,0,
0,0,0,3,0,9,0,0,0,
0,5,4,0,1,0,0,7,0,
5,0,0,0,0,1,0,0,0,
6,0,0,9,0,7,0,0,0,
0,0,0,0,0,0,7,5,0 
  
};  
data findm();//�ҵ����Ŀո�ĵ�ַ  
int check(int i, int j,int num);//��鵱ǰ�Ƿ���ϵĹ���  
int out_answer();  
  
int f( int n ){  
    if(n == 0){  
        cout<<"�Ѿ������ˣ�����Ҫ������д"<<endl;  
        exit(0);  
    }  
    data d = findm();  
    for(int i = 1; i <= 9; i++){  
         *(d.b) = i;  
         int x = d.x;  
         int y = d.y;  
         if( check(x,y,i) ){//������ͨ��  
             if(n>1){  
                 if(f(n-1))//��д�ɹ�  
                     return 1;  
             }  
             else{  
                 out_answer();//������  
                 return 1;  
             }   
         }  
    }  
    if(i == 10){//˵��1��9�����ܷ��Ϲ�����Ҫ������һ���ո�������д  
         *(d.b) = 0;//��ոÿո�  
         return 0;  
    }  
    return 0;  
  
}  
int check(int i, int j,int num){//i�У�j �� ����ֵ num  
    int x = 0;  
    int y = 0;  
    for(y = 0; y < 9; y++){  
        if(A[i][y] == num && y != j){  
            return 0;  
        }  
    }  
    for(x = 0; x < 9; x++){  
        if(A[x][j] == num && x != i){  
            return 0;  
        }  
    }  
    int a = 0;  
    int b = 0;  
    a = i/3*3;  
    b = j/3*3;  
    for(x = a; x < a+3; x++){  
        for(y = b; y < b+3; y++){  
            if(A[x][y] == num && x!=i && y!=j ){  
                return 0;  
            }  
        }  
    }  
    return 1;  
}  
int count(){  
    int num = 0;  
    for(int x = 0; x < 9; x++){  
        for(int y = 0; y < 9; y++){  
            if(A[x][y] == 0 ){  
                num++;  
            }  
        }  
    }  
    return num;  
}  
data findm(){  
    data d;  
    for(int x = 8;x >= 0; x--){  
        for(int y = 8; y >= 0; y--){  
            if(A[x][y] == 0){  
                d.b = &A[x][y];  
                d.x = x;  
                d.y = y;  
                return d;  
            }  
        }  
    }  
    cout<<"\n findm:end \n";  
    return d;  
}  
int out_answer(){  
    for(int x = 0; x < 9; x++){  
        for(int y = 0; y < 9; y++){  
            if(y==0){  
                cout<<endl;  
            }  
            cout<<A[x][y]<<" ";  
        }  
    }  
    fflush(stdout);  
    return 0;  
}  
void init(){  
    cout<<"�������ʼֵ"<<endl;  
    for(int x = 0; x < 9; x++){  
        for(int y = 0; y < 9; y++){            
            A[x][y] = 0;  
        }  
    }  
}  
int main(){  
//  init();  
//  A[2][5] = 8;  
    int n = 0;    
    cout<<"\n��ʼֵ\n";  
    n = count();  
    out_answer();  
    cout<<"\n��\n";  
    f(n);  
    cout<<"\nhere end\n";  
    return 0;  
}  
