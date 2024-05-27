#include "../pet.hpp"
using namespace std;
void Petsystem::deleteUserNode(string key) 
{ 
    // Store head node 
    UserNode* current = userHead;
    UserNode* prev = nullptr;
    
  
    // If head node itself holds the key to be deleted
    if (current != NULL && current->a.getUname() == key) 
    { 
        userHead = current->next;   // Changed head 
        delete current;               // free old head 
        return; 
    }

    // Search for the key to be deleted, keep track of the

    while (current != NULL && current->a.getUname() != key) 
    { 
        prev = current;
        current = current->next; 
    }

    if (current == nullptr) {
        cout << "User with key '" << key << "' not found." << endl;
        return;
    }

    //delete node and point to next node
    prev->next = current->next;
    UserNode* temp = current;
    current = current->next;
    temp->next = NULL;
    delete temp;

    
} 