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
    try{
    std::cout << counter.at("Jack") << endl;
    std::cout << counter.at("Jacl") << endl;}
    catch(out_of_range& e){
        cout << e.what() << endl;
    }    

    Map<string, int> constCounter {"Adam", 23};
    cout << "Const Map::at: " << constCounter.at("Adam") << endl;
    cout << "Const Map::search " << constCounter.search("Adam") << endl;
    cout << "Const Map::display " << endl;
    constCounter.display();
    Map<string, int> mapCopy = counter;
    cout << "Copy Constructor map: " << endl;
    mapCopy.display();
    Map<string, int> assignMap {"Isabel", 12};
    mapCopy = assignMap;
    cout << "Assigned map" << endl;
    mapCopy.display();
    return 0;
}