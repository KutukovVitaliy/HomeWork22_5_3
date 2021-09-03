#include <iostream>
#include <map>
#include <string>

bool CheckWord(std::string& str1, std::string& str2){
    std::map<char, int> strMap1, strMap2;
    if(str1.size() != str2.size()) return false;
    for(int pos = 0; pos < str1.size(); ++pos){
        strMap1.insert(std::make_pair(str1[pos], pos));
        strMap2.insert(std::make_pair(str2[pos], pos));
    }
    std::map<char, int>::iterator it1, it2;
    int quantity = 0;

    for(it1 = strMap1.begin(),it2 = strMap2.begin();it1 != strMap1.end();it1++,it2++){
        if(it1->first != it2->first) return false;
        else
        if(it1->second == it2->second) quantity++;
    }
    if(quantity == strMap1.size()) return false;
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
