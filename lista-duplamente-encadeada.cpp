#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    Node<T> *next;
    Node<T> *prev;
    T data;
};

template <typename T>
class ListDE
{
private:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *it;
    int n;

public:
    ListDE();
    int size();          // Tamanho da lista
    void clear();        // Limpa tudo
    bool IsEmpty();      // Tá vazia?
    bool PushFront(T d); // Coloca na frente
    bool PushBIt(T d);   // Coloca onde ta apontando
    bool PushAIt(T d);
    bool PushBack(T d); // Coloca atras
    void PopFront();    // Tira da frente
    void PopIt();       // Tira de onde ta apontando
    void PopBack();     // Tira de trás
    T GetFront();       // O que tem na frente?
    T GetIt();          // O que tem aonde aponta?
    T GetBack();        // O que tem atrás?
    void ItBegin();     // Aponta pro começo
    void ItEnd();       // Aponta pro final
    void ItMM();        // Aponta pro próximo
    void Itmm();        // Aponta pro anterior
    bool ItNull();      // Aponta pra NULL
    ~ListDE();          // Desconstrutor
};

template <typename T>
ListDE<T>::ListDE()
{
    head = nullptr;
    it = &head;
    n = 0;
}

template <typename T>
int ListDE<T>::size()
{
    return n;
}

template <typename T>
void ListDE<T>::clear()
{
    Node<T> *P;
    while (head)
    {
        P = head;
        head = head->next;
        delete P;
    }
    it = &head;
    n = 0;
}

template <typename T>
bool ListDE<T>::IsEmpty()
{
    return !head;
}

template <typename T>
bool ListDE<T>::PushFront(T d)
{
    Node<T> *P = new Node<T>;
    if (!P)
        return false;
    P->data = d;
    P->next = head;
    P->prev = head->prev
                  n++;

    return true;
}

template <typename T>
bool ListDE<T>::PushBIt(T d)
{
    Node<T> *P = new Node<T>;
    if (!P)
        return false;
    P->data = d;
    P->next = it;
    P->prev = it->prev;
    if (it->prev)
    {
        (it->prev)->next = P;
    }
    else
    {
        head = P;
    }
    It->prev = P
        n++;

    return true;
}

template <typename T>
bool ListDE<T>::PushAIt(T d)
{
    Node<T> *P = new Node<T>;
    if (!P)
        return false;
    P->data = d;
    P->prev = it;
    P->next = it->next;
    if (it->next)
    {
        (it->next)->prev = P;
    }
    else
    {
        tail = P;
    }
    it->next = P;
    n++;
}

template <typename T>
bool ListDE<T>::PushBack(T d)
{
    Node<T> *P = new Node<T>;
    if (!P)
        return false;
    P->data = d;
    P->next = tail->next;
    P->prev = tail;

    tail->next = P;
    tail = P;
    n++;
}

template <typename T>
void ListDE<T>::PopFront()
{
    Node<T> *P = head;
    head = head->next;
    delete P;
    if (!head)
    {
        head = P;
    }
    if (!tail)
    {
        tail = P;
    }
    n--;
}

template <typename T>
void ListDE<T>::PopIt()
{
    Node<T> *P = it;
    it = it->next;
    delete P;
    if (!head)
    {
        head = P;
    }
    if (!tail)
    {
        tail = P;
    }
    n--;
}

template <typename T>
void ListDE<T>::PopBack()
{
    Node<T> *P;
    P = tail;
    tail = tail->prev;
    delete P;
    if (!head)
    {
        head = P;
    }
    if (!tail)
    {
        tail = P;
    }
    n--;
}

template <typename T>
T ListDE<T>::GetFront()
{
    return head->data;
}

template <typename T>
T ListDE<T>::GetIt()
{
    return it -> data;
}

template <typename T>
T ListDE<T>::GetBack() {
    return tail -> data;
}

template <typename T>
void ListDE<T>::ItBegin()
{
    it = head;
}

template <typename T>
void ListDE<T>::ItEnd() {
    it = tail;
}

template <typename T>
void ListDE<T>::ItMM()
{
    it = it -> next;
}

template <typename T>
void ListDE<T>::Itmm() {
    it = it -> prev;
}

template <typename T>
bool ListDE<T>::ItNull() {
    return !it;
}