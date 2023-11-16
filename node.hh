#ifndef NODE_HH_
#define NODE_HH_
#include <iostream>
template<typename T, typename U>
struct Node{
    Node () : left {nullptr}, right {nullptr} {}
    Node (const T& k) : key {k}, value {U()}, left {nullptr}, right {nullptr} {}
    Node(const std::pair<T,U>& in) : 
        key {in.first}, value {in.second}, left {nullptr}, right {nullptr} {}
    Node(const T& k, const U& v) :
        key {k}, value {v}, left {nullptr}, right {nullptr} {}
    Node(const std::pair<T,U>& in, Node* l, Node* r) : 
        key {in.first}, value {in.second}, left {l}, right {r} {}
    Node(const T& k, const U& v, Node* l, Node* r) : 
        key {k}, value {v}, left {l}, right {r} {}
    // Note:    Due to ownership, copy constructor will copy subtree of current node.
    //          Can't have two nodes with the same children node objects.
    Node(const Node& in) : key {in.key}, value {in.value}{
        if (in.left != nullptr)
            left = std::make_unique<Node<T,U>>(*(in.left));
        if (in.right != nullptr)
            right = std::make_unique<Node<T,U>> (*(in.right));
    }
    Node& operator=(const Node& in){
        key = in.key;
        value = in.value;
        left = nullptr;
        right = nullptr;
        if (in.left != nullptr)
            left = std::make_unique<Node<T,U>> (*(in.left));
        if (in.right != nullptr)
            right = std::make_unique<Node<T,U>> (*(in.right));
        return *this;
    }
    T key;
    U value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
};

template<typename V, typename W>
std::ostream& operator<<(std::ostream& os, const Node<V,W>& in){
    os << "key: " << in.key << "\tvalue: " << in.value;
    return os;
}

#endif