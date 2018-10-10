#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;
int shuffle(int b[][4]){
    int d , f;
    srand(time(0));
    d = (rand()%3)+1;
    f= (rand()%3)+1;
    for (int i = 0 ; i < 4 ; i++){
        for (int j = 0 ; j < 4 ;j++){
            swap(b[i][j],b[d][f]);
            swap(b[i][j],b[f][d]);
            swap(b[j][i],b[d][f]);
            swap(b[j][i],b[d][f]);
        }

    }
    return 0 ;
}
void print(int g[][4]){
    for (int i = 0 ;  i < 4 ; i++){
        for (int j = 0 ; j  < 4 ; j++){
            cout << g[i][j]<<"  " ;

        }
        cout << endl ;
    }
}
int rep(int v[][4],int y1, int y2 , int y3, int y4){
    if (v[y1][y2]==v[y3][y4]){
        v[y1][y2]=0 ;
        v[y3][y4]=0 ;
        }else{
            shuffle(v);
        }
}
bool check(int q[][4]){
    int c = 0 ;
    for (int i = 0 ; i < 4 ; i ++){
        for (int j = 0 ; j < 4 ; j++){
            if (q[i][j]==0){
               c++;
            }

        }

    }
    return(c==16);
}
int main()
{
    int s[4][4]={{1,2,3,4},{5,6,7,8},{1,2,3,4},{5,6,7,8}};
    int x1,x2,x3,x4;
    while (true){
    shuffle(s);
    cout << endl ;
    print(s);
    cin >> x1 >> x2 >> x3 >>x4 ;
    while (x1 == x3 && x2 == x4 && x1 ==0 && x2 == 0  ){
        cout << "WRONG CHOICE" << endl ;
        cin >> x1 >> x2 >> x3 >>x4 ;
        while (s[x1][x2]==0 && s[x3][x4]==0){
            cin >> x1 >> x2 >> x3 >>x4 ;
        }
    }
    while (x1 >3 || x2 > 3 || x3 >3 || x4 >3){
        cout << "WRONG NUM" << endl ;
        cin >> x1 >> x2 >> x3 >>x4 ;
    }
    rep(s,x1,x2,x3,x4);
    print(s);
    if ( check(s) == true){
        cout << "YOU WIIIIN "<<endl ;
        break ;

    }
    }
    return 0;
}
