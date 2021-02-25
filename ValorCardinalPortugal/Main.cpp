
#include "Main.h"
#include "ValorCardinalPortugal.h"
#include "UtilFunctions.h"

#define TEST

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

	//printf("\n");
	//printf("ValorCardinalPortugal (Version: %s)\n", VERSION);
	//printf("======================================\n");
	//printf("\n");

	//char str[255];
	//printf("Introduza valor '#0.00': ");
	//scanf("%s", str);

	//printf("\nProcessa :[%s]\n", str);

	//char* valor = str;
	////char *valor = &str;

	//char* result = converte(valor, vazioSeZeroParteinteira, vazioSeZeroParteDecimal);
	//printf("\nResultado:[%s]\n", result);

	//printf("\nEnter\n");
	//getchar();

	//return 0;
}
