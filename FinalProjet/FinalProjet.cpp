
#include <iostream>
#include <stdexcept>
#include "Fonction.h"

using namespace std;

int main()
{ 
   int stopOrStart = 1;
   try {
         while (stopOrStart == 1) {
                menu();

                cout << "Continuez [1] & Quittez [autre] : ";
                cin >> stopOrStart;
            }
   }
   catch (exception const& exception) {

       cout << "Erreur : " << exception.what() << endl;

    }

    

   
   

    return 0;
}
