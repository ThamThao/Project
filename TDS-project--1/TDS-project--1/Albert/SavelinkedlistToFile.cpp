#include "../PetSystemBody.cpp"
//#include "../pet.hpp"




using namespace std;




void Petsystem::saveUserToFile(UserNode* head) 
{
    FILE* file = fopen("users.dat", "wb");
    if (file == nullptr) {
        // handle error
        return;
    }

    UserNode* current = head;
    while (current != nullptr) {
        fwrite(&current->a, sizeof(user), 1, file);
        current = current->next;
    }

    fclose(file);
}



/*
int main()
{

   /// Create a few Pet objects
    pet pet1;
    pet1.setpName("Fluffy");
    pet1.setpBreed("Persian");
    pet1.setpAge(3);
    pet1.setpWeight(4.5);
    pet1.setpGender('M');

    pet pet2;
    pet2.setpName("Spot");
    pet2.setpBreed("Bulldog");
    pet2.setpAge(5);
    pet2.setpWeight(20.0);
    pet2.setpGender('M');

    pet pet3;
    pet3.setpName("Rex");
    pet3.setpBreed("German Shepherd");
    pet3.setpAge(7);
    pet3.setpWeight(30.0);
    pet3.setpGender('M');

    // Create a few PetNode objects
    PetNode node1 = { pet1, nullptr };
    PetNode node2 = { pet2, &node1 };
    PetNode node3 = { pet3, &node2 };

    pet pet1;
    pet1.setpName("Fluffy");
    pet1.setpBreed("Persian");
    pet1.setpAge(3);
    pet1.setpWeight(4.5);
    pet1.setpGender('M');

    pet pet2;
    pet2.setpName("Spot");
    pet2.setpBreed("Bulldog");
    pet2.setpAge(5);
    pet2.setpWeight(20.0);
    pet2.setpGender('M');

    pet pet3;
    pet3.setpName("Rex");
    pet3.setpBreed("German Shepherd");
    pet3.setpAge(7);
    pet3.setpWeight(30.0);
    pet3.setpGender('M');

    InsertPet(pet1);
    InsertPet(pet2);
    InsertPet(pet3);

    savePetToFile();

    // Set petHead to the start of the linked list
    Petsystem petsystem;
    petsystem.petHead = &node1; // start from node1

    // Save the linked list to a file
    petsystem.savePetToFile(&node1);

    return 0;
}*/