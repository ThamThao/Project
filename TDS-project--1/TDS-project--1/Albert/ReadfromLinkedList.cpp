//#include "../pet.hpp"
#include "../PetSystemBody.cpp"

using namespace std;






/*void Petsystem::savePetToFile() { //TRY WHETHER LINKED IS INITRIALIZED
        FILE* file = fopen("try.txt", "w");
        if (file == nullptr) {
            std::cout << "Error opening file for writing." << std::endl;
            return;
        }

        PetNode* current = petHead;
        while (current != nullptr) {
            fwrite(&current->p, sizeof(struct pet), 1, file);
            current = current->next;
        }

        fflush(file);
        fclose(file);
    }*/
int main()
{
    Petsystem g;
    /*cout<<"1"<<endl;
    g.readFromLinkedlist();
    cout<<"2"<<endl;
    g.printLinkedList();
    cout<<"3"<<endl;

    g.savePetToFile(g.getPetHeadNode());*/
    
}