
/************************************************************
 Program: Bifid cypher encoder
 Author: Mujtaba Asif
 e-Mail: mjtbasif@gmail.com
 Date: 11/22/2017
 ************************************************************/
// *~~~~~~~~ header declaration ~~~~~~~~~~* //
#include<iostream>

using namespace std;

// *~~~~~~~~ variable declaration ~~~~~~~~~~* //
char grid[5][5]; // 5x5  matrix to encipher or decipher
char keyword[26]; // cypher key
char msg[100]; // message
int mark[130],len,r,c; // necessary variables

// *~~~~~~~~~ Function declaration ~~~~~~~~~~~* //
void createGrid();
void showGrid();
void encipher();
void decipher();
void initialize();
void menu()
{
    system("CLS");
    int n;
    string op[]={"1. Encipher","2. Decipher","3. Exit"};
    cout<<op[0]<<endl<<op[1]<<endl<<op[2]<<endl<<"Enter choice: ";
    cin>>n;
    if(n==1) encipher();
    else if(n==2) decipher();
    else exit(1);
}
void initialize()
{
    memset(mark,0,sizeof(mark));
    system("CLS");
}
int main()
{
    menu();
    return 0;
}
void decipher()
{
    initialize();
    createGrid();
    cout<<"Cypher text: ";
    char cypText[150]; // cypher text
    cin>>cypText;
    getchar(); // flush buffer
    int l=strlen(cypText); //take length
    
    /*
     showGrid();
     for(int i=0;i<l;i+=2)
     cout<<cypText[i]<<cypText[i+1]<<" ";
     cout<<endl;
     */
    cout<<"Decipher text: ";
    //decipher starts
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
        //cout<<cypText[i]<<" ";
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
    system("PAUSE");
    menu();
}
void encipher()
{
    initialize();
    createGrid();
    cout<<"Message to cypher: ";
    gets(msg);
    int l=strlen(msg); // msg length
    char reqText[150]; //generate required text to encipher
    int in=0,j=0;
    for(int i=0;i<l;i++)
    {
        j=i+1;
        if(msg[i]==' ') //ignore all space from string
        {
            i++;
            j++;
        }
        if(msg[j]==' ') j++; //ignore space
        if(toupper(msg[i])=='J') msg[i]='i'; // ignore J
        if(toupper(msg[i])==toupper(msg[j])) // if duplicate add 'X' after the first letter
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
    //cout<<in<<endl;
    if(in%2!=0)
    {
        //cout<<"added X"<<endl;
        reqText[in++]='X'; // if one character left, add 'X' after it
    }
    
    /*
     //show generated text in pair
     for(int i=0;i<in;i+=2)
     cout<<reqText[i]<<reqText[i+1]<<" ";
     cout<<endl;
     */
    
    //showGrid();
    cout<<"Cypher text: ";
    //encipher starts
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
    system("PAUSE");
    menu();
}
void createGrid()
{
    cout<<"Keyword: ";
    cin>>keyword; // key of the cypher
    getchar();
    len=strlen(keyword);  // size of input string O(n) :3
    mark['J']=1; // ignore J
    r=0,c=0; //initialize row and column
    
    // first populate the keyword
    for(int i=0;i<len;i++)
    {
        if(!mark[toupper(keyword[i])]) // ignore duplicates
        {
            mark[toupper(keyword[i])]=1;
            grid[r][c++]=toupper(keyword[i]);
            if(c%5==0) //increase row column
            {
                c=0;
                r++;
            }
        }
    }
    
    // complete rest of the matrix from unused characters starting from A
    for(int i='A';i<='Z';i++)
    {
        if(mark[i]==0) // taking values that are not in the matrix already
        {
            grid[r][c++]=i;
            mark[i]=1;
            if(c%5==0)
            {
                if(r==4 && c==5) break; //matrix populated
                
                // else increase row column
                r++;
                c=0;
            }
        }
    }
}
void showGrid()
{
    cout<<"5x5 Matrix"<<endl;
    //show grid
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}


