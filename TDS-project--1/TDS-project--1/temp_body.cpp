/*system("CLS");
    pre(2); cout << "+------------------------+" << endl;
    pre(2); cout << "|        Services        |" << endl;
    pre(2); cout << "+------------------------+" << endl;
    pre(2); cout << "|     1. Staycation      |" << endl;
    pre(2); cout << "|     2. Daycare         |" << endl;
    pre(2); cout << "|     3. Training        |" << endl;
    pre(2); cout << "+------------------------+" << endl << endl;

*/
/**/
#include <iostream>
#include <string>

class Calendar
{
private:
    int year;
    int month;
    int centCode;
    int yearCode;
    int monthCode;
    int dateCode = 1;
    int firstDay;

    bool checkLeap()
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void searchCentCode()
    {
        if (((year > 1499) && (year < 1600)) || ((year > 1899) && (year < 2000)) || ((year > 2299) && (year < 2400)))
        {
            centCode = 0;
        }
        else if (((year > 1599) && (year < 1700)) || ((year > 1999) && (year < 2100)) || ((year > 2399) && (year < 2500)))
        {
            centCode = 6;
        }
        else if (((year > 1699) && (year < 1800)) || ((year > 2099) && (year < 2200)) || ((year > 2499) && (year < 2600)))
        {
            centCode = 4;
        }
        else if (((year > 1799) && (year < 1900)) || ((year > 2199) && (year < 2300)) || ((year > 2599) && (year < 2700)))
        {
            centCode = 2;
        }
    }

    void searchYearCode()
    {
        std::string y = std::to_string(year);
        std::string str = y.substr(2);
        int last = std::stoi(str);
        yearCode = (last + (last / 4)) % 7;
    }

    void searchMonthCode()
    {
        if (month == 1 || month == 10)
        {
            monthCode = 0;
        }
        else if (month == 2 || month == 3 || month == 11)
        {
            monthCode = 3;
        }
        else if (month == 4 || month == 7)
        {
            monthCode = 6;
        }
        else if (month == 5)
        {
            monthCode = 1;
        }
        else if (month == 6)
        {
            monthCode = 4;
        }
        else if (month == 8)
        {
            monthCode = 2;
        }
        else if (month == 9 || month == 12)
        {
            monthCode = 5;
        }
    }

    void searchFirstDay()
    {
        searchCentCode();
        searchYearCode();
        searchMonthCode();
        int sum = centCode + yearCode + monthCode + dateCode;
        if (checkLeap())
        {
            if (month != 1 && month != 2)
            {
                sum++;
            }
        }
        firstDay = sum % 7;
    }

public:
    void setYear(int y)
    {
        year = y;
    }

    void setMonth(int m)
    {
        month = m;
    }

    void display()
    {
        std::string monthName[] = {" January ", " February ", " March ", " April ", " May ", " June ", " July ", " August ", " September ", " October ", " November ", " December "};
        std::string dayName[] = {" Sun\t", "Mon\t", "Tue\t", "Wed\t", "Thu\t", "Fri\t", "Sat\t"};
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int currentDay = 1;

        if (checkLeap())
        {
            days[1] = 29;
        }

        std::cout << monthName[month - 1] << year << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;

        for (int i = 0; i < 7; i++)
        {
            std::cout << dayName[i];
        }

        std::cout << std::endl << " ";
        searchFirstDay();

        for (int j = 0; j < firstDay; j++)
        {
            std::cout << "\t";
        }

        for (int i = firstDay; i < 7; i++)
        {
            std::cout << currentDay << "\t";
            currentDay++;
        }

        std::cout << std::endl << " ";

        while (currentDay <= days[month - 1])
        {
            for (int k = 0; k < 7; k++)
            {
                std::cout << currentDay << "\t";
                currentDay++;

                if (currentDay > days[month - 1])
                {
                    break;
                }

                if (k == 6)
                {
                    k = 0;
                }
            }
            std::cout << std::endl << " ";
        }
    }
};

int main()
{
    Calendar myCalendar;
    myCalendar.setYear(2024); // Set the desired year
    myCalendar.setMonth(1);   // Set the desired month
    myCalendar.display();     // Display the calendar

    return 0;
}
*/


/*void Petsystem::profile()
{
    system("cls");
    displaypet();
    char response;
    int choice, chg_choice;
    string line, line2, p_name, fname, filename, dummy;
    cout << "\nEnter the name of your pet change profile (0 to exit): ";
    getline(cin,p_name);
    if(p_name == "0")
    {
        menu();
    }
    else
    {
        fname = uname + "_" + p_name + ".txt";
        f.open(fname, ios::in);
        if(f.is_open())
        {
            pet *p = new pet;
            int k=0;
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
                        if (line == "0")
                            staycation1.setN0();
                        else
                            staycation1.setN1();
                    }
                    if(k==7)
                    {
                        if (line == "0")
                            daycare1.setN0();
                        else
                            daycare1.setN1();
                    }
                    if(k==8)
                    {
                        if (line == "0")
                            training1.setN0();
                        else
                            training1.setN1();
                    }

                }
            f.close();
            system("cls");
            pre(2);cout << "+----------------------------+" << endl;
            pre(2);cout << "|         Pet Details        |" << endl;
            pre(2);cout << "+----------------------------+" << endl;
            pre(2);cout << "|1. Name   |" << setfill(' ') << left << setw(17) << p->getName() << "|" << endl;
            pre(2);cout << "|2. Breed  |" << setfill(' ') << left << setw(17) << p->getBreed() << "|" << endl;
            pre(2);cout << "|3. Age    |" << setfill(' ') << left << setw(17) << p->getAge() << "|" << endl;
            pre(2);cout << "|4. Weight |" << setfill(' ') << left << setw(17) << p->getWeight() << "|" << endl;
            pre(2);cout << "|5. Gender |" << setfill(' ') << left << setw(17) << p->getGender() << "|" << endl;
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
                br(1); cout << "Which information you wish to change? (enter number) : ";
                cin >> chg_choice;
                while (chg_choice < 1 || chg_choice > 5)
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    br(1); cout << "Error input!"<<endl;
                    br(1);cout << "Which information you wish to change?(enter number) : ";
                    cin >> chg_choice;
                }
                getline(cin,dummy);
                if(chg_choice == 1)
                {
                    pre(1); p->setName();
                }
                else if(chg_choice == 2)
                {
                    pre(1); p->setBreed();
                }
                else if(chg_choice == 3)
                {
                    pre(1); p->setAge();
                }
                else if(chg_choice == 4)
                {
                    pre(1); p->setWeight();
                }
                else
                {
                    p->setGender();
                }
                system("CLS");
                pre(2);cout << "+----------------------------+" << endl;
                pre(2);cout << "|         Pet Details        |" << endl;
                pre(2);cout << "+----------------------------+" << endl;
                pre(2);cout << "|1. Name   |" << setfill(' ') << left << setw(17) << p->getName() << "|" << endl;
                pre(2);cout << "|2. Breed  |" << setfill(' ') << left << setw(17) << p->getBreed() << "|" << endl;
                pre(2);cout << "|3. Age    |" << setfill(' ') << left << setw(17) << p->getAge() << "|" << endl;
                pre(2);cout << "|4. Weight |" << setfill(' ') << left << setw(17) << p->getWeight() << "|" << endl;
                pre(2);cout << "|5. Gender |" << setfill(' ') << left << setw(17) << p->getGender() << "|" << endl;
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
                    f << staycation1.getN() << endl;
                    f << daycare1.getN() << endl;
                    f << training1.getN() << endl;
                    f.close();
                    if(p_name!=p->getName())
                    {

                        filename = uname + "_" + p->getName() + ".txt";
                        rename(fname.c_str(), filename.c_str());

                        //change data in user
                        filename = uname + ".txt";
                        f.open(filename, ios::in);
                        temp.open("temp.txt",ios::out);
                        while(getline(f,line))
                        {
                            if(line == p_name)
                            {
                                temp << p->getName() << endl;
                            }
                            else
                            {
                                temp << line << endl;
                            }
                        }
                        f.close();
                        temp.close();
                        remove(filename.c_str());
                        rename("temp.txt",filename.c_str());
                        delete p;
                    }
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
            cout << "Do you want to continue to delete pet?[Y/N]: ";
            cin >> response;
        }
        if(response == 'y' || response == 'Y')
        {
           getline(cin,dummy);
           profile();
        }
        else if (response == 'n' || response == 'N')
        {
            menu();
        }
    }
}

void Petsystem::book_app()
{
    string p_name,dummy,line,fname, line2;
    int k=0;
    displaypet();
    cout << "Enter the pet's name you wish to book for? [0 to exit]: ";
    getline(cin,p_name);
    if(p_name == "0")
    {
        menu();
    }
    else
    {
        fname = uname + "_" + p_name + ".txt";
        f.open(fname, ios::in);
        if(f.is_open())
        {
            pet* p = new pet;
            while (f >> line2)
                {
                    k++;
                    if(k == 1)
                    {
                        p->setpName(line2);
                    }
                    if(k == 2)
                    {
                        p->setpBreed(line2);

                    }
                    if(k == 3)
                    {
                        int *temp = new int;
                        *temp = atoi(line2.c_str());
                        p->setpAge(*temp);
                        delete temp;
                    }
                    if(k == 4)
                    {
                        double *temp = new double;
                        *temp = atof(line2.c_str());
                        p->setpWeight(*temp);
                        delete temp;
                    }
                    if(k == 5)
                    {
                        char *temp = new char;
                        *temp = line2.at(0);
                        p->setpGender(*temp);
                        delete temp;
                    }
                    if(k==6)
                    {
                        if (line2 == "0")
                            staycation1.setN0();
                        else
                            staycation1.setN1();
                    }
                    if(k==7)
                    {
                        if (line2 == "0")
                            daycare1.setN0();
                        else
                            daycare1.setN1();
                    }
                    if(k==8)
                    {
                        if (line2 == "0")
                            training1.setN0();
                        else
                            training1.setN1();
                    }

                }
                f.close();

            string name = p->getName();
            string breed = p->getBreed();
            delete p;
            appointment(name,breed);
        }
        else
        {
            cout << "\nPet not exist!"<<endl;
            cout << "Press Enter to continue...";
            getline(cin,dummy);
            menu();
        }
    }
}

void Petsystem::display_app()
{
    string p_name,dummy,line,fname, line2;
    string name,breed;
    int age;
    double weight;
    char gender;
    int k=0;
    displaypet();
    cout << "Enter the pet's name you wish to check [0 to exit]: ";
    getline(cin,p_name);
    if(p_name == "0")
    {
        menu();
    }
    else
    {
        fname = uname + "_" + p_name + ".txt";
        f.open(fname, ios::in);
        if(f.is_open())
        {
            pet* p = new pet;
            while (f >> line2)
                {
                    k++;
                    if(k == 1)
                    {
                        p->setpName(line2);
                    }
                    if(k == 2)
                    {
                        p->setpBreed(line2);

                    }
                    if(k == 3)
                    {
                        int *temp = new int;
                        *temp = atoi(line2.c_str());
                        p->setpAge(*temp);
                        delete temp;
                    }
                    if(k == 4)
                    {
                        double *temp = new double;
                        *temp = atof(line2.c_str());
                        p->setpWeight(*temp);
                        delete temp;
                    }
                    if(k == 5)
                    {
                        char *temp = new char;
                        *temp = line2.at(0);
                        p->setpGender(*temp);
                        delete temp;
                    }
                    if(k==6)
                    {
                        if (line2 == "0")
                            staycation1.setN0();
                        else
                            staycation1.setN1();
                    }
                    if(k==7)
                    {
                        if (line2 == "0")
                            daycare1.setN0();
                        else
                            daycare1.setN1();
                    }
                    if(k==8)
                    {
                        if (line2 == "0")
                            training1.setN0();
                        else
                            training1.setN1();
                    }

                }
                f.close();

             name = p->getName();
             breed = p->getBreed();
             age = p->getAge();
             weight = p->getWeight();
             gender = p->getGender();

            //delete p;
        }
        else
        {
            cout << "Pet not exist!"<<endl;
            cout << "Press Enter to continue...";
            getline(cin,dummy);
            menu();
        }
    }

    if(staycation1.getN() == 0 && daycare1.getN() == 0 && training1.getN() ==0)
    {
        system("CLS");
        cout << "\nYou don't have any appointment for your pet now."<<endl;
        cout << "Press enter to continue...";
        getline(cin,dummy);
        menu( );
    }
    cout << "+-----------------------------------------------------------------------------------------------------------------------------+"<< endl;
    cout << "| No.  | Pet                 | Breed      | Age     | Weight   | Gender   | Service      | Time                    | Fee      |" << endl;
    cout << "+-----------------------------------------------------------------------------------------------------------------------------+"<< endl;

    int x = 1,choice;

    if (staycation1.getN()==1)
    {
        cout << "| 0" << x << "   | " << setfill(' ') << left << setw(20) << name << "| "  << setfill(' ') << left << setw(11) << breed << "| " << setfill(' ') << left << setw(8) << age << "| " << setfill(' ') << left << setw(9) << weight << "| " << setfill(' ') << left << setw(9) << gender
        << "| " << setfill(' ') << left << setw(13) << staycation1.getSn() << "| " << setfill(' ') << left << setw(24) << staycation1.getTime() << "| " << setfill(' ') << left << setw(9) << staycation1.getFee() << "|" << endl;
        cout << "+-----------------------------------------------------------------------------------------------------------------------------+"<< endl;
        x++;


    }

    if (daycare1.getN()==1)
    {
        cout << "| 0" << x << "   | " << setfill(' ') << left << setw(20) << name << "| "  << setfill(' ') << left << setw(11) << breed << "| " << setfill(' ') << left << setw(8) << age << "| " << setfill(' ') << left << setw(9) << weight << "| " << setfill(' ') << left << setw(9) << gender
        << "| " << setfill(' ') << left << setw(13) << daycare1.getSn() << "| " << setfill(' ') << left << setw(24) << daycare1.getTime() << "| " << setfill(' ') << left << setw(9) << daycare1.getFee() << "|" << endl;
        cout << "+-----------------------------------------------------------------------------------------------------------------------------+"<< endl;
        x++;
    }



    if (training1.getN()==1)
    {
        cout << "| 0" << x << "   | " << setfill(' ') << left << setw(20) << name << "| "  << setfill(' ') << left << setw(11) << breed << "| " << setfill(' ') << left << setw(8) << age << "| " << setfill(' ') << left << setw(9) << weight << "| " << setfill(' ') << left << setw(9) << gender
        << "| " << setfill(' ') << left << setw(13) << training1.getSn() << "| " << setfill(' ') << left << setw(24) << training1.getTime() << "| " << setfill(' ') << left << setw(9) << training1.getFee() << "|" << endl;
        cout << "+-----------------------------------------------------------------------------------------------------------------------------+"<< endl;
        x++;
    }
        cout << "Press enter to continue...";
        getline(cin,dummy);
        menu();
}

void Petsystem::payment()
{
    system("cls");
    double debt,sum;
    string filename = uname + ".txt";
    f.open(filename,ios::in);
    string line, line2, dummy;
    int count,count1;
    fstream x;
    cout << "           >>>> Payment <<<<          " << endl << endl;
    cout << "+------------------------------------+" << endl;
    cout << "|         PET NAME          |  DEBT  |" << endl;
    cout << "+------------------------------------+" << endl;
    while(getline(f,line))
    {
        count++;
        if(count > 4)
        {
            string fname = uname + "_" + line + ".txt";
            x.open(fname, ios::in);
            if(x.is_open())
            {
                count1=0;
                debt=0;
                while(x >> line2)
                {
                    count1++;
                    if(count1==6)
                    {
                        if(line2=="1")
                            debt+=staycation1.getFee();
                    }
                    else if(count1==7)
                    {
                        if(line2=="1")
                            debt+=daycare1.getFee();
                    }
                    else if(count1==8)
                    {
                        if(line2=="1")
                            debt+=training1.getFee();
                    }
                }
                cout << "|" << setfill(' ') << setw(27) << left << line << "|" << right << setw(8) << debt << "|" << endl;
                x.close();
                sum+=debt;
            }
        }
    }
    cout << "+------------------------------------+"<<endl;
    cout << "|         TOTAL             |  "<< sum <<"|"<<endl;
    cout << "+------------------------------------+"<<endl;
    cout << endl;
    cout << "Press enter to continue...";
    getline(cin,dummy);
    menu();
}
*/

/*
void Petsystem::staycation(string name,string breed)
{
    string line,dummy;
    char response;
    if(staycation1.getN()==0)
    {
        br(1); pre(1); cout << " +-------------------------------------+" << endl;
        pre(1); cout << " |            Service Detail           |" << endl;
        pre(1); cout << " +-------------------------------------+" << endl;
        pre(1); cout << " |Service Name  |" << setfill(' ') << left << setw(22) << staycation1.getSn() << "|" << endl;
        pre(1); cout << " |Pet Name      |" << setfill(' ') << left << setw(22) << name << "|" << endl;
        pre(1); cout << " |Breed         |" << setfill(' ') << left << setw(22) << breed << "|" << endl;
        pre(1); cout << " |Fee/per night |" << setfill(' ') << left << setw(22) << staycation1.getFee() << "|" << endl;
        pre(1); cout << " +-------------------------------------+" << endl;
    }
    else
    {
        getline(cin,dummy);
        system("cls");
        cout << "\nYou have booked this service."<<endl;
        cout << "Press enter to go back to the main menu..."<<endl;
        getline(cin,dummy);
        menu();
    }

    cout << "\nDo you want to book this service?(y/n): ";
    cin >> response;
    response = tolower(response);
    while ((response != 'n' && response !='N' && response != 'y') || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nError Input!"<<endl;
        cout << "Do you want to book this service?(y/n): ";
        cin >> response;
    }

    if(response == 'y')
    {
        staycation1.setN1();
        string fname = uname + "_" + name + ".txt";
        f.open(fname, ios::in);
        temp.open("temp.txt", ios::out);
        int count = 0;
        while (f >> line)
        {
            count++;
            if(count==6)
            {
                temp << "1" << endl;
            }
            else
            {
                temp << line << endl;
            }
        }
        f.close();
        temp.close();
        remove(fname.c_str());
        rename("temp.txt", fname.c_str());
    }
    else
    {
        menu();
    }

    getline(cin,dummy);
    cout << "\nYou have successfully booked this service!"<<endl;
    cout << "See you soon! ;)" << endl;
    cout << "Press enter to go back to the main menu...";
    getline(cin,dummy);
    menu();
}

void Petsystem::daycare(string name , string breed)
{
    string line,dummy;
    char response;
    if(daycare1.getN()==0)
    {
        br(1); pre(1); cout << " +-------------------------------------+" << endl;
        pre(1); cout << " |            Service Detail           |" << endl;
        pre(1); cout << " +-------------------------------------+" << endl;
        pre(1); cout << " |Service Name  |" << setfill(' ') << left << setw(22) << daycare1.getSn() << "|" << endl;
        pre(1); cout << " |Pet Name      |" << setfill(' ') << left << setw(22) << name << "|" << endl;
        pre(1); cout << " |Breed         |" << setfill(' ') << left << setw(22) << breed << "|" << endl;
        pre(1); cout << " |Time          |" << setfill(' ') << left << setw(22) << daycare1.getTime() << "|" << endl;
        pre(1); cout << " |Fee/per day   |" << setfill(' ') << left << setw(22) <<daycare1.getFee() << "|" << endl;
        pre(1); cout << " +-------------------------------------+" << endl;
    }
    else
    {
        getline(cin,dummy);
        system("cls");
        cout<<"\nYou have booked this service."<<endl;
        cout<<"Press enter to go back to the main menu..."<<endl;
        getline(cin,dummy);
        menu();
    }

    cout << "\nDo you want to book this service?(y/n): ";
    cin >> response;
    response = tolower(response);
    while ((response != 'n' && response !='N' && response != 'y') || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nError Input!!!"<<endl;
        cout << "Do you want to book this service?(y/n): ";
        cin >> response;
    }

    if(response == 'y')
    {
        daycare1.setN1();
        string fname = uname + "_" + name + ".txt";
        f.open(fname, ios::in);
        temp.open("temp.txt", ios::out);
        int count = 0;
        while (f >> line)
        {
            count++;
            if(count==7)
            {
                temp << "1" << endl;
            }
            else
            {
                temp << line << endl;
            }
        }
        f.close();
        temp.close();
        remove(fname.c_str());
        rename("temp.txt", fname.c_str());
    }
    else
    {
        menu();
    }

    getline(cin,dummy);
    cout << "\nYou have successfully booked this service!"<<endl;
    cout << "See you soon! ;)" << endl;
    cout << "Press enter to go back to the main menu...";
    getline(cin,dummy);
    menu();


}

void Petsystem::training(string name , string breed)
{
    string line,dummy;
    char response;
    if(training1.getN()==0)
    {
        br(1); pre(1); cout << " +-------------------------------------+" << endl;
        pre(1); cout << " |            Service Detail           |" << endl;
        pre(1); cout << " +-------------------------------------+" << endl;
        pre(1); cout << " |Service Name  |" << setfill(' ') << left << setw(22) << training1.getSn() << "|" << endl;
        pre(1); cout << " |Pet Name      |" << setfill(' ') << left << setw(22) << name << "|" << endl;
        pre(1); cout << " |Breed         |" << setfill(' ') << left << setw(22) << breed << "|" << endl;
        pre(1); cout << " |Time          |" << setfill(' ') << left << setw(22) << training1.getTime() << "|" << endl;
        pre(1); cout << " |Fee/per time  |" << setfill(' ') << left << setw(22) << training1.getFee() << "|" << endl;
        pre(1); cout << " +-------------------------------------+" << endl;
    }
    else
    {
        getline(cin,dummy);
        system("cls");
        cout<<"\nYou have booked this service."<<endl;
        cout<<"Press enter to go back to the main menu..."<<endl;
        getline(cin,dummy);
        menu();
    }
    cout << "\nDo you want to book this service?(y/n): ";
    cin >> response;
    response = tolower(response);
    while ((response != 'n' && response !='N' && response != 'y') || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nError Input!"<<endl;
        cout << "Do you want to book this service?(y/n): ";
        cin >> response;
    }

    if(response == 'y')
    {
        training1.setN1();
        string fname = uname + "_" + name + ".txt";
        f.open(fname, ios::in);
        temp.open("temp.txt", ios::out);
        int count = 0;
        while (f >> line)
        {
            count++;
            if(count==8)
            {
                temp << "1" << endl;
            }
            else
            {
                temp << line << endl;
            }
        }
        f.close();
        temp.close();
        remove(fname.c_str());
        rename("temp.txt", fname.c_str());
    }
    else
    {
        menu();
    }

    getline(cin,dummy);
    cout << "\nYou have successfully booked this service!"<<endl;
    cout << "See you soon! ;)" << endl;
    cout<<"Press enter to go back to the main menu...";
    getline(cin,dummy);
    menu();

}
*/