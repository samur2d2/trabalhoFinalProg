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
float ConvertRate(){
    value.rate[0] = pow((1+value.rate[2]), 1.0/12) - 1;//to convert to mensal rate
    return(value.rate[0]);
    //value.rate[1] = pow((1+value.rate[2]), 1.0/2) - 1; //to convert to semestral rate
}
//----------------------------------------------------------------------------------------------------
    void SimpleInterest(){
        system("cls");
        cout << endl;
        cout << "\t    +-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+" << endl;
        cout << "\t    |                       |                       |                       |                       |                       |                       |" << endl;
        cout << "\t    |    SIMPLE INTEREST    |   COMPOUND INTEREST   |  TESOURO SELIC 2024   |          CDI          |          CBD          |      BANK SAVING      |" << endl;
        cout << "\t    |                       |                       |                       |                       |                       |                       |" << endl;
        cout << "\t    +-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+" << endl;
        cout << "\t    |    M. rate: " << setw(5) <<(value.rate[2]*100/12) << "%    |";
        cout << "    M. rate: " << setw(5) << (value.rate[0]*100) << "%    |";
        cout << "    M. rate: " << setw(5) << (TS2024Rate[0]*100) << "%    |";
        cout << "    M. rate: " << setw(5) << (cdiRate[0]*100) << "%    |";
        cout << "    M. rate: " << setw(5) <<(cdbRate[0]*100) << "%    |";
        cout << "    M. rate: " << setw(5) << (poupancaRate[0]*100) << "%    |" << endl;
        cout << "\t    |    S. rate: " << setw(5) <<(value.rate[2]*100/2) << "%    |";
        cout << "    S. rate: " << setw(5) << (value.rate[1]*100) << "%    |";
        cout << "    S. rate: " << setw(5) << (TS2024Rate[1]*100) << "%    |";
        cout << "    S. rate: " << setw(5) << (cdiRate[1]*100) << "%    |";
        cout << "    S. rate: " << setw(5) <<(cdbRate[1]*100) << "%    |";
        cout << "    S. rate: " << setw(5) << (poupancaRate[1]*100) << "%    |" << endl;
        cout << "\t    |    A. rate: " << setw(5) <<(value.rate[2]*100) << "%    |";
        cout << "    A. rate: " << setw(5) << (value.rate[2]*100) << "%    |";
        cout << "    A. rate: " << setw(5) << (TS2024Rate[2]*100) << "%    |";
        cout << "    A. rate: " << setw(5) << (cdiRate[2]*100) << "%    |";
        cout << "    A. rate: " << setw(5) <<(cdbRate[2]*100) << "%    |";
        cout << "    A. rate: " << setw(5) << (poupancaRate[2]*100) << "%    |" << endl;
        cout << "  +---------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|" << endl;
        if ((value.time >= 0) && (value.time <= 2)){ //ate um ano calcula cada mes

            cout << "  |  MONTH  | INTEREST       AMOUNT | INTEREST       AMOUNT | INTEREST       AMOUNT | INTEREST       AMOUNT | INTEREST       AMOUNT | INTEREST       AMOUNT |" << endl;
            cout << "  |---------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|" << endl;
            for (int t=1; t<=(value.time*12); t++){
                //CALCULA O JURO SIMPLES E O MONTANTE
                value.simpleInterest = value.startingCapital * (value.rate[2]/12) * t;
                value.simpleAmount = value.startingCapital + value.simpleInterest;
                //CALCULA O JURO COMPOSTO E O MONTANTE
                value.compoundInterest = value.startingCapital * (pow((1+value.rate[0]),t) - 1);
                value.compoundAmount = value.startingCapital + value.compoundInterest;
                //CALCULA O JURO COMPOSTO DO TESOURO SELIC 2024 E O MONTANTE
                value.ts2024Interest = value.startingCapital * (pow((1+TS2024Rate[0]),t) - 1);
                value.ts2024Amount = value.startingCapital + value.ts2024Interest;
                //CALCULA O JURO COMPOSTO DO TESOURO CDI E O MONTANTE
                value.cdiInterest = value.startingCapital * (pow((1+cdiRate[0]),t) - 1);
                value.cdiAmount = value.startingCapital + value.cdiInterest;
                //CALCULA O JURO COMPOSTO DO TESOURO CDB E O MONTANTE
                value.cdbInterest = value.startingCapital * (pow((1+cdbRate[0]),t) - 1);
                value.cdbAmount = value.startingCapital + value.cdbInterest;
                //CALCULA O JURO COMPOSTO DO TESOURO POUPANÇA E O MONTANTE
                value.poupancaInterest = value.startingCapital * (pow((1+poupancaRate[0]),t) - 1);
                value.poupancaAmount = value.startingCapital + value.poupancaInterest;

                cout << "  |" << setw(6) << t << "   |";
                cout << setw(9) << value.simpleInterest << setw(13) << value.simpleAmount << " |";
                cout << setw(9) << value.compoundInterest << setw(13) << value.compoundAmount << " |";
                cout << setw(9) << value.ts2024Interest << setw(13) << value.ts2024Amount << " |";
                cout << setw(9) << value.cdiInterest << setw(13) << value.cdiAmount << " |";
                cout << setw(9) << value.cdbInterest << setw(13) << value.cdbAmount << " |";
                cout << setw(9) << value.poupancaInterest << setw(13) << value.poupancaAmount << " |" << endl;
            }
        }else if ((value.time > 2) && (value.time <= 10)){ //de um a dez anos calcula cada 6 meses
            int aux = 0;
            cout << "  |  YEAR   | INTEREST       AMOUNT | INTEREST       AMOUNT | INTEREST       AMOUNT | INTEREST       AMOUNT | INTEREST       AMOUNT | INTEREST       AMOUNT |" << endl;
            cout << "  |---------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|" << endl;
            for (int t=1; t<=(value.time*2); t++){
                //CALCULA O JURO SIMPLES E O MONTANTE
                value.simpleInterest = value.startingCapital * (value.rate[2]/2) * t;
                value.simpleAmount = value.startingCapital + value.simpleInterest;
                //CALCULA O JURO COMPOSTO E O MONTANTE
                value.compoundInterest = value.startingCapital * (pow((1+value.rate[1]),t) - 1);
                value.compoundAmount = value.startingCapital + value.compoundInterest;
                //CALCULA O JURO COMPOSTO DO TESOURO SELIC 2024 E O MONTANTE
                value.ts2024Interest = value.startingCapital * (pow((1+TS2024Rate[1]),t) - 1);
                value.ts2024Amount = value.startingCapital + value.ts2024Interest;
                //CALCULA O JURO COMPOSTO DO TESOURO CDI E O MONTANTE
                value.cdiInterest = value.startingCapital * (pow((1+cdiRate[1]),t) - 1);
                value.cdiAmount = value.startingCapital + value.cdiInterest;
                //CALCULA O JURO COMPOSTO DO TESOURO CDB E O MONTANTE
                value.cdbInterest = value.startingCapital * (pow((1+cdiRate[1]),t) - 1);
                value.cdbAmount = value.startingCapital + value.cdbInterest;
                //CALCULA O JURO COMPOSTO DO TESOURO POUPANÇA E O MONTANTE
                value.poupancaInterest = value.startingCapital * (pow((1+cdiRate[1]),t) - 1);
                value.poupancaAmount = value.startingCapital + value.poupancaInterest;



                aux++; if (aux == 3){aux = 1;}
                cout << "  |" << setw(4) << (t+1)/2 << "/" << aux << "   |";
                cout << setw(9) << value.simpleInterest << setw(13) << value.simpleAmount << " |";
                cout << setw(9) << value.compoundInterest << setw(13) << value.compoundAmount << " |";
                cout << setw(9) << value.ts2024Interest << setw(13) << value.ts2024Amount << " |";
                cout << setw(9) << value.cdiInterest << setw(13) << value.cdiAmount << " |";
                cout << setw(9) << value.cdbInterest << setw(13) << value.cdbAmount << " |";
                cout << setw(9) << value.poupancaInterest << setw(13) << value.poupancaAmount << " |" << endl;
            }
        }else if (value.time > 10){ //mais de dez anos calcula cada ano
            cout << "  |  YEAR   | INTEREST       AMOUNT | INTEREST       AMOUNT | INTEREST       AMOUNT | INTEREST       AMOUNT | INTEREST       AMOUNT | INTEREST       AMOUNT |" << endl;
            cout << "  |---------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|" << endl;
            for (int t=1; t<=(value.time); t++){
                //CALCULA O JURO SIMPLES E O MONTANTE
                value.simpleInterest = value.startingCapital * value.rate[2] * t;
                value.simpleAmount = value.startingCapital + value.simpleInterest;
                //CALCULA O JURO COMPOSTO E O MONTANTE
                value.compoundInterest = value.startingCapital * (pow((1+value.rate[2]),t) - 1);
                value.compoundAmount = value.startingCapital + value.compoundInterest;
                //CALCULA O JURO COMPOSTO DO TESOURO SELIC 2024 E O MONTANTE
                value.ts2024Interest = value.startingCapital * (pow((1+TS2024Rate[2]),t) - 1);
                value.ts2024Amount = value.startingCapital + value.ts2024Interest;
                //CALCULA O JURO COMPOSTO DO TESOURO CDI E O MONTANTE
                value.cdiInterest = value.startingCapital * (pow((1+cdiRate[2]),t) - 1);
                value.cdiAmount = value.startingCapital + value.cdiInterest;
                //CALCULA O JURO COMPOSTO DO TESOURO CDB E O MONTANTE
                value.cdbInterest = value.startingCapital * (pow((1+cdbRate[2]),t) - 1);
                value.cdbAmount = value.startingCapital + value.cdbInterest;
                //CALCULA O JURO COMPOSTO DO TESOURO POUPANÇA E O MONTANTE
                value.poupancaInterest = value.startingCapital * (pow((1+poupancaRate[2]),t) - 1);
                value.poupancaAmount = value.startingCapital + value.poupancaInterest;

                cout << "  |" << setw(6) << t << "   |";
                cout << setw(9) << value.simpleInterest << setw(13) << value.simpleAmount << " |";
                cout << setw(9) << value.compoundInterest << setw(13) << value.compoundAmount << " |";
                cout << setw(9) << value.ts2024Interest << setw(13) << value.ts2024Amount << " |";
                cout << setw(9) << value.cdiInterest << setw(13) << value.cdiAmount << " |";
                cout << setw(9) << value.cdbInterest << setw(13) << value.cdbAmount << " |";
                cout << setw(9) << value.poupancaInterest << setw(13) << value.poupancaAmount << " |" << endl;
            }
        }
        cout << "  |---------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|" << endl;
        cout << "  |  TOTAL  |";
        cout << setw(9) << value.simpleInterest << setw(13) << value.simpleAmount << " |";
        cout << setw(9) << value.compoundInterest << setw(13) << value.compoundAmount << " |";
        cout << setw(9) << value.ts2024Interest << setw(13) << value.ts2024Amount << " |";
        cout << setw(9) << value.cdiInterest << setw(13) << value.cdiAmount << " |";
        cout << setw(9) << value.cdbInterest << setw(13) << value.cdbAmount << " |";
        cout << setw(9) << value.poupancaInterest << setw(13) << value.poupancaAmount << " |" << endl;
        cout << "  +---------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
    }
//----------------------------------------------------------------------------------------------------
}tInvestimento;

#endif
