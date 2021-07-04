#include <iostream>
#include <fstream>

using namespace std;

fstream myFyle;
void gravar(tLista* pLista){
    float data;

    myFyle.open("database.txt", ios::out);
    pLista->marcador = pLista->primeiro;

    while(!finalLista(pLista)){
        data = pLista->marcador->info;
        myFyle << "\n" << data << " ";
        pLista->marcador = pLista->marcador->proximo;

        data = pLista->marcador->info;
        myFyle << data << " ";
        pLista->marcador = pLista->marcador->proximo;

        data = pLista->marcador->info;
        myFyle << data;
        pLista->marcador = pLista->marcador->proximo;
    }

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

