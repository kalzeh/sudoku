/** @file */
#ifndef functionsH
#define functionsH

#pragma once
#include <iostream>
#include <algorithm>

/** 
 * Klasa Sudoku
*/
class Sudoku{
    private:
        /*int planszaB[9][9] ={{0, 7, 0, 8, 9, 0, 0, 0, 0},
                            {0, 5, 0, 0, 0, 0, 3, 0, 4},
                            {0, 2, 0, 0, 4, 0, 0, 1, 0},
                            {5, 6, 8, 9, 0, 0, 4, 7, 2},
                            {0, 0, 0, 6, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 5, 0, 6, 3, 8},
                            {7, 3, 0, 1, 0, 2, 0, 8, 0},
                            {6, 0, 0, 4, 7, 0, 1, 0, 0},
                            {2, 0, 9, 0, 3, 8, 7, 0, 6}};*/
        int planszaB[9][9] ={{9,8,7,6,5,4,3,2,1},
                             {6,5,4,9,8,7,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},};
        //plansza poczatkowa
        /*int planszaB[9][9] ={{0,0,9,0,4,0,8,0,0},
                            {0,6,0,5,0,8,0,0,2},
                            {5,0,0,0,3,0,0,0,0},
                            {0,4,0,0,0,0,0,7,0},
                            {7,0,0,2,0,5,9,0,0},
                            {0,0,0,3,0,0,0,0,0},
                            {0,0,1,0,0,0,0,0,6},
                            {4,0,0,7,0,9,2,0,0},
                            {0,0,0,0,8,0,0,0,0}};*/
        //plansza do zmiany
        int plansza[9][9];
    public:
        /** Konstruktor
        *   @return 
        */
        Sudoku();
        /** metoda copyGrid przekopiowuje planszeB (poczatkowa) do planszy (na niej beda wykonywane wszelkie dzialania)
        */
        void copyGrid();
        /** metoda Wyswietl sluzy do wypisania planszy 
        */
        void Wyswietl();
        /** Metoda check, sprawdza czy dana liczba jest poprawna
        *   @param x wiersz
        *   @param y kolumna
        *   @param a liczba do sprawdenia
        *   @return zwraca true jezeli liczba moze byc, false jesli nie
        */
        bool check(int x, int y, int a);
        /** Metoda checkBeginnig, sprawdza czy plansza jest poprawna
        *   @return zwraca true jezeli plansza jest poprawna, false jesli nie
        */
        bool checkBoard();

        /** Metoda solve, rozwiazujaca zadana plansze sudoku
        *   @param _plansza przyjmuje planszę do sudoku
        *   @return zwraca rozwiązaną planszę
        */
        bool Solve();
        /** Metoda findEmpty szuka pierwszego pustego pola (o wartosci 0)
        *   @param x wiersz
        *   @param y kolumna
        *   @return zwraca true jezeli dana komorka jest pusta (o wartosci 0)
        */
        bool findEmpty(int x, int y);
        
        
};

#endif