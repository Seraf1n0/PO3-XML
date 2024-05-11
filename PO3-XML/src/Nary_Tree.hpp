#ifndef NARY_TREE_HPP
#define NARY_TREE_HPP

#include "Node.hpp"
#include "list.hpp"

class NaryTreeNode {
private:
    Node* node;

public:
    //NaryTreeNode(Node* pNode) : node(pNode) {}
    //node * suNodo = new node(nullptr) 

    NaryTreeNode() : node(new Node(nullptr)) {} // Creación del nuevo nodo

    NaryTreeNode(Node* pNode) : node(pNode) {}

    Node* getNode() const {
        return node;
    }

    void addChild(Node* childNode) {
        node->getChildsList()->insertar(childNode);
    }
    //void addChild(NaryTreeNode* childNode) {
    //    node->getChildsList()->insertar(childNode->getNode());
    //}

    list<Node*>* getChildren() const {
        return node->getChildsList();
    }

    Node* search(int targetId) const {
        return searchHelper(node, targetId);
    }

private:
    Node* searchHelper(Node* currentNode, int targetId) const {
        if (currentNode == nullptr) {
            return nullptr;
        }

        if (currentNode->getIdNode() == targetId) {
            return currentNode;
        }

        list<Node*>* childNodes = currentNode->getChildsList();
        Node* temporal = childNodes->apPrimero;

        while (temporal != nullptr) {
            Node* result = searchHelper(temporal, targetId);
            if (result != nullptr) {
                return result;
            }
            temporal = temporal->getNext();
        }

        return nullptr;
    }
};

class NaryTree {
private:
    NaryTreeNode* root;

public:
    NaryTree() : root(nullptr) {}
    ~NaryTree() {
        // Liberación de memoria
    }

    void setRoot(Node* rootNode) {
        root = new NaryTreeNode(rootNode);
    }

    NaryTreeNode* getRoot() const {
        return root;
    }

    void addChildToNode(NaryTreeNode* parentNode, NaryTreeNode* childNode) {
        if (parentNode != nullptr) {
            parentNode->addChild(childNode);
        }
    }

    void removeChildFromNode(NaryTreeNode* parentNode, Node* childNode) {
        if (parentNode != nullptr) {
            list<Node*>* children = parentNode->getChildren();
            children->borrarNode(childNode);
        }
    }
};

#endif
