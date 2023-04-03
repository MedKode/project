/*
        POLYBIUS CIPHER
 
 Se bazeaza pe o matrice patratica 5x5;
 Sursa de documentare: https://en.wikipedia.org/wiki/Polybius_square
 1. Algoritmul clasic
 Se bazeaza pe ordinea literelor in alfabet, fiecare 5 litere intra pe cate un rand. Literele J se asimileaza ca litera I, toate literele trebuie sa fie mari. EXEMPLU:
 
    matrice = A B C D E
              F G H I K
              L M N O P
              Q R S T U
              V W X Y Z
 
 Spatiul nu se asimileaza, in cazul criptarii unei fraze, cuvintele se unesc intr-un singur cuvant: ANA ARE MERE devine ANAAREMERE.

 Cifrul Polybius se bazeaza pe indicii de pozitie a fiecarei litera in matrice;
 De exemplu: A -> 1 | 1(randul 1, coloana 1), S -> 4 | 3(randul 3, coloana 3).
 
 2. Algoritmul pe baza de cuvant cheie
    !Cuvantul cheie incepe de pe indicii 1,1 si se continua fara spatiu si fara
 a avea dubluri in matrice.!
    !Trebuie ca toate litere din alfabet sa fie prezente in matrice fara a avea dubluri.!
 
 EXEMPLU:
 Cuvantul cheie: polybius cipher
 Matricea devine:
 
    P O L Y B
    I U S C H
    E R A D F <---- de la litera A pana la Z sunt in ordine alfabetica
    G K M N Q       fara a crea dubluri.
    T V W X Z
 
*/





#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream fin("matrice.txt"); // matricea pe baza de cuvant cheie

char message[101]; // mesajul de criptat
int choice; //alegerea metodei: cifru,criptare,decriptare

int r = 0, c = 0; // randul si coloana fiecarei litere;

char matrice[5][5] = {{'A', 'B', 'C', 'D', 'E'}, {'F', 'G', 'H', 'I', 'K'}, {'L', 'M', 'N', 'O', 'P'}, {'Q', 'R', 'S', 'T', 'U'}, {'V', 'W', 'X', 'Y', 'Z'}}; //matricea polybius clasica

char encryption[5][5]; // folosim matrice pe baza de cuvant cheie, mult mai usor decat sa modificam matricea clasica

//message = D
void CIPHER() { //functia Cifrului PolyBius
    for (int k = 0;message[k] != '\0';k++, cout << " | ") { //pentru fiecare litera din sirul de caractere 'message'
        for(int i = 0;i<5;i++) { //pentru fiecare rand din matrice
            for(int j = 0;j<5;j++) { // pentru fiecare coloana din matrice
                if(matrice[i][j] == message[k]) { // in cazul in care litera din mesajul de criptare se regaseste in matricea polybius
                    r = i; //randul e egal cu indicele de rand al matricei
                    c = j; //coloana e egala cu indicele de coloana al matricei
                }
            }
        }
        cout << r+1 << " " << c+1; //afisam randul si coloana si incrementam deoarece parcurgerea matricei incepe de la 0
        r = 0; //ii dam valoare 0 pentru a lua o noua litera din mesajul de criptare astfel ca ne trebuie un nou rand
        c = 0; // ii dam valoarea 0 pentru a lua o noua litera din mesajul de criptare astfel ca ne trebuie o noua coloana
    }
}


void Encryption() {
    for(int i = 0;i<5;i++) {
        for(int j = 0;j<5;j++) {
            fin >> encryption[i][j]; //citim din fisier
        }
    }
    
    
    for(int k = 0;message[k] != '\0'; k++, cout << " | ") {
        for(int i = 0;i<5;i++) {
            for(int j = 0;j<5;j++) {
                if(encryption[i][j] == message[k]) {
                    r = i;
                    c = j;
                }
            }
        }
        cout << r+1 << " " << c+1;
        r=0;
        c=0;
    }
    
}

void Decript() {
    for(int i = 0;i<5;i++) {
        for(int j = 0;j<5;j++) {
            fin >> encryption[i][j]; //citim din fisier
        }
    }
    //algoritmul de decriptare este la fel ca cel de criptare doar ca indicii de pozitionare sunt dupa tiparul
    //de matrice bazat pe cuvant cheie.
    
    for(int k = 0;message[k] != '\0'; k++, cout << " | ") {
        for(int i = 0;i<5;i++) {
            for(int j = 0;j<5;j++) {
                if(encryption[i][j] == message[k]) {
                    
                    r = i;
                    c = j;
                    cout << encryption[r][c];
                }
            }
        }
        r=0;
        c=0;
    }
    
    
}
int main() {
    cout << "Mesajul de criptat: ";cin.getline(message, 101);
    
    cout << endl;
    cout << "Cifru pentru matricea clasica: ";
    CIPHER();
    cout << endl;
    cout << "Cifru/Criptarea matricea din fisier: ";
    Encryption();
    cout << endl;
    cout << "Decriptare: ";
    Decript();
    cout << endl;
}
