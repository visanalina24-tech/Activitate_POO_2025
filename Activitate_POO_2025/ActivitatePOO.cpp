#include<iostream> //librarie care contine diferite functii
#include<fstream> //partea de intrare
#include<cstring>

using namespace std; //folosim acest spatiu standard ca la cout si cin sa nu mai punem operatorul de rezolutie std::
class Vaccin //obiectul1
{
private:
    const int idVaccin; //identificator unic
    int nrDoze;
    string instructiuniAplicare;
    char* numeVaccin; //atribut alocat dinamic (pointer la caracter). Stochează numele vaccinului și necesită gestionarea memoriei (new/delete).
    float greutateVaccin;
    static int nrDozeMaxime; //stribut static (aparține clasei, nu obiectului). Folosit ca un contor pentru a genera ID-uri unice (idVaccin) pentru fiecare obiect nou
    bool confirmare; //atribut boolean, indică o stare binară
public:
    Vaccin() :idVaccin(++nrDozeMaxime)//constructor default, inițializează atributele cu valori implicite
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
    ~Vaccin()// destructor pt dezalocarea memoriei char
    {
        if (numeVaccin != nullptr)
        {
            delete[] this->numeVaccin;
        }
    }
    Vaccin& operator=(const Vaccin& p)//Operator de Atribuire, permite copierea valorilor de la un obiect la altul
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
        void setNrdoze(int nrDoze)
        {
            if (nrDoze > 0)
            {
                this->nrDoze = nrDoze;
            }

        }
        void setGreutateVaccin(float greutateVaccin)
        {
            if (greutateVaccin > 0)
                this->greutateVaccin = greutateVaccin;
        }
        bool getConfirmare()
        {
            return this->confirmare;
        }
        friend ostream& operator<<(ostream& out, Vaccin& v)//Permite afișarea directă a obiectului 
        {
            cout << v.nrDoze << " " << v.instructiuniAplicare << " " << v.numeVaccin << " " << v.greutateVaccin << " " << v.confirmare << " ";
            if (v.numeVaccin != nullptr) {
                out << v.numeVaccin;
            }
            return out;
        }
        bool operator!()//implementează o logică de verificare personalizată
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
        void operator~() //schimba starea obiectului, operator tilda
        {
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
private:
    const int idPacient;
    int nrVaccinuri;
    char* numePacient;
    string numeMedic;
    //int* nrConsultatii;
    float greutateAnimal;
    static int nrViziteIntr_unAn;
public:
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
    int getNrVaccinuri()
    {
        return this->nrVaccinuri;
    }
    char* getNumePacient()
    {
        return this->numePacient;
    }
    string getNumeMedic()
    {
        return this->numeMedic;
    }
    float getGreutateAnimal()
    {
        return this->greutateAnimal;
    }
    void setNumeMedic(string numeMedic)
    {
        this->numeMedic = numeMedic;
    }
    void setGreutateAnimal(float greutateAnimal)
    {
        this->greutateAnimal = greutateAnimal;
    }
   friend ofstream& operator<<(ofstream out, VizitaMedicala& vm0)//Permite afișarea directă a obiectului 
   {
       cout << vm0.nrVaccinuri << " " << vm0.numeMedic << " " << vm0.numePacient << " " << vm0.greutateAnimal;
       if (vm0.numePacient != nullptr) {
           out << vm0.numePacient;
       }
       return out;
   }

};
int VizitaMedicala::nrViziteIntr_unAn = 0;

class EchipamentMedical//obiectul3
{
private:
    const int idInstrument;
    int nrInstrumenteInventar;
    char* numeInstrument;
    string dataExpirare;
    float temperatura;
    static int maxInstrumenteInventar;
    bool expirat;
public:
    EchipamentMedical() :idInstrument(++maxInstrumenteInventar)// constructor default
    {
        this->nrInstrumenteInventar = 3;
        this->dataExpirare = "23.02.2025";
        this->temperatura = 20.3;
        this->numeInstrument = nullptr;
        this->expirat = expirat;
    }
    EchipamentMedical(int nrInstrumenteInventar, const char* numeInstrument, string dataExpirare, float temperatura, bool expirat) :idInstrument(++maxInstrumenteInventar)//constructori cu paramterii, initializare
    {
        this->nrInstrumenteInventar = nrInstrumenteInventar;
        this->dataExpirare = dataExpirare;
        this->temperatura = temperatura;
        this->expirat = expirat;
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
            this->expirat = em.expirat;
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
    int getNrInstrumenteInventar()
    {
        return this->nrInstrumenteInventar;
    }
    char* getNumeInstrument()
    {
        return this->numeInstrument;
    }
    string getDataExpirare()
    {
        return this->dataExpirare;
    }
    float getTemperatura()
    {
        return this->temperatura;
    }
    bool getExpirat()
    {
        return this->expirat;
    }
    void setNrInstrumenteInventar(int nrInstrumenteInventar)
    {
        this->nrInstrumenteInventar = nrInstrumenteInventar;
    }
    void setDataExpirare(string dataExpirare)
    {
        this->dataExpirare = dataExpirare;
    }


    friend ofstream& operator<<(ofstream out, EchipamentMedical& echipmed)
    {
        cout << echipmed.nrInstrumenteInventar << " " << echipmed.dataExpirare << " " << echipmed.temperatura << " " << echipmed.numeInstrument << endl;
        if (echipmed.numeInstrument != nullptr)
        {
            cout << echipmed.numeInstrument;
        }
        return out;
    }
};

int EchipamentMedical::maxInstrumenteInventar = 0;

int main()
{
  //Constructor default
  //Vaccin vaccin1;// accesare constructor default + definire obiect vaccin1
  //VizitaMedicala vm1;
  //EchipamentMedical em1;

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

   //alt tip de afisare cu getteri pt constructorul cu parametrii
    cout << "FISA VACCINURI PACIENT" << endl;
    Vaccin vaccin2(1, "Se aplica in bratul stang", "antirabic", 0.01, true); //am adaugat datele
    cout << "------Vaccinul 1------" << endl;
    cout << "Nr Doze: " << vaccin2.getNrDoze() << endl;
    cout << "Instructiunile sunt: " << vaccin2.getInstuctiuniDeAplicare() << endl;
    cout << "Nume Vaccin: " << vaccin2.getNumeVaccin() << endl;
    cout << "Greutate Vaccin: " << vaccin2.getGreutateVaccin() << endl;
    cout << "Confirmare:" << vaccin2.getConfirmare();
    cout << endl;
    //update date folosind set
    vaccin2.setGreutateVaccin(0.3f);
    cout <<"Dupa o actualizare greutatea vaccinului este: "<< vaccin2.getGreutateVaccin() << endl;
    vaccin2.setNrdoze(3);
    cout << "Dupa o actualizare nr de doze al pacientului este: " << vaccin2.getNrDoze() << endl;



    Vaccin vaccin3(11, "Se aplica in bratul drept", "hpv", 0.20, false); //am adaugat datele
    cout << "------Vaccinul 2------" << endl;
    cout << "Nr Doze: " << vaccin3.getNrDoze() << endl;
    cout << "Instructiunile sunt: " << vaccin3.getInstuctiuniDeAplicare() << endl;
    cout << "Nume Vaccin: " << vaccin3.getNumeVaccin() << endl;
    cout << "Greutate Vaccin: " << vaccin3.getGreutateVaccin() << endl;
    cout << "Confirmare: " << vaccin3.getConfirmare() << endl;
    cout << endl;
    
    cout << "Pentru vaccinul 1" << endl;//varianta pentru a determina daca o variabila de tip este de tip false sau true si ce consecinte au
    bool pericol1 = !vaccin2;
    cout <<"Stare: "<< (vaccin2.getNrDoze() > 10 ? "PERICOL" : "OK") << endl;
    

    cout << "Pentru vaccinul 2" << endl;
    bool pericol2 = !vaccin3;
    cout << "Stare: " << (vaccin3.getNrDoze() > 10 ? "PERICOL" : "OK") << endl;
    cout << endl;


    cout << "Programul merge!" << endl;// pun "Programul Merge!" ca sa pot observa daca programul ruleaza pana la capat
    cout << endl;

    cout << "FISA PACIENT VIZITA MEDICALA" << endl;
    VizitaMedicala vm2(3, "Azorel", "Mihaela Soare", 20);
    cout << "----Pacientul 1----" << endl;
    cout << "Nr vaccinuri: " << vm2.getNrVaccinuri() << endl;
    cout << "Numele Pacientului: " << vm2.getNumePacient() << endl;
    cout << "Numele Medicului: " << vm2.getNumeMedic() << endl;
    cout << "Greutate Animal: " << vm2.getGreutateAnimal() <<"kg"<< endl;
    vm2.setGreutateAnimal(25);
    vm2.setNumeMedic("Constanta Vasile");
    cout << "Dupa Actualizare: " << endl;
    cout << "Greutate animal: "<< vm2.getGreutateAnimal() << endl;
    cout << "Nume Medic: "<<vm2.getNumeMedic() << endl;
    cout << endl;

    cout << "INFORMATII ECHIPAMENT MEDICAL" << endl;
    EchipamentMedical em2(5, "Stetoscop", "20.11.2025", 45.2, true);
    {
        cout << "-----Instrumentul 1------" << endl;
        cout << "Numarul de astfel de instrumente: " << em2.getNrInstrumenteInventar() << endl;
        cout << "Data de expirare: " << em2.getDataExpirare() << endl;
        cout << "Numele Instrumentului: " << em2.getNumeInstrument() << endl;
        cout << "Temperatura: " << em2.getTemperatura() << " grade" << endl;
        if (em2.getExpirat() != false) //o alta varianta pentru a determina daca o variabila de tip este de tip false sau true si ce consecinte au
        {
            cout << "Trebuie indepartat" << endl;
        }
        else if (em2.getExpirat() == false)
        {
            cout << "Totul ok" << endl;
        }
        em2.setNrInstrumenteInventar(10);
        cout << "Dupa Actualizare: " << em2.getNrInstrumenteInventar() << endl;
    }
    EchipamentMedical em3(10, "Bisturiu", "21.10.2005", 50.6, true);
    {
        cout << "-----Instrumentul 2------" << endl;
        cout << "Numarul de astfel de instrumente: " << em3.getNrInstrumenteInventar() << endl;
        cout << "Data de expirare: " << em3.getDataExpirare() << endl;
        cout << "Numele Instrumentului: " << em3.getNumeInstrument() << endl;
        cout << "Temperatura: " << em3.getTemperatura() << " grade" << endl;
        em3.setNrInstrumenteInventar(10);
        cout << "Dupa Actualizare: " << em3.getNrInstrumenteInventar() << endl;
        if (em3.getExpirat() != false) //m-am jucat putin cu getterul, setterul si bool
        {
            cout << "Trebuie actualizat!" << endl;
            em3.setDataExpirare("30.11.2032");
            cout << "Dupa actualizare: "<< em3.getDataExpirare()<< endl;
        }
        else if (em3.getExpirat() == false)
        {
            cout << "Totul ok" << endl;
        }
    }
    EchipamentMedical em4(2, "Endoscop", "10.12.2025",30.1, false);
    {
        cout << "-----Instrumentul 3------" << endl;
        cout << "Numarul de astfel de instrumente: " << em4.getNrInstrumenteInventar() << endl;
        cout << "Data de expirare: " << em4.getDataExpirare() << endl;
        cout << "Numele Instrumentului: " << em4.getNumeInstrument() << endl;
        cout << "Temperatura: " << em4.getTemperatura() << " grade" << endl;
        em4.setNrInstrumenteInventar(10);
        cout << "Dupa Actualizare: " << em4.getNrInstrumenteInventar() << endl;
        if (em4.getExpirat() != false)
        {
            cout << "Trebuie actualizat!" << endl;
            em4.setDataExpirare("30.11.2032");
            cout << "Dupa actualizare: " << em4.getDataExpirare() << endl;
        }
        else if (em4.getExpirat() == false)
        {
            cout << "Totul ok" << endl;
        }
    }
    cout << endl;


    cout << "Programul merge! x2";
    
}
