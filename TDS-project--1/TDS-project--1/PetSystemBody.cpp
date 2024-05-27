#include <fstream>
#include <iostream>
#include <cstring>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <ios> //used to get stream size
#include <limits> //used to get numeric limits
#include <iomanip> //setw function
#include <cctype> //isdigit or isalpha function
#include <string>
#include <ctime> //used for check the day of the month
#include <algorithm>
#include <bitset>
#include <regex>


#include "pet.hpp"


using namespace std;

fstream f, temp;
string uname;

//User class
user::user(){
    uname = "Unknown";
    password = "Unknown";
    email = "Unknown";
    address = "Unknown";
    phone = "Unknown";
}

void user::setUname(){
    int n;
        char x;
        pre(1); cout << " 1. User Name          : ";
        getline(cin, uname);
        n = uname.length();
        for (int i=0; i<n; i++)
        {
            x = uname.at(i);
            if (isdigit(x)) //use isdigit or isalpha
            {
                pre(1); cout << " Error input of user's name! " << endl;
                pre(1); cout << " 1. User Name          : " ;
                getline(cin, uname);
                n = uname.length();
                i = 0;
            }
        }
}

string user::getUname(){
    return uname;
}

void user::setEmail(){
    int n, k = 0;
        char x;
        pre(1); cout << " 2. Email              : ";
        getline(cin, email);
        regex r(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");

        while(!regex_match(email,r) )
        {
            pre(1); cout << " Wrong format!" << endl;
            pre(1); cout << " 2. Email              : ";
            getline(cin,email);
        }
        /*n = email.length();
        for (int i=0; i<n; i++)
        {
            x = email.at(i);
            if (int(x)==64)
            {
                k = 1;
            }
            if ( !isdigit(x) && !isalpha(x) && (int(x)!=64) && (int(x)!=46) )// @ = ASCII value 64
            {
                pre(1); cout << " Error input of email!" << endl;
                pre(1); cout << " 2. Email              : ";
                getline(cin,email);
                n = email.length();
            }
        }*/
        /*if (k == 0)
        {
            pre(1); cout << " Error input of email!" << endl;
            setEmail();
        }*/
}

string user::getEmail(){
    return email;
}

void user::setAddress()
    {
        pre(1); cout << " 3. Address            : ";
        getline(cin,address);
    }
string user::getAddress()
    {
        return address;
    }
void user::setPhone()
    {
        pre(1); cout << " 4. Phone(without '-') : ";
        cin >> phone;
        regex r("01[0-9]{8,9}");

        while (!regex_match(phone,r) )
        {
            pre(1); cout << " Wrong format!" << endl;
            pre(1); cout << " 4. Phone(without '-') : ";
            cin >> phone;
        }
    }
string user::getPhone()
    {
        return phone;
    }
void user::setPassword()
    {
        pre(1); cout << " 5. Password           : ";
        cin >> password;
        while (password == "0")
        {
            pre(1); cout << " Wrong Password! Please try again!" << endl;
            pre(1); cout << " 5. Password           : ";
            cin >> password;
        }
    }
string user::getPassword()
    {
        return password;
    }
void user::setUname(string User_name)
    {
        uname = User_name;
    }
void user::setEmail(string e_mail)
    {
        email = e_mail;
    }
void user::setAddress(string a)
    {
        address = a;
    }
void user::setPhone(string phoneNo)
    {
        phone = phoneNo;
    }
void user::setPassword(string password)
    {
        this->password = password;
    }

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

//Pet class
void pet::setID(int a){
    id = a;
}
int pet::getID(){
    return id;
}
void pet::setName()
    {
        int n;
        char x;
        pre(1); cout << " 1. Pet Name        : ";
        getline(cin, p_name);
        n = p_name.length();
        for (int i=0; i<n; i++)
        {
            x = p_name.at(i);   //.at is a function to extract characters by characters from a given string
            if ( (int(x)<32) || ( (int(x)<65)&&(int(x)>32) ) || ((int(x)>90)&&(int(x)<97) || (int(x)>122)))  //32=space, 65=A, 90=Z, 97=a, 122=z
            {
                pre(1); cout << " Error input of pet's name!" << endl;
                pre(1); cout << " 1. Pet Name        : ";
                getline(cin,p_name);
                n = p_name.length();
                i=0;
            }
        }
    }
string pet::getName()
    {
        return p_name;
    }
void pet::setBreed()
    {
        int n;
        char x;
        pre(1); cout << " 2. Pet Breed       : ";
        getline(cin, breed);
        n = breed.length();
        for (int i=0; i<n; i++)
        {
            x = breed.at(i);
            if ( (int(x)<32) || ( (int(x)<65)&&(int(x)>32) ) || ((int(x)>90)&&(int(x)<97) || (int(x)>122))) //32=space, 65=A, 90=Z, 97=a, 122=z
            {
                pre(1); cout << " Error input of pet's breed!" << endl;
                pre(1); cout << " 2. Pet Breed       : ";
                getline(cin,breed);
                n = breed.length();
                i=0;
            }
        }
    }
string pet::getBreed()
{
        return breed;
}
void pet::setAge(int num){
        age = num;
    }
void pet::setAge()
    {
        pre(1); cout << " 3. Pet Age [year]  : ";
        cin >> age;
        while ( (age<=0) || cin.fail() )
        {
            cin.clear();            //clear the wrong input type error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clear the input buffer
            pre(1); cout << " Error input of pet's age!" << endl;
            pre(1); cout << " 3. Pet Age [year]  : ";
            cin >> age;
        }
    }
int pet::getAge()
    {
        return age;
    }
void pet::setWeight()
    {
        pre(1); cout << " 4. Pet Weight [kg] : ";
        cin >> weight;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            pre(1); cout << " Invalid input of pet's weight!"<<endl;
            pre(1); cout << " 4. Pet Weight [kg] :";
            cin >> weight;
        }
    }
double pet::getWeight()
    {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(1);
        return weight;
    }
void pet::setGender()
    {
        pre(1);cout << " 5. Pet Gender [M/F]: ";
        cin >> gender;
        while(gender != 'm' && gender != 'M' && gender != 'F' && gender != 'f')
        {
            cin.clear();
            cin.ignore(100, '\n');
            pre(1); cout << " Invalid input of pet's gender!"<<endl;
            pre(1); cout << " 5. Pet Gender [M/F]: ";
            cin >> gender;
        }
        if(gender == 'm')
            gender = 'M';
        else if(gender == 'f')
            gender = 'F';
    }
char pet::getGender()
    {
        return gender;
    }
void pet::setpName(string pet_name)
    {
        p_name = pet_name;
    }
void pet::setpBreed(string p_breed)
    {
        breed = p_breed;
    }
void pet::setpAge(int age)
    {
        this->age = age;
    }
void pet::setpWeight(double weight)
    {
        this->weight = weight;
    }
void pet::setpGender(char sex)
    {
        gender = sex;
    }
void pet::setOwner(string owner)
{
        this->owner = owner;
}
string pet::getOwner()  
{
    return owner;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

//PetSystem class
Petsystem::Petsystem()
{
    readFromLinkedlist(); //initialize user and pet linked list
    welcome();
    
}


int Petsystem::SearchNewID(){

    PetNode* temp;
    if(petHead == nullptr){
        return 100; //no pet yet, assign first id
    }
    else{
        for(temp = petHead; temp!=nullptr; temp=temp->next)
        {
            if(temp->next==nullptr){
                int id = temp->p.getID()+1;
                return id;
            }
        }
        
    }
}

ServiceNode* Petsystem::SearchNodeTreeINT(ServiceNode *head, int target){
    ServiceNode* temp = head;
    if(head == nullptr){
        return 0; //empty tree
    }
    else{
        while(temp != nullptr){
            if(temp->date == target){
                return temp;
            }
            else if(target < temp->date){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }

        return 0; // target not found
    }
}

void Petsystem::InsertUser(user &newUser){ //function insertUser under class petsystem
    UserNode* newNode = new UserNode;
    newNode->a = newUser;
    newNode->next = nullptr;
    if(userHead == nullptr){
        userHead = newNode;
    }
    else{
        for(UserNode* temp = userHead;temp!=nullptr;temp=temp->next){
            if(temp->next==nullptr){
                temp->next = newNode;
                break;
            }
        }
    }
}

void Petsystem::InsertPet(pet &newPet){
    PetNode* newNode = new PetNode;
    newNode->p = newPet;
    newNode->next = nullptr;
    if(petHead == nullptr){
        petHead = newNode;
    }
    else{
        for(PetNode* temp = petHead;temp!=nullptr;temp=temp->next){
            if(temp->next==nullptr){
                temp->next = newNode;
                break;
            }
        }
    }
}

void Petsystem::InsertDate(ServiceNode *&head, int newDate, int id){
    ServiceNode* newNode = new ServiceNode;

    newNode -> date = newDate;
    newNode -> left = nullptr;
    newNode -> right = nullptr;
    newNode -> pet1 = 0;
    newNode -> pet2 = 0;
    newNode -> pet3 = 0;
    newNode -> pet4 = 0;
    newNode -> pet5 = 0;
    newNode -> count = 1;
    if(id != 0){
        newNode -> pet1 = id;
    }
    if (head == nullptr){
        head = newNode;
    }
    else{
        ServiceNode* temp = head;
        while(temp!=nullptr){
            if (newDate < temp->date){
                if(temp->left==nullptr){
                    temp->left = newNode;
                    break;
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->right==nullptr){
                    temp->right = newNode;
                    break;
                }
                else{
                    temp = temp->right;
                }
            }
        }
    }
}

PetNode* Petsystem::SearchPetID(int id){
    PetNode* current = petHead;  // start from the head of the list
    while (current != NULL) {
        if (current->p.getID() == id) {
            return current;  // found the id, return the node
        }
        current = current->next;  // move to the next node a
    }
    return NULL;  // id not found
}

void Petsystem::deletePetNode(int id){
    if(petHead->p.getID() == id){
        PetNode* temp = petHead;
        petHead = petHead->next;
        delete temp;
    }
    else{
        PetNode* temp = petHead;
        while(temp->next!=nullptr){
            if(temp->next->p.getID() == id){
                PetNode* del = temp->next;
                temp->next = temp->next->next;
                delete del;
                break;
            }
            else{
                temp = temp->next;
            }
        }
    }
}

void Petsystem::welcome()
{
    char welcome[50]="WELCOME";
	char welcome2[50]=" TO";
	char welcome3[50]=" PET HOTEL";
	char welcome4[50]=" RECORD SYSTEM";
	printf("\n\n\n\n\n\t\t\t");
	for(int wlc=0; wlc<strlen(welcome);wlc++){

		printf(" %c",welcome[wlc]);
		Sleep(100);
	}
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){

		printf(" %c",welcome2[wlc2]);
		Sleep(100);
	}
	printf("\n\n\n\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='D'){

			printf(" %c",welcome3[wlc3]);
		}
		else{

			printf(" %c",welcome3[wlc3]);
		}

		Sleep(100);
	}
	printf("\n\n\n\t\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){

			printf(" %c",welcome4[wlc3]);
		}
		else{

			printf(" %c",welcome4[wlc3]);
		}
		Sleep(100);
	}
    main_menu();
}

void Petsystem:: main_menu(){

    int choice;

	system("cls");
    pre(1);cout<<" __      __        __\n";
    pre(1);cout<<"/  \\    /  \\ ____ |  | ____  ____    _____   ____ \n";
    pre(1);cout<<"\\   \\/\\/   // __ \\|  |/ ___\\/  _ \\  /     \\ / __ \\\n";
    pre(1);cout<<" \\        /|  ___/|  |  \\__(  <_> )|  Y Y  \|  ___/\n";
    pre(1);cout<<"  \\__/\\__/  \\____\\|__|\\_____>____/ |__|_|__|\\____\\\n";
	br(3); pre(3); echo(">> 1. Log In"); Sleep(400);
	br(2); pre(3); echo(">> 2. Sign Up"); Sleep(400);
	br(2); pre(3); echo(">> 3. Exit");  Sleep(400);


    checkerror(choice,1,3);

	if (choice == 1)
    {
        login();
    }
    else if (choice == 2)
    {
        signup();
        login();
    }
    else if (choice == 3)
    {
        exit(0);
    }
    else
    {
        br(1);pre(1);cout << "You have entered an invalid number! Please try again!" << endl; Sleep(1000);
        cin.clear();
        main_menu();
    }
}

void Petsystem::login()
{
    string uname1,password;
    string dummy;
    user *u = new user;

    getline(cin,dummy);
    system("CLS");
    br(1); pre(2);cout << " >>>> User Login <<<< " << endl;
    br(1); pre(1); cout << " [Press 0 to EXIT] " << endl ;
    pre(1); cout << " User Name: ";
    getline(cin,uname1);
    if (uname1 == "0")
    {
        exit(0);
    }

    if (uname1 == "admin")
    {
        do{
            pre(1); cout << " Password : ";
            char asterisk;

            cin >> password;
            if (password == "0")
            {
                main_menu();
            }
            else if (password == "admin")
            {
                admin();
            }
            else{
                cout << "Password wrong! Please try again!" << endl;
            }
        }while(password != "admin");
    }

    string filename = uname1 + ".txt";
    f.open(filename,ios::in); //allows input(read operations)
    while (!f.is_open()) //check if a file is open
    {
        pre(1); cout << " User Name not found! Please try again!"<<endl;
        pre(1); cout << " User Name: ";
        getline(cin,uname1);
        if (uname1 == "0")
        {
            exit(0);
        }
        if (uname1 == "admin")
        {
            do{
                pre(1); cout << " Password : ";
                char asterisk;

                cin >> password;
                if (password == "0")
                {
                    main_menu();
                }
                else if (password == "admin")
                {
                    admin();
                }
                else{
                    cout << "Password wrong! Please try again!" << endl;
                }
            }while(password != "admin");
            filename = uname1 + ".txt";
            f.open(filename,ios::in);
        }
    }
    u->setUname(uname1);
    int count = 0;
    string line;
    while(getline(f,line))
    {
        count++;
        if(count == 1)
        {
            u->setEmail(line);
        }
        if(count == 2)
        {
            u->setAddress(line);
        }
         if(count == 3)
        {
            u->setPhone(line);
        }
        if(count == 4)
        {
            u->setPassword(line);
        }
    }
    uname = u->getUname();

    f.close();

    pre(1); cout << " Password : ";
    cin >> password;
    if(password == "0") //whyyyyyy
    {
        main_menu();
    }
    while (password != u->getPassword())
    {
        if(password == "0")
        {
            main_menu();
        }
        pre(1); cout << " Password incorrect! Please try again!"<<endl;
        pre(1); cout << " Password : ";
        cin>> password;
    }
    if (password == u->getPassword())
    {
        // Get the current date
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int year = 1900 + ltm->tm_year;
        int month = 1 + ltm->tm_mon;
        ostringstream oss;
        oss << setw(2) << setfill ('0') << month;
        oss << setw(2) << setfill ('0') << year;
        string date2 = oss.str();

        string fname1 = "staycation_" + date2 + ".txt";
        string fname2 = "grooming_" + date2 + ".txt";
        string fname3 = "training_" + date2 + ".txt";

        c = fopen(fname1.c_str(), "rb");
        if(c!=nullptr){
            staycationHead = nullptr;
            readServiceFromFile(staycationHead);
            fclose(c);
        }
        else{
            fclose(c);
        }

        c = fopen(fname2.c_str(), "rb");
        if(!c){
            groomingHead = nullptr;
            readServiceFromFile(groomingHead);
            fclose(c);
        }
        else{
            fclose(c);
        }

        c = fopen(fname3.c_str(), "rb");
        if(!c){
            trainingHead = nullptr;
            readServiceFromFile(trainingHead);
            fclose(c);
        }
        else{
            fclose(c);
        }
        menu();
    }
}

void Petsystem::admin()
{

    int choice;

	system("cls");
    pre(1); cout << "                  _           _              __  __                 " << endl;
    pre(1); cout << "          /\\     | |         (_)            |  \\/  |                " << endl;
    pre(1); cout << "         /  \\   _| |_ __ ___  _ _ __        | \\  / | __ _ __  _   _ " << endl;
    pre(1); cout << "        / /\\ \\ / _ | ,_,  _ \\| | ,_ \\       | |\\/| |/ _\\ ,_ \\| | | |" << endl;
    pre(1); cout << "       / ____ \\ (_|| | | | | | | | | |      | |  | | __/ | | | |_| |" << endl;
    pre(1); cout << "      /_/    \\_\\_,_|_| |_| |_|_|_| |_|      |_|  |_|\\__|_| |_|\\__,_|" << endl;
	br(3); pre(3); echo(">> 1. View User List"); Sleep(400);
	br(2); pre(3); echo(">> 2. View Pet List"); Sleep(400);
    br(2); pre(3); echo(">> 3. View Appointment"); Sleep(400);
	br(2); pre(3); echo(">> 4. Log Out");  Sleep(400);

	br(2);pre(3); cout << "Choice: ";
	cin >> choice;
	if (choice == 1)
    {
        adminViewUser();
    }
    else if (choice == 2)
    {
        ViewPetSortOpt();
    }
    else if (choice == 3)
    {
        AdminViewAppointment();
    }
    else if (choice == 4){
        main_menu();
    }
    else
    {
        cin.clear();            //clear the wrong input type error
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clear the input buffer
        br(1);pre(1);cout << "You have entered an invalid number! Please try again!" << endl; Sleep(1000);
        admin();
    }

}
void Petsystem::signup()
{
    string dummy;
    user *u = new user;

    getline(cin,dummy);
    system("CLS");
    br(1); pre(2); cout << " >>>> User Sign Up <<<< " << endl << endl;
    u->setUname();
    string filename = u->getUname()+".txt";
    f.open(filename,ios::in);
    if(f.is_open()) // to check user had sign up or not
    {
        pre(1); cout << " User had Sign Up! Press enter to Log In..." << endl;
        f.close();
        login();
    }
    else
    {
        f.open(filename,ios::out);
    }

    u->setEmail();
    u->setAddress();
    u->setPhone();
    u->setPassword();

    f << u->getEmail() << endl;
    f << u->getAddress()<<endl;
    f << u->getPhone()<<endl;
    f << u->getPassword()<<endl;

    
    f.close();
    user w = *u;
    InsertUser(w);
    saveUserToFile();
    delete u;
    
}

void Petsystem::menu() 
{
    int choice, pet_profile_choice;
    string dummy;

    do{
    system("cls");

    cout <<"                        _____\n";
    cout <<"                       /     \\   ____   ____    __ __\n";
    cout <<"                      /  \\ /  \\_/ __ \\ /     \\ |  |  |\n";
    cout <<"                     /    Y    \\  ___/|   |   \\|  |  |\n";
    cout <<"                     \\____|____/\\____>____|____|_____|\n\n";

	br(2); pre(3); echo(">> 1. Pet profile"); Sleep(400);
	br(2); pre(3); echo(">> 2. Book Appointment");  Sleep(400);
    br(2); pre(3); echo(">> 3. Show Appointment"); Sleep(400);
	br(2); pre(3); echo(">> 4. Log out");  Sleep(400);
   // br(2); pre(3); fflush(stdin); cout << "Choice: "; scanf("%d",&choice);


   checkerror(choice,1,4);

    }while (choice<1||choice>5);

    if (choice == 1)
    {

        getline(cin,dummy);

        system("CLS");
        br(1); pre(2); cout << " +--------------------------+" << endl;
        pre(2); cout << " |        Pet profile       |" << endl;
        pre(2); cout << " +--------------------------+" << endl;
        pre(2); cout << " |                          |" << endl;
        pre(2); cout << " |   1. Add pet profile     |" << endl;
        pre(2); cout << " |   2. Delete pet profile  |" << endl;
        pre(2); cout << " |   3. Edit pet profile    |" << endl;
        pre(2); cout << " |                          |" << endl;
        pre(2); cout << " +--------------------------+" << endl << endl;


        cout << " Please enter your choice: ";
        cin >> pet_profile_choice;

        while(pet_profile_choice < 0 || pet_profile_choice > 3)
        {
            cout << " Error input!" << endl;
            cout << " Please enter your choice: ";
            cin >> pet_profile_choice;
        }
        if(pet_profile_choice == 0)
        {
            getline(cin,dummy);
            menu();
        }
        if(pet_profile_choice == 1)
        {
            getline(cin,dummy);
            addPet();
        }
        else if(pet_profile_choice == 2)
        {
            getline(cin,dummy);
            deletePet();
        }
        else if(pet_profile_choice == 3)
        {
            getline(cin,dummy);
            profile();
        }
    }
    if (choice == 2)
    {
        getline(cin,dummy);
        book_app();
    }
    if (choice == 3)
    {
        getline(cin,dummy);
        display_app();
    }
    if (choice == 4)
    {
        //staycationHead = nullptr;
        groomingHead = nullptr;
        trainingHead = nullptr;
        system("cls");
        br(2); pre(2); cout << "Thank you for using our system! See you soon!" << endl; Sleep(1000);
        pre(2); cout << "              Have a nice day! ;)            " << endl; Sleep(1000);
        main_menu();


    }

}

void Petsystem::addPet()
{
    string dummy;
    char response;
    pet *p = new pet;
    
    int id = SearchNewID();
    p->setID(id);
    
    string ids = to_string(id);

    system("cls");

    br(1);pre(2); echo(" >>>> Add New Pet <<<< ");


    br(2);p->setName();
    p->setBreed();
    p->setAge();
    p->setWeight();
    p->setGender();
    p->setOwner(uname);

    string filename = ids + ".txt";
    f.open(filename,ios::out);
    f << p->getName() << endl;
    f << p->getBreed() << endl;
    f << p->getAge() << endl;
    f << p->getWeight() << endl;
    f << p->getGender() << endl;
    f << p->getOwner() << endl;
    f.close();

    filename = uname + ".txt";
    f.open(filename, ios::app);
    f << endl;
    f << p->getID();
    f.close();
    pet q = *p;
    InsertPet(q);
    delete p;

    savePetToFile();
    br(2); cout << "Do you want to continue to add pet? [Y/N]: ";
    cin >> response;
    while(response != 'y' && response != 'Y' && response != 'n' && response != 'N')
    {
        cin.ignore(100, '\n');
        cout << "Error input! " << endl;
        cout << "Do you want to continue to add pet? [Y/N]: ";
        cin >> response;
    }
    if(response == 'y' || response == 'Y')
    {
        getline(cin,dummy);
           addPet();
    }
    else if (response == 'n' || response == 'N')
    {
        menu();
    }
}

void Petsystem::deletePet()
{

    string filename, line, fname, line2, dummy;
    string id;
    char response;
    fstream x;
    system("cls");
    displaypet();
    cout << "\nEnter the id of your pet to delete (0 to exit): ";
    cin >> id;
    if(id == "0")
    {
        menu();
    }
    else
    {
        fname = id + ".txt";
        f.open(fname, ios::in);
        if(f.is_open())
        {
            cout << "\nAre you sure you want to delete this pet information? [Y/N] : ";
            cin >> response;

            while(response != 'y' && response != 'Y' && response != 'n' && response != 'N')
                {
                    cin.ignore(100, '\n');
                    cout << "Invalid input!!! " << endl;
                    cout << "Are you sure you want to delete this pet information? [y/n]";
                    cin >> response;
                }
            if(response == 'y' || response == 'Y')
            {
               br(1); cout << "Pet deleted successfully!" << endl;
               f.close();
               remove(fname.c_str());
               filename = uname + ".txt";
               x.open(filename,ios::in);
               temp.open("temp.txt",ios::out);
               int count = 0;
               while (getline(x,line))
                {
                    count++;
                    if(line!=id)
                    {
                        temp << line << endl;
                    }
                }
                x.close();
                temp.close();
                remove(filename.c_str());
                rename("temp.txt", filename.c_str());
                deletePetNode(atoi(id.c_str()));
                savePetToFile();
            }
            else if (response == 'n' || response == 'N')
            {
                f.close();
                getline(cin,dummy);
                deletePet();
            }
        }
        else
        {
            cout << "Pet not exist!"<<endl;
            cout << "Press Enter to continue...";
            getline(cin,dummy);
            deletePet();
        }
        f.close();
        cout << "\nDo you want to continue to delete pet?[Y/N]: ";
        cin >> response;
        while(response != 'y' && response != 'Y' && response != 'n' && response != 'N')
        {
            cin.ignore(100, '\n');
            cout << "Invalid input!!! " << endl;
            cout << "Do you want to continue to delete pet?[Y/N]: ";
            cin >> response;
        }
        if(response == 'y' || response == 'Y')
        {
           getline(cin,dummy);
           deletePet();
        }
        else if (response == 'n' || response == 'N')
        {
            menu();
        }
    }
}

void Petsystem::displaypet()
{
    system("CLS");
    string filename, fname, line, line2;
    fstream x;
    filename = uname + ".txt";
    f.open(filename, ios::in); //in = input data from file into this program
    int count = 0;
    while (getline(f,line))   //f user file
    {
        count++;
        if (count > 4)  //to display how many details in user
        {
            pet* p = new pet;
            fname = line + ".txt";
            p->setID(atoi(line.c_str()));
            x.open(fname,ios::in);
            int k;
            k=0;
            while (getline(x,line2))
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
                }

                if(x.is_open())
                {
                    pre(2);cout << "+-------------------------+" << endl;
                    pre(2);cout << "|       Pet Details       |" << endl;
                    pre(2);cout << "+-------------------------+" << endl;
                    pre(2);cout << "|ID     |" << setfill(' ') << left << setw(17) << p->getID() << "|" << endl;
                    pre(2);cout << "|Name   |" << setfill(' ') << left << setw(17) << p->getName() << "|" << endl;
                    pre(2);cout << "|Breed  |" << setfill(' ') << left << setw(17) << p->getBreed() << "|" << endl;
                    pre(2);cout << "|Age    |" << setfill(' ') << left << setw(17) << p->getAge() << "|" << endl;
                    pre(2);cout << "|Weight |" << setfill(' ') << left << setw(17) << p->getWeight() << "|" << endl;
                    pre(2);cout << "|Gender |" << setfill(' ') << left << setw(17) << p->getGender() << "|" << endl;
                    pre(2);cout << "+-------------------------+" << endl << endl;
                }
                x.close();
                delete p;
        }
    }
    f.close();
}

void Petsystem::profile()
{
    system("cls");
    displaypet();
    char response;
    int choice, chg_choice;
    string line, line2, id, fname, filename, dummy;
    cout << "\nEnter the id of your pet change profile (0 to exit): ";
    cin >> id;
    if(id == "0")
    {
        menu();
    }
    else
    {
        fname = id + ".txt";
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

                }
            f.close();
            system("cls");
            pre(2);cout << "+----------------------------+" << endl;
            pre(2);cout << "|         Pet Details        |" << endl;
            pre(2);cout << "+----------------------------+" << endl;
            pre(2);cout << "|1. ID     |" << setfill(' ') << left << setw(17) << p->getID() << "|" << endl;
            pre(2);cout << "|2. Name   |" << setfill(' ') << left << setw(17) << p->getName() << "|" << endl;
            pre(2);cout << "|3. Breed  |" << setfill(' ') << left << setw(17) << p->getBreed() << "|" << endl;
            pre(2);cout << "|4. Age    |" << setfill(' ') << left << setw(17) << p->getAge() << "|" << endl;
            pre(2);cout << "|5. Weight |" << setfill(' ') << left << setw(17) << p->getWeight() << "|" << endl;
            pre(2);cout << "|6. Gender |" << setfill(' ') << left << setw(17) << p->getGender() << "|" << endl;
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
                while (chg_choice < 2 || chg_choice > 5)
                {
                    if (chg_choice == 1){
                        cin.clear();
                        cin.ignore(100, '\n');
                        br(1); cout << "ID cannot be changed!"<<endl;
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
                    p->setGender();
                }
                system("CLS");
                pre(2);cout << "+----------------------------+" << endl;
                pre(2);cout << "|         Pet Details        |" << endl;
                pre(2);cout << "+----------------------------+" << endl;
                pre(2);cout << "|1. ID     |" << setfill(' ') << left << setw(17) << p->getID() << "|" << endl;
                pre(2);cout << "|2. Name   |" << setfill(' ') << left << setw(17) << p->getName() << "|" << endl;
                pre(2);cout << "|3. Breed  |" << setfill(' ') << left << setw(17) << p->getBreed() << "|" << endl;
                pre(2);cout << "|4. Age    |" << setfill(' ') << left << setw(17) << p->getAge() << "|" << endl;
                pre(2);cout << "|5. Weight |" << setfill(' ') << left << setw(17) << p->getWeight() << "|" << endl;
                pre(2);cout << "|6. Gender |" << setfill(' ') << left << setw(17) << p->getGender() << "|" << endl;
                pre(2);cout << "+----------------------------+" << endl << endl;

                PetNode* current = new PetNode;
                current->p = *p;
                cout << "Do you want to save changes?[y/n]: ";
                cin >> response;
                if (response == 'y' || response =='Y')
                {
                    PetNode* newP = SearchPetID(p->getID());
                    newP->p = current->p;
                    newP->p.setOwner(uname);
                    f.open(fname, ios::out);
                    f << p->getName() << endl;
                    f << p->getBreed() << endl;
                    f << p->getAge() << endl;
                    f << p->getWeight() << endl;
                    f << p->getGender() << endl;
                    f << uname << endl;
                    f.close();
                    savePetToFile();
                }
                else{
                    delete current;
                }

            }
        }
        else
        {
            cout << "\nPet does not exist!" << endl;
            cout << "Press Enter to continue...";
            getline(cin,dummy);
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


void Petsystem::readFromLinkedlist() //save linked list tofile
{  
        FILE* file = fopen("pets.txt", "rb");
        pet a;
        Pet b;
        while(fread(&b,sizeof(struct Pet),1,file)){
            
            a.setID(b.id);
            a.setOwner(b.owner);
            a.setpName(b.p_name);
            a.setpBreed(b.breed);
            a.setpAge(b.age);
            a.setpGender(b.gender);
            a.setpWeight(b.weight);
            InsertPet(a);
        } 
        fclose(file);

        FILE* file2 = fopen("users.txt", "rb");
    
        user c;
        User d;

        while(fread(&d,sizeof(struct User),1,file2)){
            c.setUname(d.uname);
            //c.setPassword(d.password);
            //c.setEmail(d.email);
            //c.setAddress(d.address);
            //c.setPhone(d.phone);
            InsertUser(c);  

            
        }
        fclose(file2);
    }

void Petsystem::savePetToFile()  //save linked list to file 2 Pet
{
    FILE* file = fopen("pets.txt", "wb"); // wb = write binary
    if (file == nullptr) {
        // handle error
        return;
    }

    PetNode* current = petHead;
    Pet b;
    while (current != nullptr) {

        b.id = current->p.getID();
        strncpy(b.owner, current->p.getOwner().c_str(), sizeof(b.owner) - 1);
        b.owner[sizeof(b.owner) - 1] = '\0';
        strncpy(b.p_name, current->p.getName().c_str(), sizeof(b.p_name) - 1);
        b.p_name[sizeof(b.p_name) - 1] = '\0';
        strncpy(b.breed, current->p.getBreed().c_str(), sizeof(b.breed) - 1);
        b.breed[sizeof(b.breed) - 1] = '\0';
        b.age = current->p.getAge();
        b.gender = current->p.getGender();
        b.weight = current->p.getWeight();
        fwrite(&b, sizeof(struct Pet), 1, file);
        current = current->next;
    }
    fclose(file);

}

void Petsystem::saveUserToFile() 
{
    FILE* file = fopen("users.txt", "wb");
    if (file == nullptr) {
        // handle error
        return;
    }
    UserNode* current = userHead;
    User c;
    while (current != nullptr) {
        strncpy(c.uname, current->a.getUname().c_str(), sizeof(c.uname) - 1);
        c.uname[sizeof(c.uname) - 1] = '\0';
        fwrite(&c, sizeof(struct User), 1, file);

        /*
        strncpy(b.password, current->a.getPassword().c_str(), sizeof(b.password) - 1);
        b.password[sizeof(b.password) - 1] = '\0';
        strncpy(b.email, current->a.getEmail().c_str(), sizeof(b.email) - 1);
        b.email[sizeof(b.email) - 1] = '\0';
        strncpy(b.address, current->a.getAddress().c_str(), sizeof(b.address) - 1);
        b.address[sizeof(b.address) - 1] = '\0';
        strncpy(b.phone, current->a.getPhone().c_str(), sizeof(b.phone) - 1);
        b.phone[sizeof(b.phone) - 1] = '\0';
        */
        current = current-> next;   
        
    }

    fclose(file);
}

void Petsystem:: saveServiceToFile(ServiceNode *curPtr)
{
    if(curPtr){
        saveServiceToFile(curPtr->left);
        Service s;
        s.pet1 = curPtr->pet1;
        s.pet2 = curPtr->pet2;
        s.pet3 = curPtr->pet3;
        s.pet4 = curPtr->pet4;
        s.pet5 = curPtr->pet5;
        s.count = curPtr->count;
        s.date = curPtr->date;
        
        fwrite(&s,sizeof(struct Service),1,c);
        saveServiceToFile(curPtr->right);
    }
}

void Petsystem::readServiceFromFile(ServiceNode *&head){
    Service s;
    
    while(fread(&s, sizeof(struct Service),1,c))
    {
        ServiceNode* newNode = new ServiceNode(); // Move this line inside the loop
        newNode->pet1 = s.pet1;
        newNode->pet2 = s.pet2;
        newNode->pet3 = s.pet3;
        newNode->pet4 = s.pet4;
        newNode->pet5 = s.pet5;
        newNode->count = s.count;
        newNode->date = s.date;
        newNode->left = nullptr;
        newNode->right = nullptr;
        
        if(head == nullptr){
            head = newNode;
        }
        else{
            ServiceNode* temp = head;
            while(temp!=nullptr){
                if(newNode->date < temp->date){
                    if(temp->left == nullptr){
                        temp->left = newNode;
                        break;
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else{
                    if(temp->right == nullptr){
                        temp->right = newNode;
                        break;
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }
        }
    }
}

void Petsystem::display_app()
{
    string dummy,line,sname,gname,tname, line2;
    string name,breed,id;
    int age;
    double weight;
    char gender;
    int k=0;
    bool check = false;
    displaypet();
    cout << "\nEnter the id of your pet to display appointment (0 to exit): ";
    getline(cin,id);
    if(id == "0")
    {
        menu();
    }
    else
    {
        sname = "staycation_" + id + ".txt";
        FILE* file0 = fopen(sname.c_str() , "rb");
        if (file0 != nullptr)
        {
            check = true;
        }
        fclose(file0);
        gname = "grooming_" + id + ".txt";
        FILE* file2 = fopen(gname.c_str() , "rb");
        if (file2 != nullptr)
        {
            check = true;
        }
        fclose(file2);
        tname = "training_" + id + ".txt";
        FILE* file3 = fopen(tname.c_str() , "rb");
        if (file3 != nullptr)
        {
            check = true;
        }
        fclose(file3);
        // 1 boolean check got appointment
        
        if(check == true)
        {
            cout << "+-----------------------------------------------------------------+"<< endl;
            cout << "| No.   | Service      | Time                         | Fee       |" << endl;
            cout << "+-----------------------------------------------------------------+"<< endl;
        }
        else
        {
            cout << "You have no appointment!" << endl;
            cout << "Press enter to continue..."<<endl;
            getline(cin,dummy);
            menu();
        }
        
        int x = 1;

        f.open(sname, ios::in);
        if(f.is_open())
        {
            string day, month, year;

            while(getline(f, day) && getline(f, month) && getline(f, year))
            {
                string date = day + "/" + month + "/" + year;
                
                cout << "| 0" << setw(5) << x << "| " << "Staycation   " << "| " << setfill(' ') << left << setw(24) << date << "     | " << setfill(' ') << left << setw(9) << "300" << " |" << endl;
                cout << "+-----------------------------------------------------------------+"<< endl;
                x++;
            }
            f.close();

        }

        f.open(gname, ios::in);
        if(f.is_open())
        {
            string day, month, year;

            while(getline(f, day) && getline(f, month) && getline(f, year))
            {
                string date = day + "/" + month + "/" + year;
                
                cout << "| 0" << setw(5) << x << "| " << "Grooming     " << "| " << setfill(' ') << left << setw(24) << date << "     | " << setfill(' ') << left << setw(9) << "100" << " |" << endl;
                cout << "+-----------------------------------------------------------------+"<< endl;
                x++;
            }
            f.close();

        }

        f.open(tname, ios::in);
        if(f.is_open())
        {
            string day, month, year;

            while(getline(f, day) && getline(f, month) && getline(f, year))
            {
                string date = day + "/" + month + "/" + year;
                
                cout << "| 0" << setw(5) << x << "| " << "Training     " << "| " << setfill(' ') << left << setw(24) << date << "     | " << setfill(' ') << left << setw(9) << "200" << " |" << endl;
                cout << "+----------------------------------------------------------------+"<< endl;
                x++;
            }
            f.close();

        }
    }
        cout << "Press enter to continue...";
        getline(cin,dummy);
        menu();
}

void Petsystem::grooming(int id)
{
    string dummy;
    int date , section;
    br(1); pre(2); cout << "+------------------------+" << endl;
    pre(2); cout << "|        Service         |" << endl;
    pre(2); cout << "+------------------------+" << endl;
    pre(2); cout << "|        Grooming        |" << endl;
    pre(2); cout << "|      Fees : RM" << gprice << "    |" << endl; // fees use variable gprice //thank you sabrina
    pre(2); cout << "+------------------------+" << endl;
    cout << "Enter the date you wish to book appointment: " ;
    cin >> date;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error input!" << endl;
        cout << "Enter the date you wish to book appointment: " ;
        cin >> date;
    }

    
    // Get the current date
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Set the day of the month
    ltm->tm_mday = date;

    // Convert to time_t
    time_t userTime = mktime(ltm);

    // Get the current time again
    time_t currentTime = time(0);

    if (userTime < currentTime+1) {  // check whether the date user entered is valid
        cout << "\nSorry, you cannot book an appointment for a past date. Please use different date to book appointment." << endl;
        cout << "Press enter to continue..."<<endl;
        getline(cin,dummy);
        getline(cin,dummy);
        menu();
    }

    // Convert to tm again for formatting
    tm *date1 = localtime(&userTime);

    char buffer[80];
    strftime(buffer, 80, "%A", date1);

    if (string(buffer) == "Sunday") { //check whether the day drop on sunday
        cout << "\nSorry, we are closed on Sundays. Please enter a different date." << endl;
        cout << "Press enter to continue..."<<endl;
        getline(cin,dummy);
        menu();
    }

 
    ServiceNode* check = SearchNodeTreeINT(groomingHead,date);
    if(check != nullptr)
    {
        if(check->pet1 != 0 && check->pet2 != 0 && check->pet3 != 0)  // check whether that day is full or not
        {
            cout << "\nFully Booked! Please choose another day to book for appointment." << endl;
            getline(cin,dummy);
            getline(cin,dummy);
            menu();
        }
        else
        {   
            br(1); pre(2); cout << "+--------------------------+" << endl;
            pre(2); cout << "|     Available section    |" << endl;
            pre(2); cout << "+--------------------------+" << endl;
            if(check->pet1 == 0)
            {
                pre(2); cout << "| 1.  8.00a.m. - 10.00a.m. |"<<endl;
            }
            if(check->pet2 == 0)
            {
                pre(2); cout << "| 2. 10.00a.m. - 12.00p.m. |"<<endl;
            }
            if(check->pet3 == 0)
            {
                pre(2); cout << "| 3.  2.00p.m. - 4.00p.m.  |"<<endl;
            }
            pre(2); cout << "+--------------------------+" << endl;

            cout << "Which section do you want to book : ";
        }
        
    }
    else
    {
        InsertDate(groomingHead,date,0);
        br(1); pre(2); cout << "+--------------------------+" << endl;
        pre(2); cout << "|     Available section    |" << endl;
        pre(2); cout << "+--------------------------+" << endl;
        pre(2); cout << "| 1.  8.00a.m. - 10.00a.m. |" << endl;
        pre(2); cout << "| 2. 10.00a.m. - 12.00p.m. |" << endl;
        pre(2); cout << "| 3.  2.00p.m. - 4.00p.m.  |" << endl;
        pre(2); cout << "+--------------------------+" << endl;

        cout << "Which section do you want to book : ";
    }

    if(check != nullptr)
    {
        do 
        {
            cin >> section;
            if ((section == 1 && check->pet1 != 0) || (section == 2 && check->pet2 != 0) || (section == 3 && check->pet3 != 0)) 
            {
                cout << "This section is already booked. Please choose another section: ";
                cin >> section;
            }

        } while ((section == 1 && check->pet1 != 0) || 
            (section == 2 && check->pet2 != 0) || 
            (section == 3 && check->pet3 != 0));
    }
    else{
        cin >> section;

        while(cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Error input!" << endl;
            cout << "Which section do you want to book : ";
            cin >> section;
        }
    }
    
    // print available section for that day

    ServiceNode* temp = SearchNodeTreeINT(groomingHead,date);

        if(section == 1)
        {
            temp -> pet1 = id;
        }
        else if (section == 2)
        {
            temp -> pet2 = id;
        }
        else if (section == 3)
        {
            temp -> pet3 = id;
        }
        else
        {
            cout << "Invalid Input"<<endl;
        }

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    ostringstream oss;
    oss << setw(2) << setfill ('0') << month;
    oss << setw(2) << setfill ('0') << year;
    string date2 = oss.str();

    insertServiceIntoFile(id,"grooming",date);

    string fname = "grooming_" + date2 + ".txt";
    c = fopen(fname.c_str(), "wb");
    saveServiceToFile(groomingHead);
    fclose(c);

    cout << "Your appointment has been booked!" << endl;
    cout << "Press enter to continue..."<<endl;
    getline(cin,dummy);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    menu();


}

void Petsystem::training(int id)
{
    string dummy;
    int date , section;
    br(1); pre(2); cout << "+------------------------+" << endl;
    pre(2); cout << "|         Service        |" << endl;
    pre(2); cout << "+------------------------+" << endl;
    pre(2); cout << "|         Training       |" << endl;
    pre(2); cout << "|     Fees : RM " << tprice << "    |" << endl;  // fees use variable tprice //thank you sabrina
    pre(2); cout << "+------------------------+" << endl;
    cout << "Enter the date you wish to book for: " ;
    cin >> date;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error input!" << endl;
        cout << "Enter the date you wish to book for: " ;
        cin >> date;
    }

    // Get the current date
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Set the day of the month
    ltm->tm_mday = date;

    // Convert to time_t
    time_t userTime = mktime(ltm);

    // Get the current time again
    time_t currentTime = time(0);

    if (userTime < currentTime+1) {  // check whether the date user entered is valid
        cout << "\nSorry, you cannot book an appointment for a past date. Please use different date to book appointment." << endl;
        cout << "Press enter to continue..."<<endl;
        getline(cin,dummy);
        getline(cin,dummy);
        menu();
    }

    // Convert to tm again for formatting
    tm *date1 = localtime(&userTime);

    char buffer[80];
    strftime(buffer, 80, "%A", date1);

    if (string(buffer) == "Sunday") { //check whether the day drop on sunday
        cout << "\nSorry, we are closed on Sundays. Please enter a different date." << endl;
        cout << "Press enter to continue..."<<endl;
        getline(cin,dummy);
        menu();
    }

    //training each day can have 4 section and training only open class at saturday

    if (string(buffer) != "Saturday") { //check whether the day drop on saturday
        
        cout << "\nTraining only available on Saturday. Please choose another day to book appointment." << endl;
        cout << "Press enter to continue..."<<endl;
        getline(cin,dummy);
        getline(cin,dummy);
        menu();
    }

    ServiceNode* check = SearchNodeTreeINT(trainingHead,date);

    //for training it doesnt have section so just check whether that day is full or not
    if(check != nullptr){
        switch(check->count)
        {
        
            case 1:
                check -> pet2 = id;
                break;
            case 2:
                check -> pet3 = id;
                break;
            case 3:
                check -> pet4 = id;
                break;
            case 4:
                cout << "Fully Booked! Please choose another day to book for appointment." << endl;
                getline(cin,dummy);
                menu();
        }
    }
    else
    {
        InsertDate(trainingHead,date,id);
        ServiceNode* temp = SearchNodeTreeINT(trainingHead,date);

    }

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    ostringstream oss;
    oss << setw(2) << setfill ('0') << month;
    oss << setw(2) << setfill ('0') << year;
    string date2 = oss.str();

    insertServiceIntoFile(id,"training",date);

    string fname = "training_" + date2 + ".txt";
    c = fopen(fname.c_str(), "wb");
    saveServiceToFile(trainingHead);
    fclose(c);
    cout << "Your appointment has been booked!" << endl;
    cout << "Press enter to continue..."<<endl;
    getline(cin,dummy);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    menu();
}

void Petsystem::staycation(int id)
{
    string dummy;
    int date , section;
    br(1); pre(2); cout << "+------------------------+" << endl;
    pre(2); cout << "|         Service        |" << endl;
    pre(2); cout << "+------------------------+" << endl;
    pre(2); cout << "|        Staycation      |" << endl;
    pre(2); cout << "|      Fees : RM" << sprice << "    |" << endl;  // fees use variable sprice //thank you sabrina
    pre(2); cout << "+------------------------+" << endl;
    cout << "Enter the date you wish to book for: " ;
    cin >> date;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error input!" << endl;
        cout << "Enter the date you wish to book for: " ;
        cin >> date;
    }
    
    // Get the current date
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Set the day of the month
    ltm->tm_mday = date;

    // Convert to time_t
    time_t userTime = mktime(ltm);

    // Get the current time again
    time_t currentTime = time(0);

    if (userTime < currentTime+1) {  // check whether the date user entered is valid
        cout << "\nSorry, you cannot book an appointment for a past date. Please use different date to book appointment." << endl;
        cout << "Press enter to continue..."<<endl;
        getline(cin,dummy);
        getline(cin,dummy);
        menu();
    }

    // Convert to tm again for formatting
    tm *date1 = localtime(&userTime);

    char buffer[80];
    strftime(buffer, 80, "%A", date1);

    if (string(buffer) == "Sunday") { //check whether the day drop on sunday
        cout << "\nSorry, we are closed on Sundays. Please enter a different date." << endl;
        cout << "Press enter to continue..."<<endl;
        getline(cin,dummy);
        menu();
    }


    ServiceNode* check = SearchNodeTreeINT(staycationHead,date);

    if(check != nullptr){
        switch(check->count)
        {
            case 1:
                check -> pet2 = id;
                check -> count++;
                break;
            case 2:
                check -> pet3 = id;
                check -> count++;
                break;
            case 3:
                check -> pet4 = id;
                check -> count++;
                break;
            case 4:
                check -> pet5 = id;
                check -> count++;
                break;
            case 5:
                cout << "Fully Booked! Please choose another day to book for appointment." << endl;
                getline(cin,dummy);
                getline(cin,dummy);
                menu();
        }
    }
    else
    {
        InsertDate(staycationHead,date,id);
    }

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    ostringstream oss;
    oss << setw(2) << setfill ('0') << month;
    oss << setw(2) << setfill ('0') << year;
    string date2 = oss.str();

    insertServiceIntoFile(id,"staycation",date);
    string fname = "staycation_" + date2 + ".txt";
    c = fopen(fname.c_str(), "wb");
    saveServiceToFile(staycationHead);
    fclose(c);
    cout << "Your appointment has been booked!" << endl;
    cout << "Press enter to continue..."<<endl;
    getline(cin,dummy);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    menu();
}

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
            pre(2);cout << "+-----------------------------+" << endl;
            pre(2);cout << "|          Pet Details        |" << endl;
            pre(2);cout << "+-----------------------------+" << endl;
            pre(2);cout << "|1. ID         |" << setfill(' ') << left << setw(14) << id << "|" << endl; 
            pre(2);cout << "|2. Name       |" << setfill(' ') << left << setw(14) << p->getName() << "|" << endl; 
            pre(2);cout << "|3. Breed      |" << setfill(' ') << left << setw(14) << p->getBreed() << "|" << endl;
            pre(2);cout << "|4. Age        |" << setfill(' ') << left << setw(14) << p->getAge() << "|" << endl;
            pre(2);cout << "|5. Weight     |" << setfill(' ') << left << setw(14) << p->getWeight() << "|" << endl;
            pre(2);cout << "|6. Gender     |" << setfill(' ') << left << setw(14) << p->getGender() << "|" << endl;
            pre(2);cout << "|7. Owner Name |" << setfill(' ') << left << setw(14) << p->getOwner() << "|" << endl;
            pre(2);cout << "+-----------------------------+" << endl << endl;

            cout << "[Press 0 to Main Menu]          [Press 1 to Change Information]" << endl;
            cout << "Please enter your choice: ";
            cin >> choice;

            while (cin.fail() || (choice != 0 && choice != 1) )
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
                while (chg_choice < 2 || chg_choice > 6 || cin.fail())
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
                pre(2);cout << "+-----------------------------+" << endl;
                pre(2);cout << "|          Pet Details        |" << endl;
                pre(2);cout << "+-----------------------------+" << endl;
                pre(2);cout << "|1. ID         |" << setfill(' ') << left << setw(14) << p->getID() << "|" << endl; 
                pre(2);cout << "|2. Name       |" << setfill(' ') << left << setw(14) << p->getName() << "|" << endl; 
                pre(2);cout << "|3. Breed      |" << setfill(' ') << left << setw(14) << p->getBreed() << "|" << endl;
                pre(2);cout << "|4. Age        |" << setfill(' ') << left << setw(14) << p->getAge() << "|" << endl;
                pre(2);cout << "|5. Weight     |" << setfill(' ') << left << setw(14) << p->getWeight() << "|" << endl;
                pre(2);cout << "|6. Gender     |" << setfill(' ') << left << setw(14) << p->getGender() << "|" << endl;
                pre(2);cout << "|7. Owner Name |" << setfill(' ') << left << setw(14) << p->getOwner() << "|" << endl;
                pre(2);cout << "+-----------------------------+" << endl << endl;

                PetNode* current = new PetNode;
                current->p = *p;
                cout << "Do you want to save changes?[y/n]: ";
                cin >> response;
                if (response == 'y' || response =='Y')
                {
                    PetNode* newP = SearchPetID(p->getID());
                    newP->p = current->p;
                    f.open(fname, ios::out);
                    f << p->getName() << endl;
                    f << p->getBreed() << endl;
                    f << p->getAge() << endl;
                    f << p->getWeight() << endl;
                    f << p->getGender() << endl;
                    f << p->getOwner() << endl;
                    f.close();
                    savePetToFile();
                }
                else{
                    delete current;
                }

            }
        }
        else
        {
            cout << "\nPet does not exist!" << endl;
            cout << "Press Enter to continue...";
            getline(cin,dummy);
            getline(cin,dummy);
            ViewPetSortOpt();
        }
        f.close();
        cout << "Do you want to continue to change information?[Y/N]: ";
        cin >> response;
        while(response != 'y' && response != 'Y' && response != 'n' && response != 'N')
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nError input! " << endl;
            cout << "Do you want to continue to change information?[Y/N]: ";
            cin >> response;
        }
        if(response == 'y' || response == 'Y')
        {
           getline(cin,dummy);
           ViewPetSortOpt();
        }
        else if (response == 'n' || response == 'N')
        {
            admin();
        }
}

void Petsystem::AdminViewPet() {
    // First print all pet names and IDs
    system("CLS");
    cout << "All pets:" << endl;
    PetNode* petTemp = petHead;
    pre(2);cout << "+------------------------------------------+" << endl;
    pre(2);cout << "| " << setfill(' ') << setw(5) << "ID" << setw(5) << " | " << setw(10) << "Name" << setw(10)<< " | " << setw(10) << "Owner" <<" |" << endl;
    pre(2);cout << "+------------------------------------------+" << endl;
    
    while (petTemp != nullptr) 
    {
        pre(2);cout << "| " << setfill(' ') << setw(5) << petTemp->p.getID()<< setw(5) << " | " << setw(10) << petTemp->p.getName() << setw(10)<<" | " << setw(10) << petTemp->p.getOwner() << " |" << endl;
        pre(2);cout << "+------------------------------------------+" << endl;
        petTemp = petTemp->next;
    }
    
    // Then ask the user what they want to do
        cout << "[Press 0 to Main Menu]          [Press 1 to Change Information]" << endl;
        cout << "Please enter your choice: ";
        int choice;
        cin >> choice;

        while (cin.fail() || (choice != 0 && choice != 1))
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

void Petsystem::AdminViewAppointment(){
    int choice;
    char response;
    int year,month,day;
    system("CLS");
    pre(2); cout << "+------------------------+" << endl;
    pre(2); cout << "|        Services        |" << endl;
    pre(2); cout << "+------------------------+" << endl;
    pre(2); cout << "|     1. Staycation      |" << endl;
    pre(2); cout << "|     2. Grooming        |" << endl;
    pre(2); cout << "|     3. Training        |" << endl;
    pre(2); cout << "+------------------------+" << endl << endl;

    cout << "Which services appointment you would like to view: ";
    cin >> choice;
    while(choice < 1 || choice > 3 || cin.fail()){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error input!" << endl;
        cout << "Which services appointment you would like to view: ";
        cin >> choice;
    }
    if(choice == 1){
        system("CLS");
        pre(2); cout << "+------------------------+" << endl;
        pre(2); cout << "|       Staycation       |" << endl;
        pre(2); cout << "+------------------------+" << endl;

        cout << endl;
        cout << "Year: ";
        cin >> year;
        //check year correct or not
        while(cin.fail() || to_string(year).length() != 4){
            cin.clear();                        //clear the wrong input type error
            cin.ignore(100, '\n');              //clear the input buffer
            cout << "Error year format!" <<endl;
            cout << "Year: ";
            cin >> year;
        }
        cout << "Month: ";
        cin >> month;
        //check month correct or not
        while(cin.fail() || month < 1 || month > 12){
            cin.clear();                        //clear the wrong input type error
            cin.ignore(100, '\n');              //clear the input buffer
            cout << "Error month format!" <<endl;
            cout << "Month: ";
            cin >> month;
        }
        
        ostringstream oss;
        oss << setw(2) << setfill ('0') << month;
        oss << setw(2) << setfill ('0') << year;
        string date2 = oss.str();

        string filename = "staycation_" + date2 + ".txt";
        FILE* file0 = fopen(filename.c_str() , "rb");
        if(file0 == nullptr){
            cout << "No appointment today..." << endl;
            cout << "Do you wish to continue to view appointment[Y/N]: ";
            cin >> response;
        }
        else{
            fclose(file0);
            c = fopen(filename.c_str(), "rb");
            staycationHead = nullptr;
            readServiceFromFile(staycationHead);
            fclose(c);
            cout << "+---+-----+-----+-----+-----+-----+" << endl;
            cout << "|Day|Pet 1|Pet 2|Pet 3|Pet 4|Pet 5|" << endl;
            cout << "+---+-----+-----+-----+-----+-----+" << endl;
            AdmininOrderService(staycationHead, 1);
            cout << "Do you wish to continue to view appointment[Y/N]: ";
            cin >> response;
        }
        
    }
    else if(choice == 2){
        system("CLS");
        pre(2); cout << "+------------------------+" << endl;
        pre(2); cout << "|        Grooming        |" << endl;
        pre(2); cout << "+------------------------+" << endl;

        cout << endl;
        cout << "Year: ";
        cin >> year;
        //check year correct or not
        while(cin.fail() || to_string(year).length() != 4){
            cin.clear();                        //clear the wrong input type error
            cin.ignore(100, '\n');              //clear the input buffer
            cout << "Error year format!" <<endl;
            cout << "Year: ";
            cin >> year;
        }
        cout << "Month: ";
        cin >> month;
        //check month correct or not
        while(cin.fail() || month < 1 || month > 12){
            cin.clear();                        //clear the wrong input type error
            cin.ignore(100, '\n');              //clear the input buffer
            cout << "Error month format!" <<endl;
            cout << "Month: ";
            cin >> month;
        }
        
        ostringstream oss;
        oss << setw(2) << setfill ('0') << month;
        oss << setw(2) << setfill ('0') << year;
        string date2 = oss.str();

        string filename = "grooming_" + date2 + ".txt";
        FILE* file0 = fopen(filename.c_str() , "rb");
        if(file0 == nullptr){
            cout << "No appointment today..." << endl;
            cout << "Do you wish to continue to view appointment[Y/N]: ";
            cin >> response;
        }
        else{
            fclose(file0);
            c = fopen(filename.c_str(), "rb");
            groomingHead = nullptr;
            readServiceFromFile(groomingHead);
            fclose(c);
            cout << "+---+---------+---------+---------+" << endl;
            cout << "|Day|Section 1|Section 2|Section 3|" << endl;
            cout << "+---+---------+---------+---------+" << endl;
            AdmininOrderService(groomingHead, 2);
            cout << "Do you wish to continue to view appointment[Y/N]: ";
            cin >> response;
        }
    }
    else if(choice == 3){
        int year, month, day;
        system("CLS");
        pre(2); cout << "+------------------------+" << endl;
        pre(2); cout << "|        Training        |" << endl;
        pre(2); cout << "+------------------------+" << endl;

        cout << endl;
        cout << "Year: ";
        cin >> year;
        //check year correct or not
        while(cin.fail() || to_string(year).length() != 4){
            cin.clear();                        //clear the wrong input type error
            cin.ignore(100, '\n');              //clear the input buffer
            cout << "Error year format!" <<endl;
            cout << "Year: ";
            cin >> year;
        }
        cout << "Month: ";
        cin >> month;
        //check month correct or not
        while(cin.fail() || month < 1 || month > 12){
            cin.clear();                        //clear the wrong input type error
            cin.ignore(100, '\n');              //clear the input buffer
            cout << "Error month format!" <<endl;
            cout << "Month: ";
            cin >> month;
        }
        
        ostringstream oss;
        oss << setw(2) << setfill ('0') << month;
        oss << setw(2) << setfill ('0') << year;
        string date2 = oss.str();

        string filename = "training_" + date2 + ".txt";
        FILE* file0 = fopen(filename.c_str() , "rb");
        cout << filename << endl;
        if(file0 == nullptr){
            cout << "No appointment today..." << endl;
            cout << "Do you wish to continue to view appointment[Y/N]: ";
            cin >> response;
        }
        else{
            fclose(file0);
            c = fopen(filename.c_str(), "rb");
            trainingHead = nullptr;
            readServiceFromFile(trainingHead);
            fclose(c);
            cout << "+---+-----+-----+-----+-----+" << endl;
            cout << "|Day|Pet 1|Pet 2|Pet 3|Pet 4|" << endl;
            cout << "+---+-----+-----+-----+-----+" << endl;
            AdmininOrderService(trainingHead, 3);
            cout << "Do you wish to continue to view appointment[Y/N]: ";
            cin >> response;
        }
    }
    while(response != 'y' && response != 'Y' && response != 'n' && response != 'N')
    {
        cin.ignore(100, '\n');
        cout << "\nError input! " << endl;
        cout << "Do you wish to continue to view appointment[Y/N]: ";
        cin >> response;
    }
    if(response == 'y' || response == 'Y'){
        AdminViewAppointment();
    }
    else if (response == 'n' || response == 'N'){
        admin();
    }
}

void Petsystem::AdmininOrderService(ServiceNode *curPtr, int type){
    if(type == 1){ // 1 is staycation
        if(curPtr != nullptr){
            AdmininOrderService(curPtr->left, 1);
            cout << "|" << setfill(' ') << setw(3) << left << curPtr->date << "|" << setw(5) << left << curPtr->pet1 
            << "|" <<setw(5) << left << curPtr->pet2 << "|" << setw(5) << left << curPtr->pet3
            << "|" << setw(5) << left << curPtr->pet4 << "|" << setw(5) << left << curPtr->pet5 << "|" <<endl;
            cout << "+---+-----+-----+-----+-----+-----+" << endl;
            AdmininOrderService(curPtr->right, 1);
        }
    }
    else if(type == 2){ // 2 is grooming
        if(curPtr != nullptr){
            AdmininOrderService(curPtr->left, 2);
            cout << "|" << setfill(' ') << setw(3) << left << curPtr->date << "|" << setw(9) << left << curPtr->pet1 
            << "|" <<setw(9) << left << curPtr->pet2 << "|" << setw(9) << left << curPtr->pet3<< "|" << endl;
            cout << "+---+---------+---------+---------+" << endl;
            AdmininOrderService(curPtr->right, 2);
        }
    }
    else if(type == 3){ // 3 is training
        if(curPtr != nullptr){
            AdmininOrderService(curPtr->left, 3);
            cout << "|" << setfill(' ') << setw(3) << left << curPtr->date << "|" << setw(5) << left << curPtr->pet1 
            << "|" <<setw(5) << left << curPtr->pet2 << "|" << setw(5) << left << curPtr->pet3
            << "|" << setw(5) << left << curPtr->pet4 << "|"<< endl;
            cout << "+---+-----+-----+-----+-----+" << endl;
            AdmininOrderService(curPtr->right, 3);
        }
    }
}

int Petsystem::searchNumDays(int year, int month){
    tm t={0};
    t.tm_year = year - 1900; //year start from 1900
    t.tm_mon = month - 1; // january is zero
    t.tm_mday = 1; //set to first day

    mktime(&t);

    int numDays = 32 - t.tm_mday;

    return numDays;
}

string Petsystem::searchDay(int year, int month, int day){
    //get current time
    time_t t = time(nullptr);
    tm *now = localtime(&t);
    //define year, month, day
    now->tm_year = year - 1900;
    now->tm_mon = month - 1;
    now->tm_mday = day;

    mktime(now);

    if(now->tm_wday == 0){
        return "Sunday";
    }
    else if(now->tm_wday == 1){
        return "Monday";
    }
    else if(now->tm_wday == 2){
        return "Tuesday";
    }
    else if(now->tm_wday == 3){
        return "Wednesday";
    }
    else if(now->tm_wday == 4){
        return "Thursday";
    }
    else if(now->tm_wday == 5){
        return "Friday";
    }
    else if(now->tm_wday == 6){
        return "Saturday";
    }
}


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
            pre(2);cout << "+------------------------------------+" << endl;
            pre(2);cout << "|            User Details            |" << endl;
            pre(2);cout << "+------------------------------------+" << endl;
            pre(2);cout << "|1. Name           |" << setfill(' ') << left << setw(17) << a->getUname() << "|" << endl; 
            pre(2);cout << "|2. Email          |" << setfill(' ') << left << setw(17) << a->getEmail() << "|" << endl;
            pre(2);cout << "|3. Address        |" << setfill(' ') << left << setw(17) << a->getAddress() << "|" << endl;
            pre(2);cout << "|4. Phone          |" << setfill(' ') << left << setw(17) << a->getPhone() << "|" << endl;
            pre(2);cout << "|5. Password       |" << setfill(' ') << left << setw(17) << a->getPassword() << "|" << endl;
            pre(2);cout << "+------------------------------------+" << endl << endl;

            cout << "[Press 0 to Main Menu]          [Press 1 to Change Information]" << endl;
            cout << "Please enter your choice: ";
            cin >> choice;

            while (cin.fail()||choice != 0 && choice != 1 )
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
                br(1); cout << "Which information you wish to change except username? (enter number) : ";
                cin >> chg_choice;
                while (chg_choice < 2 || chg_choice > 5 || cin.fail())
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
                pre(2);cout << "+------------------------------------+" << endl;
                pre(2);cout << "|            User Details            |" << endl;
                pre(2);cout << "+------------------------------------+" << endl;
                pre(2);cout << "|1. Name           |" << setfill(' ') << left << setw(17) << a->getUname() << "|" << endl; 
                pre(2);cout << "|2. Email          |" << setfill(' ') << left << setw(17) << a->getEmail() << "|" << endl;
                pre(2);cout << "|3. Address        |" << setfill(' ') << left << setw(17) << a->getAddress() << "|" << endl;
                pre(2);cout << "|4. Phone          |" << setfill(' ') << left << setw(17) << a->getPhone() << "|" << endl;
                pre(2);cout << "|5. Password       |" << setfill(' ') << left << setw(17) << a->getPassword() << "|" << endl;
                pre(2);cout << "+------------------------------------+" << endl << endl;

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
            getline(cin,dummy);
            adminViewUser();
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
           adminViewUser();
        }
        else if (response == 'n' || response == 'N')
        {
            admin();
        }
}

void Petsystem::book_app()
{
    string fname, dummy;
    int id;
    displaypet();
    cout << "Enter the pet's id you wish to book for? [0 to exit]: ";
    cin >> id;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error input!" << endl;
        cout << "Enter the pet's id you wish to book for? [0 to exit]: ";
        cin >> id;
    }
    if(id == 0)
    {
        menu();
    }
    else
    {   
            string ids = to_string(id);
            fname = ids + ".txt";
            f.open(fname, ios::in);
            if(f.is_open())
            {
                f.close();
                int choice;
                system("cls");
                pre(2);cout << "+-----------------------------+" << endl;
                pre(2);cout << "|       Book for Service      |" << endl;
                pre(2);cout << "+-----------------------------+" << endl;
                pre(2);cout << "|       1. Staycation         |" << endl;
                pre(2);cout << "|       2. Grooming           |" << endl;
                pre(2);cout << "|       3. Training           |" << endl;
                pre(2);cout << "+-----------------------------+" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                while(choice < 1 || choice > 3 || cin.fail())
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Error input!" << endl;
                    cout << "Please enter again!" << endl;
                    pre(2);cout << "+-----------------------------+" << endl;
                    pre(2);cout << "|       Book for Service      |" << endl;
                    pre(2);cout << "+-----------------------------+" << endl;
                    pre(2);cout << "|       1. Staycation         |" << endl;
                    pre(2);cout << "|       2. Grooming           |" << endl;
                    pre(2);cout << "|       3. Training           |" << endl;
                    pre(2);cout << "+-----------------------------+" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;
                }
                if(choice == 1)
                {

                    staycation(id);
                }
                else if(choice == 2)
                {
                    grooming(id);
                }
                else
                {
                    training(id);
                }
            }
            else
            {
                cout << "Pet does not exist!" << endl;
                cout << "Press enter to continue...";
                cin.clear();
                cin.ignore(100, '\n');
                getline(cin,dummy);
                menu();
            }
        }
}

void Petsystem::insertServiceIntoFile(int id, string service, int day)
{
    string filename;
    filename =  service + "_" + to_string(id) + ".txt";
    f.open(filename, ios::app);
     if (!(f.is_open()))
    {
        f.open(filename, ios::out);

    }

    //get system month and year
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;

    f << day << endl;
    f << month << endl;
    f << year << endl;


    f.close();

    
}
/*void AdminViewUser(UserNode* head) {
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

}*/

void Petsystem::checkerror(int &choice, int min, int max)
{
    string dummy;
    br(2);pre(3); cout << "Choice: ";
	cin >> choice;
    while (choice < min || choice > max || cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        br(1); pre(3); cout << "Invalid input! Please enter again: "  ;
        cin >> choice;
    }
}

//Below used for BST
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

void Petsystem::AdmininOrder(SortUserNodeTree *node) {
    if (node != nullptr) {
        AdmininOrder(node->left); // Visit left subtree
        pre(2);cout << "|" << setfill(' ') << setw(10)<< node->a.getUname() << setw(10) << "|"<< endl;
        pre(2);cout << "+-------------------+" << endl;
        AdmininOrder(node->right); // Visit right subtree
    }
}

void Petsystem::adminViewUser(){
    if(userHead!=nullptr){
        UserNode* current = userHead;  // start from the head of the list
        sortUserHead = nullptr;
        while (current != NULL) {
            AdminSortUser(current->a);
            current = current->next;  // move to the next node
        }
        system("cls");
        pre(2);cout << "+-------------------+" << endl;
        pre(2);cout << "|" << setfill(' ') << setw(10)<< "     User List" << setw(6) << "|"<< endl;
        pre(2);cout << "+-------------------+" << endl;
        AdmininOrder(sortUserHead);
        cout << "[Press 0 to Main Menu]          [Press 1 to Change Information]" << endl;
        cout << "Please enter your choice: ";
        int choice;
        cin >> choice;

        while (cin.fail() || choice != 0 && choice != 1)
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
            cout<<"Please Enter the username you want to edit: ";
            string username;
            cin>>username;
            AdminEditUserProfile(username);
        }

    }
    else{
        cout<<"User not found"<<endl;
        cout << "Please press Enter to back to admin page.";
        cin.ignore(); // Ignore the newline character in the input buffer
        cin.get(); // Wait for the user to press Enter
        admin();  // Back to admin page
    }
}

void Petsystem::AdminSortUser(user a){
    SortUserNodeTree* current = sortUserHead;
    SortUserNodeTree* temp = new SortUserNodeTree;
    temp->a = a;
    temp->left = NULL;
    temp->right = NULL;
    if (sortUserHead == nullptr){
        sortUserHead = temp;
    }
    else{
        //cout << sortUserHead->a.getUname() << endl;
        string upperUsername = toUpper(a.getUname()); // Convert username to uppercase
        string newbinaryUsername = toBinary(upperUsername); // Convert username to binary
        while(current!=nullptr){
            string upperUsername = toUpper(current->a.getUname()); // Convert username to uppercase
            string curbinaryUsername = toBinary(upperUsername); // Convert username to binary
            if (newbinaryUsername <= curbinaryUsername){ // Compare binary usernames
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
//Below is BST for petname
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

void Petsystem::AdmininOrder(SortPetNodeTree* node) {
    if (node != nullptr) {
        PetNode* petTemp = petHead;
        AdmininOrder(node->left); // Visit left subtree
        cout << "| " << setfill(' ') << setw(5) << node->p.getID()<< setw(5) << " | " << setw(15) << node->p.getName()  << setw(15)<<" | " << setw(15) << node->p.getOwner() << setw(15)<< " |" << endl;
        cout << "+----------------------------------------------------------------------+" << endl;
        AdmininOrder(node->right); // Visit right subtree
    }
}

void Petsystem::AdminViewPetByName(){
    sortPetHead=nullptr;
    system("CLS");
    cout << "All pets:" <<endl;
    cout << "+----------------------------------------------------------------------+" << endl;
    cout << "| " << setfill(' ') << setw(5) << "ID" << setw(5) << " | " << setw(15) << "Name" << setw(15)<< " | " << setw(15) << "Owner" <<  setw(15) <<" |" << endl;
    cout << "+----------------------------------------------------------------------+" << endl;
    if(petHead!=nullptr){
        PetNode* current = petHead;  // start from the head of the list
        while (current != NULL) {
            AdminSortPet(current->p);
            current = current->next;  // move to the next node
        }
        AdmininOrder(sortPetHead);
        cout << "[Press 0 to Main Menu]          [Press 1 to Change Information]" << endl;
        cout << "Please enter your choice: ";
        int choice;
        cin >> choice;

        while (cin.fail()||choice != 0 && choice != 1 )
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

void Petsystem::AdminSortPet(pet p){
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
//view pet list option
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

        while(cin.fail()||choice1 < 1 || choice1 > 2)
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
            AdminViewPetByName();
        }
}




