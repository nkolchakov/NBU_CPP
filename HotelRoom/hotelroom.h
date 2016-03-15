#ifndef HOTELROOM_H
#define HOTELROOM_H
#include<identificationnumber.h>


class HotelRoom
{
public:
    HotelRoom();
    HotelRoom(char* id, double price);
    HotelRoom(const HotelRoom&);
    void AddReservation(char* id, double price);
    HotelRoom& operator=(const HotelRoom&);
    ~HotelRoom();
    void print();
    double* GetPrices() const;
    int TotalReservations()const;

private:
    IdentificationNumber* ids;
    double* prices;
    int index;
    int capacity;

};

double MaxPriceReservation(const HotelRoom&);
#endif // HOTELROOM_H
