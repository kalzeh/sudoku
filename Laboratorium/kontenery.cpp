#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm> 
#include <iterator>  
#include <iomanip>

//zadanie 1
class impreza {
private:
    std::set<std::string> moi_przyjaciele;
    std::set<std::string> jego_przyjaciele;
    std::set<std::string> wspolni_przyjaciele;

public:
    impreza() {}
    ~impreza() {}
    
    void moi_dodaj(std::string imie) {
        moi_przyjaciele.insert(imie);
    }

    void jego_dodaj(std::string imie) {
        jego_przyjaciele.insert(imie);
    }

    void moi_wyswietl() {
        std::cout << "Moi przyjaciele: ";
        for (const auto& imie : moi_przyjaciele) {
            std::cout << imie << " ";
        }
        std::cout << std::endl;
    }

    void jego_wyswietl() {
        std::cout << "Przyjaciele znajomego: ";
        for (const auto& imie : jego_przyjaciele) {
            std::cout << imie << " ";
        }
        std::cout << std::endl;
    }

    void scal(){
        std::set_union(
            moi_przyjaciele.begin(), moi_przyjaciele.end(),
            jego_przyjaciele.begin(), jego_przyjaciele.end(),
            std::inserter(wspolni_przyjaciele, wspolni_przyjaciele.begin())
        );
    }

    void wyswietl_wspolne(){
        std::cout << "Wspolni przyjaciele: ";
        for (const auto& imie : wspolni_przyjaciele) {
            std::cout << imie << " ";
        }
        std::cout << std::endl;
    }
};

//zadanie 2
class KonWekt{
    protected:
        std::vector<int> liczby1;
        std::vector<int> liczby2;
    public:
        KonWekt(){}
        ~KonWekt(){}

        void dodaj_koniec1(int a){
            liczby1.push_back(a);
        }

        void dodaj_poczatek1(int a){
            liczby1.insert(liczby1.begin(),a);
        }

        void wyswietl1(){
            std::cout<<"Pierwszy wektor: ";
            for(const auto &el : liczby1){
                std::cout<<el<<" ";
            }
            std::cout<<std::endl;
        }

        void dodaj_koniec2(int a){
            liczby2.push_back(a);
        }

        void dodaj_poczatek2(int a){
            liczby2.insert(liczby2.begin(),a);
        }

        void wyswietl2(){
            std::cout<<"Drugi wektor: ";
            for(const auto &el : liczby2){
                std::cout<<el<<" ";
            }
            std::cout<<std::endl;
        }

        void usun(int a) {
            int i=0;
            auto it1 = std::find(liczby1.begin(), liczby1.end(), a);
            while (it1 != liczby1.end()) {
                liczby1.erase(it1);
                std::cout << a << " usunieto z pierwszego wektora" << std::endl;
                it1 = std::find(liczby1.begin(), liczby1.end(), a);
                i=1;
            }

            auto it2 = std::find(liczby2.begin(), liczby2.end(), a);
            while (it2 != liczby2.end()) {
                liczby2.erase(it2);
                std::cout << a << " usunieto z drugiego wektora" << std::endl;
                it2 = std::find(liczby2.begin(), liczby2.end(), a);
                if(i==1){i=2;};
            }

            if(i==0){
                std::cout<<"wartosci "<<a<<" nie ma w zadnym z wektorow."<<std::endl;
            }

        }

        void zmien(){
            std::swap(liczby1, liczby2);
        }
};

//zadanie 3
class Student{
    private:
        std::string imie;
        std::string nazwisko;
    public:
        Student(std::string imie, std::string nazwisko) : imie(imie), nazwisko(nazwisko) {}

        std::string getImie() const {
            return imie;
        }

        std::string getNazwisko() const {
            return nazwisko;
        }

        bool operator<(const Student& other) const {
            return imie < other.imie;
        }
};

void WyswietlOceny(const std::map<Student, std::vector<int>>& _oceny) {
    for (const auto& pair : _oceny) {
        const Student& student = pair.first;
        const std::vector<int>& grades = pair.second;

        // Wyświetlenie nazwy studenta
        std::cout << "Student: " << student.getNazwisko()<<" "<<student.getImie() << std::endl;

        // Wyświetlenie ocen
        std::cout << "Oceny: ";
        for (int grade : grades) {
            std::cout << grade << " ";
        }
        std::cout << std::endl;

        // Obliczenie średniej ocen
        double average = 0.0;
        for (int grade : grades) {
            average += grade;
        }
        average /= grades.size();

        // Wyświetlenie średniej ocen
        std::cout << "Średnia: " << std::fixed << std::setprecision(2) << average << std::endl;

        std::cout << std::endl; // Oddzielenie informacji o kolejnych studentach
    }
}

int main(){
    //zadanie 1
    std::cout<<std::endl;
    std::cout<<"==============================="<<std::endl;
    std::cout<<"Zadanie 1: "<<std::endl;
    impreza sylwek;
    sylwek.moi_dodaj("Jaroslaw");
    sylwek.moi_dodaj("Mateusz");
    sylwek.moi_dodaj("Szymon");
    sylwek.moi_dodaj("Donald");
    sylwek.jego_dodaj("Przemyslaw");
    sylwek.jego_dodaj("Borys");
    sylwek.jego_dodaj("Andrzej");
    sylwek.jego_dodaj("Donald");
    sylwek.jego_wyswietl();
    sylwek.moi_wyswietl();
    sylwek.scal();
    sylwek.wyswietl_wspolne();
    

    //zadanie 2
    std::cout<<std::endl;
    std::cout<<"==============================="<<std::endl;
    std::cout<<"Zadanie 2: "<<std::endl;
    KonWekt zestaw1;
    zestaw1.dodaj_poczatek1(4);
    zestaw1.dodaj_poczatek1(1);
    zestaw1.dodaj_poczatek1(7);
    zestaw1.dodaj_poczatek1(2);
    zestaw1.dodaj_poczatek1(6);
    zestaw1.dodaj_koniec1(3);
    zestaw1.dodaj_koniec1(9);
    zestaw1.dodaj_koniec1(1);
    zestaw1.dodaj_koniec1(0);
    zestaw1.dodaj_koniec1(11);
    zestaw1.dodaj_poczatek2(77);
    zestaw1.dodaj_poczatek2(12);
    zestaw1.dodaj_poczatek2(73);
    zestaw1.dodaj_poczatek2(2);
    zestaw1.dodaj_poczatek2(65);
    zestaw1.dodaj_koniec2(32);
    zestaw1.dodaj_koniec2(93);
    zestaw1.dodaj_koniec2(41);
    zestaw1.dodaj_koniec2(40);
    zestaw1.dodaj_koniec2(1);
    zestaw1.wyswietl1();
    zestaw1.wyswietl2();
    int a;
    std::cout<<"Podaj pierwsza liczbe do usuniecia: "<<std::endl;
    std::cin>>a;
    zestaw1.usun(a);
    std::cout<<"Podaj druga liczbe do usuniecia: "<<std::endl;
    std::cin>>a;
    zestaw1.usun(a);
    std::cout<<"wartosci obu wektorow po usunieciu i zamianie wartosci: "<<std::endl;
    zestaw1.zmien();
    zestaw1.wyswietl1();
    zestaw1.wyswietl2();

    //zadanie 3
    std::cout<<std::endl;
    std::cout<<"==============================="<<std::endl;
    std::cout<<"Zadanie 3: "<<std::endl;

    Student student("Robert", "Biedron");
    Student studentka("Anna", "Kowal");

    std::map<Student, std::vector<int>> oceny;
    oceny[student] = {4, 5, 3};
    oceny[studentka] = {5, 5, 5};
    
    std::cout<<"Poczatkowe oceny: "<<std::endl;
    WyswietlOceny(oceny);

    auto it = oceny.find(studentka);
    if (it != oceny.end()) {

        it->second[0] = 3;

        const Student& student = it->first;
        const std::vector<int>& grades = it->second;

    } else {
        std::cout << "Nie znaleziono studentki o imieniu: " << studentka.getImie() << std::endl;
    }

    std::cout<<"Oceny po zmianie jednej z ocen studentki na 3: "<<std::endl;
    WyswietlOceny(oceny);
    
    //swap i wyswietlanie

    auto it1 = oceny.find(student);
    auto it2 = oceny.find(studentka);

    if (it1 != oceny.end() && it2 != oceny.end()) {
        // Swap the grades
        std::swap(it1->second, it2->second);
    } else {
        std::cout << "Nie znaleziono jednego z studentów." << std::endl;
    }

    std::cout<<"Oceny po zmianie ocen studenta i studenki: "<<std::endl;
    WyswietlOceny(oceny);


};