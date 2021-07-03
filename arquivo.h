#include <iostream>
#include <fstream>

using namespace std;

fstream myFyle;//declara uma variavel pra abrir o arquivo;
void gravar(){
    //cria um arquivo limpo e escreve nele;
    myFyle.open("database.txt", ios::out);
    myFyle << "Hello";
    myFyle.close();
}
void adicionar(){
    //abre um arquivo existente e adiciona nele outras coisas;
    myFyle.open("database.txt", ios::app);
    myFyle << "\nworld";
    myFyle.close();
}
void ler(){
    //cria um arquivo limpo e escreve nele;
    myFyle.open("database.txt", ios::in);
    string c;
    if(myFyle.is_open()){
        while(!myFyle.eof()) {
            myFyle >> c;
            cout << c << endl;
        }
    }else{cout << "error...";}
    myFyle.close();
    system("pause");
}

