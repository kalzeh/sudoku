/** @file */
#ifndef UI
#define UI
#pragma once
#include "sudoku_functions.h"

class abstractUI{
    protected:
        Sudoku sudoku;
    public:
        /** Metoda virtualna wyświetlająca menu
        *   
        */
        virtual void displayMenu() = 0;

        /** Metoda virtualna tworzaca plansze (za pomoca metody generatePlansza())
        *   
        */
        virtual void generatePlansza(std::string level) = 0;

        /** Metoda virtualna ładująca Planszę z pliku (za pomoca metody wczytajPlik())
        *   
        */
        virtual void loadBoardFromFile(std::string filepath) = 0;

        /** Metoda virtualna rozwiazujaca plansze (za pomoca metody solve())
        *   
        */
        virtual void solvePlansza() = 0;

        /** Metoda virtualna wyswietlajaca plansze (za pomoca metody getPlansza)
        *   
        */
        virtual void displayPlansza() = 0;

        /** Metoda virtualna wyswietlajaca wygenerowaną plansze (za pomoca metody getGeneratedPlansza)
        *   
        */
        virtual void displayGeneratedPlansza() = 0;

         /** Metoda virtualna wyswietlajaca rozwiazana plansze (za pomoca metody getSolvedPlansza)
        *   
        */
        virtual void displaySolvedPlansza() = 0;

        virtual ~abstractUI() = default;
};

#endif