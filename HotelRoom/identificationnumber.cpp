#include "identificationnumber.h"
#include <cstring>

IdentificationNumber::IdentificationNumber(){
    id = NULL;
}

IdentificationNumber::IdentificationNumber(char* id)
{
    int sz = strlen(id);
    this->id = new char[sz+1];
    strcpy(this->id,id);
}


IdentificationNumber& IdentificationNumber::operator=(const char* newId){
    if (id != NULL)
        delete[] id;
    if (id != newId){
        int n = strlen(newId);
        id = new char[n+1];
        strcpy(id, newId);
    }
    return *this;
}

IdentificationNumber& IdentificationNumber::operator=(const IdentificationNumber& r){
    if (id != NULL)
        delete[] id;
    if (this != &r){
        int n = strlen(r.id);
        id = new char[n+1];
        strcpy(id, r.id);
    }
    return *this;
}

IdentificationNumber::IdentificationNumber(const IdentificationNumber& obj){
    int sz = strlen(obj.id);
    id = new char[sz+1];
    id = strcpy(id,obj.id);

}

IdentificationNumber::~IdentificationNumber(){
    delete[] id;
}

std::ostream& operator<< (std::ostream& os, const IdentificationNumber& obj) {
    os << obj.id;
    return os;
}
