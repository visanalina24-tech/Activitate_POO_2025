#include<iostream> //librarie care contine diferite functii
#include<fstream> //partea de intrare
#include<string> 

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
		this->instructiuniAplicare = "1. Deschidere recipient medicament 2. Extragere cu seringa 3. Aplucarea spirtului pe membrul pacientului 4. Introducere ac de la vaccin in membrul pacientului";
		this->greutateVaccin = 0.01;
		this->numeVaccin = nullptr;
		//nrDozeMaxime++; am initializat jos numarul static daca pun  nrDozeMaxime++ imi da eroare
	}

	/*Vaccin(int nrDoze, string instructiuniAplicare, const char* numeVaccin, float greutateVaccin) //constructor cu parametrii, initializare
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

	// Destructor pentru eliberarea memoriei
	~Vaccin()
	{
		delete[] numeVaccin;
	}
*/
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

	}

	/*VizitaMedicala(int nrVaccinuri, const char* numePacient, string numeMedic, float greutateAnimal) //constructor cu parametrii, initializare
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
	/*EchipamentMedical(int garantieAni, const char* numeInstrument, string dataExpirare, float temperatura) //constructori cu paramterii, initializare
	{
		this->garantieAni = garantieAni;
		this->dataExpirare = dataExpirare;
		this->temperatura = temperatura;
		this->numeInstrument = new char[strlen(numeInstrument) + 1];
		strcpy_s(this->numeInstrument, strlen(numeInstrument) + 1, numeInstrument);
	}
	*/
};

int EchipamentMedical::maxInstrumenteInventar = 0;

int main()
{
	Vaccin vaccin1;
	VizitaMedicala vm1;
	EchipamentMedical em1;
	cout << "Programul merge!";


}