#include<iostream> //librarie care contine diferite functii
#include<fstream> //partea de intrare
#include<cstring> 

using namespace std; //folosim acest spatiu standard ca la cout si cin sa nu mai punem operatorul de rezolutie std::
class Vaccin //obiectul1
{
public:
	const int idVaccin;
	int nrDoze;
	string instructiuniAplicare;
	char* numeVaccin;
	float greutateVaccin;
	static int nrDozeMaxime;

	Vaccin() :idVaccin(++nrDozeMaxime)//constructor default
	{
		this->nrDoze = 2;
		this->instructiuniAplicare = "1. Deschidere recipient medicament, 2. Extragere cu seringa, 3. Aplicarea spirtului pe membrul pacientului, 4. Introducere ac de la vaccin in membrul pacientului";
		this->greutateVaccin = 0.01;
		this->numeVaccin = nullptr;
		//nrDozeMaxime++; //am initializat jos numarul static daca pun  nrDozeMaxime++ imi da eroare
	}

	Vaccin(int nrDoze, string instructiuniAplicare, const char* numeVaccin, float greutateVaccin) : idVaccin(++nrDozeMaxime) //constructor cu parametrii, initializare
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
	}
	// Destructor pentru eliberarea memoriei
	~Vaccin()
	{
		delete[] numeVaccin;
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

	VizitaMedicala() :idPacient(++nrViziteIntr_unAn)
	{
		this->nrVaccinuri = 2;
		this->numeMedic = "Gabriela Stanescu";
		this->greutateAnimal = 0.5;
		this->numePacient = nullptr;
		++nrViziteIntr_unAn;
	}
	VizitaMedicala(int nrVaccinuri, const char* numePacient, string numeMedic, float greutateAnimal) :idPacient(++nrViziteIntr_unAn)
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
	~VizitaMedicala()
	{
		delete[] numePacient;
	}
/*
	VizitaMedicala(int nrVaccinuri, const char* numePacient, string numeMedic, float greutateAnimal) //constructor cu parametrii, initializare
	{
		this->nrVaccinuri = nrVaccinuri;
		this->numeMedic = numeMedic;
		this->greutateAnimal = greutateAnimal;
		this->numePacient = new char[strlen(numePacient) + 1];
		strcpy_s(this->numePacient, strlen(numePacient) + 1, numePacient);
	}
	*/
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

	EchipamentMedical() :idInstrument(++maxInstrumenteInventar)
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
	~EchipamentMedical()
	{
		delete[] numeInstrument;
	}
	
};

int EchipamentMedical::maxInstrumenteInventar = 0;

int main()
{
	//Constructor default
	Vaccin vaccin1;// accesare constructor default
	VizitaMedicala vm1;
	EchipamentMedical em1;
	cout << vaccin1.greutateVaccin << endl; // accesez informatia din constructorul default
	//Constructor cu parametri
	Vaccin vaccin2 (1, "Se aplica in bratul stang", "antirabic", 0.01);
	cout << vaccin2.instructiuniAplicare << endl; //acces constructorul cu parametrii
	VizitaMedicala vm2(2, "Lori", "Bianac Giurcan",0.5);
	cout << vm2.numePacient << endl;
	EchipamentMedical em2(3, "stetoscop", "30.04.2029", 20.7);
	cout << em2.dataExpirare << endl;

	// 2. Apelează Constructorul de Copiere (Sintaxă standard)
	Vaccin v1 = vaccin1;

	// 3. Apelează Constructorul de Copiere (Sintaxă directă)
	Vaccin v2(vaccin1);
	cout << "Nume Vaccin: " << v1.numeVaccin << endl;
	cout << "Nume Vaccin: " << v2.numeVaccin << endl;

	cout << "Programul merge!";


	return 0;

}