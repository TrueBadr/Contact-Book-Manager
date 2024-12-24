#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

// Forward declaration for Address class
class Address;

// Array template class
template <typename T>
class Array {
private:
    T* a;
    size_t length;
    size_t capacity;

    void resize(size_t newCapacity) {
        T* NEW = new T[newCapacity];
        for (size_t i = 0; i < length; i++) {
            NEW[i] = a[i];
        }
        delete[] a;
        a = NEW;
        capacity = newCapacity;
    }

public:
    Array() : length(0), capacity(2) {
        a = new T[capacity];
    }

    Array(const Array& obj) : length(obj.length), capacity(obj.capacity) {
        a = new T[capacity];
        for (size_t i = 0; i < length; i++) {
            a[i] = obj.a[i];
        }
    }

    Array& operator=(const Array& obj) {
        if (this == &obj) return *this;
        delete[] a;
        length = obj.length;
        capacity = obj.capacity;
        a = new T[capacity];
        for (size_t i = 0; i < length; i++) {
            a[i] = obj.a[i];
        }
        return *this;
    }

    ~Array() {
        delete[] a;
    }

    void append(const T& element) {
        if (length >= capacity) {
            resize(capacity * 2);
        }
        a[length++] = element;
    }

    void insert(size_t index, const T& element) {
        if (index > length) throw out_of_range("Index out of range for insert");
        if (length >= capacity) {
            resize(capacity * 2);
        }
        for (size_t i = length; i > index; i--) {
            a[i] = a[i - 1];
        }
        a[index] = element;
        length++;
    }

    void reverse() {
        std::reverse(a, a + length);
    }

    void removeAt(size_t index) {
        if (index >= length) throw out_of_range("Index out of range for remove");
        for (size_t i = index; i < length - 1; i++) {
            a[i] = a[i + 1];
        }
        length--;
    }

    T& getAt(size_t index) {
        if (index >= length) throw out_of_range("Index out of range");
        return a[index];
    }

    const T& getAt(size_t index) const {
        if (index >= length) throw out_of_range("Index out of range");
        return a[index];
    }

    T& operator[](size_t index) {
        return getAt(index);
    }

    const T& operator[](size_t index) const {
        return getAt(index);
    }

    void reset() {
        delete[] a;
        a = new T[capacity];
        length = 0;
    }

    size_t getSize() const {
        return length;
    }

    void display() const {
        for (size_t i = 0; i < length; i++) {
            cout << setw(5) << a[i] << " ";
        }
        cout << endl;
    }
};

// Person class
class Person {
private:
    string First_Name;
    string Last_Name;
    string Classification;
    size_t Capacity_of_Nums;
    string* ptr_Nums;
    size_t Capacity_of_Mails;
    string* ptr_Mails;
    Address address;
    bool fav;

public:
    Person(string FN = "*****", string LN = "*****", string C = "*****", size_t Cap_of_Nums = 2, size_t Cap_of_Mails = 2)
        : First_Name(FN), Last_Name(LN), Classification(C), Capacity_of_Nums(Cap_of_Nums), Capacity_of_Mails(Cap_of_Mails), fav(false) {
        ptr_Nums = new string[Capacity_of_Nums];
        ptr_Mails = new string[Capacity_of_Mails];
    }

    ~Person() {
        delete[] ptr_Nums;
        delete[] ptr_Mails;
    }

    Person(const Person& p) : First_Name(p.First_Name), Last_Name(p.Last_Name), Classification(p.Classification),
                              Capacity_of_Nums(p.Capacity_of_Nums), Capacity_of_Mails(p.Capacity_of_Mails), address(p.address), fav(p.fav) {
        ptr_Nums = new string[Capacity_of_Nums];
        copy(p.ptr_Nums, p.ptr_Nums + Capacity_of_Nums, ptr_Nums);
        ptr_Mails = new string[Capacity_of_Mails];
        copy(p.ptr_Mails, p.ptr_Mails + Capacity_of_Mails, ptr_Mails);
    }

    Person& operator=(const Person& p) {
        if (this != &p) {
            delete[] ptr_Nums;
            delete[] ptr_Mails;
            First_Name = p.First_Name;
            Last_Name = p.Last_Name;
            Classification = p.Classification;
            Capacity_of_Nums = p.Capacity_of_Nums;
            Capacity_of_Mails = p.Capacity_of_Mails;
            address = p.address;
            fav = p.fav;

            ptr_Nums = new string[Capacity_of_Nums];
            copy(p.ptr_Nums, p.ptr_Nums + Capacity_of_Nums, ptr_Nums);
            ptr_Mails = new string[Capacity_of_Mails];
            copy(p.ptr_Mails, p.ptr_Mails + Capacity_of_Mails, ptr_Mails);
        }
        return *this;
    }

    void display() const {
        cout << setw(20) << "Name: " << setw(15) << First_Name << setw(15) << Last_Name
             << setw(25) << "Classification: " << Classification << endl;
    }

    string get_First_Name() const { return First_Name; }
    string get_Last_Name() const { return Last_Name; }
    string get_Classification() const { return Classification; }
};

// Contact class using Array
template<typename T, size_t Size>
class Contact {
private:
    Array<Person> contacts;

public:
    void addContact(Person& person) {
        contacts.append(person);
    }

    void removeContact(size_t index) {
        contacts.removeAt(index);
        cout << "Contact removed" << endl;
    }

    void displayContacts() const {
        cout << "Display all contacts: " << endl;
        cout << setw(5) << "No." << setw(20) << "First Name" << setw(20) << "Last Name" << setw(20) << "Classification" << endl;
        cout << "--------------------------------------------------------------------------\n";
        for (size_t i = 0; i < contacts.getSize(); i++) {
            cout << setw(5) << i + 1 << setw(20) << contacts[i].get_First_Name()
                 << setw(20) << contacts[i].get_Last_Name()
                 << setw(20) << contacts[i].get_Classification() << endl;
        }
    }
};

#endif // CLASSES_H_INCLUDED
