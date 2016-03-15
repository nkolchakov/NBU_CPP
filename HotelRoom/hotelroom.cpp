#include "hotelroom.h"
#include <cstring>
#include <iostream>

HotelRoom::HotelRoom(){
    // purvonachalen razmer 5, pri vsqko napulvane se udvoqva.
    capacity = 5;
    ids = new IdentificationNumber[capacity];
    prices = new double[capacity];
    index = 0; // tekushtiqt broi na rezervaciite
}

HotelRoom::HotelRoom(char* id, double price){
    // povtorenie na gorniq kod, vuzmojno li e izvikvane na gorniq konstruktor
    // i produljavane na inicializaciqta v tozi ?
    capacity = 5;
    ids = new IdentificationNumber[capacity];
    prices = new double[capacity];
    index = 0;


    ids[index] = id;
    prices[index] = price;
    index++;
}

HotelRoom::HotelRoom(const HotelRoom& r){
    int newSize = r.capacity;
    ids = new IdentificationNumber[newSize];
    prices = new double[newSize];
    for (int i = 0; i < r.index; i++) {
        ids[i] = r.ids[i];
        prices[i] = r.prices[i];
    }
    index = r.index;

}
void HotelRoom::AddReservation(char* id, double price){
    if (index < capacity){
        ids[index] = id;
        prices[index] = price;
        index++;
    }else{
        capacity *= 2;
        IdentificationNumber* tmpIds = new IdentificationNumber[capacity];
        double* tmpPrices = new double[capacity];
        for (int i = 0; i < index; i++) {
           tmpIds[i] = ids[i];
           tmpPrices[i] = prices[i];
        }
        // preorazmerqvane + add tekushtata rezervaiq
        tmpIds[index] = id;
        tmpPrices[index] = price;
        index++;

        ids = new IdentificationNumber[capacity];
        //ids = tmpIds;
        for (int i = 0; i < index; i++) {
            ids[i] = tmpIds[i];
        }
        prices = tmpPrices;

        delete[] tmpIds, tmpPrices;
    }

}

double MaxPriceReservation(const HotelRoom& r){
    int index = r.TotalReservations();
    double* allPrices = new double[index];
    allPrices = r.GetPrices();
    double maxPrice = allPrices[0];

    for (int i = 1; i < index; i++) {
        if (allPrices[i] > maxPrice)
            maxPrice = allPrices[i];
    }
    return maxPrice;
}

double* HotelRoom::GetPrices() const{
    return prices;
}

int HotelRoom::TotalReservations()const{

    return index;
}

HotelRoom& HotelRoom::operator=(const HotelRoom& r){
    if (this != &r){
        delete[] ids;
        delete[] prices;

        int newSize = r.index;
        ids = new IdentificationNumber[newSize];
        prices = new double[newSize];
        for (int i = 0; i < newSize; i++) {
            ids[i] = r.ids[i];
            prices[i] = r.prices[i];
        }
        index = r.index;
    }
    return *this;
}
void HotelRoom::print(){
    for (int i = 0; i < index; i++) {
        std::cout << "----------------- \n";
        std::cout << "Id: " << ids[i] << "\n" << "Price: " << prices[i] << std::endl;
    }
}
HotelRoom::~HotelRoom(){
    delete[] ids;
    delete[] prices;
}

