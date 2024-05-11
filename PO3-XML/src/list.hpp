#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

template <typename T>
class list {
private:
    int cantidad;
    T* apPrimero;
    T* apUltimo;

public:
    list();
	int getLength ();
    void insertar(T* pData);
    void imprimirLista();
    T* buscarNode(T* pData);
    void borrarNode(T* pData);
};

// Implementación de la lista

template <typename T>
list<T>::list() {
    cantidad = 0;
    apPrimero = nullptr;
    apUltimo = nullptr;
}

template <typename T>
void list<T>::insertar(T* pData) {
    if (!pData) {
        return;
    }

    if (apPrimero == nullptr) {
        apPrimero = pData;
        apUltimo = pData;
        apPrimero->setNext(nullptr);
    } else {
        apUltimo->setNext(pData);
        apUltimo = pData;
    }
    cantidad++;
}

template <typename T>
void list<T>::imprimirLista() {
    T* temporal = apPrimero;
    while (temporal != nullptr) {
        std::cout << "N@[" << temporal << "] = " << temporal->getValue() << std::endl;
        temporal = temporal->getNext();
    }
}

template <typename T>
T* list<T>::buscarNode(T* pData) {
    T* temporal = apPrimero;
    while (temporal != nullptr) {
        if (temporal->getValue() == pData->getValue()) {
            return temporal;
        }
        temporal = temporal->getNext();
    }
    return nullptr;
}

template <typename T>
void list<T>::borrarNode(T* pData) {
    if (!apPrimero) {
        return;
    }

    T* temporal = apPrimero;
    T* anterior = nullptr;

    while (temporal != nullptr) {
        if (temporal->getValue() == pData->getValue()) {
            if (temporal == apPrimero) {
                apPrimero = apPrimero->getNext();
            } else {
                anterior->setNext(temporal->getNext());
            }

            if (temporal == apUltimo) {
                apUltimo = anterior;
            }

            delete temporal;  // Asegurarse de liberar la memoria
            cantidad--;
            return;
        }

        anterior = temporal;
        temporal = temporal->getNext();
    }

}

template <typename T>
int list<T>::getLength () {
	return cantidad;
}

#endif