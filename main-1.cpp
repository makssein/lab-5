/*
Дана строка длиной не более 100 символов. 
Удалить в ней все гласные буквы.

Сеин Максим
*/

#include <iostream>
#include <fstream>
#include <sstream>


int main(){
    setlocale(LC_ALL, "Rus");
    unsigned char c;

    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    while (in >> c){
        if (c >= 192 && c <= 223)
            c=' ';
        out << c;
    }

    return 0;
}
