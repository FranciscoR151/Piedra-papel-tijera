#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>
using namespace std;
//Variables globales
//hello world

//Ahora si me apareces unido

string estado[200],resultados[200]; 
//Arreglos para almacenar los resultados de cada jugador
int perdidas = 0, ganes = 0, empates = 0,puntos=0;
int perdidasM = 0, ganesM = 0, empatesM = 0,puntosM=0;
int perdidasJ = 0, ganesJ = 0, empatesj = 0,puntosJ=0;
int Npersonas=1,Njugadores=1;

bool Inicio = false;

//Structura para el historial con maquina
struct HMaquina
{
    string nombre;
    int Ganes;
    int Empates;
    int Perdidas;
    int Puntos;
    string fechaHora;
}historial[100];

//Estructura historial maquina-jugador
struct HMaquina_jugador{
    string nombre;
    int Ganes;
    int Empates;
    int Perdidas;
    int Puntos;
    char fechaHora[20];
}jugador[100];

void MenuPrincipal();

void mostrarPuntos(bool modo){
    cout<<setfill(' ');

    if (modo==false){
      cout<<"Nombre "<<setw(5)<<" Puntos"<<setw(5)<<" Ganes"<<setw(5)<<" Perdidas"<<setw(5)<<" Empates"<<endl;
      cout << jugador[1].nombre<<setw(5)<<puntos<<setw(5)<<ganes<<setw(5)<< perdidas<<setw(5)<< empates << endl;
      cout<<endl;
      cout << jugador[Njugadores].nombre<<setw(5)<<puntosJ<<setw(5)<< ganesM<<setw(5)<< perdidasM<<setw(5)<< empatesM << endl;
    }else{
        cout<<"Nombre "<<setw(5)<<" Puntos"<<setw(5)<<" Ganes"<<setw(5)<<" Perdidas"<<setw(5)<<" Empates"<<endl;
        cout << historial[Npersonas].nombre<<setw(5)<<puntos<<setw(5)<< ganes<<setw(5)<< perdidas<<setw(5)<< empates << endl;
        cout<<endl;
        cout << historial[1].nombre<<setw(5)<<puntosM<<setw(5)<< ganesM<<setw(5)<< perdidasM<<setw(5)<< empatesM << endl;
    }  
}

void JugadorVSmaquina(){
    bool Salir = false;
    int opcion = 0, contador = 0, x = 0,guardar;
    string elige[4] = {"Piedra", "Piedra", "Papel", "Tijera"},fechas;
    string partida[200];
    Npersonas++;
    cout << "Ingrese su nombre de usuario: ";
    //Cargar la estructura HJugadores
    cin>>historial[Npersonas].nombre;
    historial[1].nombre="DeepBlue2020";
    system("cls");
    while (!Salir){
        contador++;
        mostrarPuntos(true);
        cout << "\n\nIngrese (1) Piedra (2) Papel (3) Tijera (4) Salir" << endl;
        cout << "Eliga una opcion: ";
        cin >> opcion;
        system("cls");
        x = 1 + rand() % 3;
        switch (opcion){
            case 1:
                if (x == 1){
                    empates++;
                    empatesM++;
                    puntos++;
                    puntosM++;
                    partida[contador] = "Empate";
                }
                else if (x == 2){
                    perdidas++;
                    puntosM+=2;
                    ganesM++;
                    partida[contador] = "Perdiste";
                }
                else if (x == 3){
                    ganes++;
                    puntos+=2;
                    perdidasM++;
                    partida[contador] = "Ganaste"; 
                }
                cout << partida[contador]<<"  Elegiste " << elige[opcion] << "  La maquina " << elige[x] << endl;
                break;
            case 2:
                if (x == 1){
                    ganes++;
                    perdidasM++;
                    puntos+=2;
                    partida[contador] = "Ganaste";
                }
                else if (x == 2){
                    empates++;
                    empatesM++;
                    puntos++;
                    puntosM++;
                    partida[contador] = "Empate";
                }
                else if(x==3){
                    perdidas++;
                    ganesM++;
                     puntosM+=2;
                    partida[contador] = "Perdiste";
                }
                cout << partida[contador]<<"  Elegiste " << elige[opcion] << "  La maquina " << elige[x] << endl;
                break;
            case 3:
                if (x == 1){
                    ganesM++;
                    perdidas++;
                     puntosM+=2;
                    partida[contador] = "Perdiste";
                }
                else if (x == 2){
                    perdidasM++;
                    ganesM++;
                    puntos+=2;
                    partida[contador] = "Ganaste";
                }
                else if(x==3){
                    empates++;
                    empatesM++;
                    puntos++;
                    puntosM++;
                    partida[contador] = "Empate";
                }
                cout << partida[contador]<<"  Elegiste " << elige[opcion] << "  DeepBlue2020 " << elige[x] << endl;
                break;
            case 4:
                cout << "Desea guardar los resultados 0 (si),1 (no) >>";
                cin >> guardar;
                system("cls");
                if (guardar==0){
                    cout<<"\n Ingrese la fecha y hora de hoy: ";cin>>fechas;
                    cout<<"Guardando...";
                    historial[Npersonas].Ganes=ganes;
                    historial[Npersonas].Empates=empates;
                    historial[Npersonas].Perdidas=perdidas;
                    historial[Npersonas].Puntos=puntos;
                    historial[Npersonas].fechaHora=fechas;
                    historial[1].Ganes=ganesM;
                    historial[1].Empates=empatesM;
                    historial[1].Perdidas=perdidasM;
                    historial[1].Puntos=puntosM;
                    //historial[1].fechaHora[20]=fechas[20];
                    ganes=0;
                    empates=0;
                    perdidas=0;
                    puntos=0;
                    ganesM=0;
                    empatesM=0;
                    perdidasM=0;
                    puntosM=0;
                    cout<<"Los resultados seguradaron correctamente"<<endl;
                    Salir = true;
                    MenuPrincipal();
                }
                else{
                    cout<<"Regresando al menu principal..."<<endl;
                    system("timeout 2");
                    MenuPrincipal();
                }
                break;
                default:
                 cout<<"La opcion eligida no existe";
                 system("timeout 3");
                 system("cls");
                 contador--;
                 break;
}}}

void JugadorVSjugador(){
    bool Salir = false;
    char guardar[1],Fechas[20];
    int opcion = 0, contador = 0, opcion2 = 0;
    string elige[4] = {"Piedra", "Piedra", "Papel", "Tijera"};
    string partida[2];
    Njugadores++;
    cout << "Ingrese su nombre de usuario 1: "; cin>>jugador[1].nombre;
    cout << "Ingrese su nombre de usuario 2: "; cin>>jugador[Njugadores].nombre;
    system("cls");
    while (!Salir){
        contador++;
        cout << "\n\nIngrese (1) Piedra (2) Papel (3) Tijera (4) Salir \nEliga una opcion Jugador 1: "; cin >> opcion;
        system("cls");
        cout << "\n\nIngrese (1) Piedra (2) Papel (3) Tijera (4) Salir \nEliga una opcion Jugador : ";cin >> opcion2;
        system("cls");
        switch (opcion){
            case 1:
                if (opcion2 == 1){
                    empates++;
                    empatesj++;
                    puntos++;
                    puntosJ++;
                    partida[1] = "Empate";
                    partida[2] = "Empate";
                }
                else if (opcion2 == 2){
                    perdidas++;
                    puntosJ+=2;
                    ganesJ++;
                    partida[1] = "Perdiste";
                    partida[2] = "Ganaste"; 
                }
                else if (opcion2 == 3){
                    ganes++;
                    puntos+=2;
                    perdidasJ++;
                    partida[1] = "Ganaste"; 
                    partida[2] = "Perdiste";
                }
                break;
            case 2:
                if (opcion2 == 1){
                    ganes++;
                    perdidasM++;
                    puntos+=2;
                    partida[1] = "Ganaste"; 
                    partida[2] = "Perdiste";
                }
                else if (opcion2 == 2){
                    empates++;
                    empatesM++;
                    puntos++;
                    puntosM++;
                    partida[1] = "Empate";
                    partida[2] = "Empate";
                }
                else if(opcion2==3){
                    perdidas++;
                    ganesJ++;
                    puntosJ+=2;
                    partida[1] = "Perdiste";
                    partida[2] = "Ganaste";
                }
                break;
            case 3:
                if (opcion2 == 1){
                    ganesJ++;
                    perdidas++;
                    puntosJ+=2;
                    partida[1] = "Perdiste";
                    partida[2] = "Ganaste";
                }
                else if (opcion2 == 2){
                    perdidasJ++;
                    ganesJ++;
                    puntos+=2;
                    partida[1] = "Ganaste"; 
                    partida[2] = "Perdiste";
                }
                else if(opcion2==3){
                    empates++;
                    empatesj++;
                    puntos++;
                    puntosJ++;
                    partida[1] = "Empate";
                    partida[2] = "Empate";
                }
                break;
            case 4:
                cout << "Desea guardar los resultados S (si),N (no) >>";
                cin >> guardar;
                cout<<"\n Ingrese la fecha y hora de hoy: ";cin>>Fechas;
                system("cls");
                if (guardar[0] == 'S' || guardar[0] == 's'){
                    cout<<"Guardando...";
                    //Se almacena los valores de cada jugador nuevo
                    jugador[Njugadores].Ganes=ganesJ;
                    jugador[Njugadores].Empates=empatesj;
                    jugador[Njugadores].Perdidas=perdidasJ;
                    jugador[Njugadores].Puntos=puntosJ;
                    jugador[Njugadores].fechaHora[20]=Fechas[20];
                    //Se guarda los valores del primer jugador
                    jugador[1].Ganes=ganes;
                    jugador[1].Empates=empates;
                    jugador[1].Perdidas=perdidas;
                    jugador[1].Puntos=puntos;
                    //Son para primer jugadore
                    ganes=0;
                    empates=0;
                    perdidas=0;
                    puntos=0;
                    // Son para el resto de jugadores...
                    ganesJ=0;
                    empatesj=0;
                    perdidasJ=0;
                    puntosJ=0;
                    system("timeout 3");
                    cout<<"Los resultados se guradaron correctamente"<<endl;
                    Salir = true;
                    MenuPrincipal();
                    resultados[contador] = elige[opcion];
                    estado[contador] = partida[contador];
                }
                else{
                    cout<<"Regresando al menu principal..."<<endl;
                    system("timeout 3");
                    MenuPrincipal();
                }
                break;
                default:
                 cout<<"La opcion eligida no existe";
                 system("timeout 2");
                 system("cls");
                 contador--;
                 break;
}
mostrarPuntos(false);
cout<<"\n";
cout<<jugador[1].nombre<<" "<<partida[1]<<"  Elegiste " << elige[opcion]<<endl;
cout<<jugador[Njugadores].nombre<<" "<<partida[2]<<"  Elegiste " << elige[opcion2]<<endl;
}}

void Historial(){
    int opcion;
    cout<<"(1) Partida vs Maquina\n(2)Partida vs Jugador\n(3)Regresar al Menu Principal\nEliga una opcion: ";
    cin>>opcion;
    switch (opcion)
    {
    case 1:
        for (int i = 1; i < Npersonas; i++){
            cout<<"Nombre: "<<historial[i].nombre;
            cout<<"Ganes: "<<historial[i].Ganes;
            cout<<"Perdidas: "<<historial[i].Perdidas;
            cout<<"Empates: "<<historial[i].Empates;
            cout<<"Puntos: "<<historial[i].Puntos;
            cout<<"Fecha/hora:"<<jugador[i].fechaHora;
            cout<<"\n\n";
        }
        break;
    case 2:
         for (int i = 1; i < Njugadores; i++){
             cout<<"Nombre: "<<jugador[i].nombre;
             cout<<"Ganes: "<<jugador[i].Ganes;
             cout<<"Empates: "<<jugador[i].Empates;
             cout<<"Perdidas: "<<jugador[i].Perdidas;
             cout<<"Puntos: "<<jugador[i].Puntos;
             cout<<"Fecha/hora:"<<jugador[i].fechaHora;
             cout<<"\n\n";
         }
        break;
    case 3:
        MenuPrincipal();
        break;
    default:
        cout<<"La opcion que ingresaste no existe"<<endl;
        break;
}}

void MenuPrincipal(){
    int opc = 0;
    system("cls");
    while (!Inicio){
    cout << "\n(1) Partida vs Maquina\n(2) Partida vs jugador2\n(3) Historial del juego\n(4) Cerrar" << endl;
    cout << "\nCual opcion desea elegir:";
    cin >> opc; //Se guarda la opcion elegida
    system("cls");
    switch (opc){
    case 1:
        JugadorVSmaquina();
        break;
    case 2:
        JugadorVSjugador();
        break;
    case 3:
        Historial();
    default:
       Inicio=true;
       Inicio=true;
       Inicio=true;
       Inicio=true;
       Inicio=true;
       Inicio=true;
       break;
}}}

int main(){
    srand(time(NULL));
    MenuPrincipal();
    system("pause");
    return 0;
}