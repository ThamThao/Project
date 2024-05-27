#include "../pet.hpp"

PetNode* Petsystem::SearchPetName(string petname) {
    PetNode* current = petHead;  // start from the head of the list
    while (current != NULL) {
        if (current->p.getName() == petname) {
            return current;  // found the username, return the node
        }
        current = current->next;  // move to the next node a
    }
    return NULL;  // username not found
}