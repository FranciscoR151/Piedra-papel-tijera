#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <iomanip>
using namespace std;
//Variables globales y arreglos
int perdidas = 0, ganes = 0, empates = 0,puntos=0, perdidasM = 0, ganesM = 0, empatesM = 0,puntosM=0,Njugadores=0,Nmaquinas=0;
char Jugadas[][20] ={"Piedra", "Papel", "Tijera"};
char  Estados[][20] ={"Empate","Perdiste","Ganaste"};
bool Inicio = false;
//Estructuras para usarlos en el histrial del juego
struct Maquinas{
    char Nombre[13],FechaHora[20];
    int Ganes,Empates,Perdidas,Puntos;
}maquinas[100];//Vector maquinas de tipo Maquinas

struct Jugador{
    char Nombre[20],FechaHora[20];
    int Ganes,Empates,Perdidas,Puntos;
}jugador[100];//Vector jugador de tipo Jugador

struct Jugador1{
    char Nombre[20],FechaHora[20];
    int Ganes,Empates,Perdidas,Puntos;
}jugador1[100];//Vector jugador1 de tipo Jugador1

struct Jugador2{
    char Nombre[20],FechaHora[20];
    int Ganes,Empates,Perdidas,Puntos;
}jugador2[100];//Vector jugador2 de tipo Jugador2

int main();//Declaracion de la funcion main

//Metodo para mostrar los puntos
void mostrarPuntos(bool modo){
    if (modo==false){
      cout << jugador1[Njugadores].Nombre << "   Puntos: "<<puntos<< "   Ganadas: " << ganes << "   Perdidas: " << perdidas << "  Empates: " << empates << endl;
      cout<<endl;
      cout << jugador2[Njugadores].Nombre << "   Puntos: "<<puntosM<< "   Ganadas: " << ganesM << "   Perdidas: " << perdidasM << "   Empates: " << empatesM << endl;
    }else{
      cout << maquinas[Nmaquinas].Nombre << "   Puntos: "<<puntosM<< "   Ganadas: " << ganesM << "   Perdidas: " << perdidasM << "   Empates: " << empatesM << endl;
      cout<<endl;
      cout << jugador[Nmaquinas].Nombre << "   Puntos: "<<puntos<< "   Ganadas: " << ganes << "   Perdidas: " << perdidas << "   Empates: " << empates << endl;
}}

void JugadorVSmaquina(){
    bool Salir = false;
    int opcion = 0, contador = 0, x = 0,guardar;

      Nmaquinas++;
      cin.ignore();
      cout << "Ingrese su nombre: "; cin.getline(jugador[Nmaquinas].Nombre,20,'\n');
      strcpy(maquinas[Nmaquinas].Nombre,"DeepBlue2020");//Se agrega el nombre a la maquina
      system("cls");

    while (!Salir){
        fflush(stdin);
        cout << "\n\nIngrese (1) Piedra (2) Papel (3) Tijera (4) Salir" << endl;
        cout << "\nEliga una opcion: "; cin >> opcion;
        x = 1 + rand() % 3;//Numero aleatorio opciones de para la maquina
        system("cls");

        switch (opcion){
            case 1:
                if (x == 1){
                    //Se incrementan los resultados
                    empates++; empatesM++; puntos++;  puntosM++;
                    contador=0;
                }else if (x == 2){
                    perdidas++;  puntosM+=2; ganesM++;
                    contador=1;
                }else if (x == 3){
                    //Se incrementan los resultados
                    ganes++; puntos+=2; perdidasM++; 
                    contador=2;
                }
                mostrarPuntos(true); cout<<"\n\n";
                cout << Estados[contador]<<" elegiste  " << Jugadas[opcion-1] << "    DeepBlue2020 " << Jugadas[x-1] << endl;break;
            case 2:
                if (x == 1){
                    ganes++; perdidasM++; puntos+=2;
                    contador=2;
                }else if (x == 2){
                    //Se incrementan los resultados
                    empates++;  empatesM++;  puntos++;  puntosM++;
                    contador=0;
                }else if(x==3){
                    //Se incrementan los resultados
                    perdidas++; ganesM++; puntosM+=2;
                    contador=1;
                }
                mostrarPuntos(true); cout<<"\n\n";
                cout << Estados[contador]<<" elegiste  " << Jugadas[opcion-1] << "   DeepBlue2020 " << Jugadas[x-1] << endl; break;
            case 3:
                if (x == 1){
                    //Se incrementan los resultados
                    ganesM++;  perdidas++;  puntosM+=2;
                    contador=1;
                }else if (x == 2){
                    perdidasM++; ganes++;
                    puntos+=2;  contador=2;
                }else if(x==3){
                    //Se incrementan los resultados
                    empates++;  empatesM++; puntos++;  puntosM++;
                    contador=0;
                }
                mostrarPuntos(true); cout<<"\n\n";
                cout << Estados[contador]<<"  elegiste " << Jugadas[opcion-1] << "   DeepBlue2020 " << Jugadas[x-1] << endl; break;
            case 4:
                cout << "Desea guardar los resultados 0 (si),1 (no): "; cin >> guardar;//Se pide si quiere guardar los resultados
                system("cls");

                switch (guardar) {
                case 0:
                    cin.ignore();
                    cout<<"\n Ingrese la fecha y hora de hoy para guardar los resultados: ";
                    cin.getline(jugador[Nmaquinas].FechaHora,20,'\n');//Se pide la Fecha y la hora
                    strcpy(maquinas[Nmaquinas].FechaHora,jugador[Nmaquinas].FechaHora);
                    //Se guarda el resultado de cada jugado en el vector maquinas y jugador
                    maquinas[Nmaquinas].Ganes=ganesM;        maquinas[Nmaquinas].Empates=empatesM;
                    maquinas[Nmaquinas].Perdidas=perdidasM;  maquinas[Nmaquinas].Puntos=puntosM;
                    jugador[Nmaquinas].Ganes=ganes;          jugador[Nmaquinas].Empates=empates;
                    jugador[Nmaquinas].Perdidas=perdidas;    jugador[Nmaquinas].Puntos=puntos;
                    //Los contadores pasan a cero
                    ganes=0;     empates=0;
                    perdidas=0;  puntos=0;
                    ganesM=0;    empatesM=0;
                    perdidasM=0; puntosM=0;
                    cout<<"Guardando...\n"; system("timeout 2");
                    cout<<"Los resultados se guardaron correctamente"<<endl; system("timeout 1");
                    Salir = true;
                    main();break;
                default:
                    cout<<"Regresando al menu principal..."<<endl;
                    //Para que los resultados no se guarden todos los arreglos se pone en 0
                    maquinas[Nmaquinas].Ganes=0;    maquinas[Nmaquinas].Empates=0;
                    maquinas[Nmaquinas].Perdidas=0; maquinas[Nmaquinas].Puntos=0;
                    jugador[Nmaquinas].Ganes=0;     jugador[Nmaquinas].Empates=0;
                    jugador[Nmaquinas].Perdidas=0;  jugador[Nmaquinas].Puntos=0;
                    //Los contadores pasan a cero
                    ganes=0;     empates=0;
                    perdidas=0;  puntos=0;
                    ganesM=0;    empatesM=0;
                    perdidasM=0; puntosM=0;
                    Nmaquinas--;
                    system("timeout 2");
                    main();
                } break;
                default: cout<<"La opcion eligida no existe"; system("timeout 3"); break;
}}}

void JugadorVSjugador(){
    bool Salir = false;
    int opcion = 0, x = 0,guardar;

      Njugadores++;
      cin.ignore();
      //Se pide el nombre de el jugador1 y 2
      cout << "Jugador 1, Ingrese su nombre: "; cin.getline(jugador1[Njugadores].Nombre,20,'\n');
      cout << "Jugador 2, Ingrese su nombre: "; cin.getline(jugador2[Njugadores].Nombre,20,'\n');
      system("cls");

    while (!Salir){
        fflush(stdin);
        //Se piden las jugadas de los jugadores
        cout << "\nIngrese (1) Piedra (2) Papel (3) Tijera (4) Salir\n" << endl;
        cout <<jugador1[Njugadores].Nombre<<" Eliga una opcion: "; cin >> opcion;

        cout << "\nIngrese (1) Piedra (2) Papel (3) Tijera (4) Salir\n" << endl;
        cout <<jugador2[Njugadores].Nombre<<" Eliga una opcion: "; cin>>x;
        system("cls");

        switch (opcion){
            case 1:
                if (x == 1){
                    //Se incrementan los resultados
                    empates++; empatesM++; puntos++;  puntosM++;

                    mostrarPuntos(false);
                    cout<<"\n Empates  "<<jugador1[Njugadores].Nombre<<"   Elegiste:  "<<Jugadas[opcion-1]<<endl;
                    cout<<" Empates  "<<jugador2[Njugadores].Nombre<<"   Elegiste:  "<<Jugadas[x-1]<<endl;
                }else if (x == 2){
                    //Se incrementan los resultados
                    perdidas++; puntosM+=2; ganesM++;

                    mostrarPuntos(false);
                    cout<<"\n Pierde  "<<jugador1[Njugadores].Nombre<<"   Elegiste:  "<<Jugadas[opcion-1]<<endl;
                    cout<<" Gana  "<<jugador2[Njugadores].Nombre<<"   Elegiste:  "<<Jugadas[x-1]<<endl;
                }else if (x == 3){
                    ganes++; puntos+=2; perdidasM++; 

                    mostrarPuntos(false);
                    cout<<"\n Gana  "<<jugador1[Njugadores].Nombre<<"   Elegiste:  "<<Jugadas[opcion-1]<<endl;
                    cout<<" Perdio  "<<jugador2[Njugadores].Nombre<<"   Elegiste:  "<<Jugadas[x-1]<<endl;
                }break;
            case 2:
                if (x == 1){
                    //Se incrementan los resultados
                    ganes++; perdidasM++; puntos+=2;
                    mostrarPuntos(false);
                    cout<<"\n Gana  "<<jugador1[Njugadores].Nombre<<"   Elegiste:  "<<Jugadas[opcion-1]<<endl;
                    cout<<" Perdio  "<<jugador2[Njugadores].Nombre<<"   Elegiste:  "<<Jugadas[x-1]<<endl;
                }else if (x == 2){
                    //Se incrementan los resultados
                    empates++;  empatesM++;  puntos++;  puntosM++;

                    mostrarPuntos(false);
                    cout<<"\n Empates  "<<jugador1[Njugadores].Nombre<<"   Elegiste:  "<<Jugadas[opcion-1]<<endl;
                    cout<<" Empates  "<<jugador2[Njugadores].Nombre<<"   Elegiste:  "<<Jugadas[x-1]<<endl;
                }else if(x==3){
                    //Se incrementan los resultados
                    perdidas++;  ganesM++;  puntosM+=2;

                    mostrarPuntos(false);
                    cout<<"\n Pierde  "<<jugador1[Njugadores].Nombre<<"  Elegiste: "<<Jugadas[opcion-1]<<endl;
                    cout<<" Gana  "<<jugador2[Njugadores].Nombre<<"  Elegiste: "<<Jugadas[x-1]<<endl;
                } break;
            case 3:
                if (x == 1){
                    //Se incrementan los resultados
                    ganesM++;  perdidas++;  puntosM+=2;

                    mostrarPuntos(false);
                    cout<<"\n Pierde  "<<jugador1[Njugadores].Nombre<<"  Elegiste: "<<Jugadas[opcion-1]<<endl;
                    cout<<" Gana  "<<jugador2[Njugadores].Nombre<<"  Elegiste: "<<Jugadas[x-1]<<endl;
                }else if (x == 2){
                    //Se incrementan los resultados
                    perdidasM++;  ganes++;  puntos+=2; 

                    mostrarPuntos(false);
                    cout<<"\n Gana  "<<jugador1[Njugadores].Nombre<<"  Elegiste: "<<Jugadas[opcion-1]<<endl;
                    cout<<" Pierde  "<<jugador2[Njugadores].Nombre<<"  Elegiste: "<<Jugadas[x-1]<<endl;
                }else if(x==3){
                    //Se incrementan los resultados
                    empates++;  empatesM++;  puntos++;  puntosM++;

                    mostrarPuntos(false);
                    cout<<"\n Empates  "<<jugador1[Njugadores].Nombre<<"  Elegiste:  "<<Jugadas[opcion-1]<<endl;
                    cout<<" Empates  "<<jugador2[Njugadores].Nombre<<"  Elegiste:  "<<Jugadas[x-1]<<endl;
                } break;
            case 4:
                cout << "Desea guardar los resultados 0 (si),1 (no): "; cin >> guardar;
                system("cls");

                switch (guardar) {
                case 0:
                    cin.ignore();
                    cout<<"\n Ingrese la fecha y hora de hoy para guardar los resultados: ";
                    cin.getline(jugador1[Njugadores].FechaHora,20,'\n');
                    strcpy(jugador2[Njugadores].FechaHora,jugador1[Njugadores].FechaHora);//Se fecha ingresada se guarda tanto en el hitorial de maquina y el de Jugador
                    //Se guarda el resultado de cada jugador en el vector Jugador1 y Jugador2
                    jugador1[Njugadores].Ganes=ganesM;        jugador1[Njugadores].Empates=empatesM;
                    jugador1[Njugadores].Perdidas=perdidasM;  jugador1[Njugadores].Puntos=puntosM;
                    jugador2[Njugadores].Ganes=ganes;         jugador2[Njugadores].Empates=empates;
                    jugador2[Njugadores].Perdidas=perdidas;   jugador2[Njugadores].Puntos=puntos;
                    ganes=0;     empates=0;
                    perdidas=0;  puntos=0;
                    ganesM=0;    empatesM=0;
                    perdidasM=0; puntosM=0;
                    cout<<"Guardando...\n"; system("timeout 2");
                    cout<<"Los resultados se guardaron correctamente"<<endl; system("timeout 1");
                    Salir = true;
                    main();break;
                default:
                    cout<<"Regresando al menu principal..."<<endl;
                    jugador1[Njugadores].Ganes=0;    jugador1[Njugadores].Empates=0;
                    jugador1[Njugadores].Perdidas=0; jugador1[Njugadores].Puntos=0;
                    jugador2[Njugadores].Ganes=0;    jugador2[Njugadores].Empates=0;
                    jugador2[Njugadores].Perdidas=0; jugador2[Njugadores].Puntos=0;
                    ganes=0;     empates=0;
                    perdidas=0;  puntos=0;
                    ganesM=0;    empatesM=0;
                    perdidasM=0; puntosM=0;
                    Njugadores--;
                    system("timeout 2");
                    main();
                } break;
                default:
                 cout<<"La opcion eligida no existe";
                 system("timeout 3"); break;
}}}

void Historial(){
    int opcion;

    while (opcion!=3){
    cout<<"(1) Partida vs Maquina\n(2) Partida vs Jugador\n(3) Regresar al Menu Principal\n\nEliga una opcion: ";cin>>opcion;
    system("cls");

    switch (opcion){
    case 1:
    if (Nmaquinas==0){
       cout<<"\nNo hay historial\n"<<endl;
    }else{//Se imprime el historial de el modo Jugador vs Maquina
    
    for (int i = 1; i <= Nmaquinas; i++){
        cout<<"\n";
        cout<<" Nombre: "<<jugador[i].Nombre<<"   Ganes:  "<<jugador[i].Ganes;
        cout<<"   Perdidas:  "<<jugador[i].Perdidas<<"   Empates:  "<<jugador[i].Empates;
        cout<<"   Puntos:  "<<jugador[i].Puntos<<"   Fecha/hora:  "<<jugador[i].FechaHora;
        cout<<"\n";
        cout<<" Nombre:  "<<maquinas[i].Nombre<<"   Ganes:  "<<maquinas[i].Ganes;
        cout<<"   Perdidas:  "<<maquinas[i].Perdidas<<"   Empates:  "<<maquinas[i].Empates;
        cout<<"   Puntos:  "<<maquinas[i].Puntos<<"   Fecha/hora:  "<<maquinas[i].FechaHora;
        cout<<"\n\n";
    }}break;

    case 2:
    if (Njugadores==0){
       cout<<"\nNo hay historial\n"<<endl;
    }else{//Se imprime el historial de el modo Jugador vs Jugador
    
    for (int i = 1; i <= Njugadores; i++){
        cout<<"\n";
        cout<<" Nombre:  "<<jugador1[i].Nombre<<"   Ganes:  "<<jugador1[i].Ganes;
        cout<<"   Perdidas:  "<<jugador1[i].Perdidas<<"   Empates:  "<<jugador1[i].Empates;
        cout<<"   Puntos:  "<<jugador1[i].Puntos<<"   Fecha/hora:  "<<jugador1[i].FechaHora;
        cout<<"\n";
        cout<<" Nombre:  "<<jugador2[i].Nombre<<"   Ganes:  "<<jugador2[i].Ganes;
        cout<<"   Perdidas: "<<jugador2[i].Perdidas<<"   Empates:  "<<jugador2[i].Empates;
        cout<<"   Puntos:  "<<jugador2[i].Puntos<<"   Fecha/hora:  "<<jugador2[i].FechaHora;
        cout<<"\n\n";
    }}break;
    case 3: main();break;
    default:cout<<"La opcion que ingresaste no existe!"<<endl; break;
}}}


int main(){
    srand(time(NULL));
     int opc = 0;
    system("cls");
    while (!Inicio){
    cout << "\n(1) Partida vs Maquina\n(2) Partida vs jugador2\n(3) Historial del juego\n(4) Cerrar" << endl;
    cout << "\nCual opcion desea elegir: "; cin >> opc; //Se guarda la opcion elegida
    system("cls");

    switch (opc){
    case 1: JugadorVSmaquina(); break;
    case 2: JugadorVSjugador(); break;
    case 3: Historial();
    case 4: Inicio=true; break;
    default: cout<<"La Opcion no existe:\n"; break;

}}
    getch();
    return 0;
}