/** @file */
#include "sudoku_functions.h"

Sudoku::Sudoku(){
    Plansza latwa;
    if(latwa.Generate_plansza("easy", plansza)){
        std::cout<<"Wygenerowana/ wybrana plansza - pierwotna, bedzie niezmienna";
        latwa.Wyswietl();
    };
    
    std::cout<<std::endl<<"Plansza do modyfikacji";
    Wyswietl();
    Solver solver(*this);

    if(solver.checkBoard()){
        std::cout<<std::endl<<"Plansza jest poprawna"<<std::endl;}else{std::cout<<"Plansza jest bledna";};
    if(solver.Solve()){
        std::cout<<"Rozwiazana plansza: ";
        solver.Wyswietl();
    }else{
        std::cout<<"Plansza jest bledna";
        solver.Wyswietl();
    };
};

Sudoku::Plansza::Plansza(){
    std::cout<<"Stworzony"<<std::endl;
};

bool Sudoku::Plansza::Generate_plansza(std::string _level, int _plansza[9][9]){
    std::string data;
    switch(_level[0]){
        case 'e':
            data="easy";
        break;
        case 'm':
            data="medium";
        break;
        case 'h':
            data="hard";
        break;
        
    }
    if(data!=""){Wczytaj_plik(data);
    }else{
        Generate_random();
    };
    
    for(int i =0;i<9;i++){
        for(int j =0;j<9;j++){
            _plansza[i][j] = plansza[i][j];
        }
    }
    return true;
}

void Sudoku::Plansza::Wczytaj_plik(std::string _data){

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int random_number = std::rand() % 5 + 1;
    std::ifstream File("plansze/"+_data+"/"+_data+"00"+std::to_string(random_number)+".txt");

    std::cout<<"plansze/"+_data+"/"+_data+"00"+std::to_string(random_number)+".txt"<<std::endl;

    if (!File.is_open()) {
        std::cout << "Error opening the file for writing." << std::endl;
        return; 
    };

    char digit;
    int i=0,j = 0;
    while (File >> digit) {
        if (std::isdigit(digit)) {
            int liczba = digit - '0';
            if (i < 9 && j < 9) {
                plansza[j][i] = liczba;
                i++;
                if (i == 9) {
                    j++;
                    i = 0;
                }
            } 
        }
    }

    File.close();
}

void Sudoku::Plansza::Generate_random(){
    std::cout<<"GENERUJ"; 
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int random_number = std::rand() % 12 + 13;
    for(int k=0; k<random_number; k++){
        int i =0;
        int j = 0;
        int insert_num = std::rand() % 9 + 1;
        do{
            insert_num = std::rand() % 9 + 1;
            i = std::rand() % 9;
            j = std::rand() % 9;
        }while(!check(i,j,insert_num));
        plansza[i][j]=insert_num;
    }
    for(int i =0;i<9;i++){
        for(int j =0;j<9;j++){
            if(plansza[i][j]>9 || plansza[i][j]<0){
                plansza[i][j]=0;
            }
        } 
    }

};

Sudoku::Solver::Solver(Sudoku & outerMember){
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            plansza[i][j] = outerMember.plansza[i][j];
        }
    }
}

void Sudoku::Wyswietl(){
    std::cout<<std::endl<<"--------+-------+--------"<<std::endl;
    for(int i =0; i<9;i++){
        std::cout<<"| "; 
        for(int j=0; j<9; j++){
            std::cout<<plansza[i][j]<<" ";
            if(j%3==2)std::cout<<"| "; 
        }
        std::cout<<std::endl;
        if(i%3==2) std::cout<<"--------+-------+--------"<<std::endl; 
    }
};

void Sudoku::Solver::Wyswietl(){
    std::cout<<std::endl<<"--------+-------+--------"<<std::endl;
    for(int i =0; i<9;i++){
        std::cout<<"| "; 
        for(int j=0; j<9; j++){
            std::cout<<plansza[i][j]<<" ";
            if(j%3==2)std::cout<<"| "; 
        }
        std::cout<<std::endl;
        if(i%3==2) std::cout<<"--------+-------+--------"<<std::endl; 
    }
};

void Sudoku::Plansza::Wyswietl(){
    std::cout<<std::endl<<"--------+-------+--------"<<std::endl;
    for(int i =0; i<9;i++){
        std::cout<<"| "; 
        for(int j=0; j<9; j++){
            std::cout<<plansza[i][j]<<" ";
            if(j%3==2)std::cout<<"| "; 
        }
        std::cout<<std::endl;
        if(i%3==2) std::cout<<"--------+-------+--------"<<std::endl; 
    }
};

bool Sudoku::Solver::check(int x, int y, int a){
    //sprawdzenie rzedu
    for(int i = 0 ;i<9;i++){
        if( i != y && plansza[x][i]==a) return false;
    }
    //sprawdzenie kolumny
    for(int i = 0 ;i<9;i++){
        if( i != x && plansza[i][y]==a) return false;
    }
    //sprawdzenie kwadratu 3x3
    int startX = x - x%3;
    int startY = y - y%3;
    for(int i = 0;i<3;i++){
        for(int j = 0; j< 3;j++){
            if(x!=(startX+i) && y!=(startY+j) && plansza[startX+i][startY+j]==a) return false;
        }
    }
    return true;
}

bool Sudoku::Plansza::check(int x, int y, int a){
    //sprawdzenie rzedu
    for(int i = 0 ;i<9;i++){
        if( i != y && plansza[x][i]==a) return false;
    }
    //sprawdzenie kolumny
    for(int i = 0 ;i<9;i++){
        if( i != x && plansza[i][y]==a) return false;
    }
    //sprawdzenie kwadratu 3x3
    int startX = x - x%3;
    int startY = y - y%3;
    for(int i = 0;i<3;i++){
        for(int j = 0; j< 3;j++){
            if(x!=(startX+i) && y!=(startY+j) && plansza[startX+i][startY+j]==a) return false;
        }
    }
    return true;
}

bool Sudoku::Solver::checkBoard(){
    for(int i =0;i<9;i++){
        for(int j =0;j<9;j++){
            if(plansza[i][j]!=0){
                if (!check(i,j,plansza[i][j])){
                    std::cout<<"Niepoprawne jest: "<<plansza[i][j]<<" w rzedzie: "<<(i+1)<<", kolumnie: "<<(j+1)<<std::endl;
                    return false;
                }
            }
        }
    }
    return true;
};

bool Sudoku::Solver::findEmpty(int x, int y){
    if(plansza[x][y]==0) return true;
    return false;
};

bool Sudoku::Solver::Solve(){
    if (!checkBoard()) return false;
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (findEmpty(i, j)) {
                for (int k = 1; k <= 9; k++) {
                    if (check(i, j, k)) {
                        plansza[i][j] = k;
                        if (Solve()) return true;
                        plansza[i][j] = 0;
                        
                    }
                }
                return false;
            }
        }
    }
    
    return true;
};