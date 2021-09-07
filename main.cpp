#include <iostream>
#include <map>
#include <string>
#include <vector>

bool CheckWord(std::string& str1, std::string& str2){
    std::map<char, int> strMap1, strMap2;//состоит из символа и вектора, содержащего номер
                                                      //позиции в слове
    if(str1.size() != str2.size()) return false; //Длинны слов не совпадают
    if(str1 == str2) return false;
    for(int pos = 0; pos < str1.size(); ++pos){
        std::map<char, int>::iterator it;
        it = strMap1.find(str1[pos]);
        if(it != strMap1.end()){    //если такой символ уже есть, то добавляем 1 в кол-во символов
            it->second +=1;
        }
        else{
            strMap1.insert(std::make_pair(str1[pos], 1)); //и новую пару
        }
        it = strMap2.find(str2[pos]);
        if(it != strMap2.end()){
            it->second +=1;
        }
        else{
            strMap2.insert(std::make_pair(str2[pos], 1));
        }

    }
    if(strMap1 != strMap2) return false;
    else return true;
}

int main() {
    std::string str1,str2;

    std::cout << "First word: ";
    std::cin >> str1;
    std::cout << "Second word: ";
    std::cin >> str2;
    bool result = CheckWord(str1, str2);
    if(result) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
    return 0;
}
