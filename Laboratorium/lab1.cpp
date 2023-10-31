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
            for(int  i = 0; i<10; i++ )
            {
                tab[i]= Z();
            }
            zajetosc = 0;
        };

        void drukuj() {
            if(zajetosc !=0){
                for (int i = 0; i <= 9; i++) {
                    std::cout << tab[i] << std::endl;
                }
            }
            else {
                std::cout << "Stos jest pusty"<<std::endl;
            }
            
        };

        void wloz(Z x) 
        {
            if(zajetosc < 10)
            {
                tab[zajetosc] = x;
                zajetosc += 1;
            }else{
                std::cout<<"Stos jest pelny"<<std::endl;
            }
        };
        
        Z wez() 
        {
            Z temp = tab[zajetosc-1];
            tab[zajetosc-1] = Z();
            zajetosc-=1;
            return temp;
        };

        int ile_elem(){
            return zajetosc;
        };

        bool czyPusta(){
            return (zajetosc == 0);
        };

        bool czyPelna(){
            return (zajetosc==10);
        };

        ~kolejka(){};
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
    kolejka<int> kolejka_int;
    kolejka<std::string> kolejka_string;
    int x;
    std::string y;

    for(int i =0; i < 3;i++){
        std::cout<<"Co chcesz dodac do kolejki intow?";
        std::cin>>x;
        std::cout<<std::endl;
        kolejka_int.wloz(x);
    }

    for(int i =0; i < 5;i++){
        std::cout<<"Co chcesz dodac do kolejki stringow?";
        std::cin>>y;
        std::cout<<std::endl;
        const char* cstr = y.c_str();
        kolejka_string.wloz(cstr);
    }
    
    

    std::cout<<"Kolejka intow: "<<std::endl;
    kolejka_int.drukuj();
    std::cout<<"Kolejka stringow: "<<std::endl;
    kolejka_string.drukuj();

    int z  = kolejka_int.wez();
    std::cout<<z<<std::endl;
    std::cout<<"Kolejka intow: "<<std::endl;
    kolejka_int.drukuj();
}
