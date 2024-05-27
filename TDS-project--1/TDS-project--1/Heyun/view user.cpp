#include "../pet.hpp"
using namespace std;

void AdminViewUser(UserNode* head) {
    // First print all user names
    cout << "All users:" << endl;
    UserNode* temp = head;
    while (temp != nullptr) {
        cout << "User Name: "<<temp->a.getUname() << endl;
        temp = temp->next;
    }

    // Then ask for the user name to view
    string name;
    cout << "Enter the name of the user you want to view: ";
    getline(cin, name);

}