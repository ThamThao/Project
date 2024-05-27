#include "../pet.hpp"
using namespace std;


void Petsystem:: AdminViewPet() {
    // First print all pet names and IDs
    cout << "All pets:" << endl;
    PetNode* petTemp = petHead;
    cout << "+----------------------------------------------------------------------+" << endl;
    cout << "| " << setfill(' ') << setw(5) << "ID" << setw(5) << " | " << setw(15) << "Name" << setw(15)<< " | " << setw(15) << "Owner" <<  setw(15) <<" |" << endl;
    cout << "+----------------------------------------------------------------------+" << endl;
    
    while (petTemp != nullptr) 
    {
        cout << "| " << setfill(' ') << setw(5) << petTemp->p.getID()<< setw(5) << " | " << setw(15) << petTemp->p.getName() << setw(15)<<" | " << setw(15) << petTemp->p.getOwner() << setw(15)<< " |" << endl;
        cout << "+----------------------------------------------------------------------+" << endl;
        petTemp = petTemp->next;
    }

    // Then ask the user what they want to do
    string id;
    cout << "Enter pet's ID to edit a pet [ 0 to return to admin page]: ";
    cin >> id;

    if (id == "0") {
        admin();
    }
    else {
        AdminEditPetProfile(id);
    }
}