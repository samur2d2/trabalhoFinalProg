//LANCEI O DESAFIO
//CADA ERRO É 1 SHOT DE CACHAÇA
//"Let the game begin!" - Jigsaw
//Total de perdas: 5 shots

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include "investimento.h"

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
    cout << "\t |                 Samuel Ribeiro - 05/21  |" << endl;
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

    FirstWindow();

    SecondWindow();

    tInvestimento object;


    bool close = true;
    do{
        object.DefiningCapital();
        object.DefiningTime();
        object.DefiningRate();
        object.ConvertRate();
        object.SimpleInterest();
        system("pause");
        RunAgain();

    }while ((close ==true ));
}
