#include <iostream>
#include <iomanip>

using namespace std;

struct tNo{
    float info;
    tNo* proximo;
};
//---------------------------------------------------------------------------------------------------
struct tLista{
    tNo* primeiro;
    tNo* ultimo;
    tNo* marcador;
    int tamanho;
};
//---------------------------------------------------------------------------------------------------
void iniciarLista(tLista* pLista){
    pLista->primeiro = NULL;
    pLista->ultimo = NULL;
    pLista->marcador = NULL;
    pLista->tamanho = 0;
}
//---------------------------------------------------------------------------------------------------
int obterTamanho(tLista* pLista){
    return (pLista->tamanho);
}
//---------------------------------------------------------------------------------------------------
bool listaVazia(tLista* pLista){
    return (pLista->tamanho==0);
}
//---------------------------------------------------------------------------------------------------
bool finalLista(tLista* pLista){
    return (pLista->marcador == NULL);
}
//---------------------------------------------------------------------------------------------------
tNo* criaNo(float item){
    tNo* no = new tNo;

    no->info = item;
    no->proximo = NULL;

    return no;
}
//---------------------------------------------------------------------------------------------------
void incluirElemento(tLista* pLista, float info){
    tNo* no;
    no = criaNo(info);

    if (listaVazia(pLista)){pLista->primeiro = no;}
    else{pLista->ultimo->proximo = no;}

    pLista->ultimo = no;
    pLista->marcador = no;
    pLista->tamanho++;
}
//---------------------------------------------------------------------------------------------------
void imprimirLista(tLista* pLista){
    system("cls");
    for (int i=0; i<3; i++){cout << endl;}
    pLista->marcador = pLista->primeiro;
    float informacao;

    cout << "\t +------------------------------------------+" << endl;
    cout << "\t |                                          |" << endl;
    cout << "\t |    INFORMATIONS ABOUT THE INVESTMENT     |" << endl;
    cout << "\t |                                          |" << endl;
    while(!finalLista(pLista)){
        cout << "\t +------------------------------------------+" << endl;
        cout << "\t |                                          |" << endl;
        informacao = pLista->marcador->info;
        cout << "\t |     Starting Capital: " << setw(10) << informacao << " R$      |" << endl;
        pLista->marcador = pLista->marcador->proximo;

        informacao = pLista->marcador->info;
        cout << "\t |     Application Time: " << setw(10) <<informacao << " years   |" << endl;
        pLista->marcador = pLista->marcador->proximo;

        informacao = pLista->marcador->info;
        cout << "\t |           Anual Rate: " << setw(10) <<informacao*100 << " %       |" << endl;
        pLista->marcador = pLista->marcador->proximo;
        cout << "\t |                                          |" << endl;
    }
    cout << "\t +------------------------------------------+" << endl;
    cout << endl;
}
//---------------------------------------------------------------------------------------------------
void DellElements(tLista* pLista, int pos){
    tNo* anterior;
    tNo* aux;

    if(!listaVazia(pLista)){
        pLista->marcador = pLista->primeiro;

        if(pos < obterTamanho(pLista)){

            if (pos==0){pLista->primeiro = pLista->marcador->proximo;}
            else{
                anterior = pLista->marcador;
                pLista->marcador = pLista->marcador->proximo;
                aux = pLista->marcador->proximo;
            }
            anterior->proximo = aux;

        }
    }
}


