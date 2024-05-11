#ifndef NODE_HPP
#define NODE_HPP
#include "list.hpp"


class Node {
private:
    int idNode;
    char* value;   //Con esto me refiero al valor del Node o sea digamos lo que almacena
    char* nameNode; // este puede no ser necesario
    list<Node*> *pListChilds = new list<Node*>(); 
    int amountChilds;
    int balance;
    int height;
    Node *pNext;

public:
    Node(char *pValue);

// gets y setters
    list<Node*> *getChildsList ();
    int getIdNode();
    void setIdNode(int id);
    char* getValue();
    void setValue(char* value);
    int getAmountChilds();
    void setAmountChilds(int amount);
    int getBalance();
    int getHeight();
    void setHeight(int height);
    Node* getNext();
    void setNext(Node *pNextNode);
};

    Node::Node(char *pNodeValue) {
        idNode = 0;
        value = pNodeValue;
        nameNode = nullptr;
        amountChilds = 0;
        balance = false;
        height = 0;
    
    }


    list<Node*>* Node::getChildsList() {
        return pListChilds;
    }

    int Node::getIdNode() {
        return idNode;
    }

    char* Node::getValue() {
        return value;
    }

    int Node::getAmountChilds() {
        return amountChilds;
    }

    int Node::getBalance() {
        return balance;
    }

    int Node::getHeight(){
        return height;
    }

    void Node::setIdNode(int id) {
        idNode = id;
    }

    void Node::setValue(char* newValue) {
        value = newValue;
    }

    void Node::setAmountChilds(int amount) {
        amountChilds = amount;
    }

    void Node::setHeight(int newHeight) {
        height = newHeight;
    }

    Node* Node::getNext() {
        return pNext;
    }

    void Node::setNext(Node *pNextNode) {
        pNext = pNextNode;
    }

#endif    

