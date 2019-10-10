#include<iostream>
#include <stdio.h>
using namespace std;

void progression(int *N){
    int s,m=0;
    s = N[1]-N[0];
    if (N[0]!=0){
        m = N[1]/N[0];
    }
    if(N[2] == N[1]+s){
        cout << "AP "<< N[2]+s<< "\n";
    }
    else if(N[2]==N[1]*m){
        cout << "GP "<< N[2]*m<< "\n";
    }
}

int main () {
    int N[3];
    while(true){
        for(int i = 0; i < 3; i++){
           scanf ("%d", &N[i]);
        }
        if (N[0] == 0 && N[1] == 0 && N[2] == 0){
            break;
        }
        progression(N);
    }
}