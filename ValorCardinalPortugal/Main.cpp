
#include "Main.h"
#include "ValorCardinalPortugal.h"
#include "UtilFunctions.h"

//#define TEST

const string VERSION = "1.0.8";

int main(int argc, char* argv[])
{
	#ifdef TEST
		tests();
		return 0;
	#endif

	bool vazioSeZeroParteinteira = false;
	bool vazioSeZeroParteDecimal = false;

	if (argc >= 3)
	{
		string temp = strupper(argv[2]);
		vazioSeZeroParteinteira = (temp.compare("TRUE") == 0);
	}

	if (argc >= 4)
	{
		string temp = strupper(argv[3]);
		vazioSeZeroParteDecimal = (temp.compare("TRUE") == 0);
	}

	if (argc >= 2)
	{
		string result = Converte(argv[1], vazioSeZeroParteinteira, vazioSeZeroParteDecimal);
		cout << "[" + result + "]" << endl;
		return 0;
	}

	cout << endl << "ValorCardinalPortugal (Version: " << VERSION << ")" << endl;
	cout << "======================================" << endl << endl;

	string valor;
	cout << "Introduza valor '#0.00': ";
	cin >> valor; // str; 

	cout << "Processa :[" << valor << "]" << endl;

	string result = Converte(valor, vazioSeZeroParteinteira, vazioSeZeroParteDecimal);
	cout << endl << "Resultado:[" << result << "]" << endl;

	return 0;
}
