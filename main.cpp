#include <iostream>
#include <cctype>
#include <algorithm>
#include <conio.h>
#include "Contact.h"
#include "Array.h"
#include "Person.h"
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    Contact<Person, 100> MyContact;
    Contact<Person, 50> Favcontacts;

    string option;

    while (true)
    {
        cout << "\n\t\t\t\t\t\t==================================================================\n";
        cout << "\t\t\t\t\t\t\t\tContacts Book Menu:\n";
        cout << "\t\t\t\t\t\t\t\t-------------------------\n";
        cout << "\t\t\t\t\t\t\t1: Add A New Contact\n";
        cout << "\t\t\t\t\t\t\t2: Search By Last Name (Enter Last Name Correctly)\n";
        cout << "\t\t\t\t\t\t\t3: Search By Classification (Friend, Work, Family, Other)?\n";
        cout << "\t\t\t\t\t\t\t4: Print All Contacts\n";
        cout << "\t\t\t\t\t\t\t5: Print Fav Contacts\n";
        cout << "\t\t\t\t\t\t\t6: Save To File\n";
        cout << "\t\t\t\t\t\t\t7: Load From File\n";
        cout << "\t\t\t\t\t\t\t8: Delete Contact\n";
        cout << "\t\t\t\t\t\t\t9: Update Contact Information\n";
        cout << "\t\t\t\t\t\t\t10: Share Contact With Other\n";
        cout << "\t\t\t\t\t\t\t11: Reverse Contacts Book\n";
        cout << "\t\t\t\t\t\t\t12: Exit\n";
        cout << "\t\t\t\t\t\t==================================================================\n";
        cout << endl;
        cout << "\t\t\t\t\t\tWhat is the option you need: ";
        cin >> option;
        cin.clear(); // Reset any error flags on cin
cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining characters in the input buffer

        cout << "\t\t\t\t\t\t__________________________________________________________________\n";

        int opt = stoi(option);

        switch (opt)
        {
            case 1:
            {
                Person Person1;
                Person1.inputPerson();
                MyContact.addContact(Person1);

                if (Person1.GetFav())
                {
                    Favcontacts.addContact(Person1);
                    cout << "\t\t\t\t\t\ Contact added to fav numbers" << endl;
                }
                cout << "\t\t\t\t\t\ Contact added successfully" << endl;
                getch();
                system("cls");
                break;
            }

            case 2:
            {
                string lastName;
                cout << "\t\t\t\t\t\ Enter Last Name: ";
                cin >> lastName;
                MyContact.Find_By_Name(lastName);
                getch();
                system("cls");
                break;
            }

            case 3:
            {
                string classification;
                cout << "\t\t\t\t\t\ Enter Classification (Friend, Work, Family, Other): ";
                cin >> classification;
                MyContact.Find_By_Classification(classification);
                getch();
                system("cls");
                break;
            }

            case 4:
                MyContact.displaycontacts();
                getch();
                system("cls");
                break;

            case 5:
                Favcontacts.displaycontacts();
                getch();
                system("cls");
                break;

            case 6:
            {
                std::string filename = "project";
                MyContact.saveToFile(filename);
                getch();
                system("cls");
                break;
            }

            case 7:
                MyContact.loadFromFile("project");
                getch();
                system("cls");
                break;

            case 8:
            {
                int index;
                cout << "\t\t\t\t\t\ Enter index of the name you want to delete: ";
                cin >> index;
                for (int i = 0; i < Favcontacts.getSize(); i++)
                {
                    if (MyContact[index] == Favcontacts[i])
                    {
                        Favcontacts.removeContact(i);
                        break;
                    }
                }
                MyContact.removeContact(index);
                getch();
                system("cls");
                break;
            }

            case 9:
            {
                Person Person1;
                MyContact.displaycontacts();
                int index;
                cout << "\t\t\t\t\t\ Enter the NO. of contact : ";
                cin >> index;
                MyContact.removeContact(index - 1);
                Person1.inputPerson();
                MyContact.addContactAt(index - 1, Person1);
                MyContact.displaycontacts();
                getch();
                system("cls");
                break;
            }

            case 10:
            {
                size_t index;
                cout << "\t\t\t\t\t\t\ Enter a contact index to share (1 to " << MyContact.getSize() << "): ";
                cin >> index;

                if (index > 0 && index <= MyContact.getSize())
                {
                    MyContact.share(index - 1);
                }
                else
                {
                    cout << "\t\t\t\t\t\ Invalid index!" << endl;
                }

                getch();
                system("cls");
                break;
            }

            case 11:
                MyContact.reversey();
                getch();
                system("cls");
                break;

            case 12:
                return 0;

            default:
                cout << "\t\t\t\t\t\t\ Invalid option, please enter an option from 1 to 12 " << endl;
                getch();
                system("cls");
                break;
        }
    }
    return 0;
}
