
#include "Tests.h"
#include "UtilFunctions.h"
#include "ValorCardinalPortugal.h"

void tests()
{
    cout << "Tests Begin..." << endl;

    test_strcopy();
    test_substring();
    test_indexof();
    test_leftpad();
    test_strltrim();
    test_strrtrim();
    test_strtrim();
    test_strupper();

    test_validaValor();
    test_formataValor();
    test_valorNegativo();

    test_adicionaSufixoDeGrupoMil();
    test_obtemQualificadorParteDecimal();
    test_obtemQualificadorParteInteira();
    test_obtemCentenas();
    test_obtemDezenas();
    test_obtemUnidades();
    test_juntaCentenasDezenasUnidades();
    test_descodificaCardinal();
    test_removeUltimasVirgulasEmExcesso();
    test_juntaTodosGruposDeMil(); 
    test_divideEmGruposDeMil();
    test_divideEmPartesInteiraDecimal();
    
    test_converte();

    cout << "Tests End..." << endl;
}

void test_strcopy()
{
    cout << "testing function: strcopy" << endl;
    string input = "AABBCCDDEEFF";
    string output = strcopy(input);
    if (output.compare("AABBCCDDEEFF") != 0)
        cout << "ERROR testing function: strcopy (0)" << endl;
}

void test_leftpad()
{
    cout << "testing function: leftpad" << endl;
    string input = "123";
    string output = padleft(input, 'A', 10);
    if (output.compare("AAAAAAA123") != 0)
        cout << "ERROR testing function: leftpad (0)" << endl;

    string output1 = padleft(input, 'A', 3);
    if (output1.compare("123") != 0)
        cout << "ERROR testing function: leftpad (1)" << endl;
}

void test_substring()
{
    cout << "testing function: substring" << endl;
    string input = "123456789";
    string output = substring(input, 5, 7);
    if (output.compare("67") != 0)
        cout << "ERROR testing function: substring" << endl;
}

void test_indexof()
{
    cout << "testing function: indexof" << endl;
    size_t pos = indexof("alfabetazulu", "beta");
    if (pos != 4)
        cout << "ERROR testing function: indexof" << endl;
}

void test_strltrim()
{
    cout << "testing function: strltrim" << endl;
    string output = leftTrim("   alfabetazulu");
    if (output.compare("alfabetazulu") != 0)
        cout << "ERROR testing function: strltrim (0)" << endl;

    string output1 = leftTrim("");
    if (output1.compare("") != 0)
        cout << "ERROR testing function: strltrim (1)" << endl;

    string output2 = leftTrim("   ");
    if (output2.compare("") != 0)
        cout << "ERROR testing function: strltrim (2)" << endl;
}

void test_strrtrim()
{
    cout << "testing function: strrtrim" << endl;
    string output = rightTrim("alfabetazulu   ");
    if (output.compare("alfabetazulu") != 0)
        cout << "ERROR testing function: strrtrim (0)" << endl;

    string output1 = rightTrim("");
    if (output1.compare("") != 0)
        cout << "ERROR testing function: strrtrim (1)" << endl;

    string output2 = rightTrim("   ");
    if (output2.compare("") != 0)
        cout << "ERROR testing function: strrtrim (2)" << endl;
}

void test_strtrim()
{
    cout << "testing function: strtrim" << endl;
    string output = trimString("   alfabetazulu   ");
    if (output.compare("alfabetazulu") != 0)
        cout << "ERROR testing function: strtrim (0)" << endl;

    string output1 = trimString("");
    if (output1.compare("") != 0)
        cout << "ERROR testing function: strtrim (1)" << endl;

    string output2 = trimString("   ");
    if (output2.compare("") != 0)
        cout << "ERROR testing function: strtrim (2)" << endl;
}

void test_strupper()
{
    cout << "testing function: strupper" << endl;
    string output = strupper("alfa12345zulu");
    if (output.compare("ALFA12345ZULU") != 0)
        cout << "ERROR testing function: strupper (0)" << endl;
}

// /////////

void test_validaValor()
{
    cout << "testing function: ValidaValor" << endl;

    bool ok = ValidaValor("123456.89");
    if (!ok)
        cout << "ERROR testing function: ValidaValor (0)" << endl;

    ok = ValidaValor("123.456.89");
    if (ok)
        cout << "ERROR testing function: ValidaValor (1)" << endl;
}

void test_formataValor()
{
    cout << "testing function: FormataValor" << endl;
    //char *valor101 = "123.89";
    string output = FormataValor("123.89");
    if (output.compare("123.89") != 0)
        cout << "ERROR testing function: FormataValor (0)" << endl;

    string output1 = FormataValor("123.8");
    if (output1.compare("123.80") != 0)
        cout << "ERROR testing function: FormataValor (1)" << endl;

    string output2 = FormataValor("123.");
    if (output2.compare("123.00") != 0)
        cout << "ERROR testing function: FormataValor (2)" << endl;

    string output3 = FormataValor(".");
    if (output3.compare("0.00") != 0)
        cout << "ERROR testing function: FormataValor (3)" << endl;

    string output4 = FormataValor("0.");
    if (output4.compare("0.00") != 0)
        cout << "ERROR testing function: FormataValor (4)" << endl;

    string output5 = FormataValor("");
    if (output5.compare("0.00") != 0)
        cout << "ERROR testing function: FormataValor (5)" << endl;

    string output6 = FormataValor("123");
    if (output6.compare("123.00") != 0)
        cout << "ERROR testing function: FormataValor (6)" << endl;
}

void test_valorNegativo()
{
    cout << "testing function: ValorNegativo" << endl;
    bool negativo = ValorNegativo("-123456.89");
    if (!negativo)
        cout << "ERROR testing function: ValorNegativo (1)" << endl;

    negativo = ValorNegativo("123456.89");
    if (negativo)
        cout << "ERROR testing function: ValorNegativo (3)" << endl;
}

// /////

void test_adicionaSufixoDeGrupoMil()
{
    cout << "testing function: AdicionaSufixoDeGrupoMil" << endl;
    string input = "oito";
    string output = AdicionaSufixoDeGrupoMil(input, 2);
    if (output.compare("oito milhões") != 0)
        cout << "ERROR testing function: AdicionaSufixoDeGrupoMil" << endl;
}

void test_obtemQualificadorParteDecimal()
{
    cout << "testing function: ObtemQualificadorParteDecimal" << endl;
    string input = "123";
    string output = ObtemQualificadorParteDecimal(input, false);
    if (output.compare("centimos") != 0)
        cout << "ERROR testing function: ObtemQualificadorParteDecimal" << endl;
}

void test_obtemQualificadorParteInteira()
{
    cout << "testing function: ObtemQualificadorParteInteira" << endl;
    string input = "123";
    string output = ObtemQualificadorParteInteira(input, false);
    if (output.compare("euros") != 0)
        cout << "ERROR testing function: ObtemQualificadorParteInteira" << endl;
}

void test_obtemCentenas()
{
    cout << "testing function: ObtemCentenas" << endl;
    string output = ObtemCentenas(2, 1, 3);
    if (output.compare("duzentos") != 0)
        cout << "ERROR testing function: ObtemCentenas (1)" << endl;

    output = ObtemCentenas(1, 0, 0);  //new
    if (output.compare("cem") != 0) //new
        cout << "ERROR testing function: ObtemCentenas (2)" << endl; //new
}

void test_obtemDezenas()
{
    cout << "testing function: ObtemDezenas" << endl;
    string output = ObtemDezenas(1, 2);
    if (output.compare("doze") != 0)
        cout << "ERROR testing function: ObtemDezenas (1)" << endl;

    output = ObtemDezenas(2, 1); //new
    if (output.compare("vinte") != 0) //new
        cout << "ERROR testing function: ObtemDezenas (2)" << endl; //new
}

void test_obtemUnidades()
{
    cout << "testing function: ObtemUnidades" << endl;
    string output = ObtemUnidades(8, 2);
    if (output.compare("oito") != 0)
        cout << "ERROR testing function: ObtemUnidades (1)" << endl;

   output = ObtemUnidades(8, 1); //new
    if (output.compare("") != 0) //new
        cout << "ERROR testing function: ObtemUnidades (2)" << endl; //new

}

void test_juntaCentenasDezenasUnidades()
{
    cout << "testing function: JuntaCentenasDezenasUnidades" << endl;
    string output = JuntaCentenasDezenasUnidades("oitocentos", "setenta", "seis");
    if (output.compare("oitocentos e setenta e seis") != 0)
        cout << "ERROR testing function: JuntaCentenasDezenasUnidades" << endl;
}

void test_descodificaCardinal()
{
    cout << "testing function: DescodificaCardinal" << endl;
    string output = DescodificaCardinal("123", 2);
    if (output.compare("cento e vinte e três milhões") != 0)
        cout << "ERROR testing function: DescodificaCardinal" << endl;
}

void test_removeUltimasVirgulasEmExcesso()
{
    cout << "testing function: RemoveUltimasVirgulasEmExcesso" << endl;
    string output = RemoveUltimasVirgulasEmExcesso("123456789, , , ");
    if (output.compare("123456789") != 0)
        cout << "ERROR testing function: RemoveUltimasVirgulasEmExcesso" << endl;
}

void test_juntaTodosGruposDeMil()
{
    cout << "testing function: JuntaTodosGruposDeMil" << endl;

    vector<string> phrases = { "alfa", "beta", "zulu" };
    string output = JuntaTodosGruposDeMil(phrases, false);
    if (output.compare("alfa, beta e zulu") != 0)
        cout << "ERROR testing function: JuntaTodosGruposDeMil" << endl;
}

void test_divideEmGruposDeMil()
{
    cout << "testing function: DivideEmGruposDeMil" << endl;

    vector<string> resultado = DivideEmGruposDeMil("123456789012345");
    int sizegrp = resultado.size();

    if (sizegrp != 5)
        cout << "ERROR testing function: DivideEmGruposDeMil (n)" << endl;

    string g0 = resultado[0];
    string g1 = resultado[1];
    string g2 = resultado[2];
    string g3 = resultado[3];
    string g4 = resultado[4];
    if (g0.compare("123") != 0)
        cout << "ERROR testing function: DivideEmGruposDeMil (0)" << endl;
    if (g1.compare("456") != 0)
        cout << "ERROR testing function: DivideEmGruposDeMil (1)" << endl;
    if (g2.compare("789") != 0)
        cout << "ERROR testing function: DivideEmGruposDeMil (2)" << endl;
    if (g3.compare("012") != 0)
        cout << "ERROR testing function: DivideEmGruposDeMil (3)" << endl;
    if (g4.compare("345") != 0)
        cout << "ERROR testing function: DivideEmGruposDeMil (4)" << endl;
}

void test_divideEmPartesInteiraDecimal()
{
    cout << "testing function: DivideEmPartesInteiraDecimal" << endl;

    vector<string> resultado = DivideEmPartesInteiraDecimal("1234567.89");
    string p10 = resultado[0];
    string p11 = resultado[1];
    if (p10.compare("1234567") != 0)
        cout << "ERROR testing function: DivideEmPartesInteiraDecimal (0)" << endl;
    if (p11.compare("89") != 0)
        cout << "ERROR testing function: DivideEmPartesInteiraDecimal (1)" << endl;
}

void test_converte(void)
{
    cout << "testing function: Converte" << endl;
    string input = "123456789.87";
    string output = Converte(input, false, false);
    if (output.compare("cento e vinte e três milhões, quatrocentos e cinquenta e seis mil, setecentos e oitenta e nove euros e oitenta e sete centimos") != 0)
        cout << "ERROR testing function: Converte (0)" << endl;
}
