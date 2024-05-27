#include "../pet.hpp"


void Petsystem::AdminEditPetProfile(string id)
{
    char response;
    int choice, chg_choice;
    string line, line2, p_name, fname, filename, dummy;
        fname = id + ".txt";//filename
        f.open(fname, ios::in);
        if(f.is_open())
        {
            pet *p = new pet;
            int k=0;
            p->setID(atoi(id.c_str()));
            while(getline(f,line))
                {
                    k++;
                    if(k == 1)
                    {
                        p->setpName(line);
                    }
                    if(k == 2)
                    {
                        p->setpBreed(line);

                    }
                    if(k == 3)
                    {
                        int *temp = new int;
                        *temp = atoi(line.c_str());
                        p->setpAge(*temp);
                        delete temp;
                    }
                    if(k == 4)
                    {
                        double *temp = new double;
                        *temp = atof(line.c_str());
                        p->setpWeight(*temp);
                        delete temp;
                    }
                    if(k == 5)
                    {
                        char *temp = new char;
                        *temp = line.at(0);
                        p->setpGender(*temp);
                        delete temp;
                    }
                    if(k == 6)
                    {
                        p->setOwner(line);
                    }
                }
            f.close();
            system("cls");
            pre(2);cout << "+----------------------------+" << endl;
            pre(2);cout << "|         Pet Details        |" << endl;
            pre(2);cout << "+----------------------------+" << endl;
            pre(2);cout << "|1. ID         |" << setfill(' ') << left << setw(14) << id << "|" << endl; 
            pre(2);cout << "|2. Name       |" << setfill(' ') << left << setw(14) << p->getName() << "|" << endl; 
            pre(2);cout << "|3. Breed      |" << setfill(' ') << left << setw(14) << p->getBreed() << "|" << endl;
            pre(2);cout << "|4. Age        |" << setfill(' ') << left << setw(14) << p->getAge() << "|" << endl;
            pre(2);cout << "|5. Weight     |" << setfill(' ') << left << setw(14) << p->getWeight() << "|" << endl;
            pre(2);cout << "|6. Gender     |" << setfill(' ') << left << setw(14) << p->getGender() << "|" << endl;
            pre(2);cout << "|7. Owner Name |" << setfill(' ') << left << setw(14) << p->getOwner() << "|" << endl;
            pre(2);cout << "+----------------------------+" << endl << endl;

            cout << "[Press 0 to Main Menu]          [Press 1 to Change Information]" << endl;
            cout << "Please enter your choice: ";
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
                br(1); cout << "Which information you wish to change except pet ID and its owner? (enter number) : ";
                cin >> chg_choice;
                while (chg_choice < 2 || chg_choice > 6)
                {
                    if (chg_choice == 1){
                        cin.clear();
                        cin.ignore(100, '\n');
                        br(1); cout << "ID cannot be changed!"<<endl;
                        br(1);cout << "Which information you wish to change?(enter number) : ";
                        cin >> chg_choice;
                    }
                    else if (chg_choice == 7){
                        cin.clear();
                        cin.ignore(100, '\n');
                        br(1); cout << "Owner cannot be changed!"<<endl;
                        br(1);cout << "Which information you wish to change?(enter number) : ";
                        cin >> chg_choice;
                    }
                    else{
                        cin.clear();
                        cin.ignore(100, '\n');
                        br(1); cout << "Error input!"<<endl;
                        br(1);cout << "Which information you wish to change?(enter number) : ";
                        cin >> chg_choice;
                    }
                    
                }

                getline(cin,dummy);
                if(chg_choice == 2)
                {
                    pre(1); p->setName();
                }
                else if(chg_choice == 3)
                {
                    pre(1); p->setBreed();
                }
                else if(chg_choice == 4)
                {
                    pre(1); p->setAge();
                }
                else if(chg_choice == 5)
                {
                    pre(1); p->setWeight();
                }
                else
                {
                    pre(1); p->setGender();
                }
                
                system("CLS");
                pre(2);cout << "+----------------------------+" << endl;
                pre(2);cout << "|         Pet Details        |" << endl;
                pre(2);cout << "+----------------------------+" << endl;
                pre(2);cout << "|1. ID         |" << setfill(' ') << left << setw(14) << p->getID() << "|" << endl; 
                pre(2);cout << "|2. Name       |" << setfill(' ') << left << setw(14) << p->getName() << "|" << endl; 
                pre(2);cout << "|3. Breed      |" << setfill(' ') << left << setw(14) << p->getBreed() << "|" << endl;
                pre(2);cout << "|4. Age        |" << setfill(' ') << left << setw(14) << p->getAge() << "|" << endl;
                pre(2);cout << "|5. Weight     |" << setfill(' ') << left << setw(14) << p->getWeight() << "|" << endl;
                pre(2);cout << "|6. Gender     |" << setfill(' ') << left << setw(14) << p->getGender() << "|" << endl;
                pre(2);cout << "|7. Owner Name |" << setfill(' ') << left << setw(14) << p->getOwner() << "|" << endl;
                pre(2);cout << "+----------------------------+" << endl << endl;

                cout << "Do you want to save changes?[y/n]: ";
                cin >> response;
                if (response == 'y' || response =='Y')
                {
                    f.open(fname, ios::out);
                    f << p->getName() << endl;
                    f << p->getBreed() << endl;
                    f << p->getAge() << endl;
                    f << p->getWeight() << endl;
                    f << p->getGender() << endl;
                    f << p->getOwner() << endl;
                    f.close();
                }

            }
        }
        else
        {
            cout << "\nPet does not exist!" << endl;
            cout << "Press Enter to continue...";
            getline(cin,dummy);
            profile();
        }
        f.close();
        cout << "Do you want to continue to change information?[Y/N]: ";
        cin >> response;
        while(response != 'y' && response != 'Y' && response != 'n' && response != 'N')
        {
            cin.ignore(100, '\n');
            cout << "\nError input! " << endl;
            cout << "Do you want to continue to change information?[Y/N]: ";
            cin >> response;
        }
        if(response == 'y' || response == 'Y')
        {
           getline(cin,dummy);
           AdminEditPetProfile(id);
        }
        else if (response == 'n' || response == 'N')
        {
            admin();
        }
}