#include <iostream>
#include <string>
using namespace std;

char word[1001];



//algoritmul de criptare
void Encrypt(int shift) {
    string result;
    int i = 0;
    while (word[i] != '\0')
    {
        char ch = word[i];
        if (isupper(ch)) // daca literele sunt mari
        {
            ch = ((ch + shift - 'A' + 26) % 26) + 'A'; //cifrul
            result += ch;//adaugarea la rezultat
        }
        else if (ch >= 'a' && ch <= 'z') //daca literele sunt mici
        {
            ch = ((ch + shift - 'A' + 26) % 26) + 'a'; //cifrul
            result += ch;//adaugarea la rezultat
        }
        i++;//incrementarea pozitiei sirului de caracter
    }
    cout << result;
}

void Decrypt(int shift) {
    string result;
    int i = 0;
    while (word[i] != '\0')
    {
        char ch = word[i];
        if (isupper(ch)) // daca literele sunt mari
        {
            ch = ((ch - shift - 'A' + 26) % 26) + 'A'; //cifrul doar ca mergem de la dreapta la stanga
            result += ch;//adaugarea la rezultat
        }
        else if (ch >= 'a' && ch <= 'z') //daca literele sunt mici
        {
            ch = ((ch - shift - 'A' + 26) % 26) + 'a'; //cifrul
            result += ch;//adaugarea la rezultat
        }
        i++;//incrementarea pozitiei sirului de caracter
    }
    cout << result;
}

int main() {
    
    cout << "Mesaj: " << endl;
    cin.getline(word, 1001);
    cout << "1.Criptare \n2.Decriptare" << endl;
    int metoda;
    cin >> metoda;
    if(metoda == 1) {
        for(int i = 0;i<27;i++) { // criptarea de la 0 la 27
            cout << "Decrypting " << word << " with key " << i << " : ";
            Encrypt(i);
            cout << endl;
        }
    } else {
        for(int i = 0;i<27;i++) { // criptarea de la 0 la 27
            cout << "Encrypting " << word << " with key " << i << " : ";
            Decrypt(i);
            cout << endl;
        }
    }
}
