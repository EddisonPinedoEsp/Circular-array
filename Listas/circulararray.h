#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class CircularArray {
    private:
        T *array;
        int capacity;
        int back, front;

    public:
        CircularArray(int _capacity) {
            this->array = new T[_capacity];
            this->capacity = _capacity;
            this->back = front = -1;
        }
        virtual ~CircularArray() {
            delete[] array;
        }
        bool is_full() {
            return ((back + 1) % capacity == front);
        }
        bool is_empty() {
            return (front == -1 && back == -1);
        }
        int size() {
            if (front == -1) {
                return 0;
            }
            if (front <= back) {
                return (back - front + 1);
            } else {
                return (capacity - front + back + 1);
            }
        }
        void push_front(T data) {
            if (is_full()) {
                throw "El array esta lleno";
            } 
            if (is_empty()){
                front = 0;
                back = 0;
            } else {
                front = prev(front);
            }
            array[front] = data;
        }
        void push_back(T data) {
            if (is_full()) {
                throw "El array esta lleno";
            }
            if (is_empty()) {
                front = 0;
                back = 0;
            } else {
                back = next(back);
            }
            array[back] = data;
        }
        void insert(T data, int pos) {
            // if (pos < 0 || pos >= capacity) {
            //     throw;
            // }
            // if (is_full()) {
            //     throw;
            // } else if (pos == back) {
            //     push_back(data);
            //     return;
            // } else if (pos == front) {
            //     push_front(data);
            //     return;
            // }
            // pos = (front + pos) % capacity;
            // array[pos] = data;
            // back = next(back);
            
            // Falta implementation
        }
        T pop_front() {
            if (is_empty()) {
                throw "El array esta vacio";
            }
            if (front == back) {
                front = back = -1;
            } else {
                front  = next(front);
            }
            return array[front];
        }
        T pop_back() {
            if (is_empty()) {
                throw "El array esta vacio";
            }
            if (front == back) {
                front = back = -1;
            } else {
                back = prev(back);
            }
            return array[back];
        }
        void clear() {
            this->front = this->back = -1;
        }
        T& operator[](int index) {
            if (index < 0 || index >= capacity) {
                throw "La posicion esta fuera de rango";
            } 
            if (index >= size()) {
                throw "Indice no inicializado";
            }
            else {
                index = (front + index) % capacity;
            }
            return array[index];
        } 
        bool is_sorted() {
            if (is_empty()) {
                return true;
            }

            int iter = front;
            while (iter != back) {
                int next_inter = next(iter);
                if (array[iter] > array[next_inter]) {
                    return false;
                }
                iter = next_inter;
            }
            return true;
        }
        void sort() {
            if (is_empty()) {
                return;
            } 
            for (int i = 0; i < size() - 1; i++) {
                for (int j = 0; j < size() - i - 1; j++) {
                    if (array[(front + j) % capacity] > array[(front + j +1) % capacity]) {
                        T temp = array[(front + j) % capacity];
                        array[(front + j) % capacity] = array[(front + j + 1) % capacity];
                        array[(front + j + 1) % capacity] = temp;
                    }
                }
            }
        }
        void reverse() {
            if (is_empty()) {
                return;
            }
            int i = front, j = back;
            while(i != j && next(i) != j) {
                T temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i = next(i);
                j = prev(j);
            }
        }
        string to_string(string sep=" ") {
            stringstream ss;

            if (is_empty()) {
                ss << "El arreglo esta vacio";
            } else {
                int current = front;
                while (current != back) {
                    ss << array[current] << sep;
                    current = next(current);
                }
                ss << array[back] << sep;
            }
            return ss.str();
        }

    private:
        int next(int index) {
            return ((index + 1) % capacity);
        }
        int prev(int index) {
            return ((index - 1 + capacity) % capacity);
        }
};


