/* Дан файл, содержащий русский текст, 
размер текста не превышает 10 К байт. 
Найти в тексте N (N ≤ 100) самых длинных слов, 
в которых все буквы упорядочены по алфавиту. 
Записать найденные слова в текстовый файл в порядке 
не возрастания длины. Все найденные слова должны быть 
разными. Число N вводить из файла.
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <array>


int main(){
    setlocale(LC_ALL, "Rus");

    int n,k,i,j,b,c;
    char s[100];
    std::array<std::string, 100> mas;
    b=1;
    k=1;
    i=0;
    j=1;
    c=0;
    
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    in >> n;
    while(!in.eof()){
        in >> s;
        while(b<strlen(s)){
            if((int)s[i] > (int)s[j]){
                break;
            } else {
                b++;
                i++;
                j++;
            }
        } 
        if(b == strlen(s)){
            for(int i; i<k; i++){
                if(s != mas[i]){
                    mas[k] = s; 
                    k++; 
                }
            }  
        }     
        b=1;
        i=0;
        j=1;
    }
    for(int i=0; i<k; i++){
        for(int j=i+1; j<k; j++){
            if(mas[j].length() > mas[i].length()){
                std::swap(mas[j], mas[i]);
            }
        }
    }
    for(int i=0; i<n; i++){
        out << mas[i] << std::endl; 
    }
        
    return 0;
}
