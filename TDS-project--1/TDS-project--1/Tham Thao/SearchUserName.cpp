#include "../pet.hpp"

UserNode* Petsystem::SearchUserName(string username) {
    UserNode* current = userHead;  // start from the head of the list
    while (current != NULL) {
        if (current->a.getUname() == username) {
            return current;  // found the username, return the node
        }
        current = current->next;  // move to the next node
    }
    return NULL;  // username not found
}