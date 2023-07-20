#include <iostream>
#include <sstream>
using namespace std;

template<typename T>
struct Node {
    T value;
    Node* next;
    Node* prev;
    Node(const T& value_) : value(value_), next(nullptr), prev(nullptr) {}
};

template<typename T>
class DoublyLinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr) {}
        ~DoublyLinkedList() {
            while(head) {
                Node<T>* temp = head;
                head = temp->next;
                delete temp;
            }
        }
        bool empty() {
            return (head == nullptr && tail == nullptr);
        }
        T front() {
            if (empty()) {
                throw "DoublyLinkedList: Lista vacía";
            }
            return (head->value);
        }
        T back() {
            if (empty()) {
                throw "DoublyLinkedList: Lista vacía";
            }
            return (tail->value);
        }
        void push_front(T value) {
            Node<T>* new_node = new Node<T>(value);
            new_node->next = head;
            if (head) {
                head->prev = new_node;
            } else {
                tail = new_node;
            }
            head = new_node;
        }
        void push_back(T value) {
            Node<T>* new_node = new Node<T>(value);
            new_node->prev = tail;
            if (tail) {
                tail->next = new_node;
            } else {
                head = new_node;
            }
            tail = new_node;
        }
        void insert(T value, int index) {
            if (index < 0 || index >= size()) {
                throw "Doubly-linked-list: Indice invalido";
            }
            Node<T>* new_node = new Node<T>(value);
            if (index == 0) {
                new_node->next = head;
                if (head) head->prev = new_node;
                else tail = new_node;
                head = new_node;
            } else {
                Node<T>* temp = head;
                int i = 0;
                while (i++ < index ) {
                    temp = temp->next;
                }
                new_node->next = temp;
                new_node->prev = temp->prev;
                temp->prev->next = new_node;
                temp->prev = new_node; 
            }
        }
        T pop_front() {
            if (empty()) {
                throw "DoublyLinkedList: Lista vacía";
            }
            Node<T>* temp = head;
            head = temp->next;
            if (head) head->prev = nullptr;
            T value_ = temp->value;
            delete temp;
            return (value_);
        }
        T pop_back() {
            if (empty()) {
                throw "DoublyLinkedList: Lista vacía";
            }
            Node<T>* temp = tail;
            tail = temp->prev;
            if (tail) tail->next = nullptr;
            T value_ = temp->value;
            delete temp;
            return (value_);
        }
        int size() {
            if (empty()) {
                return 0;
            }
            Node<T>* temp = head;
            int size = 0;
            while(temp->next != nullptr) {
                temp = temp->next;
                size++;
            }
            return (size+1);                                        
        }
        T operator[](int index) {
            if (empty()) {
                throw "DoublyLinkedList: Lista vacía";
            }
            if (index < 0 || index >= size()) {
                throw "Doubly-linked-list: Indice invalido";
            }
            Node<T>* temp = head;
            int i = 0;
            while (i++ < index ) {
                temp = temp->next;
            }
            return (temp->value);
        }
        void remove(int index) {
            if (empty()) {
                throw "DoublyLinkedList: Lista vacía";
            }
            if (index < 0 || index >= size()) {
                throw "Doubly-linked-list: Indice invalido";
            }
            if (index == 0) {
                head->next->prev = nullptr;
                head = head->next;
            } else if (index == size()-1) {
                tail->prev->next = nullptr;
                tail = tail->prev;
            } else {
                Node<T>* temp = head;
                int i = 0;
                while (i++ < index ) {
                    temp = temp->next;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
        }
        void clear() {
            if (empty()) {
                throw "DoublyLinkedList: Lista vacía";
            }
            while(head) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;
        }
        void reverse(); // Falta implementar

        void display_list() {
            for (Node<T>* p = head; p != nullptr; p = p->next) {
                cout << p->value << " ";
            }
        }
};