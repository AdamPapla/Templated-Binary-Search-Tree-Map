#ifndef Map_HH_
#define Map_HH_
#include <iostream>
#include <memory>
#include "node.hh"

template<typename T, typename U>
class Map{
public:
    Map() : root {nullptr} {}
    Map(const std::pair<T,U>& initialPair) : root {std::make_unique<Node<T,U>> (initialPair)} {}
    Map(const T& k, const U& v) : root {std::make_unique<Node<T,U>> (k, v)} {}
    Map(const Map& in){
        root = std::make_unique<Node<T,U>> (*(in.root));
    }
    Map operator=(const Map& original){
        *root = *(original.root);
        return *this;
    }
    void insert(std::pair<T, U> entry){
        std::unique_ptr<Node<T,U>> newNode = std::make_unique<Node<T,U>> (entry);
        insertRecursion(std::move(newNode), root);
    }
    void insert(T key, U value){
        std::unique_ptr<Node<T,U>> newNode = std::make_unique<Node<T,U>> (key, value);
        insertRecursion(std::move(newNode), root);
    }

    U& at(const T& key){
        std::unique_ptr<Node<T,U>>& foundNode = searchRecursion(key, root);
        if (foundNode -> key == root -> key && root -> key != key){
            throw std::out_of_range("No key corresponding to given index");
        }
        return foundNode -> value;
    }
    const U& at(const T& key) const{
        const std::unique_ptr<Node<T,U>>& foundNode = searchRecursion(key, root);
        if (foundNode -> key == root -> key && root -> key != key){
            throw std::out_of_range("No key corresponding to given index");
        }
        return foundNode -> value;
    }


    void display(){
        displayRecursion(root);
    }



    bool search(T key){
        std::unique_ptr<Node<T,U>>& foundNode = searchRecursion(key, root);
        if (foundNode -> key == root -> key && root -> key != key)
            return false;
        return true;
    }

    U& operator[](const T key);

    private:

    void insertRecursion(std::unique_ptr<Node<T,U>> newNode, std::unique_ptr<Node<T,U>>& subRoot);
    void displayRecursion(const std::unique_ptr<Node<T,U>>& root) const;
    std::unique_ptr<Node<T,U>>& searchRecursion(const T& searchKey, std::unique_ptr<Node<T,U>>& subRoot);
    const std::unique_ptr<Node<T,U>>& searchRecursion(const T& searchKey, const std::unique_ptr<Node<T,U>>& root) const;
    std::unique_ptr<Node<T,U>> root;
};

template <typename T, typename U>
U& Map<T,U>::operator[](const T key){
    const std::unique_ptr<Node<T,U>>& foundNode = searchRecursion(key, root);
    if (foundNode -> key == root -> key && root -> key != key){
        insert(key, U());
        return searchRecursion(key, root) -> value;
    }
    return foundNode -> value;
}


template <typename T, typename U>
void Map<T,U>::insertRecursion(std::unique_ptr<Node<T,U>> newNode, std::unique_ptr<Node<T,U>>& root){
    if (newNode == nullptr)
        return;
    else if (root == nullptr){
        return;
    }
    else if(newNode -> key < root -> key){
        if (root -> left == nullptr){
            root -> left = std::move(newNode);
            newNode = nullptr;
        }
        else
            insertRecursion(std::move(newNode), root -> left);
    }
    else if (newNode -> key > root -> key){
        if (root -> right == nullptr){
            root -> right = std::move(newNode);
            newNode = nullptr;
        }
        else
            insertRecursion(std::move(newNode), root -> right);
    }
    else if (newNode -> key == root -> key){
        root -> value = newNode -> value;
    }
}

template <typename T, typename U>
void Map<T,U>::displayRecursion(const std::unique_ptr<Node<T,U>>& root) const{
    if (root != nullptr){
        displayRecursion(root -> left);
        std::cout << *root << std::endl;
        displayRecursion(root -> right);
    }
}

template <typename T, typename U>
const std::unique_ptr<Node<T,U>>& Map<T,U>::searchRecursion(const T& searchKey, const std::unique_ptr<Node<T,U>>& subRoot) const{
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

template <typename T, typename U>
std::unique_ptr<Node<T,U>>& Map<T,U>::searchRecursion(const T& searchKey, std::unique_ptr<Node<T,U>>& subRoot){
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
#endif