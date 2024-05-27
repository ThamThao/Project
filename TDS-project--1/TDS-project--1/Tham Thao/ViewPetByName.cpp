#include "../pet.hpp"
#include <algorithm>
#include <bitset>

string Petsystem::toUpperPet(const string& str) { //convert all pet name to uppercase
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

string Petsystem::toBinaryPet(const string& str) { //convert all pet name to binary number
    string binary;
    for (char c : str) {
        binary += bitset<8>(c).to_string();
    }
    return binary;
}

void Petsystem::inOrder(SortPetNodeTree* node) {
    if (node != nullptr) {
        PetNode* petTemp = petHead;
        inOrder(node->left); // Visit left subtree
        cout << "| " << setfill(' ') << setw(5) << node->p.getID()<< setw(5) << " | " << setw(15) << node->p.getName()  << setw(15)<<" | " << setw(15) << node->p.getOwner() << setw(15)<< " |" << endl;
        cout << "+----------------------------------------------------------------------+" << endl;
        inOrder(node->right); // Visit right subtree
    }
}

void Petsystem::ViewPetByName(){
    cout << "+----------------------------------------------------------------------+" << endl;
    cout << "| " << setfill(' ') << setw(5) << "ID" << setw(5) << " | " << setw(15) << "Name" << setw(15)<< " | " << setw(15) << "Owner" <<  setw(15) <<" |" << endl;
    cout << "+----------------------------------------------------------------------+" << endl;
    if(petHead!=nullptr){
        PetNode* current = petHead;  // start from the head of the list
        while (current != NULL) {
            SortPet(current->p);
            current = current->next;  // move to the next node
        }
        inOrder(sortPetHead);
        cout << "[Press 0 to Main Menu]          [Press 1 to Change Information]" << endl;
        cout << "Please enter your choice: ";
        int choice;
        cin >> choice;

        while (choice != 0 && choice != 1)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Error input!" << endl;
            cout << "[Press 0 to Main Menu]          [Press 1 to Change Information]" << endl;
            cout << "Please enter your choice: ";
            cin >> choice;
        }
        if (choice == 0)
        {
            admin();
        }
        if (choice == 1)
        {
            cout<<"Please Enter the pet ID that you want to edit: ";
            string id;
            cin>>id;
            AdminEditPetProfile( id);
        }

    }
    else{
        cout<<"Pet not found"<<endl;
        cout << "Please press Enter to back to admin page.";
        cin.ignore(); // Ignore the newline character in the input buffer
        cin.get(); // Wait for the user to press Enter
        admin();  // Back to admin page
    }
}

void Petsystem::SortPet(pet p){
    SortPetNodeTree* current = sortPetHead;
    SortPetNodeTree* temp = new SortPetNodeTree;
    temp->p = p;
    temp->left = NULL;
    temp->right = NULL;
    if (sortPetHead == nullptr){
        sortPetHead = temp;
    }
    else{
        string upperPetname = toUpperPet(p.getName()); // Convert username to uppercase
        string newbinaryPetname = toBinaryPet(upperPetname); // Convert username to binary
        while(current!=nullptr){
            string upperPetname = toUpperPet(current->p.getName()); // Convert username to uppercase
            string curbinaryPetname = toBinaryPet(upperPetname); // Convert username to binary
            if (newbinaryPetname < curbinaryPetname){ // Compare binary usernames
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