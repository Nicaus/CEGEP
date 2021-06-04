#include <iostream>
#include <conio.h>
#include <string>


using namespace std;

/*

    LE TYEP STRING ET L'OPÉRATEUR []

    - L'opérateur [] permet d'accéder aux caractères de la string comme un tableau

    - Attention:
        - l'indice doit être entre [ 0 .. size() - 1 ] 

*/

int main()
{
    // EXEMPLE #1 -- lecture des caractères d'une string avec l'opérateur []

    string s;
    char c;

    s = "Bonjour";
    for (int i = 0; i < s.size(); ++i)
    {
        c = s[i];
        cout << c;
    }
    cout << endl;


    // EXEMPLE #2 -- remplacement des caractères d'une string avec l'opérateur []

    s = "informatique";
    for (int i = 0; i < s.size(); ++i)
    {
        s[i] = toupper(s[i]);
    }
    cout << s << endl;


    // EXEMPLE #3 -- Attention: accès interdit

    s = "01234";

    // s[i] = 'A';  // erreur si:  i >= s.size()  ou  i < 0


	_getch();
}