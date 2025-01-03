#ifndef CONTACTBOOK_H_INCLUDED
#define CONTACTBOOK_H_INCLUDED
#include "Array.h"
#include "Person.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
template<typename T, size_t Size>

class Contact
{
private:

    Array<Person> contacts;

public:

    void addContact(Person&person)
    {
        contacts.append(person);
    }


    void addContactAt(size_t index,Person&person)
    {
        contacts.insert(index,person);
    }


    void removeContact(size_t index)
    {
        contacts.removeAt(index);
        cout << "\t\t\t\t\t\t\ Contact removed" << endl;
    }


    void displaycontacts()
    {
        cout << "\nDisplay all contacts: \n" << endl;
        cout << setw(5) <<"    No."
             << setw(20) <<" First Name"
             << setw(20) <<" Last Name"
             << setw(20) <<"\tClassification"
             <<setw(20)<<"Fav"
             << setw(20)<<"\tAddress\t"
             <<setw(20)<<"\tPhone"<<endl;

        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        for (size_t i = 0; i < contacts.getSize(); i++)
        {
            cout << setw(5) << i + 1
                 << setw(20) << contacts[i].get_First_Name()
                 << setw(20) << contacts[i].get_Last_Name()
                 << setw(20) << contacts[i].get_Classifacation()
                 <<setw(24)<<contacts[i].GetFav()<<setw(15);
                 contacts[i].displayadress();

            cout<<setw(10)<<contacts[i].get_phone_Numbers();
cout << endl ;
        }
    }


    void Find_By_Name( string lastName)
    {
        bool found = false;
        for (size_t i = 0; i < contacts.getSize(); i++)
        {
            if (contacts[i].get_Last_Name() == lastName)
            {
                contacts[i].display();
                cout << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "\t\t\t\t\t\t\ No contact found with the name: " << lastName << endl;
        }
    }


    void Find_By_Classification(string classs)
    {
        bool found = false;
        for (size_t i = 0; i < contacts.getSize(); i++)
        {
            if (contacts[i].get_Classifacation() == classs)
            {
                contacts[i].display();
                cout << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "\t\t\t\t\t\t\ No contact found with the classification: " << classs << endl;
        }

    }


    void reversey()
    {
        contacts.reverse();
        displaycontacts();
    }
    size_t getSize() const
    {
        return contacts.getSize();
    }
    void share(size_t index)
    {
        if (index < contacts.getSize())
        {
            cout << "\t\t\t\t\t\t\ Sharing contact: ";
            contacts[index].display();
        }
        else
        {
            cout << "\t\t\t\t\t\t\ Index out of range." << endl;
        }
    }


    void saveToFile(const string& filename)
    {
        ofstream outFile(filename);
        if (!outFile)
        {
            cerr << "\t\t\t\t\t\t\ Error opening file for writing.\n";
            return;
        }
        outFile << contacts.getSize() << "\n";
        for (size_t i = 0; i < contacts.getSize(); i++)
        {
            outFile << contacts[i].get_First_Name() << " "
                    << contacts[i].get_Last_Name() << "                  "
                    << contacts[i].get_Classifacation() <<"\n"
                    " "<<contacts[i].get_Address()<<"\n"
                    << "___________________________________________________________________________\n";
        }
        outFile.close();
        cout << "\t\t\t\t\t\t Contacts saved to file successfully.\n";
    }


    void loadFromFile(const string& filename)
    {
        ifstream inFile(filename);
        if (!inFile)
        {
            cerr << "\t\t\t\t\t\t\ Error opening file for reading.\n";
            return;
        }
        size_t numContacts;
        inFile >> numContacts;
        inFile.ignore();

        for (size_t i = 0; i < numContacts; i++)
        {
            string firstName, lastName, classification;
            getline(inFile, firstName, ' ');
            getline(inFile, lastName, ' ');
            getline(inFile, classification);

            size_t streetNum;
            string streetName, town, state;
            inFile >> streetNum;
            inFile.ignore();
            getline(inFile, streetName, ' ');
            getline(inFile, town, ' ');
            getline(inFile, state);

            Address address(streetNum, streetName, town, state);
            Person person(firstName, lastName, classification,2,2,address);
            addContact(person);
        }
        inFile.close();
        cout << "\t\t\t\t\t\t\ Contacts loaded from file successfully.\n";
    }


    const T& operator[](size_t index) const
    {
        return contacts.getAt(index);
    }


};

#endif // CONTACTBOOK_H_INCLUDED
