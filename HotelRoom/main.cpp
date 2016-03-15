#include <iostream>
#include <typeinfo>
#include <hotelroom.h>

using namespace std;

int main(){

    HotelRoom hotel = HotelRoom();

    hotel.AddReservation("xc231a", 12.3);
    hotel.AddReservation("12fcxz", 5.3);
    hotel.AddReservation("asd21", 2.3);
    hotel.AddReservation("zca23", 4.4);
    hotel.AddReservation("zxczx", 12.3);
    hotel.AddReservation("vfgf", 12.3);
    hotel.AddReservation("iytrq", 9.32);
    hotel.AddReservation("bxzli", 4.112);
    hotel.AddReservation("zzxw21", 27.15);
    hotel.AddReservation("iytrq", 9.32);
    hotel.AddReservation("bxzli", 4.112);

    hotel.print();
    cout << endl;
    cout<< "Total reservations: " << hotel.TotalReservations()<<endl;
    cout << "Max Price: "<< MaxPriceReservation(hotel)<<endl;


    return 0;

}
