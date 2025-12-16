#include<iostream> //librarie care contine diferite functii
#include<fstream> //partea de intrare
#include<string>

using namespace std;
class Vaccin //obiectul1
{
private:
    const int idVaccin; //identificator unic
    int nrDoze;
    string instructiuniAplicare;
    char* numeVaccin; //atribut alocat dinamic (pointer la caracter). Stochează numele vaccinului și necesită gestionarea memoriei (new/delete).
    float greutateVaccin;
    static int nrDozeMaxime; //atribut static (aparține clasei, nu obiectului). Folosit ca un contor pentru a genera ID-uri unice (idVaccin) pentru fiecare obiect nou
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
class FisaPacient //obiectul2
{
private:
    const int idPacient;
    int nrVaccinuri;
    char* numePacient;
    string numeVaccinuriEfectuate;
    float greutateAnimal;
    int varstaAni;
    int varstaLuni;
    bool problemeDeSanatate;
    static int nrViziteIntr_unAn;
public:
    float* nrConsultatii;
    int nrConsultatii0;
    /* FisaPacient() :idPacient(++nrViziteIntr_unAn)//constructor default
     {
          this->nrVaccinuri = 3;
          this->numeVaccinuriEfectuate = "Antirabie, Polivalent, Monovalent";
          this->numePacient = nullptr;
          this->varstaAni = 2;
          this->varstaLuni = 5;
          this->problemeDeSanatate = true;
          this->greutateAnimal = 0.5;
          this->numePacient = nullptr;
          this->nrConsultatii0 = 2;
          this->nrConsultatii = NULL;
     }  */
    FisaPacient(const char* numePacient, int varstaAni, int varstaLuni, string numeVaccinuriEfectuate, int nrVaccinuri, bool problemeDeSanatate, float greutateAnimal, int nrConsultatii0, const float* nrConsultatii) :idPacient(++nrViziteIntr_unAn)//constructor cu parametrii, initializare
    {
        if (numePacient != nullptr)
        {
            this->numePacient = new char[strlen(numePacient) + 1];
            strcpy_s(this->numePacient, strlen(numePacient) + 1, numePacient);
        }
        else
        {
            this->numePacient = nullptr;
        }
        this->varstaAni = varstaAni;
        this->varstaLuni = varstaLuni;
        this->numeVaccinuriEfectuate = numeVaccinuriEfectuate;
        this->nrVaccinuri = nrVaccinuri;
        this->problemeDeSanatate = problemeDeSanatate;
        this->greutateAnimal = greutateAnimal;
        this->nrConsultatii = new float[nrConsultatii0];
        for (int i = 0; i < this->nrConsultatii0; i++)
        {
            this->nrConsultatii[i] = nrConsultatii[i];
        }
    }
    FisaPacient(const FisaPacient& fp1) :idPacient(++nrViziteIntr_unAn)// constrctor de copiere
    {
        if (fp1.numePacient != nullptr)
        {
            this->numePacient = new char[strlen(fp1.numePacient) + 1];
            strcpy_s(this->numePacient, strlen(fp1.numePacient) + 1, fp1.numePacient);
        }
        else
        {
            this->numePacient = nullptr;
        }
        this->varstaAni = fp1.varstaAni;
        this->varstaLuni = fp1.varstaLuni;
        this->numeVaccinuriEfectuate = fp1.numeVaccinuriEfectuate;
        this->nrVaccinuri = fp1.nrVaccinuri;
        this->problemeDeSanatate = fp1.problemeDeSanatate;
        this->greutateAnimal = fp1.greutateAnimal;
        this->nrConsultatii = new float[fp1.nrConsultatii0];
        for (int i = 0; i < fp1.nrConsultatii0; i++)
        {
            this->nrConsultatii[i] = fp1.nrConsultatii[i];
        }
    }
    ~FisaPacient()
    {
        if (numePacient != nullptr)
        {
            delete[] this->numePacient;
        }
        delete[] this->nrConsultatii;

    };
    FisaPacient& operator=(const FisaPacient& fp2)
    {
        if (numePacient != nullptr)
        {
            delete[] this->numePacient;
        }
        if (fp2.numePacient != nullptr)
        {
            this->numePacient = new char[strlen(fp2.numePacient) + 1];
            strcpy_s(this->numePacient, strlen(fp2.numePacient) + 1, fp2.numePacient);
        }
        else
        {
            this->numePacient = nullptr;
        }
        this->varstaAni = fp2.varstaAni;
        this->varstaLuni = fp2.varstaLuni;
        this->numeVaccinuriEfectuate = fp2.numeVaccinuriEfectuate;
        this->nrVaccinuri = fp2.nrVaccinuri;
        this->problemeDeSanatate = fp2.problemeDeSanatate;
        this->greutateAnimal = fp2.greutateAnimal;
        this->nrConsultatii = new float[fp2.nrConsultatii0];
        for (int i = 0; i < fp2.nrConsultatii0; i++)
        {
            this->nrConsultatii[i] = fp2.nrConsultatii[i];
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
    string getNumeVaccinuriEfectuate()
    {
        return this->numeVaccinuriEfectuate;
    }
    float getGreutateAnimal()
    {
        return this->greutateAnimal;
    }
    int getVarstaAni()
    {
        return this->varstaAni;
    }
    int getVarstaLuni()
    {
        return this->varstaLuni;
    }
    bool getProblemeDeSanatate()
    {
        return this->problemeDeSanatate;

    }
    float* getNrConsultatii()
    {
        return this->nrConsultatii;

    }
    int getNrConsultatii0()
    {
        return this->nrConsultatii0;
    }
    void setGreutateAnimal(float greutateAnimal)
    {
        if (greutateAnimal > 0)
            this->greutateAnimal = greutateAnimal;
    }
    friend ofstream& operator<<(ofstream out, FisaPacient& fp0)//Permite afișarea directă a obiectului 
    {

        cout << fp0.nrVaccinuri << " " << fp0.numeVaccinuriEfectuate << " " << fp0.greutateAnimal << " " << fp0.varstaAni << " " << fp0.varstaLuni << " " << fp0.problemeDeSanatate;
        if (fp0.numePacient != nullptr)
        {
            cout << fp0.numePacient;
            cout << endl;
        }
        return out;

        if (fp0.nrConsultatii != nullptr && fp0.nrConsultatii0 > 0) {
            for (int i = 0; i < fp0.nrConsultatii0; i++)
            {
                cout << fp0.nrConsultatii[i];
                if (i < fp0.nrConsultatii0 - 1) cout << ", ";
            }
            cout << fp0.nrConsultatii0;
            cout << endl;
        }

    }
};

int FisaPacient::nrViziteIntr_unAn = 0;

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

   //alt tip de afisare cu getteri pt constructorul cu parametrii\

    cout << "FISA PACIENT VIZITA MEDICALA" << endl;
    cout << "------Pacientul 1------" << endl;
    //float consultatii[] = { 1, 2, 3, 4 };
    FisaPacient f1("Azorel", 0, 6, "Antirabie, Polivalent, Monovalent", 3, false, 10.5, 4, new float[4] {1, 2, 3, 4});
    cout << "Nume pacient: " << f1.getNumePacient() << endl;
    cout << "Varsta: " << f1.getVarstaAni() << " ani." << endl;
    cout << "Si: " << f1.getVarstaLuni() << " luni." << endl;
    cout << "Nume vaccinuri efectuate: " << f1.getNumeVaccinuriEfectuate() << endl;
    cout << "Numar de vaccinuri: " << f1.getNrVaccinuri() << endl;
    cout << "Are probleme de sanatate?" << endl;
    if (f1.getProblemeDeSanatate() != true)
    {
        cout << "Nu, nu are probleme de sanatate";
    }
    cout << "Greutate: " << f1.getGreutateAnimal() << " kg." << endl;
    cout << "A cata consultatie este?" << f1.getNrConsultatii() << endl;
    f1.setGreutateAnimal(11);
    cout << "Dupa Actualizare: " << endl;
    cout << "Greutate animal: " << f1.getGreutateAnimal()<< " kg." << endl;
    cout << endl;

   cout << "FISA VACCINURI PACIENT" << endl;
    Vaccin vaccin2(1, "Se aplica in bratul stang", "Antirabic", 0.01, true); //am adaugat datele
    cout << "------Vaccinul 1------" << endl;
    cout << "Nr Doze: " << vaccin2.getNrDoze()<<"." << endl;
    cout << "Instructiunile sunt: " << vaccin2.getInstuctiuniDeAplicare()<<"." << endl;
    cout << "Nume Vaccin: " << vaccin2.getNumeVaccin()<<"." << endl;
    cout << "Greutate Vaccin: " << vaccin2.getGreutateVaccin()<<" grame." << endl;
    cout << endl;
    //update date folosind set
    vaccin2.setGreutateVaccin(0.3);
    cout <<"Dupa o actualizare greutatea vaccinului este: "<< vaccin2.getGreutateVaccin()<<" grame." << endl;
    vaccin2.setNrdoze(3);
    cout << "Dupa o actualizare nr de doze al pacientului este: " << vaccin2.getNrDoze()<<"." << endl;

    Vaccin vaccin3(4, "Se aplica in bratul drept", "Polivalent", 0.20, false); //am adaugat datele
    cout << "------Vaccinul 2------" << endl;
    cout << "Nr Doze: " << vaccin3.getNrDoze()<<"." << endl;
    cout << "Instructiunile sunt: " << vaccin3.getInstuctiuniDeAplicare()<<"." << endl;
    cout << "Nume Vaccin: " << vaccin3.getNumeVaccin()<<"." << endl;
    cout << "Greutate Vaccin: " << vaccin3.getGreutateVaccin()<<" grame." << endl;
    cout << endl;
    
    cout << "Pentru vaccinul 1" << endl;//varianta pentru a determina daca o variabila de tip este de tip false sau true si ce consecinte au
    bool pericol1 = !vaccin2;
    cout <<"Stare: nr dozelor este mai mare decat 3?  "<< (vaccin2.getNrDoze() > 3 ? "Da, PERICOL!" : "Nu, totul ok!") << endl;
    

    cout << "Pentru vaccinul 2" << endl;
    bool pericol2 = !vaccin3;
    cout << "Stare: nr dozelor este mai mare decat 3?" << (vaccin3.getNrDoze() > 3 ? "Da, PERICOL!" : "Nu, totul ok!") << endl;
    cout << endl;


    cout << "Programul merge!" << endl;// pun "Programul Merge!" ca sa pot observa daca programul ruleaza pana la capat
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


    cout << "Programul merge! x2"; // ruleaza pana la capat
    
    // de adaugat id pacient la fisa pacientului in interiorul constructorului cumva pentru a arata mai bine
}

