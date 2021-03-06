#include "lecture.h"
#include "fichiers.h"
#include <string.h>



absorp lecture(FILE* file_pf,  int* file_state){// poiteur à mon fichier et pointeur à l'état de mon fichier

    absorp myAbsorp={0};//initialisation à 0 des valeurs AC et DC
    char actualCaractere = 0;//
    int i =0; //indice
    char tramDataStr[21]; //Tableau pour stocker chaque caractère de la tram, taille d'une tram = 21 caratèrere

    if(file_pf == NULL) { //vérification que le fichier est bien lu
        *file_state = EOF; // fin de fichier
        printf("Pas de fichier en entrée de lecture \n");//Affiche une erreur de lecture de fichier
    }else{
        for(i=0; i<21; i++){ //boucle pour obetenir les 21 caractères de la tram
            actualCaractere = (char)fgetc(file_pf); //lecture caractère par caractère et curseur change automatiquement tant que file_pf ouvert
            if(actualCaractere == EOF){ //arrivée au dernie caractère
                *file_state = EOF; //fin de fichier
            }else{
                tramDataStr[i]= (actualCaractere);//remplir la tram dans le tableau
            }
        }
            /*          Exemple format de du tabelau tramDatastr
             *     ____________________________________________________________________________________
             *    [     ACr      | , |       DCr     | , |      ACir     | , |      DCir     |LF |CR ]
             *    [2 | 0 | 8 | 5 | , | 2 | 0 | 3 | 0 | , | 2 | 0 | 2 | 7 | , | 2 | 0 | 3 | 0 |\n |\r ] = tramDataStr en string
             *    [32| 30| 38| 35| 2C| 32| 30| 33| 30| 2C| 32| 30| 33| 37| 2C| 32| 30| 33| 30|0A |0D ] = Correspondance en ASSCI (hexa)
             *    [50| 48| 56| 53| 44| 50| 48| 51| 30| 44| 32| 48| 50| 55| 44| 50| 48| 51| 30|10 |13 ] = Correspondance en int
             *    [0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15| 16| 17| 18|19|20 ] = indice de correspondance dans le tableau
            */

            //-48 pour passer de ASCII à un nombre entier.
            myAbsorp.acr = (float)((tramDataStr[0]-48)*1000 + (tramDataStr[1]-48)*100 + (tramDataStr[2]-48) * 10 + (tramDataStr[3]-48));
            myAbsorp.dcr = (float)((tramDataStr[5]-48)*1000 + (tramDataStr[6]-48)*100 + (tramDataStr[7]-48) * 10 + tramDataStr[8]-48);
            myAbsorp.acir = (float)((tramDataStr[10]-48) *1000 + (tramDataStr[11]-48) * 100 + (tramDataStr[12]-48) * 10 +( tramDataStr[13]-48));
            myAbsorp.dcir = (float)(( tramDataStr[15] -48)*1000 + (tramDataStr[16]-48) * 100 + (tramDataStr[17]-48) * 10 +( tramDataStr[18]-48));

            myAbsorp.acir -=2048 ; //Centrer acir en 0 car avant elles ocillaient entre 0 et 4096
            myAbsorp.acr -= 2048 ;//centrer acr en 0

        }
	return myAbsorp; // return EOF flag
}

