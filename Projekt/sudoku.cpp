/** @file */

#include <iostream>
#include "sudoku_functions.h"

int main(){
    Sudoku latwe;
    latwe.Wyswietl();
    if(latwe.checkBoard()){std::cout<<"Plansza jest poprawna"<<std::endl;}else{std::cout<<"Plansza jest bledna";};
    if(latwe.Solve()){
        std::cout<<"Rozwiazana plansza: ";
        latwe.Wyswietl();
    }else{
        std::cout<<"Plansza jest bledna";
    };
}