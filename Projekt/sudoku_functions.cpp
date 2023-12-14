/** @file */
#include "sudoku_functions.h"

Sudoku::Sudoku(){
    std::cout<<"Stworzylem gre xd "<<std::endl;
};

void Sudoku::Wyswietl(){
    std::cout<<std::endl<<"--------+-------+--------"<<std::endl;
    for(int i =0; i<9;i++){
        std::cout<<"| "; 
        for(int j=0; j<9; j++){
            std::cout<<plansza[i][j]<<" ";
            if(j%3==2){
               std::cout<<"| "; 
            }
        }
        std::cout<<std::endl;
        if(i%3==2){
               std::cout<<"--------+-------+--------"<<std::endl; 
            }
    }
};