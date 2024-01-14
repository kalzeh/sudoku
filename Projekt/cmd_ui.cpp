/** @file */
#include "cmd_ui.h"

CmdUI::CmdUI() {}

void CmdUI::displayMenu() {
    int wybor;

    do{
        std::cout << std::endl << "Wybierz co chcesz zrobic:" << std::endl;
        std::cout << "1. Wygeneruj plansze." << std::endl;
        std::cout << "2. Wybierz poziom trudnosci" << std::endl;
        std::cout << "3. Wprowadz wlasna plansze z pliku. (musisz podac pelna sciezke)" << std::endl;
        std::cout << "4. Zakoncz program." << std::endl;

        std::cout << "Wprowadz numer: ";

        if (std::cin >> wybor) {
            std::string level;
            switch (wybor) {
                case 1:
                    generatePlansza("random");
                    displayGeneratedPlansza();
                    displayPlanszaMenu();
                    break;
                case 2:
                    std::cout << "Wpisz jaki chcesz poziom trudnosci (easy - latwy, medium - sredni, hard - trudny)" << std::endl;
                    std::cin >> level;

                    while (level != "easy" && level != "medium" && level != "hard") {
                        std::cout << "Musisz poprawnie wpisac level." << std::endl;
                        std::cin >> level;
                    }
                    generatePlansza(level);
                    displayGeneratedPlansza();
                    displayPlanszaMenu();
                    break;
                case 3:
                    std::cout<<"Wprowadz sciezke."<<std::endl;
                    std::cin >> level;
                    generatePlansza(level);
                    displayGeneratedPlansza();
                    displayPlanszaMenu();
                    break;
                case 4:
                    std::cout << "Dzieki za gre..."<<std::endl;
                    break;
                default:
                    std::cout << "Musisz wybrac numer odpowiadajacy opcji, ktora chcesz wybrac."<<std::endl;
            }
        } else {
            std::cout << "Wprowadzono nieprawidlowy znak. Wpisz ponownie." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    }while (wybor != 4);
}

void CmdUI::displayPlanszaMenu(){
    int wybor;

    do {
        std::cout << std::endl << "Wybierz co chcesz zrobic z ta plansza:" << std::endl;
        std::cout << "1. Zacznij rozwiazywac." << std::endl;
        std::cout << "2. wyswietl rozwiazana." << std::endl;
        std::cout << "3. Wroc do Menu." << std::endl;
        std::cout << "Wprowadz numer: ";

        if (std::cin >> wybor) {
            switch (wybor) {
                case 1:
                    
                    break;
                case 2:
                    solvePlansza();
                    std::cout<<std::endl;
                    std::cout<<"Rozwiazana Plansza:"<<std::endl;
                    displaySolvedPlansza();
                    break;
                case 3:
                    break;
                default:
                    std::cout << "Musisz wybrac numer odpowiadajacy opcji, ktora chcesz wybrac."<<std::endl;
            }
        } else {
            std::cout << "Wprowadzono nieprawidlowy znak. Wpisz ponownie." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (wybor != 3);
}

void CmdUI::generatePlansza(std::string level) {
    sudoku.board.generatePlansza(level,sudoku.plansza);
    std::cout << "Board generated successfully.\n";
}

void CmdUI::solvePlansza() {
    sudoku.solver.updatePlansza(sudoku.plansza);
    if (!sudoku.solver.Solve()) {
        std::cout << "Plansza jest niemozliwa do rozwiazania."<<std::endl;
    }
}

void CmdUI::displayGeneratedPlansza() {
    const int (*board)[9] = sudoku.getGeneratedPlansza();

    std::cout<<std::endl<<"--------+-------+--------"<<std::endl;
    for(int i =0; i<9;i++){
        std::cout<<"| "; 
        for(int j=0; j<9; j++){
            std::cout<<board[i][j]<<" ";
            if(j%3==2)std::cout<<"| "; 
        }
        std::cout<<std::endl;
        if(i%3==2) std::cout<<"--------+-------+--------"<<std::endl; 
    }
}

void CmdUI::displaySolvedPlansza() {
    const int (*board)[9] = sudoku.getSolvedPlansza();

    std::cout<<std::endl<<"--------+-------+--------"<<std::endl;
    for(int i =0; i<9;i++){
        std::cout<<"| "; 
        for(int j=0; j<9; j++){
            std::cout<<board[i][j]<<" ";
            if(j%3==2)std::cout<<"| "; 
        }
        std::cout<<std::endl;
        if(i%3==2) std::cout<<"--------+-------+--------"<<std::endl; 
    }
}

void CmdUI::displayPlansza() {
    const int (*board)[9] = sudoku.getPlansza();

    std::cout<<std::endl<<"--------+-------+--------"<<std::endl;
    for(int i =0; i<9;i++){
        std::cout<<"| "; 
        for(int j=0; j<9; j++){
            std::cout<<board[i][j]<<" ";
            if(j%3==2)std::cout<<"| "; 
        }
        std::cout<<std::endl;
        if(i%3==2) std::cout<<"--------+-------+--------"<<std::endl; 
    }
}