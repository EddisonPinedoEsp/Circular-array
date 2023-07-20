#include <iostream>
#include <sstream>
using namespace std;

template<typename T>
struct Node {
    T value;
    Node* next;
    Node(const T& value_) : value(value_), next(nullptr) {}
};

template<typename T>
class ForwardList {
    private:
        Node<T>* head;
    public:
        ForwardList(): head(nullptr) {}
        ~ForwardList() {
            while(head) {
                Node<T>* temp = head;
                head = temp->next;
                delete temp;
            }
        }
        bool empty() {
            return (head == nullptr);
        }
        T front() {
            if (empty()) {
                throw "ForwardList vacio";
            }
            return (head->value);
        }
        T back() {
            if (empty()) {
                throw "ForwardList vacio";
            }
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            return (temp->value);
        }
        void push_front(T value) {
            Node<T>* new_node = new Node<T>(value);
            new_node->next = head;
            head = new_node;
        }
        void push_back(T value){
            Node<T>* new_node = new Node<T>(value);
            if (head == nullptr) {
                head = new_node;
            } else {
                Node<T>* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = new_node;
            }
        }
        void insert(T value, int index) {
            if (empty()) {
                throw "ForwardList: Vacia";
            }
            if (index < 0 || index >= size()) {
                throw "ForwardList: Indice invalido";
            }
            Node<T>* new_node = new Node<T>(value);
            if (index == 0) { // Caso especial para insertar al principio
                new_node->next = head;
                head = new_node;
            } else {
                Node<T>* temp = head;
                int i = 0;
                while (i++ < index - 1) {
                    temp = temp->next;
                }
                new_node->next = temp->next;
                temp->next = new_node;
            } 
        }
        T pop_front() {
            if (empty()) {
                throw "ForwardList: Vacia";
            }
            Node<T>* temp = head;
            head = temp->next;
            T value_ = temp->value;
            delete temp;
            return (value_);
        }
        T pop_back() {
            if (empty()) {
                throw "ForwardList: Vacia";
            }
            T value_;
            if (head->next == nullptr) { // Solo hay un elemento en la lista
                value_ = head->value;
                delete head;
                head = nullptr;
            } else {
                Node<T>* temp = head;
                while (temp->next->next != nullptr) {
                    temp = temp->next;
                }
                value_ = temp->next->value;
                delete temp->next;
                temp->next = nullptr;
            }
            return value_;
        }
        T operator[](int index) {
            if (empty()) {
                throw "ForwardList: Vacia";
            }
            if (index < 0 || index >= size()) {
                throw "ForwardList: Indice invalido";
            }
            Node<T>* temp = head;
            int i = 0;
            while (temp->next != nullptr) {
                if (i == index) {
                    break;
                }
                i++;
                temp = temp->next;
            }
            return (temp->value);
        }
        int size() {
            if (empty()) {
                return(0);
            }
            Node<T>* temp = head;
            int size = 0;
            while (temp->next != nullptr) {
                temp = temp->next;
                size++;
            }
            return (size+1);
        }
        void clear(){
            if (empty()) {
                throw "ForwardList: Vacia";
            }
            while (head) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        }
        // Pendientes
        void reverse();
        void sort();

        void display_list() {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << temp->value << " ";
        }
};

