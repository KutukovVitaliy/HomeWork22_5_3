#include <iostream>
#include <map>
#include <string>
#include <vector>

bool CheckWord(std::string& str1, std::string& str2){
    std::map<char, std::vector<int>> strMap1, strMap2;//состоит из символа и вектора, содержащего номер
                                                      //позиции в слове
    if(str1.size() != str2.size()) return false; //Длинны слов не совпадают

    for(int pos = 0; pos < str1.size(); ++pos){
        std::map<char, std::vector<int>>::iterator it;
        it = strMap1.find(str1[pos]);
        if(it != strMap1.end()){    //если такой символ уже есть, то добавляем позицию в вектор
            it->second.push_back(pos);
        }
        else{
            std::vector<int> mas;   //иначе добавляем новый вектор
            mas.push_back(pos);
            strMap1.insert(std::make_pair(str1[pos], mas)); //и новую пару
        }
        it = strMap2.find(str2[pos]);
        if(it != strMap2.end()){
            it->second.push_back(pos);
        }
        else{
            std::vector<int> mas;
            mas.push_back(pos);
            strMap2.insert(std::make_pair(str2[pos], mas));
        }

    }
    std::map<char, std::vector<int>>::iterator it1, it2;
    int quantity = 0;

    for(it1 = strMap1.begin(),it2 = strMap2.begin();it1 != strMap1.end();it1++,it2++){
        if(it1->first != it2->first) return false;
        else
        if(it1->second.size() == it2->second.size()){
            int tmp = 0;
            for(int i = 0; i < it1->second.size(); ++i){
                if(it1->second.at(i) == it2->second.at(i)) tmp++;
            }
            if(tmp == it1->second.size()) quantity++;
        }
        else return false;  //Значит количество букв в словах не совпадает
    }
    if(quantity == strMap1.size()) return false; //Значит слова одинаковые
    return true;
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
