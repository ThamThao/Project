#include "../pet.hpp"


void Petsystem::AdminEditUserProfile(string username)
{
    char response;
    int choice, chg_choice;
    string line, line2, p_name, fname, filename, dummy;
        fname = username + ".txt";//check the variable uname later
        f.open(fname, ios::in);
        if(f.is_open())
        {
            user *a = new user;
            int k=0;
            a->setUname(username);
            while(getline(f,line))
                {
                    k++;
                    if(k == 1)
                    {
                        a->setEmail(line);

                    }
                    if(k == 2)
                    {
                        a->setAddress(line);
                    }
                    if(k == 3)
                    {
                        a->setPhone(line);
                    }
                    if(k == 4)
                    {
                        a->setPassword(line);
                    }
                }
            f.close();
            system("cls");
            pre(2);cout << "+----------------------------+" << endl;
            pre(2);cout << "|         User Details        |" << endl;
            pre(2);cout << "+----------------------------+" << endl;
            pre(2);cout << "|1. Name           |" << setfill(' ') << left << setw(17) << a->getUname() << "|" << endl; 
            pre(2);cout << "|2. Email          |" << setfill(' ') << left << setw(17) << a->getEmail() << "|" << endl;
            pre(2);cout << "|3. Address        |" << setfill(' ') << left << setw(17) << a->getAddress() << "|" << endl;
            pre(2);cout << "|4. Phone          |" << setfill(' ') << left << setw(17) << a->getPhone() << "|" << endl;
            pre(2);cout << "|5. Password       |" << setfill(' ') << left << setw(17) << a->getPassword() << "|" << endl;
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
                menu();
            }
            if (choice == 1)
            {
                br(1); cout << "Which information you wish to change except username? (enter number) : ";
                cin >> chg_choice;
                while (chg_choice < 2 || chg_choice > 5)
                {
                    if (chg_choice == 1){
                        cin.clear();
                        cin.ignore(100, '\n');
                        br(1); cout << "Username cannot be changed!"<<endl;
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
                    pre(1); a->setEmail();
                }
                else if(chg_choice == 3)
                {
                    pre(1); a->setAddress();
                }
                else if(chg_choice == 4)
                {
                    pre(1); a->setPhone();
                }
                else
                {
                    pre(1); a->setPassword();
                }
                
                system("CLS");
                pre(2);cout << "+----------------------------+" << endl;
                pre(2);cout << "|         User Details        |" << endl;
                pre(2);cout << "+----------------------------+" << endl;
                pre(2);cout << "|1. Name           |" << setfill(' ') << left << setw(17) << a->getUname() << "|" << endl; 
                pre(2);cout << "|2. Email          |" << setfill(' ') << left << setw(17) << a->getEmail() << "|" << endl;
                pre(2);cout << "|3. Address        |" << setfill(' ') << left << setw(17) << a->getAddress()<< "|" << endl;
                pre(2);cout << "|4. Phone          |" << setfill(' ') << left << setw(17) << a->getPhone() << "|" << endl;
                pre(2);cout << "|5. Password       |" << setfill(' ') << left << setw(17) << a->getPassword() << "|" << endl;
                pre(2);cout << "+----------------------------+" << endl << endl;

                cout << "Do you want to save changes?[y/n]: ";
                cin >> response;
                if (response == 'y' || response =='Y')
                {
                    f.open(fname, ios::out);
                    f << a->getEmail() << endl;
                    f << a->getAddress() << endl;
                    f << a->getPhone() << endl;
                    f << a->getPassword() << endl;
                    f.close();
                }

            }
        }
        else
        {
            cout << "\nUser does not exist!" << endl;
            cout << "Press Enter to continue...";
            getline(cin,dummy);
            AdminEditUserProfile(username);//nid check
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
           AdminEditUserProfile(username);
        }
        else if (response == 'n' || response == 'N')
        {
            menu();
        }
}