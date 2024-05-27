#include "../pet.hpp"

int searchIndex(UserNode* head, string target) {
    int index = 0;
    UserNode* current = head;

    while (current != nullptr) {
        if (current->a == target) {
            return index;
        }
        current = current->next;
        index++;
    }

    return index; // Return -1 if the target is not found
}

int main()
{
    StringNode* userHead = new StringNode("User1");

    // Add nodes to the user linked list
    userHead->next = new StringNode("User2");
    userHead->next->next = new StringNode("User3");

    int index = searchIndex(userHead, "User1");

    if (index != -1) {
        cout << "Found " << " at index " << index << endl;
    } else {
        cout << " not found in the list." << endl;
    }
}
