
#include<iostream>
#include <fstream>
using namespace std;


ifstream fin("matrice.txt");

char grid[5][5];
char keyword[26];
char msg[100];
int mark[130],len,r,c;


void initialize();

void initialize()
{
    memset(mark,0,sizeof(mark));
}

void decipher()
{

    for(int i = 1;i<=5;i++) {
        for(int j = 1;j<=5;j++) {
            fin >> grid[i][j];
        }
    }
    initialize();
    cout<<"Cypher text: ";
    char cypText[150];
    cin.getline(cypText, 151);
    int l=strlen(cypText);
    
    cout<<"Decipher text: ";
    int P,Q,S,f1,f2;
    char x,y;
    int R[l+l+2],C[l+l+2];
    P=0;
    Q=0;
    for(int i=0;i<l/2;i++)
    {
        for(int k=0;k<5;k++)
        {
            for(int m=0;m<5;m++)
            {
                if(cypText[i]==grid[k][m])
                {
                    R[P]=k;
                    P++;
                    R[P]=m;
                    P++;
                    break;
                }
            }
        }
    }
    int index=0;
    for(int i=l/2;i<l;i++)
    {
        for(int k=0;k<5;k++)
        {
            for(int m=0;m<5;m++)
            {
                if(cypText[i]==grid[k][m])
                {
                    C[index++]=k;
                    C[index++]=m;
                    break;
                }
            }
        }
    }
    for(int i=0;i<index;i++)
        cout<<grid[R[i]][C[i]];
    cout<<endl<<endl;
    
}
void encipher()
{

    for(int i = 1;i<=5;i++) {
        for(int j = 1;j<=5;j++) {
            fin >> grid[i][j];
        }
    }

    initialize();
    int l=strlen(msg);
    char reqText[150];
    int in=0,j=0;
    for(int i=0;i<l;i++)
    {
        j=i+1;
        if(msg[i]==' ')
        {
            i++;
            j++;
        }
        if(msg[j]==' ') j++;
        if(toupper(msg[i])=='J') msg[i]='i';
        if(toupper(msg[i])==toupper(msg[j]))
        {
            reqText[in]=toupper(msg[i]);
            reqText[in+1]='X';
            in++;
        }
        else
        {
            reqText[in]=toupper(msg[i]);
        }
        in++;
    }
    if(in%2!=0)
    {
        reqText[in++]='X';
    }
    
    cout<<"Cypher text: ";
    int P,Q,R,S,f1,f2;
    char x,y;
    int mat[in+in+2];
    P=0;
    Q=in;
    for(int i=0;i<in;i++)
    {
        for(int k=0;k<5;k++)
        {
            for(int m=0;m<5;m++)
            {
                if(reqText[i]==grid[k][m])
                {
                    mat[P++]=k;
                    mat[Q++]=m;
                    break;
                }
            }
        }
    }
    for(int i=0;i<in+in;i+=2)
        cout<<grid[mat[i]][mat[i+1]];
    cout<<endl<<endl;
}


int main()
{


    cin.getline(msg, 101);

    int choose;
    cin >> choose;
    
    
    if(choose == 1) {
        encipher();
    } if(choose == 2) {
        decipher();
    }
    return 0;
}
