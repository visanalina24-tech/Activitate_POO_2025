#include<iostream> //librarie care contine diferite functii
#include<fstream> //partea de intrare
#include<cstring>

using namespace std; //folosim acest spatiu standard ca la cout si cin sa nu mai punem operatorul de rezolutie std::
class Vaccin //obiectul1
{
private:
    const int idVaccin;
    int nrDoze;
    string instructiuniAplicare;
    char* numeVaccin;
    float greutateVaccin;
    static int nrDozeMaxime;
    bool confirmare;
public:
    Vaccin() :idVaccin(++nrDozeMaxime)//constructor default
    {
        this->nrDoze = 2;
        this->instructiuniAplicare = "1. Deschidere recipient medicament, 2. Extragere cu seringa, 3. Aplicarea spirtului pe membrul pacientului, 4. Introducere ac de la vaccin in membrul pacientului";
        this->greutateVaccin = 0.01;
        this->numeVaccin = nullptr;
        this->confirmare = true;
        //nrDozeMaxime++; //am initializat jos numarul static daca pun  nrDozeMaxime++ imi da eroare
    }

    Vaccin(int nrDoze, string instructiuniAplicare, const char* numeVaccin, float greutateVaccin, bool confirmare) : idVaccin(++nrDozeMaxime) //constructor cu parametrii, initializare
    {
        this->nrDoze = nrDoze;
        this->instructiuniAplicare = instructiuniAplicare;
        this->greutateVaccin = greutateVaccin;
        if (numeVaccin != 0)
        {
            this->numeVaccin = new char[strlen(numeVaccin) + 1];
            strcpy_s(this->numeVaccin, strlen(numeVaccin) + 1, numeVaccin);
        }
        else
        {
            this->numeVaccin = nullptr;
        }
        this->confirmare = confirmare;
    }

    Vaccin(const Vaccin& v) :idVaccin(++nrDozeMaxime)//constructor de copiere
    {
        this->nrDoze = v.nrDoze;
        this->instructiuniAplicare = v.instructiuniAplicare;
        this->greutateVaccin = v.greutateVaccin;
        if (v.numeVaccin != 0)
        {
            this->numeVaccin = new char[strlen(v.numeVaccin) + 1];
            strcpy_s(this->numeVaccin, strlen(v.numeVaccin) + 1, v.numeVaccin);
        }
        else
        {
            this->numeVaccin = nullptr;
        }
        this->confirmare = v.confirmare;
    }
    ~Vaccin()
    {
        if (numeVaccin != nullptr)
        {
            delete[] this->numeVaccin;
        }
    }
    Vaccin& operator=(const Vaccin& p)
    {
        if (numeVaccin != nullptr)
        {
            delete[] this->numeVaccin;
        }
        this->nrDoze = p.nrDoze;
        this->instructiuniAplicare = p.instructiuniAplicare;
        this->greutateVaccin = p.greutateVaccin;
        if (p.numeVaccin != 0)
        {
            this->numeVaccin = new char[strlen(p.numeVaccin) + 1];
            strcpy_s(this->numeVaccin, strlen(p.numeVaccin) + 1, p.numeVaccin);
        }
        else
        {
            this->numeVaccin = nullptr;
        }
        return *this;
    }

        int getNrDoze()
        {
            return this->nrDoze;
        }
        string getInstuctiuniDeAplicare()
        {
             return this->instructiuniAplicare;
        }
        char* getNumeVaccin()
        {
            return this->numeVaccin;
        }
        float getGreutateVaccin()
        {
            return this->greutateVaccin;
        }
        bool getConfirmare()
        {
            return this->confirmare;
        }
        friend ostream& operator<<(ostream& out, Vaccin& v)
        {
            cout << v.nrDoze << " " << v.instructiuniAplicare << " " << v.numeVaccin << " " << v.greutateVaccin << " " << v.confirmare << " ";
            if (v.numeVaccin != nullptr) {
                out << v.numeVaccin;
            }
            return out;
        }
        bool operator!()
        {
            if (confirmare == false && nrDoze > 10) 
            {
                return true;
            }
            else 
            {
                return false;
            }
        }

        void operator~() {
            if (confirmare == 0)
            {
                confirmare = 1;
            }
            else 
            {
                confirmare = 0;
            }
        }
};
int Vaccin::nrDozeMaxime = 0; //neaparat aici altfel nu imi ruleaza programul

class VizitaMedicala //obiectul2
{
public:
    const int idPacient;
    int nrVaccinuri;
    char* numePacient;
    string numeMedic;
    //int* nrConsultatii;
    float greutateAnimal;
    static int nrViziteIntr_unAn;

    VizitaMedicala() :idPacient(++nrViziteIntr_unAn)//constructor default
    {
        this->nrVaccinuri = 2;
        this->numeMedic = "Gabriela Stanescu";
        this->greutateAnimal = 0.5;
        this->numePacient = nullptr;

    }
    VizitaMedicala(int nrVaccinuri, const char* numePacient, string numeMedic, float greutateAnimal) :idPacient(++nrViziteIntr_unAn)//constructor cu parametrii, initializare
    {
        this->nrVaccinuri = nrVaccinuri;
        this->numeMedic = numeMedic;
        this->greutateAnimal = greutateAnimal;
        if (numePacient != 0)
        {
            this->numePacient = new char[strlen(numePacient) + 1];
            strcpy_s(this->numePacient, strlen(numePacient) + 1, numePacient);
        }
        else
        {
            this->numePacient = nullptr;
        }
    }
    VizitaMedicala(const VizitaMedicala& vm) :idPacient(++nrViziteIntr_unAn)// constrctor de copiere
    {
        this->nrVaccinuri = vm.nrVaccinuri;
        this->numeMedic = vm.numeMedic;
        this->greutateAnimal = vm.greutateAnimal;
        if (vm.numePacient != 0)
        {
            this->numePacient = new char[strlen(vm.numePacient) + 1];
            strcpy_s(this->numePacient, strlen(vm.numePacient) + 1, vm.numePacient);
        }
        else
        {
            this->numePacient = nullptr;
        }
    }
    ~VizitaMedicala()
    {
        if (numePacient != nullptr)
            delete[] this->numePacient;
    };
    VizitaMedicala& operator=(const VizitaMedicala& p) 
    {
        if (numePacient != nullptr)
        {
            delete[] this->numePacient;
        }
        this->nrVaccinuri = p.nrVaccinuri;
        this->numeMedic = p.numeMedic;
        this->greutateAnimal = p.greutateAnimal;
        if (p.numePacient != 0)
        {
            this->numePacient = new char[strlen(p.numePacient) + 1];
            strcpy_s(this->numePacient, strlen(p.numePacient) + 1, p.numePacient);
        }
        else
        {
            this->numePacient = nullptr;
        }
        return *this;

    }
};
int VizitaMedicala::nrViziteIntr_unAn = 0;

class EchipamentMedical//obiectul3
{
public:
    const int idInstrument;
    int nrInstrumenteInventar;
    char* numeInstrument;
    string dataExpirare;
    float temperatura;
    static int maxInstrumenteInventar;

    EchipamentMedical() :idInstrument(++maxInstrumenteInventar)// constructor default
    {
        this->nrInstrumenteInventar = 3;
        this->dataExpirare = "23.02.2025";
        this->temperatura = 20.3;
        this->numeInstrument = nullptr;
    }
    EchipamentMedical(int nrInstrumenteInventar, const char* numeInstrument, string dataExpirare, float temperatura) :idInstrument(++maxInstrumenteInventar)//constructori cu paramterii, initializare
    {
        this->nrInstrumenteInventar = nrInstrumenteInventar;
        this->dataExpirare = dataExpirare;
        this->temperatura = temperatura;
        if (numeInstrument != 0)
        {
            this->numeInstrument = new char[strlen(numeInstrument) + 1];
            strcpy_s(this->numeInstrument, strlen(numeInstrument) + 1, numeInstrument);
        }
        else
        {
            this->numeInstrument = nullptr;
        }
    }
    EchipamentMedical(const EchipamentMedical& em) :idInstrument(++maxInstrumenteInventar)// constructor de copiere
    {
        {
            this->nrInstrumenteInventar = em.nrInstrumenteInventar;
            this->dataExpirare = em.dataExpirare;
            this->temperatura = em.temperatura;
            if (em.numeInstrument != 0)
            {
                this->numeInstrument = new char[strlen(em.numeInstrument) + 1];
                strcpy_s(this->numeInstrument, strlen(em.numeInstrument) + 1, em.numeInstrument);
            }
            else
            {
                this->numeInstrument = nullptr;
            }
        }
    }
    ~EchipamentMedical()
    {
        if(numeInstrument!=nullptr)
        delete[] numeInstrument;
    }
};

int EchipamentMedical::maxInstrumenteInventar = 0;

int main()
{
   //Constructor default
   Vaccin vaccin1;// accesare constructor default + definire obiect vaccin1
   VizitaMedicala vm1;
   EchipamentMedical em1;

  /* cout << vaccin1.greutateVaccin << endl; // accesez informatia din constructorul default

   //Constructor cu parametri
   Vaccin vaccin2(1, "Se aplica in bratul stang", "antirabic", 0.01, true); //am adaugat datele
   cout << vaccin2.instructiuniAplicare << endl; //accesul constructorulului cu parametrii 
   VizitaMedicala vm2(2, "Lori", "Bianca Giurcan", 0.5);
   cout << vm2.numePacient << endl;
   EchipamentMedical em2(3, "stetoscop", "30.04.2029", 20.7);
   cout << em2.dataExpirare << endl;
   //2. Apelează Constructorul de Copiere (Sintaxă standard)
   Vaccin v1 = vaccin2;
   //3. Apelează Constructorul de Copiere (Sintaxă directă)
   Vaccin v2(vaccin2);
   cout << "Nume Vaccin: " << v1.numeVaccin << endl; //accesul constructorului cu COPIERE se face pe baza CONSTRUCTORULUI DE PARAMETRII
   VizitaMedicala vizita_medicala1 = vm2;
   cout << "Nume Pacient: " << vm2.numePacient << endl;
   EchipamentMedical echipament_medical1 = em2;
   cout << "Nume Echipament Medical: " << em2.numeInstrument << endl;
   */

    cout << "Programul merge!";

   //alt tip de afisare cu getteri 
    Vaccin vaccin1(1, "Se aplica in bratul stang", "antirabic", 0.01, true); //am adaugat datele
    cout << "Nr Doze: " << vaccin1.getNrDoze() << endl;
    cout << "Instructiunile sunt: " << vaccin1.getInstuctiuniDeAplicare() << endl;
    cout << "Nume Vaccin: " << vaccin1.getNumeVaccin() << endl;
    cout << "Greutate Vaccin: " << vaccin1.getGreutateVaccin() << endl;
    cout << "Confirmare:" << vaccin1.getConfirmare();
    cout << endl;

    Vaccin vaccin2(11, "Se aplica in bratul drept", "hpv", 0.20, false); //am adaugat datele
    cout << "Nr Doze: " << vaccin2.getNrDoze() << endl;
    cout << "Instructiunile sunt: " << vaccin2.getInstuctiuniDeAplicare() << endl;
    cout << "Nume Vaccin: " << vaccin2.getNumeVaccin() << endl;
    cout << "Greutate Vaccin: " << vaccin2.getGreutateVaccin() << endl;
    cout << "Confirmare: " << vaccin2.getConfirmare() << endl;
    cout << endl;
    
    bool pericol1 = !vaccin1;
    cout <<"Stare: "<< (vaccin1.getNrDoze() > 10 ? "PERICOL" : "OK") << endl;

    ~vaccin1;
    cout << "Dupa ~" << endl << vaccin1 << endl;
    bool pericol2 = !vaccin2;
    cout << "Stare: " << (vaccin2.getNrDoze() > 10 ? "PERICOL" : "OK") << endl;

    ~vaccin2;
    cout << "Dupa ~" << endl << vaccin2 << endl;
    
}
