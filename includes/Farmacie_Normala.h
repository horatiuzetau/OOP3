//------------CLASA FARMACIE----------------------------------
class F_Normala : public Farmacie{
    int nr_angajati;
    double profit;
public:
    //------------CONSTRUCTORI
    F_Normala();
    F_Normala(const string&, const int&, const double&);
    //------------Geteri/ Seteri
    const int get_angajati() const;
    const double get_profit() const;
    //------------FUNCTII
    const void print() const override;
    void read() override;
    const int get_type() const;
    //------------SUPRAINCARCARE OPERATORI
    F_Normala& operator=(const F_Normala&);
};
//------------CONSTRUCTORI
F_Normala::F_Normala(){
    nr_angajati = 0;
    profit = 0;
}
F_Normala::F_Normala(const string& a, const int& b,const double& c) : Farmacie(a), nr_angajati(b), profit(c){};
//------------GETERI/SETERI
const  int F_Normala::get_angajati() const{
    return nr_angajati;
}
const double F_Normala::get_profit() const{
    return profit;
}
//------------FUNCTII
const void F_Normala::print() const{
    Farmacie::print();
    cout << "Are " << nr_angajati << " angajati si un profit de " << profit << " RON.\n";
}
void F_Normala::read(){
    cout << "Se citeste farmacie normala...\n";
    Farmacie::read();
    cout << "Introduceti nr. de angajati: ";
    cin >> nr_angajati;
    cout << "Introduceti profitul(poate fi double): ";
    cin >> profit;
}
const int F_Normala::get_type() const{return 0;}
