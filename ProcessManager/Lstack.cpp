/* File:      Lstack.cpp
Author:       Zia Animashaun
Date:         12/08/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build a process manager.
*/

#ifndef LSTACK_CPP
#define LSTACK_CPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Templated node class used in templated linked list
template <class T>
class Node {
public:
    Node( const T& data ); //Constructor
    T& GetData(); //Gets data from node
    void SetData( const T& data ); //Sets data in node
    Node<T>* GetNext(); //Gets next pointer
    void SetNext( Node<T>* next ); //Sets next pointer
private:
    T m_data; //Templated data for node
    Node<T>* m_next; //Templated node pointer to next node
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
    m_data = data;
    m_next = nullptr;
}

//Returns the data from a Node
template <class T>
T& Node<T>::GetData() {
    return m_data;
}

//Sets the data in a Node
template <class T>
void Node<T>::SetData( const T& data ) {
    m_data = data;
}

//Gets the pointer to the next Node
template <class T>
Node<T>* Node<T>::GetNext() {
    return m_next;
}

//Sets the next Node
template <class T>
void Node<T>::SetNext( Node<T>* next ) {
    m_next = next;
}

template <class T>
class Lstack {
public:
    // Name: Lstack() (Linked List Stack) - Default Constructor
    // Desc: Used to build a new templated stack (as a linked list) m_head = top
    // Preconditions: None
    // Postconditions: Creates a new lstack where m_head points to nullptr and m_size = 0
    // Required
    Lstack();
    // Name: ~Lstack() - Destructor
    // Desc: Used to destruct a Lstack
    // Preconditions: There is an existing lstack with at least one node
    // Postconditions: An lstack is deallocated (including dynamically allocated nodes)
    //                 to have no memory leaks. (Allowed to use Clear in this function)
    // Required
    ~Lstack();
    // Name: Lstack (Copy Constructor)
    // Preconditions: Creates a copy of existing LStack
    //                Requires an existing Lstack
    // Hint: Make sure that the copy is not inverted
    // Postconditions: Copy of existing Lstack
    // Required
    Lstack(const Lstack&);
    // Name: operator= (Overloaded Assignment Operator)
    // Preconditions: Requires two Lstacks holding the same type of data
    //                After running, both stacks are identical with no memory loss
    //                Requires an existing Lstack
    // Postconditions: Two identical Lstack
    // Hint: Make sure that the destination Lstack has the same data in the same order as source
    // Required
    Lstack<T>& operator= (Lstack&);
    // Name: Push
    // Preconditions: Takes in data. Creates new node.
    //                Requires an existing Lstack
    // Postconditions: Adds a new node to the top of the lstack.
    // Required
    void Push(const T&);
    // Name: Pop
    // Preconditions: Requires an existing Lstack with at least one node
    // Postconditions: Removes top node in the lstack.
    // Assume that the Lstack has at least one node (Will check prior to call)
    // Required
    void Pop();
    // Name: Display
    // Preconditions: Outputs the lstack.
    // Postconditions: Displays the data in each node of lstack
    // Required (used only for testing lstack_test)
    void Display();
    // Name: Top
    // Preconditions: Requires an existing Lstack
    // Postconditions: Returns whatever data is on top
    // Required
    T Top();
    // Name: IsEmpty
    // Preconditions: Requires an existing Lstack
    // Postconditions: Returns true if the Lstack is empty else false.
    // Required
    bool IsEmpty();
    // Name: GetSize
    // Preconditions: Requires an existing Lstack
    // Postconditions: Returns m_size
    // Required
    int GetSize();
    // Name: Find()
    // Preconditions:  Requires an existing Lstack
    // Postconditions: Iterates and if it finds the thing, returns index, else -1
    // Required
    int Find(T&);
    // Name: Clear
    // Preconditions:  Requires an existing Lstack
    // Postconditions: Removes all nodes in Lstack
    // Required
    void Clear();
    // Name: At(int)
    // Preconditions:  Requires an existing Lstack
    // Postconditions: Returns the data at a specific index;
    //                 Index will be checked prior to call (assume int is valid)
    // Required
    T At (int x);
private:
    Node <T> *m_head; //Node pointer for the head
    int m_size; //Number of nodes in stack
};

//**********Implement Lstack Class Here***********
//**********All Functions Are Required Even If Not Used for Processor**************
template <class T>
Lstack<T>::Lstack() {
    m_head = nullptr;
    m_size = 0;
}

template <class T>
Lstack<T>::~Lstack() {
    Clear();
}

template <class T>
void Lstack<T>::Clear() {
    Node<T>* node = m_head;
    while(node != nullptr) {
        Node<T>* next = node->GetNext();
        delete node;
        node = next;
    }
    m_head = nullptr;
    m_size = 0;
}

template <class T>
Lstack<T>::Lstack(const Lstack<T>& other) {
    Node<T> *node;
    Node<T> *onode = other.m_head;
    if(onode != nullptr) {
        node = new Node<T>(onode->GetData());
        m_head = node;
        m_size = 1;
    }
    else {
        m_head = nullptr;
        m_size = 0;
    }
    while(onode->GetNext() != nullptr) {
        Node<T> *onext = onode->GetNext();
        node->SetNext(new Node<T>(onext->GetData()));
        m_size++;
        node = node->GetNext();
        onode = onext;
    }
}

template <class T>
Lstack<T>& Lstack<T>::operator=(Lstack<T>& other) {
    Clear();
    Node<T> *node;
    Node<T> *onode = other.m_head;
    if(onode != nullptr) {
        node = new Node<T>(onode->GetData());
        m_head = node;
        m_size = 1;
    }
    else {
        m_head = nullptr;
        m_size = 0;
    }
    while(onode->GetNext() != nullptr) {
        Node<T> *onext = onode->GetNext();
        node->SetNext(new Node<T>(onext->GetData()));
        m_size++;
        node = node->GetNext();
        onode = onext;
    }
    return *this;
}

template <class T>
void Lstack<T>::Push(const T& data) {
    Node<T>* node = new Node<T>(data);
    node->SetNext(m_head);
    m_head = node;
    m_size++;
}

template <class T>
void Lstack<T>::Pop() {
    Node<T>* node = m_head;
    if(node != nullptr) {
        m_head = node->GetNext();
        delete node;
        m_size--;
    }
}

template <class T>
void Lstack<T>::Display() {
    Node<T>* node = m_head;
    if(node == nullptr) {
        cout << "Lstack is empty." << endl;
        return;
    }
    while(node != nullptr) {
        cout << node->GetData();
        node = node->GetNext();
        if(node != nullptr) cout << " ";
    }
    cout << endl;
}

template <class T>
T Lstack<T>::Top() {
    return m_head->GetData();
}

template <class T>
bool Lstack<T>::IsEmpty() {
    return !(m_size > 0 && m_head != nullptr);
}

template <class T>
int Lstack<T>::GetSize() { return m_size; }

template <class T>
int Lstack<T>::Find(T& item) {
    Node<T>* node = m_head;
    int i = 0;
    while(node != nullptr) {
        if(node->GetData() == item) {
            return i;
        }
        i++;
        node = node->GetNext();
    }
    return -1;
}

template <class T>
T Lstack<T>::At(int x) {
    Node<T>* node = m_head;
    int i = 0;
    while(node != nullptr) {
        if(i == x) return node->GetData();
        i++;
        node = node->GetNext();
    }
}

#endif
