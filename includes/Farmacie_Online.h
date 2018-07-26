//------------CLASA FARMACIE ONLINE---------------------------
class F_Online : public Farmacie{
    string site;
    int vizitatori, discount;
public:
    //------------CONSTRUCTORI
    F_Online();
    F_Online(const string& a, const string& b,const int& x,const int& y);
    //------------Geteri/ Seteri
    const string get_site() const;
    const int get_vizitatori() const;
    const int get_discount() const;
    //------------FUNCTII
    const void print() const override;
    void read() override;
    const int get_type() const override;
};
//----------------CONSTRUCTORI
F_Online::F_Online(){
    site = "SITE";
    vizitatori = 0;
    discount = 0;
}
F_Online::F_Online(const string& a, const string& b,const int& x,const int& y) : site(b), vizitatori(x), discount(y), Farmacie(a) {};
//----------------GETER/SETERI
const string F_Online::get_site() const{ return site;};
const int F_Online::get_vizitatori() const{ return vizitatori;};
const int F_Online::get_discount() const{ return discount;};
//----------------FUNCTII
const void F_Online::print() const{
    Farmacie::print();
    cout << "Are site-ul: " << site << " cu " << vizitatori << " vizitatori si un discount de " << discount << "%\n";
}
void F_Online::read(){
    cout << "Se citeste farmacie online...\n";
    Farmacie::read();
    cout << "Introduceti site-ul: ";
    cin >> site;
    cout << "Introduceti nr. de vizitatori: ";
    cin >> vizitatori;
    cout << "Introduceti discountul: ";
    cin >> discount;
}
const int F_Online::get_type() const{return 1;}
//----------------SUPRAINCARCARE DE OPERATORI
//Fac la acesta pentru a indeplini dorinta, desi nu trebuie supraincarcat,
//deoarece aceasta clasa nu contine alocare dinamica
F_Normala& F_Normala::operator=(const F_Normala& x){
    nr_angajati = x.nr_angajati;
    profit = x.profit;
}
