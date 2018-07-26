//Aceasta clasa este aproape inutila, deci nu are rost supraincarcaera
//operatorilor =, constructorul de copiere, destructor s.a...
template<>
class Gestionare_Farmacii<void>{
    int nr_vizitatori;
public:
    //--------------------CONSTRUCTORI
    Gestionare_Farmacii();
    Gestionare_Farmacii(const Gestionare_Farmacii&);
    //--------------------SUPRAINCARCAREA OEPRATORILOR
    Gestionare_Farmacii& operator+=(const Farmacie&);
    friend ostream& operator<<(ostream&, const Gestionare_Farmacii<void>&);
};
//------------------------CONSTRUCTORI
Gestionare_Farmacii<void>::Gestionare_Farmacii() : nr_vizitatori(0){};
//------------------------SUPRAINCARCAREA OPERATORILOR
Gestionare_Farmacii<void>& Gestionare_Farmacii<void>::operator+=(const Farmacie & x) {
    //woooow si p e doar pointer deci nici nu trebuie sters. URA!
    auto * p = const_cast<Farmacie*>(&x);
    if(p){
        nr_vizitatori += dynamic_cast<F_Online*>(p)->get_vizitatori();
    }
    return *this;
}
ostream& operator<<(ostream& out, const Gestionare_Farmacii<void>& x){

    cout << "Numarul de vizitator este " << x.nr_vizitatori << ".\n";

    return out;


}
