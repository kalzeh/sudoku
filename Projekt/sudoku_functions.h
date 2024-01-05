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


/** 
 * Klasa Sudoku
*/
class Sudoku{
    
    private:
        //plansza poczatkowa
        int plansza[9][9] ={{9,8,7,6,5,4,3,2,1},
                            {6,5,4,0,0,0,9,8,7},
                            {0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0},};
    public:
        class Plansza{
            private:
                int plansza[9][9];
            public:
                /** Konstruktor
                */
                Plansza();
                /** metoda Generate_plansza sprawdza poziom, jaki chce uzytkownik i na tej podstawie wybiera plansze z predefiniowanych
                 * @param _level rzadany poziom
                */
                bool Generate_plansza(std::string _level,int _plansza[9][9]);
                /** metoda Generate_random tworzy losowo wygenerowana plansze
                */
               /** Metoda check, sprawdza czy dana liczba jest poprawna
                *   @param x wiersz
                *   @param y kolumna
                *   @param a liczba do sprawdenia
                *   @return zwraca true jezeli liczba moze byc, false jesli nie
                */
                bool check(int x, int y, int a);
                void Generate_random();
                /** metoda Wczytaj_plik wczytuje plansze z pliku
                 * @param _data jaki poziom ma byc
                */
                void Wczytaj_plik(std::string _data);
                /** Metoda do wyswietlania planszy 
                * 
                */
                void Wyswietl();   
        };

        class Solver{
            private:
                int plansza[9][9];
            public:

            /** kopiuje planszę do klasy solver z klasy sudoku
             * 
            */
            Solver(Sudoku & outerMember);

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
            /** Metoda do wyswietlania planszy 
             * 
            */
            void Wyswietl();           
        };


        /** Konstruktor, ktory odpala cala gre
        *   
        */
        Sudoku();  
        /** Metoda do wyswietlania planszy 
        * 
        */
        void Wyswietl();   
        
        
};

#endif