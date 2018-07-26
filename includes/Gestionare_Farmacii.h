//------------CLASA GESTIONARE FARMACII-----------------------
//Am implementat template pentru aceasta clasa doar pentru cerinta
//Nu era deloc necesar un template
template<typename T>
class Gestionare_Farmacii{
    static int s_nr_farmacii;
    Farmacie ** a;
public:
    //--------------------CONSTRUCTORI
    explicit Gestionare_Farmacii(int);
    Gestionare_Farmacii(const Gestionare_Farmacii&);
    //--------------------DESTRUCTOR
    ~Gestionare_Farmacii();
    //--------------------SUPRAINCARCAREA OEPRATORILOR
    Gestionare_Farmacii& operator+=(const Farmacie&);
    Gestionare_Farmacii& operator=(const Gestionare_Farmacii&);
    template<typename F>
    friend ostream& operator<<(ostream&, const Gestionare_Farmacii<F>&);
};
template<typename T>
int Gestionare_Farmacii<T>::s_nr_farmacii = 0;
//------------------------CONSTRUCTORI
template<typename T>
Gestionare_Farmacii<T>::Gestionare_Farmacii(int x) : a(new Farmacie*[x]){};
template<typename T>
Gestionare_Farmacii<T>::Gestionare_Farmacii(const Gestionare_Farmacii<T>& x) {
    s_nr_farmacii  = x.s_nr_farmacii;
    a = new Farmacie*[s_nr_farmacii];

    for(int i = 0; i < s_nr_farmacii; i++){
        switch(x.a[i]->get_type()){
            case 0:
                a[i] = new F_Normala(dynamic_cast<F_Normala*>(x.a[i])->get_nume(), dynamic_cast<F_Normala*>(x.a[i])->get_angajati(),
                                     dynamic_cast<F_Normala*>(x.a[i])->get_profit());
                break;
            case 1:
                a[i] = new F_Online(dynamic_cast<F_Online*>(x.a[i])->get_nume(), dynamic_cast<F_Online*>(x.a[i])->get_site(),
                                    dynamic_cast<F_Online*>(x.a[i])->get_vizitatori(), dynamic_cast<F_Online*>(x.a[i])->get_discount());
                break;
            default:
                break;
        }
    }
}
//------------------------DESTRUCTOR
template<typename T>
Gestionare_Farmacii<T>::~Gestionare_Farmacii() {
    for(int i = 0; i < s_nr_farmacii; i++)
        delete a[i];

    delete a;
}
//------------------------SUPRAINCARCAREA OPERATORILOR
template<typename T>
Gestionare_Farmacii<T>& Gestionare_Farmacii<T>::operator+=(const Farmacie & x) {
    a[s_nr_farmacii] = const_cast<Farmacie* >(&x);

    s_nr_farmacii++;
    return *this;
}
template<typename T>
Gestionare_Farmacii<T>& Gestionare_Farmacii<T>::operator=(const Gestionare_Farmacii<T>& x){
    s_nr_farmacii  = x.s_nr_farmacii;
    a = new Farmacie*[s_nr_farmacii];

    for(int i = 0; i < s_nr_farmacii; i++){
        switch(x.a[i]->get_type()){
            case 0:
                a[i] = new F_Normala(dynamic_cast<F_Normala*>(x.a[i])->get_nume(), dynamic_cast<F_Normala*>(x.a[i])->get_angajati(),
                                     dynamic_cast<F_Normala*>(x.a[i])->get_profit());
                break;
            case 1:
                a[i] = new F_Online(dynamic_cast<F_Online*>(x.a[i])->get_nume(), dynamic_cast<F_Online*>(x.a[i])->get_site(),
                                    dynamic_cast<F_Online*>(x.a[i])->get_vizitatori(), dynamic_cast<F_Online*>(x.a[i])->get_discount());
                break;
            default:
                break;
        }
    }
}
template<typename T>
ostream& operator<<(ostream& out, const Gestionare_Farmacii<T>& x){

    for(int i = 0; i < x.s_nr_farmacii; i++){
        cout << *(x.a[i]);
    }

    return out;


}


