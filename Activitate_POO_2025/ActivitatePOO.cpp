#include<iostream> //librarie care contine diferite functii
#include<fstream> //partea de intrare
#include<string> 

using namespace std; //folosim acest spatiu standard ca la cout si cin sa nu mai punem operatorul de rezolutie std::
// int numele clasei::atribut=0; // initializare atribut static, variabila globala


class Vaccin //obiectul1
{
private:
	const int idVaccin;
public:
	int nrDoze;
	char* numeVaccin;
	string instructiuniAplicare;
	float greutateVaccin;
	static int nrDozeMaxime;

	Vaccin() :idVaccin(++nrDozeMaxime)//constructor default
	{
		this->nrDoze = 2;
		this->instructiuniAplicare = "1. Deschidere recipient medicament 2. Extragere cu seringa 3. Aplucarea spirtului pe membrul pacientului 4. Introducere ac de la vaccin in membrul pacientului";
		this->greutateVaccin = 0.01;
		this->numeVaccin = nullptr;
		nrDozeMaxime++;
	}

	Vaccin(int nrDoze, string instructiuniAplicare, const char* numeVaccin, float greutateVaccin) //constructor cu parametrii, initializare
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
};


/*/class VizitaMedicala //obiectul2
{
public:
	static int
	const int idPacient;
	int nrVaccinuri;
	char* numePacient;
	string numeMedic;
	//int* nrConsultatii;
	float greutateAnimal;


	VizitaMedicala(int nrVaccinuri, const char* numePacient, string numeMedic, float greutateAnimal) //constructor cu parametrii, initializare
	{
		this->nrVaccinuri = nrVaccinuri;
		this->numeMedic = numeMedic;
		this->greutateAnimal = greutateAnimal;
		this->numePacient = new char[strlen(numePacient) + 1];
		strcpy_s(this->numePacient, strlen(numePacient) + 1, numePacient);
	}
};

class EchipamentMedical//obiectul3
{
public:
	const int idInventar;
	int garantieAni;
	char* numeInstrument;
	string dataExpirare;
	float temperatura;

	EchipamentMedical(int garantieAni, const char* numeInstrument, string dataExpirare, float temperatura) //constructori cu paramterii, initializare
	{
		this->garantieAni = garantieAni;
		this->dataExpirare = dataExpirare;
		this->temperatura = temperatura;
		this->numeInstrument = new char[strlen(numeInstrument) + 1];
		strcpy_s(this->numeInstrument, strlen(numeInstrument) + 1, numeInstrument);
	}
} */


int main()
{

	Vaccin v1(2;

}