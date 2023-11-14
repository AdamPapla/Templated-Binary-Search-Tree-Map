#include <iostream>
#include <map>
#include "map.hh"
using namespace std;
int main(){

    Map<string, int> counter ("Adam", 10);
    counter["Isabel"] = 5;
    counter.insert("Jack", 10);
    counter["Jack"] = 20;
    counter.display();
    std::cout << counter.at("Jack") << endl;
    std::cout << counter.at("Jacl") << endl;

    return 0;
}