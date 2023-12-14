/** @file */
#include "sudoku_functions.h"

Sudoku::Sudoku(){
    Sudoku::copyGrid();
    std::cout<<"Stworzylem gre xd "<<std::endl;
};

void Sudoku::copyGrid() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            plansza[i][j] = planszaB[i][j];
        }
    }
}

void Sudoku::Wyswietl(){
    std::cout<<std::endl<<"--------+-------+--------"<<std::endl;
    for(int i =0; i<9;i++){
        std::cout<<"| "; 
        for(int j=0; j<9; j++){
            std::cout<<plansza[i][j]<<" ";
            if(j%3==2)std::cout<<"| "; 
        }
        std::cout<<std::endl;
        if(i%3==2) std::cout<<"--------+-------+--------"<<std::endl; 
    }
};

bool Sudoku::check(int x, int y, int a){
    //sprawdzenie rzedu
    for(int i = 0 ;i<9;i++){
        if( i != y && plansza[x][i]==a) return false;
    }
    //sprawdzenie kolumny
    for(int i = 0 ;i<9;i++){
        if( i != x && plansza[i][y]==a) return false;
    }
    //sprawdzenie kwadratu 3x3
    int startX = x - x%3;
    int startY = y - y%3;
    for(int i = 0;i<3;i++){
        for(int j = 0; j< 3;j++){
            if(x!=(startX+i) && y!=(startY+j) && plansza[startX+i][startY+j]==a) return false;
        }
    }
    return true;
}

bool Sudoku::checkBoard(){
    for(int i =0;i<9;i++){
        for(int j =0;j<9;j++){
            if(plansza[i][j]!=0){
                if (!check(i,j,plansza[i][j])){
                    std::cout<<"Niepoprawne jest: "<<plansza[i][j]<<" w rzedzie: "<<(i+1)<<", kolumnie: "<<(j+1)<<std::endl;
                    return false;
                }
            }
        }
    }
    return true;
};

bool Sudoku::findEmpty(int x, int y){
    if(plansza[x][y]==0) return true;
    return false;
};

bool Sudoku::Solve(){
    if(!checkBoard()) return false;
    for(int i =0;i<9;i++){
        for(int j=0;j<9;j++){
            if(findEmpty(i,j)){
                for(int k = 1;k <= 9;k++){
                    plansza[i][j]=k;
                    plansza[i][j]=0;
                    if(check(i,j,k)){
                        plansza[i][j]=k;
                        if(Solve())return true;
                        plansza[i][j]=0;
                    };
                }
                return false;
            }
        }
    }
    return true;
};