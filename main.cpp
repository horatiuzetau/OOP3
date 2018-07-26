#include "includes/usings.h"


//------------FUNCTII IN AFARA CLASELOR
const void Alegeri(){
    cout << "0-Inchidere program\n1-Adaugare farmacie normala\n2-Adaugare farmacie online\nAlegerea dumneavoastra: ";
}




int main() {
//Intrebuintare pentru clasa gestionare specializata
    Gestionare_Farmacii<void> g;
    F_Online a("g", "g", 42, 0),
            b("g", "g", 12, 0);
    g += a;
    g += b;
    cout << g;

    return 0;
}