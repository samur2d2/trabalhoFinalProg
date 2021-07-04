#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include "investimento.h"
#include "linkedList.h"
#include "arquivo.h"

using namespace std;

void FirstWindow(){
    char option = ' ';
    system("cls");
    for (int i=0; i<3; i++){cout << endl;}
    cout << "\t +-----------------------------------------+" << endl;
    cout << "\t |                                         |" << endl;
    cout << "\t |    TO EXPERIENCE BETTER PERFORMANCE     |" << endl;
    cout << "\t |     I RECOMMEND USING CODE BLOCKS       |" << endl;
    cout << "\t |                                         |" << endl;
    cout << "\t |                                         |" << endl;
    cout << "\t |    commands like system(cls) may not    |" << endl;
    cout << "\t |        work correctly elsewhere         |" << endl;
    cout << "\t |                                         |" << endl;
    cout << "\t |                                         |" << endl;
    cout << "\t +-----------------------------------------+" << endl;
    cout << "\t |                 Samuel Ribeiro - 07/21  |" << endl;
    cout << "\t +-----------------------------------------+" << endl;
    for (int i=0; i<3; i++){cout << endl;}
    cout << "\t Please enter Y to continue or N to exit: ";
    cin >> option;
    if (toupper(option) == 'Y'){
    }else{exit(EXIT_FAILURE);}

}

//-----------------------------------------------------------------------------------------------------------------

void SecondWindow(){
    system("cls");
    for (int i=0; i<3; i++){cout << endl;}
    cout << "\t +------------------------------------------------+" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t |            IMPORTANT INFORMATIONS              |" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t +------------------------------------------------+" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t |   - I will show you how much your              |" << endl;
    cout << "\t |     money will yield.                          |" << endl;
    cout << "\t |   - I will need you tell me some important     |" << endl;
    cout << "\t |     informations like value and time.          |" << endl;
    cout << "\t |   - Use dot, not comma.                        |" << endl;
    cout << "\t |   - Put the window to full screen.             |" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t +------------------------------------------------+" << endl;
    for (int i=0; i<1; i++){cout << endl;}
    cout << "\t" << system("pause");
}
//-----------------------------------------------------------------------------------------------------------------
int ThirdWindow(){
    int option=0;
    system("cls");
    for (int i=0; i<3; i++){cout << endl;}
    cout << "\t +------------------------------------------------+" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t |     WHAT OPERATION DO YOU WANT TO PERFORM?     |" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t +------------------------------------------------+" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t |   TYPE:                                        |" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t |    1 TO WRITE IN A NEW DATABASE                |" << endl;
    cout << "\t |       - old information will be lost           |" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t |    2 TO WRITE IN AN EXISTING DATABASE          |" << endl;
    cout << "\t |       - add new information to end of file     |" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t |    3 TO READ AN EXISTING DATABASE              |" << endl;
    cout << "\t |       - open an existing file                  |" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t |    0 TO EXIT THE PROGRAM                       |" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t +------------------------------------------------+" << endl;
    cout << "\t   Option: "; cin >> option;
    return(option);
}
//-----------------------------------------------------------------------------------------------------------------
char RunAgain(){
    char option = ' ';
    system("cls");
    for (int i=0; i<3; i++){cout << endl;}
    cout << "\t +---------------------------------------------+" << endl;
    cout << "\t |                                             |" << endl;
    cout << "\t |    DO YOU WANT TO RUN THE PROGRAM AGAIN?    |" << endl;
    cout << "\t |                                             |" << endl;
    cout << "\t +---------------------------------------------+" << endl;
    for (int i=0; i<3; i++){cout << endl;}
    cout << "\t Please enter Y to continue or X to exit: ";
    cin >> option;
    if (toupper(option) == 'Y'){}
    else{exit(EXIT_FAILURE);}
}
//-----------------------------------------------------------------------------------------------------------------
int main() {
    cout << fixed << setprecision(2);

    tLista* pDatas = new tLista;

    iniciarLista(pDatas);

    FirstWindow();

    SecondWindow();

    tInvestimento object;

    bool close = true;
    while (close){
        int option = ThirdWindow();
        if ((option == 1) || (option == 2)){
            int numberItens = object.TimesToRun();
            for (int i=0; i<numberItens; i++){
                float capital = object.DefiningCapital();
                incluirElemento(pDatas, capital);
                float time = object.DefiningTime();
                incluirElemento(pDatas, time);
                float rate = object.DefiningRate();
                incluirElemento(pDatas, rate);
            }
            if (option == 1){
                writeOnANewFile(pDatas);
            }else if(option == 2){
                addNewElements(pDatas);
            }

            int len = obterTamanho(pDatas)-1;
            for(int i=len; i>0; i--){
                DellElements(pDatas, i);
            }
            iniciarLista(pDatas);

        }else if (option == 3){
            readTheFile(pDatas);

            int len = obterTamanho(pDatas)-1;
            for(int i=len; i>0; i--){
                DellElements(pDatas, i);
            }
            iniciarLista(pDatas);
        }else{exit(EXIT_FAILURE);}

    }
}
