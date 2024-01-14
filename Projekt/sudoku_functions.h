/** @file */
#ifndef functionsH
#define functionsH

#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <limits>

class Plansza;
class Solver;

/** 
 * Klasa Sudoku
*/
class Sudoku{
    
    private:
        
        class Plansza{
            private:

                /** Plansza, która jest początkowo wygenerowana - użytkownik nie działa na niej, to jest początkowa plansza, do sprawdzania wersji początkowej.
                *   
                */
                int plansza[9][9];

            public:

                /** Konstruktor
                */
                Plansza();

                /** metoda Generate_plansza sprawdza poziom, jaki chce uzytkownik i na tej podstawie wybiera plansze z predefiniowanych
                 * @param _level rzadany poziom
                */
                bool generatePlansza(std::string _level,int _plansza[9][9]);

                /** metoda Generate_random tworzy losowo wygenerowana plansze
                */
                void generateRandom();

               /** Metoda check, sprawdza czy dana liczba jest poprawna
                *   @param x wiersz
                *   @param y kolumna
                *   @param a liczba do sprawdenia
                *   @return zwraca true jezeli liczba moze byc, false jesli nie
                */
                bool check(int x, int y, int a);
                

                /** metoda Wczytaj_plik wczytuje plansze z pliku
                 * @param _data jaki poziom ma byc
                */
                void wczytajPlik(std::string _data);

                /** Metoda zwraca plansze
                * @return plansza[9][9]
                */
                auto getGenerated() -> const int(*)[9];

        };

        class Solver{
            private:
                
            public:
                /** PRozwiązana plansza, użytkownik nie ma do niej dostępu
                *   
                */
                int plansza[9][9];

                /** kopiuje planszę do klasy solver z klasy sudoku
                 * 
                */
                Solver(Sudoku & outerMember);

                /** kopiuje planszę do klasy solver z podanego parametru
                 * @param plansza do zapisania
                */
                void updatePlansza(const int _plansza[9][9]);

                /** Metoda check, sprawdza czy dana liczba jest poprawna
                *   @param x wiersz
                *   @param y kolumna
                *   @param a liczba do sprawdenia
                *   @return zwraca true jezeli liczba moze byc, false jesli nie
                */
                bool check(int x, int y, int a);

                /** Metoda checkBoard, sprawdza czy plansza jest poprawna
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
                
                /** Metoda zwraca plansze
                *   @return plansza[9][9]
                */
                auto getSolved() -> const int(*)[9];        
        };
       
    public:
        /** Plansza, na której uzytkownik wykonuje działania
        *  
        */
        int plansza[9][9];
        Plansza board;
        Solver solver;
        /** Konstruktor, ktory odpala cala gre
        *   
        */
        Sudoku();  

        /** Metoda zwraca plansze
        *   @return plansza[9][9]
        */
        auto getPlansza() -> const int(*)[9];        

        /** Metoda pozwala na interakcję z solverem
        *   
        */
        void solveSudoku();

        /** Metoda zwraca wygenerowana plansze sudoku
        *   @return plansza[9][9]
        */
        auto getGeneratedPlansza() -> const int(*)[9];
        
        /** Metoda zwraca rozwiązaną plansze sudoku
        *   @return plansza[9][9]
        */
        auto getSolvedPlansza() -> const int(*)[9];
        
};

#endif