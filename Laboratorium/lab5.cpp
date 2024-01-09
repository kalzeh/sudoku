#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>

//zadanie1
void sprawdzLiczbe(int liczba) {
    if (liczba % 2 != 0) {
        throw std::runtime_error("Liczba nie jest parzysta.");
    }

    if (liczba % 3 != 0) {
        throw std::runtime_error("Liczba nie jest podzielna przez 3.");
    }

    if (liczba % 5 == 0) {
        throw std::runtime_error("Liczba jest podzielna przez 5.");
    }
}

//zadanie2
class Singleton {
private:
    static Singleton* instance;
    std::ofstream file;
    std::string file_name; 

    Singleton(const std::string& file_name) : file_name(file_name) {
        file.open(file_name, std::ios::app);
    }

public:
    static Singleton* getInstance(const std::string& file_name) {
        if (!instance) {
            instance = new Singleton(file_name);
        }
        return instance;
    }

    void writeToFile(const std::string& data) {
        file << data;
        file.flush();
    }

    std::string readFromFile() {
        std::ifstream inputFile(file_name);
        inputFile.seekg(0, std::ios::beg);
        std::string content((std::istreambuf_iterator<char>(inputFile)),
                             std::istreambuf_iterator<char>());
        inputFile.close();
        return content;
    }

    ~Singleton() {
        if (file.is_open()) {
            file.close();
        }
        instance = nullptr; 
    }
};

Singleton* Singleton::instance = nullptr;

//zadanie 3

class DynamicArray {
private:
    int* array;
    int size;

public:
    DynamicArray(int initialSize) {
        size = initialSize;
        array = new int[size];
    }

    ~DynamicArray() {
        delete[] array;
    }

    void printValueAtIndex(int index) {
        if (index < 0 || index >= size) {
            std::cerr << "Blad: Indeks poza zakresem tablicy!" << std::endl;
            return;
        }
        std::cout << "Wartosc elementu o indeksie " << index << ": " << array[index] << std::endl;
    }

    void printIndexesBelowValue(int value) {
        std::cout << "Indeksy elementow o wartosci mniejszej niz " << value << ": ";
        for (int i = 0; i < size; ++i) {
            if (array[i] < value) {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
    }
};


int main() {

    //zadanie 1
    int liczba;

    std::cout << "Podaj liczbe: ";
    std::cin >> liczba;

    try {
        sprawdzLiczbe(liczba);
        std::cout << "Liczba spelnia warunki." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Wyjatek: " << e.what() << std::endl;
    }

    //zadanie 2

    std::string file_name;
    std::cout << "Podaj nazwe pliku: ";
    std::cin >> file_name;

    Singleton* file_handler = Singleton::getInstance(file_name);

    file_handler->writeToFile("Hello, World!\n");
    std::string file_content = file_handler->readFromFile();
    std::cout << "Zawartosc pliku: " << file_content;

    delete file_handler;

    //zadanie 3
    int arraySize;
    std::cout << "Podaj rozmiar tablicy dynamicznej: ";
    std::cin >> arraySize;

    DynamicArray dynamicArray(arraySize);

    for (int i = 0; i < arraySize; ++i) {
        dynamicArray.printValueAtIndex(i);
    }

    int threshold;
    std::cout << "Podaj wartosc dla porownania: ";
    std::cin >> threshold;

    dynamicArray.printIndexesBelowValue(threshold);


    return 0;
}