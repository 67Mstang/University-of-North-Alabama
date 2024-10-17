#include <iostream>
#include <iomanip>
#include "pets.h"
using namespace std;




/**********************************************************************************************************************
    Name:  IntNode::IntNode()
    Description:  This member function will set a new node to the given values.
    Incoming:  The pointer to the head of the linked list, the new name, the new type, and the new age.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
IntNode::IntNode(string inName, string inType, int inAge, IntNodePtr theLink)
{
    name = inName;
    type = inType;
    age = inAge;
    link = theLink;
}




/**********************************************************************************************************************
    Name:  IntNode::setName()
    Description:  This member function will set the name of the node.
    Incoming:  The new name.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void IntNode::setName(string inName)
{
    name = inName;
}




/**********************************************************************************************************************
    Name:  IntNode::setType()
    Description:  This member function will set the type of the node.
    Incoming:  The new type.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void IntNode::setType(string inType)
{
    type = inType;
}




/**********************************************************************************************************************
    Name:  IntNode::setAge()
    Description:  This member function will set the age of the node.
    Incoming:  The new age.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void IntNode:: setAge(int inAge)
{
    age = inAge;
}




/**********************************************************************************************************************
    Name:  IntNode::setLink()
    Description:  This member function will set the Link of the node.
    Incoming:  The new link.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void IntNode::setLink(IntNodePtr theLink)
{
    link = theLink;
}




/**********************************************************************************************************************
    Name:  IntNode::getName()
    Description:  This member function will return the name of the node.
    Incoming:  None.
    Outgoing:  None.
    Return:  The name of the node.
***********************************************************************************************************************/
string IntNode::getName() const
{
    return name;
}




/**********************************************************************************************************************
    Name:  IntNode::getType()
    Description:  This member function will return the type of the node.
    Incoming:  None.
    Outgoing:  None.
    Return:  The type of the node.
***********************************************************************************************************************/
string IntNode::getType() const
{
    return type;
}




/**********************************************************************************************************************
    Name:  IntNode::getAge()
    Description:  This member function will return the age of the node.
    Incoming:  None.
    Outgoing:  None.
    Return:  The age of the node.
***********************************************************************************************************************/
int IntNode::getAge() const
{
    return age;
}




/**********************************************************************************************************************
    Name:  IntNode::getLink()
    Description:  This member function will return the link of the node.
    Incoming:  None.
    Outgoing:  None.
    Return:  The link of the node.
***********************************************************************************************************************/
IntNodePtr IntNode::getLink() const
{
    return link;
}




/**********************************************************************************************************************
    Name:  headInsert()
    Description:  This function will add a new node onto the head of the list.
    Incoming:  The pointer to the head of the linked list.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void headInsert(IntNodePtr &head)
{
    string name;
    string type;
    int age;

    cout << "Enter the Name of the pet: ";
    cin >> name;
    cout << "Enter the Type of the pet: ";
    cin >> type;
    cout << "Enter the Age of the pet: ";
    cin >> age;
    cout << endl << endl << endl;

    head = new IntNode(name, type, age, head);
}




/**********************************************************************************************************************
    Name:  display()
    Description:  This function will display a listig of all the nodes in the list and their data.
    Incoming:  The pointer to the head of the linked list.
    Outgoing:  Print all of the data for all of the nodes in the list.
    Return:  None.
***********************************************************************************************************************/
void display(IntNodePtr head)
{
    IntNodePtr temp = head;

    cout << left << setw(20) << "Name:" << setw(20) << "Type:" << setw(20) << "Age:" << endl;
    cout << "------------------------------------------------" << endl;

    while(temp != nullptr)
    {
        cout << setw(20) << temp -> getName() << setw(20) << temp -> getType() << setw(20) << temp -> getAge() << endl << endl;

        temp = temp -> getLink();
    }

    cout << endl << endl << endl;
}




/**********************************************************************************************************************
    Name:  insert()
    Description:  This function will insert the new node into the given position in the list.
    Incoming:  The pointer the data is to be inserted after, the new name, the new type, and the new age.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void insert(IntNodePtr afterMe, string name, string type, int age)
{
    IntNodePtr temp = nullptr;
    temp = new IntNode(name, type, age, afterMe -> getLink());
    afterMe -> setLink(temp);
}




/**********************************************************************************************************************
    Name:  tailInsert()
    Description:  This function will add a new node onto the tail of the list.
    Incoming:  The pointer to the head of the linked list.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void tailInsert(IntNodePtr &head)
{
    string name;
    string type;
    int age;

    cout << "Enter the Name of the pet: ";
    cin >> name;
    cout << "Enter the Type of the pet: ";
    cin >> type;
    cout << "Enter the Age of the pet: ";
    cin >> age;
    cout << endl << endl << endl;

    if(head == nullptr)                     // empty list???
    {
        head = new IntNode(name, type, age, head);
    }
    else
    {
        IntNodePtr temp = nullptr;
        IntNodePtr next = nullptr;

        temp = head;                        // points to the first node in list
        next = temp -> getLink();           // points to the second node in list

        while(next != nullptr)
        {
            temp = next;
            next = next -> getLink();
        }                           // temp now points to the tail node

        insert(temp, name, type, age);      // call to the insert function
    }
}




/**********************************************************************************************************************
    Name:  deleteNodeByName()
    Description:  This function will delete a node in the list with the given name.
    Incoming:  The pointer to the head of the linked list, and the name to be deleted.
    Outgoing:  print the status of the deletion.
    Return:  None.
***********************************************************************************************************************/
void deleteNodeByName(IntNodePtr &head)
{
    string target;

    cout << "Enter the name of the pet to be deleted: ";
    cin >> target;

    if(head == nullptr)                 // 1.  Empty List
    {
        cout << endl << endl << "CANNOT DELETE FROM AN EMPTY LIST!!!" << endl << endl << endl;
    }
    else
    {
        IntNodePtr pred = head;
        IntNodePtr temp = head -> getLink();

        if(pred -> getName() == target) // 2.  Delete 1st item
        {
            cout << endl << endl <<"PET DELETED SUCCESSFULLY!!!" << endl << endl << endl;
            head = temp;  // head now points to 2nd item
            delete pred;
        }
        else                            // 3.  Normal Case
        {
            while((temp -> getName() != target) && (temp -> getLink() != nullptr))
            {
                pred = temp;
                temp = temp -> getLink();
            }

            if(temp -> getName() == target)
            {
                pred -> setLink(temp -> getLink());
                delete temp;
                cout << endl << endl << "PET DELETED SUCCESSFULLY!!!" << endl << endl << endl;
            }
            else
            {
                cout << endl << endl << "PET WAS NOT FOUND IN THE LIST!!!" << endl << endl << endl;
            }
        }
    }
}




/**********************************************************************************************************************
    Name:  countNodes()
    Description:  This function will return the number of nodes in the linked list.
    Incoming:  The pointer to the head of the linked list.
    Outgoing:  None.
    Return:  The number of nodes in the list.
***********************************************************************************************************************/
int countNodes(IntNodePtr head)
{
    IntNodePtr temp = head;
    int count = 0;

    while(temp != nullptr)
    {
        count++;
        temp = temp -> getLink();
    }

    return count;
}




/**********************************************************************************************************************
    Name:  searchGivenType()
    Description:  This function will print all of the nodes in the linked list that have the same type.
    Incoming:  The pointer to the head of the linked list.
    Outgoing:  print all nodes in the list that have the given type.
    Return:  None
***********************************************************************************************************************/
void searchGivenType(IntNodePtr head)
{
    string type;

    cout << "Enter the Type of pet you want to search for: ";
    cin >> type;
    cout << endl << endl;

    IntNodePtr temp = head;

    while(temp != nullptr)
    {
        if(temp -> getType() == type)
        {
            cout << temp -> getName() << endl;
            cout << temp -> getType() << endl;
            cout << temp -> getAge() << endl;
            cout << endl << endl;
        }

        temp = temp -> getLink();
    }
}




/**********************************************************************************************************************
    Name:  averageAgeIterative()
    Description:  This function will print the average of all pets using Iteration.
    Incoming:  The pointer to the head of the linked list.
    Outgoing:  print the average age of all pets
    Return:  None
***********************************************************************************************************************/
void averageAgeIterative(IntNodePtr head)
{
    IntNodePtr temp = head;

    int ageSum = 0.0;

    while(temp != nullptr)
    {
        ageSum += temp -> getAge();
        temp = temp -> getLink();
    }

    ageSum /= countNodes(head);

    cout << endl << endl << "The average age of all pets in the list is:    " << ageSum << endl << endl << endl;
}




/**********************************************************************************************************************
    Name:  averageAgeRecursive()
    Description:  This function will print the average of all pets using recursion.
    Incoming:  The pointer to the head of the linked list.
    Outgoing:  print the average age of all pets
    Return:  None
***********************************************************************************************************************/
void averageAgeRecursive(IntNodePtr head)
{
        IntNodePtr temp = head;

    int ageSum = 0.0;

    while(temp != nullptr)
    {
        ageSum += temp -> getAge();
        temp = temp -> getLink();
    }

    ageSum /= countNodes(head);

    cout << endl << endl << "The average age of all pets in the list is:    " << ageSum << endl << endl << endl;
}




/**********************************************************************************************************************
    Name:  displayMenu()
    Description:  This function will print out the menu for the user.
    Incoming:  None.
    Outgoing:  The menu for the user to make selections from.
    Return:  The input from the user.
***********************************************************************************************************************/
int displayMenu()
{
    int input = 0;

    cout << "Please Enter The Number Of The Option You Would Like: " << endl << endl;
    cout << "1.    Display List:" << endl;
    cout << "2.    Add To Head:" << endl;
    cout << "3.    Add To Tail:" << endl;
    cout << "4.    Search Given Type:" << endl;
    cout << "5.    Delete Node Given Pet Name:" << endl;
    cout << "6.    Print Average Age For All Pets (Iterative Function):" << endl;
    cout << "7.    Print Average Age For All Pets (Recursive Function):" << endl;
    cout << "8.    Quit:" << endl << endl;
    cin >> input;
    cout << endl << endl << endl << endl;

    return input;
}
