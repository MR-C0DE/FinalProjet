
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Fonction.h"

using namespace std;

int main()
{ 
    //la variable confirmation permet d'arreter ou de continuer le programme.
   int confirmation = 1;
   try {
       do {
           menu();
           cout << "Appuyez sur 1 pour continuer, utilisez une autre touche pour arreter : ";
           cin >> confirmation;

       } while (confirmation == 1);
   }
   catch (exception const& exception) {

       cout << "Erreur : " << exception.what() << endl;

    }

    
   return 0;
}
