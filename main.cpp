#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>
using namespace std;

//Variables globales
char nombre[20];
char maquina[]={"DeepBlue2020"};
string estado[200];
string resultados[200];
int perdidas = 0, ganes = 0, empates = 0,puntos=0;
int perdidasM = 0, ganesM = 0, empatesM = 0,puntosM;
int perdidasJ = 0, ganesJ = 0, empatesj = 0,PuntosJ;
bool Inicio = false;

void MenuPrincipal();

void timer(int ms){
    float tfinal;
    tfinal= clock()+ms*1000;
    while (clock()<tfinal) {}
}

void JugadorVSmaquina(){
    bool Salir = false;
    char guardar[1];
    int opcion = 0, contador = 0, x = 0;
    string elige[4] = {"Piedra", "Piedra", "Papel", "Tijera"};
    string partida[200];
    cout << "Ingrese su nombre de usuario: "; cin>>nombre;
    system("cls");
    while (!Salir){
        contador++;
        cout << nombre << "  Puntos: "<<puntos<< " Ganadas: " << ganes << "  Perdidas: " << perdidas << "  Empates: " << empates << endl;
        cout<<endl;
        cout << maquina << "  Puntos: "<<puntosM<< " Ganadas: " << ganesM << "  Perdidas: " << perdidasM << "  Empates: " << empatesM << endl;
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
                cout << "Desea guardar los resultados S (si),N (no) >>";
                cin >> guardar;
                system("cls");
                if (guardar[0] == 'S' || guardar[0] == 's'){
                    cout<<"Guardando...";
                    timer(1);
                    cout<<"Los resultados seguradaron correctamente"<<endl;
                    Salir = true;
                    MenuPrincipal();
                    resultados[contador] = elige[opcion];
                    estado[contador] = partida[contador];
                }
                else{
                    cout<<"Regresando al menu principal..."<<endl;
                    timer(1);
                    MenuPrincipal();
                }
                break;
                default:
                 cout<<"La opcion eligida no existe";
                 timer(2);
                 system("cls");
                 contador--;
                 break;
}}}

void JugadorVSjugador(){
//Se hace lo mismo del jugador contra maguina

}
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
    default: 
     Inicio=true;
     break;
}}}

int main(){
    srand(time(NULL));
        MenuPrincipal();
    
    system("pause");
    return 0;
}