/** @file */
#ifndef functionsH
#define functionsH

#pragma once
#include <iostream>

/** 
 * Klasa Sudoku
*/
class Sudoku{
    private:
        int plansza[9][9] ={{0, 7, 0, 8, 9, 0, 0, 0, 0},
                            {0, 5, 0, 0, 0, 0, 3, 0, 4},
                            {0, 2, 0, 0, 4, 0, 0, 1, 0},
                            {5, 6, 8, 9, 0, 0, 4, 7, 2},
                            {0, 0, 0, 6, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 5, 0, 6, 3, 8},
                            {7, 3, 0, 1, 0, 2, 0, 8, 0},
                            {6, 0, 0, 4, 7, 0, 1, 0, 0},
                            {2, 0, 9, 0, 3, 8, 7, 0, 6}};
    public:
        /** Konstruktor
        *   @return 
        */
        Sudoku();
        /** metoda Wyswietl sluzy do wypisania planszy 
        *   
        */
        void Wyswietl();
};

#endif