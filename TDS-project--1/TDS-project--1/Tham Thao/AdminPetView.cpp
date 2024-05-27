#include "../pet.hpp"

void Petsystem::ViewPetSortOpt(){
    system("CLS");
        br(1); 
        pre(2); cout << " +--------------------------+" << endl;
        pre(2); cout << " |        Pet List          |" << endl;
        pre(2); cout << " +--------------------------+" << endl;
        pre(2); cout << " |                          |" << endl;
        pre(2); cout << " |   1. View by pet ID      |" << endl;
        pre(2); cout << " |   2. View by pet name    |" << endl;
        pre(2); cout << " |                          |" << endl;
        pre(2); cout << " +--------------------------+" << endl << endl;


        cout << " Please enter your choice: ";
        int choice1;
        cin >> choice1;

        while(choice1 < 1 || choice1 > 2)
        {
            cout << " Error input!" << endl;
            cout << " Please enter your choice: ";
            cin >> choice1;
        }
        if(choice1 == 1)
        {
            AdminViewPet();
        }
        else if(choice1 == 2)
        {
            ViewPetByName();
        }
    }
