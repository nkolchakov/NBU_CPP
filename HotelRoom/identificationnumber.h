#ifndef IDENTIFICATIONNUMBER_H
#define IDENTIFICATIONNUMBER_H
#include <iostream>


class IdentificationNumber
{
    friend std::ostream& operator<<(std::ostream&, const IdentificationNumber&);
private:
    char* id;
public:
    IdentificationNumber();
    IdentificationNumber(char*);
    IdentificationNumber(const IdentificationNumber&);
    ~IdentificationNumber();
    IdentificationNumber& operator=(const char*);
    IdentificationNumber& operator=(const IdentificationNumber&);
};
#endif // IDENTIFICATIONNUMBER_H
