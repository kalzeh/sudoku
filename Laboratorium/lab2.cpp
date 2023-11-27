#include <iostream>
#include <algorithm>
#include <vector>

void zadanie1(){
    auto A = [](int x){return x;};
    auto B = [](int x){return (x*4+10);};
    auto C = [](int x){return ((x*x*x)-100);};

    std::cout<<"Zadanie 1, podpunkt A (x):";
    for (int i=0;i<=10;++i){
        std::cout << "dla " << i << ": " << A(i)<< std::endl;
    }
    std::cout<<"Zadanie 1, podpunkt B (Wartosc x*4+10):";
    for (int i=0;i<=10;++i){
        std::cout << "dla " << i << ": " << B(i)<< std::endl;
    }
    std::cout<<"Zadanie 1, podpunkt C (Wartosc x*x*x-100):";
    for (int i=0;i<=10;++i){
        std::cout << "dla " << i << ": " << C(i)<< std::endl;
    }
}

void zadanie2(){
    std::cout<<"Zadanie 2:"<<std::endl;
    std::vector<int> liczby = {1,45,21,5,7,3,2};
    std::cout<<"Wprowadz mnoznik: "<<std::endl;
    int mnoznik;
    std::cin>>mnoznik;
    std::cout<<std::endl;
    std::cout<<"Wektor przed przemnozeniem:"<<std::endl;
    for(const auto el:liczby){
        std::cout<<el<<std::endl;
    }

    std::for_each(liczby.begin(),liczby.end(),[mnoznik](int &el){
        el *= mnoznik;
    });

    std::cout<<"Wektor po przemnozeniu:"<<std::endl;
    for(const auto el:liczby){
        std::cout<<el<<std::endl;
    }
}

void zadanie3(){
    std::cout<<"Zadanie 3:"<<std::endl;
    std::vector<int> liczby;
    std::cout<<"Wprowadz dziesiec liczb (zatwierdz liczbe enterem): "<<std::endl;
    for(int i =0; i<10; i++){
        int temp;
        std::cin>>temp;
        liczby.push_back(temp);
    }
    std::cout<<"Wprowadzone liczby: "<<std::endl;
    int i=0;
    for(const auto &el : liczby){
        std::cout<<"liczby["<<i<<"] = "<<el<<std::endl;
        i++;
    };

    auto max = std::max_element(liczby.begin(),liczby.end(),[](const auto &x, const auto &y){
        return x<y;
    });

    std::cout<<"Najwieksza liczba w tym zbiorze, to: "<<*max<<std::endl;


    auto parzystych = std::count_if(liczby.begin(), liczby.end(), [](const auto &a) -> bool {
        return a % 2 == 0;
    });

    std::cout << "Liczb parzystych jest w zbiorze: " << parzystych << std::endl;

    auto newEnd = std::remove_if(liczby.begin(),liczby.end(), [](const auto &b){
        return b%2==1;
    });
    liczby.erase(newEnd,liczby.end());

    std::cout<<"Zbior, po usunieciu liczb nieparzystych: "<<std::endl;
    i=0;
    for(const auto &el : liczby){
        std::cout<<"liczby["<<i<<"] = "<<el<<std::endl;
        i++;
    };

    std::sort(liczby.begin(),liczby.end(),[](const auto& a, const auto &b){
        return a>b;
    });

    std::cout<<"Zbior, posortowany malejaco: "<<std::endl;
    i=0;
    for(const auto &el : liczby){
        std::cout<<"liczby["<<i<<"] = "<<el<<std::endl;
        i++;
    };

}

int main(){
    zadanie1();
    zadanie2();
    zadanie3();
}