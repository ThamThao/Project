#include "../pet.hpp"
#include <algorithm>
#include <bitset>

string Petsystem::toUpper(const string& str) { //convert all username to uppercase
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

string Petsystem::toBinary(const string& str) { //convert all username to binary number
    string binary;
    for (char c : str) {
        binary += bitset<8>(c).to_string();
    }
    return binary;
}

void Petsystem::inOrder(SortUserNodeTree* node) {
    if (node != nullptr) {
        inOrder(node->left); // Visit left subtree
        cout << node->a.getUname() << endl; // Visit root node
        inOrder(node->right); // Visit right subtree
    }
}

void Petsystem::ViewUser(){
    if(userHead!=nullptr){
        UserNode* current = userHead;  // start from the head of the list
        while (current != NULL) {
            SortUser(current->a);
            current = current->next;  // move to the next node
        }
        inOrder(sortUserHead);
    }
    else{
        cout<<"User not found"<<endl;
        cout << "Please press Enter to back to admin page.";
        cin.ignore(); // Ignore the newline character in the input buffer
        cin.get(); // Wait for the user to press Enter
        admin();  // Back to admin page
    }
}

void Petsystem::SortUser(user a){
    SortUserNodeTree* current = sortUserHead;
    SortUserNodeTree* temp = new SortUserNodeTree;
    temp->a = a;
    temp->left = NULL;
    temp->right = NULL;
    if (sortUserHead == nullptr){
        sortUserHead = temp;
    }
    else{
        string upperUsername = toUpper(a.getUname()); // Convert username to uppercase
        string newbinaryUsername = toBinary(upperUsername); // Convert username to binary
        while(current!=nullptr){
            string upperUsername = toUpper(current->a.getUname()); // Convert username to uppercase
            string curbinaryUsername = toBinary(upperUsername); // Convert username to binary
            if (newbinaryUsername < curbinaryUsername){ // Compare binary usernames
                if(current->left==nullptr){
                    current->left = temp;
                    break;
                }
                else{
                    current = current->left;
                }
            }
            else{
                if(current->right==nullptr){
                    current->right = temp;
                    break;
                }
                else{
                    current = current->right;
                }
            }
        }
    }
}

