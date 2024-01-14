/** @file */
#ifndef UI
#define UI
#pragma once
#include "sudoku_functions.h"

class abstractUI{
    protected:
        Sudoku sudoku;
    public:
        /** Metoda wyświetlająca menu
        *   
        */
        virtual void displayMenu() = 0;

        /** Metoda wyświetlająca menu Planszy (co gracz chce zrobic z wygenerowana plansza)
        *   
        */
        virtual void displayPlanszaMenu() = 0;

        /** Metoda tworzaca plansze (za pomoca metody generatePlansza())
        *   
        */
        virtual void generatePlansza(std::string level) = 0;

        /** Metoda rozwiazujaca plansze (za pomoca metody solve())
        *   
        */
        virtual void solvePlansza() = 0;

        /** Metoda wyswietlajaca plansze (za pomoca metody getPlansza)
        *   
        */
        virtual void displayPlansza() = 0;

        /** Metoda wyswietlajaca wygenerowaną plansze (za pomoca metody getGeneratedPlansza)
        *   
        */
        virtual void displayGeneratedPlansza() = 0;

         /** Metoda wyswietlajaca rozwiazana plansze (za pomoca metody getSolvedPlansza)
        *   
        */
        virtual void displaySolvedPlansza() = 0;

        virtual ~abstractUI() = default;
};

#endif