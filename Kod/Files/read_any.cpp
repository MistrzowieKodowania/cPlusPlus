#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// funkcja do wczytywania pliku
// zwraca wektor zawieraj�cy wszystkie linijki plik�w
vector<string> read_file(string nazwa_pliku)
{
	fstream reader;
	vector<string> lines;
	// sprawd�my adres wektora w pami�ci
	cout << "Adres wektora z read_file linijka 13: " << &lines << endl << endl;
	
	reader.open (nazwa_pliku.c_str(), ios::in); // istotne jest to, �e "open" wymaga
	                                            // typu const char*, a nie string
	                                            // dlatego u�ywamy metody c_str()
	                                            // aby zamieni� string na const char*
	if (reader.is_open())
	{
	string line;
	while (getline(reader,line))
		lines.push_back(line);
	}
	reader.close();
	return lines;
}

// funkcja do wczytywania pliku
// drugi spos�b - wynik zapisywany w wektorze przekazywanym
// przez referencj�
// mo�na jeszcze przez wska�nik - do eksperymentowania
// wtedy zadzia�a podobnie jak ta funkcja, ale napiszemy troch� wi�cej kodu
// a co si� stanie jak przeka�emy wektor do funkcji przez warto��?
// czyli tak:
// void read_file(string nazwa_pliku, vector<string> lines) 
// do poeksperymentowania (usu� symbol & z funkcji poni�ej)
// dlaczego tak si� sta�o?
void read_file(string nazwa_pliku, vector<string>& lines)
{
	cout << "Adres wektora z read_file linijka 31: " << &lines << endl << endl;

	fstream reader;
	reader.open (nazwa_pliku.c_str(), ios::in);
	if (reader.is_open())
	{
	string line;
	while (getline(reader,line))
		lines.push_back(line);
	}
	reader.close();
}

int main()
{
	vector<string> lines;
	string nazwa_pliku;
	getline(cin,nazwa_pliku);
	
	// pierwszy spos�b na wczytanie pliku
	// funkcja zwraca wektor
	// co to znaczy zwr�cenie wektora?
	// jak to wygl�da w pami�ci komputera?
	// w pami�ci wygl�da to tak, �e 
	// vector<string> z linijki 13 w funkcji read_file
	// ma zarezerwowany sw�j w�asny obszar oraz
	// vector<string> z linijki poni�ej ma w�asny
	// elementy z pami�ci przeznaczonej dla wektora
	// z linijki 13 s� kopiowane do tego poni�ej
	// Zwracanie wektora przez warto�� (nie wska�nik i nie referencj�!)
	// oznacza kopiowanie
	// eksperymenty:
	// co by by�o gdyby zwraca� wska�nik na wektor z linijki 13?
	// czy mo�emy zwr�ci� referencj�?
	//
	// podpowied�: �ywotno�� zmiennych w pamieci jest ograniczona do bloku
	// funkcja jest osobnym blokiem, a wi�c po wyj�ciu z funkcji wektor z linijki
	// 13 mo�e "znikn��" lub zosta� swobodnie nadpisany przez system operacyjny
	lines = read_file(nazwa_pliku);
	
	cout << "Adres wektora z main linijka 70: " << &lines << endl << endl;
	
	for ( int i = 0; i < lines.size(); i++ )
		cout << lines[i] << endl;
	cout << endl << endl;
	
	// ale nie musimy kopiowa� danych (co czasem mo�e obni�a� szybko�� dzia�ania programu)
	vector<string> lines2;
	
	// tutaj korzystamy z funkcji w kt�rej przekazujemy referencj�
	// wektor z funkcji jest dok�adnie tym samym co z linijki 72
	// wk�adamy elementy do "otwartego" wektora i nic nie kopiujemy
	// kod b�dzie szybszy
	read_file(nazwa_pliku, lines2);
	
	cout << "Adres wektora z main linijka 79: " << &lines2 << endl << endl;
	
	for ( int i = 0; i < lines2.size(); i++ )
		cout << lines2[i] << endl;
}
