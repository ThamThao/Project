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
using namespace std;

void echo(char print[])
{
    printf("%s",print);
}
void br(int line)
{
    for(int i=0; i<line;i++)
    {
        printf("\n");
    }
}
void pre(int tab)
{
    for(int i=0; i<tab;i++)
    {
        printf("\t");
    }

}


class user
{
private:
    string uname, password, email, address, phone;
public:
    user();
    void setUname();
    string getUname();
    void setEmail();
    string getEmail();
    void setAddress();
    string getAddress();
    void setPhone();
    string getPhone();
    void setPassword();
    string getPassword();
    void setUname(string User_name);
    void setEmail(string e_mail);
    void setAddress(string a);
    void setPhone(string phoneNo);
    void setPassword(string password);
};

class pet
{
private:
    string p_name, breed , owner ;   //p_name=pet name //got id
    int age , id;
    double weight;
    char gender;
public:
    void setID(int a);   
    int getID();
    void setName();
    string getName();
    void setBreed();
    string getBreed();
    void setAge(int num);
    void setAge();
    int getAge();
    void setWeight();
    double getWeight();
    void setGender();
    char getGender();
    void setpName(string pet_name);
    void setpBreed(string p_breed);
    void setpAge(int age);
    void setpWeight(double weight);
    void setpGender(char sex);
    void setOwner(string owner);
    string getOwner();
    void getsprice();
    void getgprice();
    void gettprice();
};

struct User
{
    char uname[50];
    char password[50];
    char email[50];
    char address[50];
    char phone[50];


};

struct UserNode  //admin viewed
{
    user a;
    UserNode* next; 
};

struct Pet
{
    int id;
    char owner[50];
    char p_name[50];
    char breed[50];   //p_name=pet name got id
    int age;
    char gender;
    double weight;
    
};

struct PetNode
{
    pet p; 
    PetNode* next;
};


struct SortUserNodeTree
{
    user a;
    SortUserNodeTree* left;
    SortUserNodeTree* right;
};

struct SortPetNodeTree
{
    pet p;
    SortPetNodeTree* left;
    SortPetNodeTree* right;
};

struct Service
{
    int pet1;
    int pet2;
    int pet3;
    int pet4;
    int pet5;
    int count;
    int date;
};

struct ServiceNode
{
    int pet1 = 0;
    int pet2 = 0;
    int pet3 = 0;
    int pet4 = 0;
    int pet5 = 0;
    int count = 0;
    int date;

    ServiceNode* left;
    ServiceNode* right;
};

class Petsystem
{
        private:    
            UserNode* userHead = nullptr;
            PetNode* petHead = nullptr;
            SortUserNodeTree* sortUserHead = nullptr;
            SortPetNodeTree* sortPetHead = nullptr;
            ServiceNode* trainingHead = nullptr;
            ServiceNode* groomingHead = nullptr;
            ServiceNode* staycationHead = nullptr;
            fstream f;
            FILE *c;
            double sprice = 300.00 , gprice = 100.00 , tprice = 200.00;

        public:
            
            Petsystem(); // open file those things and link to login

            int SearchNewID(); //search last pet of pet link list
            ServiceNode* SearchNodeTreeINT(ServiceNode *head, int target);
            void InsertUser(user &newUser); // insert into userhead
            void InsertPet(pet &newPet); // insert into pethead`
            void InsertDate(ServiceNode *&head, int date, int id); // insert new node of binary tree
            PetNode* SearchPetID(int id);// return petnode
            int searchNumDays(int year, int month);   //search one month got how many days
            string searchDay(int year, int month, int day); //search which day of the coming day, i.e:Sunday
            void deleteUserNode(string key); // delete user node
            void deletePetNode(int id); 
            void savePetToFile(); // save linked list to file
            void saveUserToFile(); // save linked list to file
            void saveServiceToFile(ServiceNode *head);
            void insertServiceIntoFile(int id, string service, int day); //insert service into file
            void readServiceFromFile(ServiceNode *&head);
            void readFromLinkedlist();
            void welcome();
            void main_menu();
            void login(); //done
            void signup(); //done 
            void menu();  // need to delete payment option // after go back then go in appointment no pet profile
            void addPet(); //done
            void deletePet(); //done  //update pet's linked list?
            void profile(); //done
            void book_app(); //
            void display_app();//done
            void displaypet(); //done
            void staycation(int id); // one day have 5 slot
            void grooming(int id); // doesnt stop after booked , need sabrina to make it neat / limit the inout based on available section / need to add open file  grooming_100.txt
            void training(int id); // use linked list cuz got one day only?
            void ViewPetSortOpt();//show view option when choose view pet list /tham
            void checkerror(int &choice, int min, int max); //check error for int
            

            //Admin
            void admin(); 
            void AdminEditPetProfile(string id);//edit and view pet profile / tham
            void AdminEditUserProfile(string username);//edit and view user profile, NOT DONE YET NID CHECK / tham
            void AdminViewAppointment(); //view all appointment 
            void AdmininOrderService(ServiceNode *curPtr, int type); //show all serviceNode
            void AdminViewPet(); // view pet
            //Below used for BST
            //Username 
            void adminViewUser();//tham
            string toUpper(const string& str);//tham
            string toBinary(const string& str);//tham
            void AdminSortUser(user a);//tham
            void AdmininOrder(SortUserNodeTree *node);//tham
            //Petname
            void AdmininOrder(SortPetNodeTree* node);//tham
            void AdminSortPet(pet p);//tham
            void AdminViewPetByName();//tham
            string toUpperPet(const string& str);//tham
            string toBinaryPet(const string& str); //tham

};