#include <iostream>

//zadanie 1
template <typename T>
T minimum(T a, T b)
{
    return a < b ? a : b;    
};
template <>
int minimum(int a, int b) {
    std::cout << "Dla typow int";
    return a < b ? a : b;
};
//zadanie 2
template <typename X>
X reference(X *a, X *b)
{
    X temp = *a;
    *a = *b;
    *b = temp;
    return *a, *b;
}

//zadanie 3
template <typename Z>
class kolejka
{
    private:
        Z tab[10];
        int zajetosc = 0;
        bool pelna;
    public:
        kolejka() 
        {
            delete[] tab;
        };
        void drukuj() {
            if(zajestosc !=0){
                for (int i = 0; i <= 9; i++) {
                    std::cout << tab[i] << std::endl;
                }
            }
            else {
                std::cout << "Stos jest pusty";
            }
            
        }
        void wloz(Z x) 
        {
            tab.append(x);
            zajetosc += 1;
        };
        
};

int main()
{
    std::cout << "Zadanie 1: " << minimum('A', 'a') << std::endl;
    int a = 9;
    int b = 10;
    std::cout << "Zadanie 2 przed: " << a << " " << b << std::endl;
    reference(&a, &b);
    std::cout << "Zadanie 2 po: " << a <<" " << b << std::endl;
    std::cout << "Zadanie 3" << std::endl;
    kolejka<int> nowa;
    nowa.drukuj();
    //nowa.wloz(8);
}
