//-----------CLASA INTERFATA (ABSTRACTA) --------------------
class Farmacie{
    string nume;
public:
    //-------CONSRUCTOR
    Farmacie();
    explicit Farmacie(const string&);
    //-------DESTRUCTOR VIRTUAL PUR
    virtual ~Farmacie() = 0;
    //-------FUNCTIE DE AFISARE- POLIMORFISM PENTRU SUPRAINCARCAREA <<
    virtual const void print() const;
    virtual void read();
    //-------SUARINCARCARE DE OPERATORI
    friend ostream& operator<<(ostream&,const Farmacie&);
    //-------GETERI(get_type ESTE GETER PENTRU TIPUL OBIECTULUI
    virtual const int get_type() const;
    const string get_nume() const;
};
//-----------CONSTRUCTORI
Farmacie::Farmacie(const string& x) : nume(x){};
Farmacie::Farmacie(){
    nume = "Nume";
}
//-----------DESTRUCTORI
Farmacie::~Farmacie(){};
//-------FUNCTIE DE AFISARE- POLIMORFISM PENTRU SUPRAINCARCAREA <<
const void Farmacie::print() const{
    cout << "Farmacia " << nume << ":\n";
}
void Farmacie::read(){
    cout << "Introduceti numele: ";
    cin >> nume;
}
//-------SUARINCARCARE DE OPERATORI
ostream& operator<<(ostream& out, const Farmacie& x){
    x.print();
    return out;
}
istream& operator>>(istream& in, Farmacie& x){
    x.read();
    return in;
}
//-------GETERI(get_type ESTE GETER PENTRU TIPUL OBIECTULUI
const int Farmacie::get_type() const{
    return -1;
}
const string Farmacie::get_nume()const {return nume;};

