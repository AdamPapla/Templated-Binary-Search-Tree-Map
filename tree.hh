#ifndef TREE_HH_
#define TREE_HH_
#include <iostream>
#include <memory>

template<typename T, typename U>
struct Node{
    Node () : key {T()}, value {U()}, left {nullptr}, right {nullptr} {}
    Node(T k, U v) : key {k}, value {v}, left {nullptr}, right {nullptr} {}
    Node(T k, U v, Node* l, Node* r) : 
        key {k}, value {v}, left {move(l)}, right {move(r)} {}
    T key;
    U value;
    Node* left;
    Node* right;
};

template<typename V, typename W>
std::ostream& operator<<(std::ostream& os, const Node<V,W>& in){
    os << "key: " << in.key << "\tvalue: " << in.value;
    return os;
}

template<typename T, typename U>
class Tree{
public:
    Tree() : root {nullptr} {}
    Tree(Node<T,U>* r) : root {r} {}
    int insert(Node<T,U>* newNode){
        insertRecursion(newNode, root);
        return 0;
    }
    void display(){
        displayRecursion(root);
    }
    U& operator[](const T key) const{
        std::cout << "Overload one" << std::endl;
        const Node<T,U>* result = searchRecursion(key, root);
        if (result == root && root -> key != key)
            throw(std::invalid_argument("Key not found"));
        return result -> value;
    }
    U& operator[](const T key){
        std::cout << "Overload two" << std::endl;
        Node<T,U>* result = searchRecursion(key, root);
        if (result == root && root -> key != key){
            Node<T,U>* newNode = new Node<T,U> (key, U());
            insert(newNode);
            return newNode -> value;
        }
        else {
            return result -> value;
        }
        return result -> value;
    }
    private:
    void insertRecursion(Node<T,U>* newNode, Node<T,U>* root){
        if (root == nullptr)
            return;
        else if(newNode -> key < root -> key){
            if (root -> left == nullptr)
                root -> left = newNode;
            else
                insertRecursion(newNode, root -> left);
        }
        else if (newNode -> key > root -> key){
            if (root -> right == nullptr)
                root -> right = newNode;
            else
                insertRecursion(newNode, root -> right);
        }
        else if (newNode -> key == root -> key){
            root -> value = newNode -> value;
        }
    }
    void displayRecursion(Node<T,U>* root){
        if (root != nullptr){
            displayRecursion(root -> left);
            std::cout << *root << std::endl;
            displayRecursion(root -> right);
        }
    }
    /*Node<T,U>*& searchRecursion(const T& searchKey, Node<T,U>* &subRoot){
        if (subRoot == nullptr)
            return root;
        else if (subRoot -> key == searchKey)
            return subRoot;
        else if (subRoot -> key > searchKey)
            return searchRecursion(searchKey, subRoot -> left);
        else if (subRoot -> key < searchKey)
            return searchRecursion(searchKey, subRoot -> right);  
        return root;
    }*/
    Node<T,U>* searchRecursion(const T& searchKey, Node<T,U>* subRoot) const{
        if (subRoot == nullptr)
            return root;
        else if (subRoot -> key == searchKey)
            return subRoot;
        else if (subRoot -> key > searchKey)
            return searchRecursion(searchKey, subRoot -> left);
        else if (subRoot -> key < searchKey)
            return searchRecursion(searchKey, subRoot -> right);  
        return root;
    }
    Node<T,U>* root;
};
#endif