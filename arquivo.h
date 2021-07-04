#include <iostream>
#include <fstream>

using namespace std;

fstream myFile;
void writeOnANewFile(tLista* pLista){
    float data;

    myFile.open("database.txt", ios::out);
    pLista->marcador = pLista->primeiro;

    while(!finalLista(pLista)){
        data = pLista->marcador->info;
        myFile << "\n" << data << " ";
        pLista->marcador = pLista->marcador->proximo;

        data = pLista->marcador->info;
        myFile << data << " ";
        pLista->marcador = pLista->marcador->proximo;

        data = pLista->marcador->info;
        myFile << data;
        pLista->marcador = pLista->marcador->proximo;
    }

    myFile.close();
}
void addNewElements(tLista* pLista){
    float data;

    myFile.open("database.txt", ios::app);
    pLista->marcador = pLista->primeiro;

    while(!finalLista(pLista)){
        data = pLista->marcador->info;
        myFile << "\n" << data << " ";
        pLista->marcador = pLista->marcador->proximo;

        data = pLista->marcador->info;
        myFile << data << " ";
        pLista->marcador = pLista->marcador->proximo;

        data = pLista->marcador->info;
        myFile << data;
        pLista->marcador = pLista->marcador->proximo;
    }
    myFile.close();
}
void readTheFile(tLista* pLista){
    pLista->marcador = pLista->primeiro;
    myFile.open("database.txt", ios::in);
    float readData;
    if(myFile.is_open()){
        while(!myFile.eof()) {
            myFile >> readData;
            incluirElemento(pLista, readData);
            myFile >> readData;
            incluirElemento(pLista, readData);
            myFile >> readData;
            incluirElemento(pLista, readData);
        }
        imprimirLista(pLista);
    }else{cout << "error...";}
    myFile.close();
    system("pause");
}

