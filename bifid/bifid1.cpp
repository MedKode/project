/*
        BIFID CIPHER
 
    Algoritmu BIlFID se bazeaza pe patratul polybius.
 
    Se foloseste acelasi algoritm doar ca in loc de cifru se adauga criptare.
    Astfel ca fiecare litera din mesaj se va cauta in patratul polybius.
 Indicii de rand din fiecare litera a mesajul se vor retine, la fel si indicii coloanei. EX: FLEEATONCE
        4 4 3 3 3 5 3 2 4 3 -- rand
        1 3 5 5 3 1 2 3 2 5 -- coloana
 
    Criptarea se face unind cei doi vectori 4 4 3 3 3 5 3 2 4 3 1 3 5 5 3 1 2 3 2 5, si indicii de pe pozitile impare sunt indicii de rand, iar cei pari sunt cei de coloane, rezultand UAEOLWRINS
 
 
*/





#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <deque>
using namespace std;

ifstream fin("matrice.txt"); // matricea pe baza de cuvant cheie

char message[101]; // mesajul de criptat
int choice; //alegerea metodei: cifru,criptare,decriptare

int r = 0, c = 0; // randul si coloana fiecarei litere;


//criptarea--variabile
int coloane[1001], randuri[1001], indice_coloana=0, indice_randuri=0;
int p, indici[2004];

//o incercare de decriptare
int p_randuri[1001], p_coloane[1001];
int marime_randuri = 0, marime_coloane=0;
int marime_decript =0;



char matrice[5][5] = {{'A', 'B', 'C', 'D', 'E'}, {'F', 'G', 'H', 'I', 'K'}, {'L', 'M', 'N', 'O', 'P'}, {'Q', 'R', 'S', 'T', 'U'}, {'V', 'W', 'X', 'Y', 'Z'}}; //matricea polybius clasica

char encryption[5][5]; // folosim matrice pe baza de cuvant cheie, mult mai usor decat sa modificam matricea clasica



//message = D
void Encript() {

    for(int i = 1;i<=5;i++) {
        for(int j = 1;j<=5;j++) {
            fin >> encryption[i][j]; //citim din fisier
        }
    }//functia Cifrului
    for (int k = 0;message[k] != '\0';k++) { //pentru fiecare litera din sirul de caractere 'message'
        for(int i = 1;i<=5;i++) { //pentru fiecare rand din matrice
            for(int j = 1;j<=5;j++) { // pentru fiecare coloana din matrice
                if(encryption[i][j] == message[k]) { // in cazul in care litera din mesajul de criptare se regaseste in matricea polybius
                    
                    r = i;
                    c = j;
                    
                   randuri[++indice_randuri] = r; //randul e egal cu indicele de rand al matricei
                   coloane[++indice_coloana] = c; //coloana e egala cu indicele de coloana al matricei
                
                    

                }
            }
        }
        //afisam randul si coloana si incrementam deoarece parcurgerea matricei incepe de la 0
        r = 0; //ii dam valoare 0 pentru a lua o noua litera din mesajul de criptare astfel ca ne trebuie un nou rand
        c = 0; // ii dam valoarea 0 pentru a lua o noua litera din mesajul de criptare astfel ca ne trebuie o noua coloana
    }
    int l = (indice_coloana + indice_randuri) - strlen(message);
    for(int i = 1;i<=indice_coloana;i++) {
        randuri[++indice_randuri] = coloane[i];
    }
    
    int k=1, m=2, cont=0;
    while(cont != indice_randuri) {
        cout << encryption[randuri[k]][randuri[m]];
        cont++;
        k+=2;
        m+=2;
    }
}



int main() {
    
    cout << "Mesajul de criptat: ";cin.getline(message, 101);
    if(strlen(message) % 2 == 1) {
        message[strlen(message)+1]= 'X';
    }
    cout << "Criptare: ";
    Encript();
    cout << endl;

}
