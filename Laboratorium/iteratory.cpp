#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <string>

class Algoltera
{
    private:
        std::vector<int> wartosci;

    public:  
        Algoltera(){
            wartosci = {10, 66, 43, 17, 66, 55, 56, 47, 58, 64, 57, 76, 93, 36, 88, 26, 53, 33, 87, 38, 74, 37, 62, 87, 81, 63, 17, 94, 72, 81, 50, 33, 48, 39, 34, 73, 91, 67, 38, 76, 69, 31, 36, 57, 17, 14, 76, 51, 45, 52, 32, 94, 92, 77, 11, 65, 76, 38, 55, 59, 48, 24, 93, 10, 62, 75, 68, 11, 12, 40, 82, 24, 77, 84, 63, 33, 56, 32, 81, 87, 12, 68, 83, 72, 30, 85, 68, 42, 89, 42, 67, 80, 46, 17, 36, 72, 25, 71, 41, 84, 67, 39, 77, 74, 63, 89, 33, 19, 64, 90, 82, 39, 88, 18, 82, 89, 85, 85, 82, 13, 65, 35, 94, 33, 36, 90, 51, 75, 98, 38, 95, 38, 24, 31, 46, 73, 73, 69, 91, 10, 89, 95, 30, 14, 47, 90, 17, 33, 35, 12, 65, 43, 84, 23, 58, 11, 58, 98, 67, 32, 84, 76, 29, 90, 29, 39, 19, 81, 49, 32, 77, 14, 18, 94, 41, 77, 49, 49, 96, 35, 37, 21, 74, 25, 31, 41, 86, 66, 95, 86, 62, 53, 95, 66, 52, 16, 30, 90, 37, 33};
        };
        //zadanie 2
        int El_30(){
            std::vector<int>::iterator it = std::next(wartosci.begin(), 30);
            return *it;
        };
        int El_30_2(){
            std::vector<int>::iterator it = wartosci.begin()+30;
            return *it;
        };

        //zadanie 3
        std::pair<int, int> max_el(){
            std::vector<int>::iterator it=max_element(wartosci.begin(),wartosci.end());
            int position = std::distance(wartosci.begin(), it);
            return std::make_pair(*it, position);
        }

        std::pair<int, int> min_el(){
            std::vector<int>::iterator it=min_element(wartosci.begin(),wartosci.end());
            int position = std::distance(wartosci.begin(), it);
            return std::make_pair(*it, position);
        }

        //zadanie 4
        int il_33(){
            int it =count(wartosci.begin(),wartosci.end(),33);
            return it;
        }
        
        //zadanie 5
        int poz_91(){
            std::vector<int>::iterator it=find(wartosci.begin(),wartosci.end(),91);
            int position = std::distance(wartosci.begin(), it);
            return position;
        }

        //zadanie 6
        int sum_30_40(){
            int it=accumulate(wartosci.begin()+30,wartosci.begin()+40,0);
            return it;
        }

        //zadanie 7
        void sortW(){
             std::sort(wartosci.begin(), wartosci.end());

            std::cout << "Posortowany wektor: " << std::endl;
            for (std::vector<int>::iterator it = wartosci.begin(); it != wartosci.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        };

        //zadanie 8
        void usuwanieDuplikatow() {
            auto iter = std::unique(wartosci.begin(), wartosci.end());
            
            // Erase elements from the vector based on the iterator returned by std::unique
            wartosci.erase(iter, wartosci.end());

            std::cout << "Wektor po usunieciu duplikatow: " << std::endl;
            for (std::vector<int>::iterator it = wartosci.begin(); it != wartosci.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }

        //zadanie 9
        bool Czy_60(){
            return binary_search(wartosci.begin(),wartosci.end(),60);
        }
};


int main(){
    Algoltera test;
    int a=test.El_30();
    std::cout<<"wartosc na 30 pozycji: "<< a<<std::endl;
    a=test.El_30_2();
    std::cout<<"wartosc na 30 pozycji: "<< a<<std::endl;
    std::pair<int, int> result = test.max_el();
    std::cout<<"Maksymalny element "<<result.first<<", znajduje sie na pozycji: "<< result.second<<std::endl;
    result = test.min_el();
    std::cout<<"Maksymalny element "<<result.first<<", znajduje sie na pozycji: "<< result.second<<std::endl;
    a=test.il_33();
    std::cout<<"ilosc liczb 33: "<< a<<std::endl;
    a=test.poz_91();
    std::cout<<"pozycja liczby 91: "<< a<<std::endl;
    a=test.sum_30_40();
    std::cout<<"suma liczb na pozycjach od 30 do 40: "<< a<<std::endl;
    test.sortW();
    test.usuwanieDuplikatow();
    if( test.Czy_60() ){
        std::cout<<"W tym wektorze występuje 60. "<<std::endl;
    }else{
        std::cout<<"W tym wektorze nie wystepuje 60. "<<std::endl;
    }
    return 0;
};