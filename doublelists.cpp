//
// Created by jimen on 10/01/2024.
//
#include "iostream"
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

template <typename T>
class List {
private:
    Node* head;
    Node* tail;
public:
    List(): head(nullptr), tail(nullptr) {}

    T front(){ return head->data;} // Retorna el elemento al comienzo

    T back(){return tail->data;} // Retorna el elemento al final

    void push_front(T value){
        Node* nodo = new Node{value, head, nullptr};
        if (head)
            head->prev = nodo;
        else
            tail = nodo;
        head = nodo;
    } // Agrega un elemento al comienzo

    void push_back(T value){
        Node* nodo = new Node{value, nullptr, tail};
        if (tail)
            tail->next = nodo;
        else
            head = nodo;
        tail = nodo;
    } // Agrega un elemento al final

    T pop_front(){
        if (head == NULL)
            cout<<"Error. No existe el elemento"<<endl;
        else{
            T value = head->data;
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
            return value;
        }
    } // Remueve el elemento al comienzo

    T pop_back(){
        if (tail == NULL)
            cout << "Error. No existe el elemento"<<endl;
        else{
            T value = tail->data;
            Node* temp = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
            return value;
        }

    } // Remueve el elemento al final

    void insert(T value, int pos){
        if (pos == 0)
            push_front(value);
        else if (pos == size())
            push_back(value);
        else {
            Node* temp = head;
            for (int i = 0; i < pos - 1; i++)
                temp = temp->next;
            // actualizando el nuevo nodo
            Node* nodo = new Node{value, temp->next, temp};
            // actualizando punteros
            temp->next->prev = nodo;
            temp->next = nodo;
        }

    } // Inserta en cualquier posición

    void remove(int pos){
        if (pos == 0)
            pop_front();
        else {
            Node* temp = head;
            for (int i = 0; i < pos; i++)
                temp = temp->next;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    } // Remueve en cualquier posicion

    T operator[ ](int pos){
        Node* temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;

        return temp->data;
    } // Retorna el elemento en la posición indicada

    bool empty(){
        if (head == NULL && tail == NULL )
            return true;
        else
            return false;
    } // Retorna si la lista está vacía o no

    int size(){
        Node* temp = head;
        int size = 0;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }
        return size;
    } // Retorna el tamaño de la lista

    void clear(){
        Node* temp = head;
        while(temp != NULL){
            head = head->next;
            delete temp;
            temp = head;
        }
    } // Elimina todos los elementos de la lista

    void reverse(){
        Node* current = head;
        Node* temp = nullptr;
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp) {
            head = temp->prev;
        }
    } // Revierte la lista
};



int main (){
    // Ejemplo
    List<int> list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_back(4);
    list.push_back(5);

    cout << "Lista: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;
    cout << "Pop front: " << list.pop_front() << endl;
    cout << "Pop back: " << list.pop_back() << endl;

    cout << "Luego del pop_front y pop_back: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    // insertando 10 en la posición 1
    list.insert(10, 1);

    cout << "Insertando 10 en la posicion 1: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    // eliminando el elemento de la posición 3
    list.remove(3);

    cout << "Remove: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    // revertir lista
    list.reverse();

    cout << "Reverse: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    cout << "La lista esta vacia? " << (list.empty() ? "Si" : "No")<< endl;

    // tamaño de la lista
    cout << "Size: " << list.size() << endl;

    // limpiar la lista
    list.clear();

    // tamaño luego de limpiar la lista
    cout << "Size: " << list.size() << endl;

}