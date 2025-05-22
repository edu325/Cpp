#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
    public:
        Node<T>* next;
        T data;
};

template <typename T>
class List {
    private: 
        Node<T>* head;
        Node<T>** it;
        int n;
    public:
        List();
        int size();     // Tamanho da lista
        void clear();   // Limpa tudo
        bool IsEmpty(); // Tá vazia?
        bool PushFront(T d);    // Coloca na frente
        bool PushIt(T d);   // Coloca onde ta apontando
        void PopFront();    // Tira da frente
        void PopIt();   // Tira de onde ta apontando
        T GetFront();   // O que tem na frente?
        T GetIt();  // O que tem aonde aponta?
        void ItBegin(); // Aponta pro começo
        void ItMM();    // Aponta pro próximo
        ~List();    // Desconstrutor
};

template <typename T>
List<T>::List() {
    n = 0;
    head = nullptr;
    it = &head;
}

template <typename T>
int List<T>::size() {
    return n;
}

template <typename T>
void List<T>::clear() {
    Node<T>* P;
    while (head) {
        P = head;
        head = head -> next;
        delete P;
    }
    it = &head;
    n = 0;
}

template <typename T>
bool List<T>::IsEmpty() {
    return !head;
}

template <typename T>
bool List<T>::PushFront(T d) {
    Node<T>* P = new Node<T>;
    if (!P) return false;
    P -> data = d;
    P -> next = head;
    n++;

    return true;
}

template <typename T>
bool List<T>::PushIt(T d) {
    Node<T>* P = new Node<T>;
    if(!P) return false;
    P -> data = d;
    P -> next = *it;
    *it = P;
    n++;

    return true;
}

template <typename T>
void List<T>::PopFront() {
    Node<T>* P = head;
    head = head -> next;
    delete P;
    n--;
}

template <typename T>
void List<T>::PopIt() {
    Node<T>* P = *it;
    *it = P -> next;
    delete P;
    n--;
}

template <typename T>
T List<T>::GetFront() {
    return head -> data;
}

template <typename T>
T List<T>::GetIt() {
    return (*it) -> data;
}

template <typename T>
void List<T>::ItBegin() {
    it = &head;
}

template <typename T>
void List<T>::ItMM() {
    it = &((*it) -> next);
}
