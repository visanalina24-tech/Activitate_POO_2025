#include<iostream> // librarie care contine diferite functii
#include<fstream> //partea de intrare
#include<string>

using namespace std; // folosim acest spatiu standard ca la cout si cin sa nu mai punem operatorul de rezolutie std::
// int numele clasei::atribut=0; // initializare atribut static, variabila globala

class Veterinar//domeniu, generalizare, upper camel case
{
	class Vaccin //obiectul1
	{
	public:
		const int idVaccin;
		int nrDoze;
		char* numeVaccin;
		string instructiuniAplicare;
		float geutateVaccin;

		Vaccin(int nrDoze, string instructiuniAplicare,const char* numeVaccin, float geutateVaccin) // constructor cu parametrii, initializare
		{
			this->nrDoze= nrDoze;
			this->instructiuniAplicare = instructiuniAplicare;
			this->geutateVaccin= geutateVaccin;
			this->numeVaccin = new char[strlen(numeVaccin) + 1];
			strcpy_s(this->numeVaccin, strlen(numeVaccin) + 1, numeVaccin);
		}
	};
	class VizitaMedicala //obiectul2
	{
	public:
		const int idPacient;
		int nrVaccinuri;
		char* numePacient;
		string numeMedic;
		//int* nrConsultatii;
		float greutateAnimal;


		Vizita medicala(int nrVaccinuri, const char* numePacient, string numeMedic, float greutateAnimal) //constructor cu parametrii, initializare
		{
			this->nrVaccinuri = nrVaccinuri;
			this->numeMedic = numeMedic;
			this->greutateAnimal = greutateAnimal;
			this->numePacient = new char[strlen(numePacient) +1 ];
			strcpy_s(this->numePacient, strlen(numePacient) + 1, numePacient);
		}
	};

	class EchipamentMedical// obiectul 3 
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
			this-> dataExpirare= dataExpirare ;
			this->temperatura = temperatura;
			this->numeInstrument = new char[strlen(numeInstrument) + 1];
			strcpy_s(this->numeInstrument, strlen(numeInstrument) + 1, numeInstrument);
		}
	};

 
int main()
	{

	}