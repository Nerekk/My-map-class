#ifndef UNTITLED2_MAP_H
#define UNTITLED2_MAP_H

#include <iostream>
#include <string>

using namespace std;

class KeyAlreadyExistsException : public exception {
public:
    const char* what() const throw() {
        return "Key exists";
    }
};

template <class KEY, class VALUE> class Map {
private:
    KEY* keys;
    VALUE* values;
    int size;
    int capacity;

public:
    Map() {
        this->size = 0;
        this->capacity = 5;

        this->keys = new KEY[this->capacity];
        this->values = new VALUE[this->capacity];
    }

    Map(const Map<KEY, VALUE>& map) {
        this->size = map.size;
        this->capacity = map.capacity;

        this->keys = new KEY[this->capacity];
        this->values = new VALUE[this->capacity];

        for (int i = 0; i < size; i++) {
            this->keys[i] = map.keys[i];
            this->values[i] = map.values[i];
        }
    }

    ~Map() {
        delete[] this->keys;
        delete[] this->values;
    }

    void add(KEY key, VALUE value) {
        for(int i = 0; i < this->size; i++) {
            if (this->keys[i] == key) {
                throw KeyAlreadyExistsException();
            }
        }
        if (this->size == this->capacity) {
            this->resize();
        }
        this->keys[this->size] = key;
        this->values[this->size] = value;
        this->size++;
    }

    VALUE* find(KEY key) {
        for (int i = 0; i < this->size; i++) {
            if (this->keys[i] == key) {
                return &this->values[i];
            }
        }
        return 0;
    }

    void resize() {
        this->capacity *= 2;

        KEY* newKeys = new KEY[this->capacity];
        VALUE* newValues = new VALUE[this->capacity];

        for (int i = 0; i < size; i++) {
            newKeys[i] = this->keys[i];
            newValues[i] = this->values[i];
        }

        delete[] this->keys;
        delete[] this->values;

        this->keys = newKeys;
        this->values = newValues;
    }


    Map& operator=(const Map<KEY, VALUE>& map) {
        if (this != &map) {
            delete[] this->keys;
            delete[] this->values;

            this->size = map.size;
            this->capacity = map.capacity;

            this->keys = new KEY[this->capacity];
            this->values = new VALUE[this->capacity];

            for (int i = 0; i < this->size; i++) {
                this->keys[i] = map.keys[i];
                this->values[i] = map.values[i];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Map<KEY, VALUE>& map) {
        for (int i = 0; i < map.size; i++) {
            os << map.keys[i] << ": " << map.values[i] << endl;
        }
        return os;
    }
};



#endif
