#include <iostream>
#include <map>
#include "tree.hh"
using namespace std;
int main(){
    Node<int, double>* firstNode = new Node<int, double> (2, 5.0);
    Tree<int, double> myMap (firstNode);
    Node <int, double>* secondNode = new Node<int, double>(1, 4.0);
    myMap.insert(secondNode);
    myMap.insert(new Node<int, double> (4, 2.4));
    myMap.insert(new Node<int, double> (3, 7.4));
    myMap.insert(new Node<int, double> (5, 3.4));
    map<int, double> stlMap;
    cout << "STL MAP: " << stlMap[1] << endl;
    //myMap[18] = 5.0;
    //myMap[1] = 12.0;
    try{
        const double result(myMap[123]);
        cout << "Result = " << result << endl;
    }
    catch(invalid_argument &e){
        cout << e.what() << endl;
    }
    myMap.display();
    return 0;
}