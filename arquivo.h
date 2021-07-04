#include <iostream>
#include <fstream>

using namespace std;

fstream myFyle;
void writeOnANewFile(tLista* pLista){
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
void addNewElements(tLista* pLista){
    float data;

    myFyle.open("database.txt", ios::app);
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
void readTheFile(tLista* pLista){
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

