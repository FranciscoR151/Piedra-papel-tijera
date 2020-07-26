#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;

int main(){
    int desicion; //Guarda eleccion de si es pie, pap o tij
    char nombre[20]; //Para guardar el nombre que ingrese
    int aleatorios; // 1=piedra 2=papel 3=tijera
    int x=0, x2=0; //para mantener el while
    int opc, ptsMaquina=0, ptsJugador=0, ptsJugador2=0;
    int empateJ1, empateM, empateJ2; //Aqui estarán los empates de cada usuario y maquina
    int ganeJ1=0, ganeM=0, ganeJ2=0; //Las veces que ha ganado cada usuario

    while (x=0){
        cout<<"(1) Partida vs Maquina  (2) Partida vs jugador2  (3) Historial del juego  (4) Cerrar"<<endl;
        cin>>opc;
        srand(time(NULL)); //ramdon

        if(opc==1){
            cout<<"Ingrese su nombre de ususario: ";
                cin.getline(nombre, 20, '\n');
            while(x2=0){
            cout<<"Ingrese (1) Piedra (2) Papel (3) Tijera (4) Salir y guardar"<<endl;
            cin>>desicion;
            aleatorios=1+rand()%(3);
            
            switch (desicion){
            case 1: 
            cout<<"Has ingresado PIEDRA"<<endl;
              if(aleatorios==1){
                  cout<<"DeepBlue2020 ha ingresado PIEDRA"<<endl;
                  cout<<"¡Empate!"<<endl;
                  empateJ1++; //se aumenta el empate del jugador
                  empateM++; //se aumenta el empate de la maquina
                  ptsMaquina++; //se aumenta en 1 los puntos de la maquina
                  ptsJugador++; //se aumenta en 1 los puntos del jugador
                  cout<<setfill(' ');
                  cout<<"Usuario"<<setw(5)<<"Pts"<<setw(5)<<"Empates"<<setw(5)<<"Ganes"<<endl;
                  cout<<nombre<<setw(5)<<ptsJugador<<setw(5)<<empateJ1<<setw(5)<<ganeJ1<<endl;
                  cout<<"DeepBlue2020"<<setw(5)<<ptsMaquina<<setw<<empateM<<setw(5)<<ganeM<<endl;
              } 
              else if(aleatorios==2){
                  cout<<"DeepBlue2020 ha ingresado PAPEL"<<endl;
                  cout<<"DeepBlue2020 gana"<<endl;
                  ganeM++; //Se incrementa en 1 las veces que ha ganado maquina
                  ptsMaquina=ptsMaquina+2; //Se incrementa en 2 ya que ha ganado
                  cout<<setfill(' ');
                  cout<<"Usuario"<<setw(5)<<"Pts"<<setw(5)<<"Empates"<<setw(5)<<"Ganes"<<endl;
                  cout<<nombre<<setw(5)<<ptsJugador<<setw(5)<<empateJ1<<setw(5)<<ganeJ1<<endl;
                  cout<<"DeepBlue2020"<<setw(5)<<ptsMaquina<<setw<<empateM<<setw(5)<<ganeM<<endl;
              }

              else if(aleatorios==3){
                  cout<<"DeepBlue2020 ha ingresado TIJERA"<<endl;
                  cout<<"Tu has ganado"<<endl;
                  ganeJ1++; //Se incrementa en 1 las veces que ha ganado el usuario
                  ptsJugador= ptsJugador+2; //Se incrementan los puntos en 2
                  cout<<"Usuario"<<setw(5)<<"Pts"<<setw(5)<<"Empates"<<setw(5)<<"Ganes"<<endl;
                  cout<<nombre<<setw(5)<<ptsJugador<<setw(5)<<empateJ1<<setw(5)<<ganeJ1<<endl;
                  cout<<"DeepBlue2020"<<setw(5)<<ptsMaquina<<setw<<empateM<<setw(5)<<ganeM<<endl;
              }

              else{
                  cout<<"Numero ingresado invalido"<<endl;
              }
              break; //Aqui se cierra cuando has ingresado PIEDRA
            
            case 2:
            cout<<"Has ingresado PAPEL"<<endl;
              if(aleatorios==1){
                  cout<<"DeepBlue2020 ha ingresado PIEDRA"<<endl;
                  cout<<"Has ganado"<<endl;
                  ganeJ1++;
                  ptsJugador= ptsJugador+2;
                  cout<<"Usuario"<<setw(5)<<"Pts"<<setw(5)<<"Empates"<<setw(5)<<"Ganes"<<endl;
                  cout<<nombre<<setw(5)<<ptsJugador<<setw(5)<<empateJ1<<setw(5)<<ganeJ1<<endl;
                  cout<<"DeepBlue2020"<<setw(5)<<ptsMaquina<<setw<<empateM<<setw(5)<<ganeM<<endl;
              }
              else if(aleatorios==2){
                  cout<<"DeepBlue2020 ha ingresado PAPEL"<<endl;
                  cout<<"¡Empate!"<<endl;
                  empateJ1++;
                  empateM++;
                  ptsMaquina++;
                  ptsJugador++;
                  cout<<setfill(' ');
                  cout<<"Usuario"<<setw(5)<<"Pts"<<setw(5)<<"Empates"<<setw(5)<<"Ganes"<<endl;
                  cout<<nombre<<setw(5)<<ptsJugador<<setw(5)<<empateJ1<<setw(5)<<ganeJ1<<endl;
                  cout<<"DeepBlue2020"<<setw(5)<<ptsMaquina<<setw<<empateM<<setw(5)<<ganeM<<endl;
              }
              else if(aleatorios==3){
                  cout<<"DeepBlue2020 ha ingresado TIJERA"<<endl;
                  cout<<"DeepBlue2020 gana"<<endl;
                  ganeM++;
                  ptsMaquina=ptsMaquina+2;
                  cout<<setfill(' ');
                  cout<<"Usuario"<<setw(5)<<"Pts"<<setw(5)<<"Empates"<<setw(5)<<"Ganes"<<endl;
                  cout<<nombre<<setw(5)<<ptsJugador<<setw(5)<<empateJ1<<setw(5)<<ganeJ1<<endl;
                  cout<<"DeepBlue2020"<<setw(5)<<ptsMaquina<<setw<<empateM<<setw(5)<<ganeM<<endl;
              }

              else{
                  cout<<"Numero ingresado invalido"<<endl;
              }
              break;

              case 3:
              cout<<"Has ingresado TIJERA"<<endl;
                if(aleatorios==1){
                    cout<<"DeepBlue2020 ha ingresado PIEDRA"<<endl;
                    cout<<"DeepBlue2020 gana"<<endl;
                    ganeM++;
                  ptsMaquina=ptsMaquina+2;
                  cout<<setfill(' ');
                  cout<<"Usuario"<<setw(5)<<"Pts"<<setw(5)<<"Empates"<<setw(5)<<"Ganes"<<endl;
                  cout<<nombre<<setw(5)<<ptsJugador<<setw(5)<<empateJ1<<setw(5)<<ganeJ1<<endl;
                  cout<<"DeepBlue2020"<<setw(5)<<ptsMaquina<<setw<<empateM<<setw(5)<<ganeM<<endl;
                }
                else if(aleatorios==2){
                    cout<<"DeepBlue2020 ha ingresado PAPEL"<<endl;
                    cout<<"Has ganado"<<endl;
                    ganeJ1++;
                  ptsJugador= ptsJugador+2;
                  cout<<"Usuario"<<setw(5)<<"Pts"<<setw(5)<<"Empates"<<setw(5)<<"Ganes"<<endl;
                  cout<<nombre<<setw(5)<<ptsJugador<<setw(5)<<empateJ1<<setw(5)<<ganeJ1<<endl;
                  cout<<"DeepBlue2020"<<setw(5)<<ptsMaquina<<setw<<empateM<<setw(5)<<ganeM<<endl;
                }
                else if(aleatorios==3){
                    cout<<"DeepBlue2020 ha ingresado TIJERA"<<endl;
                    cout<<"¡Empate!"<<endl;
                    empateJ1++;
                  empateM++;
                  ptsMaquina++;
                  ptsJugador++;
                  cout<<setfill(' ');
                  cout<<"Usuario"<<setw(5)<<"Pts"<<setw(5)<<"Empates"<<setw(5)<<"Ganes"<<endl;
                  cout<<nombre<<setw(5)<<ptsJugador<<setw(5)<<empateJ1<<setw(5)<<ganeJ1<<endl;
                  cout<<"DeepBlue2020"<<setw(5)<<ptsMaquina<<setw<<empateM<<setw(5)<<ganeM<<endl;
                }
                break;

                default: x2=1; //Aqui se debe guardar los resultados de los datos anteriores
                break;
            }

            }
            
        }
    }

    system("pause");
    return 0;
}