#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

template <typename T>
class List
{
private:
    Node* head;
public:
    List(): head(nullptr) {}

    T front(){return head->data;}

    T back(){
        Node* temp = head;
        temp = temp->next;
        while(temp->next != NULL){
            temp = temp->next;            
        }
        return temp->data;
    }

    void push_front(T value){
        Node* nodo = new Node();
        nodo->data = value;
        nodo->next = head;
        head = nodo;
    }

    void push_back(T value){
        Node* nodo = new Node();
        nodo->data = value;
        nodo->next = NULL;
        while(head->next != NULL)
            head = head->next;
        head->next = nodo;
    }

    T pop_front(){
        if (head == NULL)
            cout << "No hay elementos en la lista" << endl;
        Node* temp = head;
        head = head->next;
        T value = temp->data;
        delete temp;

        return value;
    }

    T pop_back(){
        if (head->next == NULL){
            delete head;
            head = NULL;
        }else{
            Node* temp = head;
            while(temp->next->next != NULL)
                temp = temp->next;
            T value = temp->next->data;
            delete temp->next;
            temp->next = NULL;
            return value;
        }
    }

    T operator[](int pos){
        Node* temp = head;
        for (int i=0; i<pos; i++)
            temp = temp->next;
        return temp->data;
    }

    bool empty(){
        if (head == NULL)
            return true;
        return false;
    }

    int size(){
        Node* temp = head;
        int size = 0;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }
        return size;
    }

    void clear(){
        while(head != NULL){
            Node* temp = head;
            head = head->next;
            delete temp;;
        }
    }

    void sort(){
        Node* temp = head;
        Node* temp2 = head;
        int size = 0;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }
        for (int i = 0; i < size; i++){
            temp = head;
            temp2 = head->next;
            for (int j = 0; j < size-1; j++){
                if (temp->data > temp2->data){
                    int aux = temp->data;
                    temp->data = temp2->data;
                    temp2->data = aux;
                }
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
    }

    void reverse(){
        Node* temp = head;
        Node* temp2 = head;
        int size = 0;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }
        for (int i = 0; i < size; i++){
            temp = head;
            temp2 = head->next;
            for (int j = 0; j < size-1; j++){
                if (temp->data < temp2->data){
                    int aux = temp->data;
                    temp->data = temp2->data;
                    temp2->data = aux;
                }
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
    }
};


int main(){

    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);

    cout << "Lista al inicio: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;
    cout << "Pop_front: " << list.pop_front() << endl;
    cout << "Pop_back: " << list.pop_back() << endl;

    cout << "Luego del pop_front y pop_back: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    cout << "Elemento en posicion 1: " << list[1] << endl;
    cout << "La lista esta vacia? " <<(list.empty() ? "Si" : "No") << endl;
    cout << "Size: " << list.size() << endl;
    cout << "Sort: ";
    list.sort();
    for (int i = 0; i < list.size(); i++){
        cout << list[i] << " ";
    }
    cout << endl << "reverse: ";
    list.reverse();
    for (int i = 0; i < list.size(); i++){
        cout << list[i] << " ";
    }
    cout << endl;

}