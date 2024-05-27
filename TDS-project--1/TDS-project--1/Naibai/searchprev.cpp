#include <iostream>
#include "../pet.hpp"

using namespace std;

UserNode* Petsystem::SearchLastPreviousNode(){
    UserNode* temp;
    if(userHead == nullptr){
        return 0;
    }
    else{
        for(temp = userHead;temp->next!=nullptr;temp=temp->next){
            if(temp->next==nullptr){
                return temp;
            }
        }
    }
}

UserNode* Petsystem::SearchPreviousNode(string target){
    UserNode* temp;
    if(userHead == nullptr){
        return 0;
    }
    else{
        for(temp = userHead;temp->next!=nullptr;temp=temp->next){
            if(temp->a.getUname() == target){
                return temp;
            }
        }
    }
    return 0; //return null if target not found
}

ServiceNode* Petsystem::SearchNodeTreeINT(ServiceNode* head, int target){
    ServiceNode* temp = head;
    if(head == nullptr){
        return 0;
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

void Petsystem::InsertUser(user newUser){
    UserNode* newNode = new UserNode;
    newNode->a = newUser;
    newNode->next = nullptr;
    if(userHead == nullptr){
        userHead = newNode;
    }
    else{
        for(UserNode* temp = userHead;temp->next!=nullptr;temp=temp->next){
            if(temp->next==nullptr){
                temp->next = newNode;
            }
        }
    }
}

void Petsystem::InsertPet(pet newPet){
    PetNode* newNode = new PetNode;
    newNode->p = newPet;
    newNode->next = nullptr;
    if(petHead == nullptr){
        petHead = newNode;
    }
    else{
        for(PetNode* temp = petHead;temp->next!=nullptr;temp=temp->next){
            if(temp->next==nullptr){
                temp->next = newNode;
            }
        }
    }
}

void Petsystem::InsertDate(ServiceNode* head, int newDate){
    ServiceNode* newNode = new ServiceNode;
    newNode -> date = newDate;
    newNode -> left = nullptr;
    newNode -> right = nullptr;
    newNode -> pet1 = 0;
    newNode -> pet2 = 0;
    newNode -> pet3 = 0;
    if (head == NULL){
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