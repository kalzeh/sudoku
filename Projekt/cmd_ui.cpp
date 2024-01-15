/** @file */
#include "cmd_ui.h"

CmdUI::CmdUI() {}

void CmdUI::clearScreen() {
    for (int i = 0; i < 50; ++i) {
        std::cout << std::endl;
    }
}

void CmdUI::displayHeader() {
    std::cout << "===============================" << std::endl;
    std::cout << "           Sudoku Game         " << std::endl;
    std::cout << "===============================" << std::endl;
}

void CmdUI::displayInstructions() {
    clearScreen();
    std::cout << "============= INSTRUKCJA =============" << std::endl;
    std::cout << "Witaj w grze Sudoku! Oto kilka wskazówek, abyś mógł swobodnie cieszyć się grą:" << std::endl << std::endl;

    std::cout << "Główne Menu:" << std::endl;
    std::cout << "1. Wygeneruj nową planszę." << std::endl;
    std::cout << "2. Wybierz poziom trudności." << std::endl;
    std::cout << "3. Wprowadź własną planszę z pliku." << std::endl;
    std::cout << "4. Wyswietl instrukcje." << std::endl;
    std::cout << "5. Zakończ program." << std::endl << std::endl;

    std::cout << "============= WYBÓR PLANSZY ==============" << std::endl;

    std::cout << "Po wybraniu opcji 1 lub 2 z Głównego Menu, wybierz jedną z dostępnych plansz:" << std::endl;
    std::cout << " Plansza moze miec wiecej niz jedno rozwiazanie - jest generowana calkowicie losowo." << std::endl;
    std::cout << "- Plansza zostanie automatycznie wygenerowana dla opcji 1." << std::endl;
    std::cout << "- Dla opcji 2, wybierz poziom trudności ('easy', 'medium' lub 'hard')."<<std::endl;
    std::cout << " Plansza zostanie pobrana z wcześniej zdefiniowanych plansz. Dla tej opcji plansza zawsze ma dokładnie jedno rozwiazanie" << std::endl;
    std::cout << "- Dla opcji 3, podaj pełną ścieżkę do pliku z planszą." << std::endl << std::endl;
    std::cout << " Wybierając ta opcje mozesz wprowadzic wlasna plansze z pliku. Plik powinien byc z rozszerzeniem .txt, a wartosci w nim zapisane powinny byc w nastepujacym formacie:" << std::endl;
    std::cout << "000000000" << std::endl;
    std::cout << "000000000" << std::endl;
    std::cout << "000000000" << std::endl;
    std::cout << "000000000" << std::endl;
    std::cout << "000000000" << std::endl;
    std::cout << "000000000" << std::endl;
    std::cout << "000000000" << std::endl;
    std::cout << "000000000" << std::endl;
    std::cout << "000000000" << std::endl;
    std::cout << "Gdzie kazdy wiersz i kolumna ma dokladnie 9 syfr w zakresie od 0 do 9, gdzie 0 reprezentuje puste miejsca." << std::endl;


    std::cout << "============= OPCJE GRY ==============" << std::endl;
    
    std::cout<<"1. Wprowadz liczbe."<<std::endl;
    std::cout << "Po wybraniu planszy z głównego menu, aby wprowadzić liczbę:" << std::endl;
    std::cout << "   - Wybierz opcję 1 z menu 'Plansza'." << std::endl;
    std::cout << "   - Następnie podaj liczbę, wiersz oraz kolumnę, gdzie chcesz umieścić cyfrę." << std::endl;
    std::cout << "     - Liczba to cyfra od 1 do 9." << std::endl;
    std::cout << "     - Wiersze i kolumny są numerowane od 1 do 9." << std::endl;
    std::cout << "Jeśli podasz liczbę spoza zakresu 1-9, zostaniesz poproszony o wprowadzenie poprawnej wartości." << std::endl;

    
    std::cout << "2. Wyswietl rozwiazanie." << std::endl;
    std::cout << " Aby zobaczyć rozwiązanie planszy, wybierz ta opcje." << std::endl;

  
    std::cout << "3. Zresetuj plansze do stanu poczatkowego." << std::endl;
    std::cout << "Jeśli zechcesz zresetować planszę do stanu początkowego, wybierz tę opcję." << std::endl;


    std::cout << "4. Wroc do menu glownego." << std::endl;
    std::cout << "5. W każdej chwili możesz wrócić do głównego menu, wybierając opcję 4." << std::endl << std::endl;

    std::cout << "Życzymy udanej rozgrywki i dużo radości z rozwiązywania Sudoku!" << std::endl;
    std::cout << "=========================================" << std::endl << std::endl;
}

void CmdUI::displayMenu() {
    int wybor;

    do{
        displayHeader();
        std::cout << "Wybierz opcje:" << std::endl;
        std::cout << "1. Wygeneruj nową plansze." << std::endl;
        std::cout << "2. Wybierz poziom trudnosci." << std::endl;
        std::cout << "3. Wprowadz wlasną plansze z pliku." << std::endl;
        std::cout << "4. Wyswietl instrukcje." << std::endl;
        std::cout << "5. Zakoncz program." << std::endl;
        std::cout << "Wprowadz numer opcji: ";
        if (std::cin >> wybor) {
            std::string level;
            switch (wybor) {
                case 1:
                    clearScreen();
                    displayHeader();
                    generatePlansza("random");
                    displayGeneratedPlansza();
                    displayPlanszaMenu();
                    break;
                case 2:
                    clearScreen();
                    displayHeader();
                    std::cout << "Wybierz poziom trudności (easy, medium, hard): ";
                    std::cin >> level;

                    while (level != "easy" && level != "medium" && level != "hard") {
                        std::cout << "Wprowadź poprawny poziom trudności." << std::endl;
                        std::cout << "Wybierz poziom trudności (easy, medium, hard): ";
                        std::cin >> level;
                    }

                    clearScreen();
                    displayHeader();
                    generatePlansza(level);
                    displayGeneratedPlansza();
                    displayPlanszaMenu();
                    break;
                case 3:
                    clearScreen();
                    displayHeader();
                    std::cout << "Wprowadź ścieżkę do pliku: ";
                    std::cin >> level;
                    generatePlansza(level);
                    displayGeneratedPlansza();
                    displayPlanszaMenu();
                    break;
                case 4:
                    displayInstructions();
                    break;
                case 5:
                    std::cout << "Dziękujemy za grę!" << std::endl;
                    break;
                default:
                    std::cout << "Musisz wybrac numer odpowiadajacy opcji, ktora chcesz wybrac."<<std::endl;
            }
        } else {
            std::cout << "Wprowadzono nieprawidlowy znak. Wpisz ponownie." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    }while (wybor != 5);
}

void CmdUI::displayPlanszaMenu(){
    int wybor;

    do {
        std::cout << std::endl << "Co chcesz zrobic z ta plansza?" << std::endl;
        std::cout << "1. Wprowadz liczbe." << std::endl;
        std::cout << "2. Wyswietl rozwiazanie." << std::endl;
        std::cout << "3. Zresetuj plansze do stanu poczatkowego." << std::endl;
        std::cout << "4. Wroc do menu glownego." << std::endl;
        std::cout << "Wprowadz numer opcji: ";;

        if (std::cin >> wybor) {
            switch (wybor) {
                case 1:
                    playerSolve();                    
                    break;
                case 2:
                    clearScreen();
                    displayHeader();
                    solvePlansza();
                    std::cout << "Rozwiazanie planszy:" << std::endl;
                    displaySolvedPlansza();
                    break;
                case 3:
                    clearScreen();
                    displayHeader();
                    std::cout << "Plansza zresetowana do stanu poczatkowego." << std::endl;
                    for (int i = 0; i < 9; ++i) {
                        for (int j = 0; j < 9; ++j) {
                            sudoku.plansza[i][j] = sudoku.board.plansza[i][j];
                        }
                    }
                    displayPlansza();
                    break;
                case 4:
                    break;
                default:
                    std::cout << "Musisz wybrac numer odpowiadajacy opcji, ktora chcesz wybrac."<<std::endl;
            }
        } else {
            std::cout << "Wprowadzono nieprawidlowy znak. Wpisz ponownie." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (wybor != 4);
}

void CmdUI::playerSolve(){
    int x, y, dig;
    std::cout << "Wprowadz liczbe, ktora chcesz wpisac: ";
    if (!(std::cin >> dig) || dig < 1 || dig > 9) {
        std::cout << "Wprowadzono nieprawidlowa liczbe. Podaj liczbe z zakresu 1 do 9." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "Wprowadz wiersz: ";
    if (!(std::cin >> x) || x < 1 || x > 9) {
        std::cout << "Wprowadzono nieprawidlowy numer wiersza. Podaj numer z zakresu 1 do 9." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "Wprowadz kolumne: ";
    if (!(std::cin >> y) || y < 1 || y > 9) {
        std::cout << "Wprowadzono nieprawidlowy numer kolumny. Podaj numer z zakresu 1 do 9." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << std::endl;
    clearScreen();
    sudoku.writeDigit((x - 1), (y - 1), dig);
    displayPlansza();
};

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