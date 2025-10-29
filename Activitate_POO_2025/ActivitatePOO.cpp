#include<iostream> // librarie care contine diferite functii
#include<fstream> //partea de intrare
#include<string>

using namespace std; // folosim acest spatiu standard ca la cout si cin sa nu mai punem operatorul de rezolutie std::
// int numele clasei::atribut=0; // initializare atribut static , variabila globala

class Veterinar//domeniu, generalizare, upper camel case
{
	class Vaccin //obiectul1
	{
		int idVaccin;
		char* InstructiuniAplicare;
		string numeVaccin;
		float greutate;
	};

	class VizitaMedicala //obiectul2
	{
		int idPacient;
		char* numeMedic;
		string DataVizitei;
		float pulAnimalBPM;

	};

	class EchipamentMedical// obiectul 3 
	{
		int idInventar;
		char* sectieUtilizare;
		string numeInstrument;
		float temperatura;
	};

 
int main()
	{

	}