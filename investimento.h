#ifndef tInvestimento_h
#define tInvestimento_h
#include <math.h>
#include <iomanip>
#include <iostream>

using namespace std;

//consulta realizada dia 20/06/2021 no site do tesouro direto e nubank;
const float cdbRate[3] = {0.003586, 0.021714, 0.0439}; //rendimento de 2019; anual[2] mensal[0
const float cdiRate[3] = {0.002263, 0.013656, 0.0275}; //rendimento acumulado dos ultimos 12 meses; anual[2] mensal[0]
const float poupancaRate[3] = {0.003626, 0.021958, 0.0444}; //rendimento médio; anual[2] mensal[0]
const float TS2024Rate[3] = {0.004566, 0.027715, 0.0562}; //tesouro selic 2024;

typedef struct{
    float startingCapital=0;
    float rate[3]={0}; //mensal[0], semestral[1] and anual[2];
    float time=0;
    float simpleInterest=0; //simple interest income
    float simpleAmount=0; //amount applied to simple interest
    float compoundInterest=0;
    float compoundAmount=0;
    float cdiInterest, cdbInterest, poupancaInterest, ts2024Interest;
    float cdiAmount, cdbAmount, poupancaAmount, ts2024Amount;
    int type=0;
}DefValues;

typedef struct{
    DefValues value;
//----------------------------------------------------------------------------------------------------
float DefiningCapital(){
    system("cls");
    for (int i=0; i<3; i++){cout << endl;}
    cout << "\t +------------------------------------------------+" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t |          PLEASE TELL ME HOW MUCH YOU           |" << endl;
    cout << "\t |           HAVE TO INVEST HIGH NOW              |" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t +------------------------------------------------+" << endl;
    cout << "\t   I have: R$ "; cin >> value.startingCapital;
    return (value.startingCapital);
}
//----------------------------------------------------------------------------------------------------
float DefiningRate(){
    system("cls");
    for (int i=0; i<3; i++){cout << endl;}
    cout << "\t +------------------------------------------------+" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t |        PLEASE TELL ME, IN PERCENTAGE,          |" << endl;
    cout << "\t |       WHAT IS THE ANUAL INTEREST RATE          |" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t +------------------------------------------------+" << endl;
    cout << "\t   The rate is: "; cin >> value.rate[2];
    value.rate[2] = value.rate[2] / 100;
    return (value.rate[2]);
}
//----------------------------------------------------------------------------------------------------
float TimesToRun(){
    system("cls");
    int numberItens=0;
    for (int i=0; i<3; i++){cout << endl;}
    cout << "\t +--------------------------------------------+" << endl;
    cout << "\t |                                            |" << endl;
    cout << "\t |         PLEASE TELL ME HOW MUCH            |" << endl;
    cout << "\t |       INFORMATIONS YOU WANT TO ADD         |" << endl;
    cout << "\t |                                            |" << endl;
    cout << "\t |        (including starting capital,        |" << endl;
    cout << "\t |              rate and time )               |" << endl;
    cout << "\t |                                            |" << endl;
    cout << "\t +--------------------------------------------+" << endl;
    cout << "\t   I want: "; cin >> numberItens;
    return (numberItens);
}
//----------------------------------------------------------------------------------------------------
float DefiningTime(){
    system("cls");
    for (int i=0; i<3; i++){cout << endl;}
    cout << "\t +------------------------------------------------+" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t |      PLEASE TELL ME WHAT IS                    |" << endl;
    cout << "\t |      THE TIME OF THE APLICATION                |" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t +------------------------------------------------+" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t |    - FIRST YOU TELL ME THE TIME.               |" << endl;
    cout << "\t |    - THEN YOU TELL ME IF THE NUMBER IS         |" << endl;
    cout << "\t |      IN YEARS (enter 1) OR MONTHS (enter 2).   |" << endl;
    cout << "\t |                                                |" << endl;
    cout << "\t +------------------------------------------------+" << endl;
    cout << "\t   Time: "; cin >> value.time;
    cout << "\t   Type: "; cin >> value.type;
    if (value.type == 2){
        value.time = value.time/12;
    }
    return (value.time);
}
//----------------------------------------------------------------------------------------------------
}tInvestimento;

#endif
