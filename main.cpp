#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include<sstream>
#include<fstream>
#include <windows.h>
using namespace std;
//  estructuras
struct proveedor{
  char nombre[30];
  char contacto[30];
  char rfc[20];
  char correo[30];
  long int telefono;
}prov1;
struct producto{
char nom [25];
char tipo[30];
char desc[40];
float precio;
string clave;
}prod1;
struct menud{
int numM;
char nomM[50];
float precioM;
}MenuM;
// declaracion de funciones
void menu();
void MenuP();
void CMenu();
void calc();
void imprimeMen();
void inicio();
void productos();
void proveedores();
void regProv();
void consultaPROD();
 void consultaP();
void venta();
void imprime();
void quitar();
void pagar();
int posicion();
void agregarP();
string genClave();
void regP(char x[]);
void gotoxy(int x, int y);
//Variables Globales
string nombre[15],desc[15],clavP[15],tipe[15];
float precios[15],iva[15],total[15];
ofstream archivo;
string linea[3];
int main()
{
  int opc;
  char sa='n';
  inicio();
  do{
    menu();
    scanf("%d",&opc);
    switch(opc){
    case 1:
         venta(); //ventas
        break;
    case 2: // productos
        productos();
        break;
    case 3:
        MenuP();// menu del dia
        break;
    case 4:
        proveedores();  // provedor
        break;
    case 5:
            printf("seguro que quieres salir ? SI(s)/NO(n)\n");
        fflush(stdin);
        scanf("%c",&sa);
        if(sa=='s'){
        return 1;
        }
        else
         system("cls");
       break;
       default:
            if(opc<1||opc>7)
            {
                 printf("Opcion no valida");
                 system("pause");
                  system("cls");
            }
    break;
        }
    }while(opc!=8);
	//system("pause");
	return 0;
}
void inicio(){

    system("color 0C");
    char inicio[10][50]
    {
     "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
     "x     Sistema para Cafeteria            x",
     "x           CyDSoft                     x",
     "x    *******BIENVENIDO******            x",
	 "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
    };
    for (int y = 0; y <6; y++){
	    gotoxy(30,y);
		for (int x = 0; x <50 ; x++){
        printf("%c",inicio[y][x]);
		}
		printf("\n");}
    gotoxy(30,7);
	printf("*********  Version 1.0........\n");
	gotoxy(30,8);
	printf("*********  Inicio ............\n");
    Sleep(2000); system("cls");
}
void menu(){
    system("cls");
    system("color 0E");
    char cabezera[4][70]
    {
      "////////////  //////////////////  /////////////",
      "x             X  \"/  MENU /\" X              x",
      "///////////  ///////////////////  /////////////"
    };
    for (int y = 0; y < 6; y++){
		gotoxy(1,y+2);
		for (int x = 0; x <65 ; x++){
        printf("%c",cabezera[y][x]);
        }
		printf("\n");
		}
	char men[13][81]
	{
     "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
     "x                                                 x",
     "x    -----------------       -----------------    x",
	 "x   | [1]REALIZAR     |     |                 |   x",
	 "x   |    VENTA        |     | [3]MENU DEL DIA |   x",
	 "x   |                 |     |                 |   x",
	 "x    -----------------       -----------------    x",
	 "x    -----------------       -----------------    x",
	 "x   |                 |     |                 |   x",
	 "x   | [2]PRODUCTOS    |     | [4]PROVEEDOR  ;)|   x",
	 "x   |                 |     |                 |   x",
	 "x    -----------------       -----------------    x",
	 "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
	};
	for (int y = 0; y < 13; y++){
		gotoxy(0,y+6);
		for (int x = 0; x <81 ; x++){
        printf("%c",men[y][x]);
        }
		}
		gotoxy(55,18);
		printf("[5]\" SALIR\"\n");
		printf("\n");
        printf("\nDigite la opcion requerida :");
}
void productos()
{
    system("cls");
int opc,s=0;

	system("color 0F");  // negro y azul
     char opci[13][40]
    {
     "X/////////////////////////////X",
     "X   *[1] BEBIDAS CALIENTES*   X",
     "X                             X",
     "X   *[2] BEBIDAS FRIAS*       X",
     "X                             X",
     "X   *[3] ALIMENTOS*           X",
     "X                             X",
     "X   *[4] DULCERIA*            X",
     "X                             X",
     "X   *[5] CONSULTA*            X",
     "X                             X",
     "X   *[6] REGRESAR*            X",
	 "X/////////////////////////////X"
    };
    char pr[5][30]
    {
     "xxxxxxxxxxxxxxxxxxxxxxxxxxx",
     "x    ****REGRISTRO****    x",
     "x           DE            x",
     "x        PRODUCTOS        x",
	 "xxxxxxxxxxxxxxxxxxxxxxxxxxx"
    };
    do{
	for(int y = 0; y <5; y++){
	    gotoxy(3,y);
		for (int x = 0;x<30 ; x++){
        printf("%c",pr[y][x]);
		}
	    }
    for(int y = 0; y <13; y++){
	    gotoxy(0,y+6);          // imprime menu
		for (int x = 0;x<40 ; x++){
        printf("%c",opci[y][x]);
		}
    }
    printf("\n\nDigite la Opcion que necesita :");
    scanf("%d",&opc);
    switch(opc)
    {
        case 1:regP("Bebida Caliente");break;
        case 2:regP("Bebida Fria");  break;
        case 3:regP("Alimento");  break;
        case 4:regP("Dulceria");  break;
        case 5:consultaPROD(); break;
        case 6:system("cls"); s=2; break;
        default: printf("opcion no valida"); system("pause");
                  system("cls");break;
    }
    }while(s!=2);
}

void regP(char x[])
{
    int xx,y;
    char opcinfo[6][50]
    {
     "X/////////////////////////////////////////X",
     "X   *[1] REGRESAR*    *[3]CORREGIR REG.*  X",
     "X                                         X",
     "X   *[2] NUEVO REG.*  *[4]GUARDAR REG.*   X",
     "X                                         X",
	 "X/////////////////////////////////////////X"
    };
    char opcCoreg[6][50]
    {
     "X/////////////////////////////////////////X",
     "X   *[1]NOMBRE*       *[3]PRECIO*         X",
     "X                                         X",
     "X   *[2]DESCRIPCION*  *[4]REGRESAR*       X",
     "X                                         X",
	 "X/////////////////////////////////////////X"
    };
    char Anuncio[6][50]
    {
     ":::::::::::::::::::::::::::::::::::::::::::",
     ":SEGURO QUE QUIERES GUARDARLO? Si(s) No(n):",
     ":                                         :",
	 ":::::::::::::::::::::::::::::::::::::::::::"
    };
    int s=0,s2=0,s3=0;
    int opc1,opc2;
    char guard;
    strcpy(prod1.tipo,x);
    //system("cls");
    do{
    fflush(stdin);
    printf("NOMBRE DEL PRODUCTO :\n");
    cin.getline(prod1.nom,25,'\n');
    printf("DESCRIPCION :\n");
    cin.getline(prod1.desc,40,'\n');
    printf("PRECIO :\n");
    scanf("%f",&prod1.precio);
    prod1.clave=genClave();
    do{
    fflush(stdin);
      system("cls");
        for(y = 0; y <6; y++){
	    gotoxy(0,y+1);              // IMPRIME MENU 1
		for (xx = 0;xx<50 ; xx++){
        printf("%c",opcinfo[y][xx]);
		}
        }
        printf("\n");
        printf("\nDigite la opcion requerida :"); scanf("%d",&opc1);
        switch(opc1)
        {
         case 1:system("cls"); s=1; s2=1; break;
         case 2: s2=1; break;
         case 3:
         do{
         system("cls");
         for(y = 0; y <6; y++){
         gotoxy(0,y+1);   // IMPRIME MENU 2
         for (xx = 0;xx<50 ; xx++){
         printf("%c",opcCoreg[y][xx]);
         }
         }
         printf("\n");
         printf("\nDigite la opcion requerida :");
         scanf("%d",&opc2);
         fflush(stdin);
         switch(opc2)
         {
         case 1:
         printf("NOMBRE DEL PRODUCTO :\n");
         cin.getline(prod1.nom,25,'\n');
         printf("NOMBRE CORREGIDO\n"); system("pause");
         prod1.clave=genClave();break;
         case 2:printf("DESCRIPCION :\n");
         cin.getline(prod1.desc,40,'\n');
         printf("DESCRIPCION CORREGIDA\n"); system("pause");;break;
         case 3:  printf("PRECIO :\n");
         scanf("%f",&prod1.precio);
         printf("PRECIO CORREGIDO\n"); system("pause"); ;break;
         case 4:system("cls"); s3=1; break;
         default : printf("OPCION NO VALIDA");system("pause");
                  system("cls"); break;
         }
         }while(s3!=1);
         break;
         case 4:
         system("cls");
         for(y= 0; y <4; y++){
         gotoxy(0,y+1);              // ANUNCIO 1
         for (xx = 0;xx<50 ; xx++){
         printf("%c",Anuncio[y][xx]);
         }
         }
         printf("\n");
         printf("Nombre: %s\n",prod1.nom);
         printf("Descripcion: %s\n",prod1.desc);
         printf("Precio: %f\n",prod1.precio);
         printf("Clave: %s\n",prod1.clave.c_str());
         printf("Tipo: %s\n",prod1.tipo);
         fflush(stdin);
         scanf("%c",&guard);
          if(guard=='s'){
            archivo.open("RegProd.txt",ios::app);// Abrimos el archivo añadiendo texto
            if(archivo.fail()){
            printf("\nErro al Abrir el archivo, contactar al administrador");
            }
             archivo <<prod1.clave<< endl;
             archivo <<prod1.nom << endl;
             archivo <<prod1.desc <<endl;
             archivo <<prod1.precio<< endl;
             archivo <<prod1.tipo<< endl;
             printf("Registro realizado\n");
             archivo.close();
             system("pause");
             system("cls");
             s=1; s2=1;
             }
             break;
            default : printf("\nOpcion no valida");system("pause");
                  system("cls"); break;
        }
    }while(s2!=1);
    }while(s!=1);

}
string genClave()
{
    string clave="";
    int longitud=strlen(prod1.nom);// tamaño
    clave=clave+prod1.nom[0]+prod1.nom[1]+prod1.nom[longitud-2]+prod1.nom[longitud-1];
    return clave;
}
void gotoxy(int x, int y){ //nombre de la funcion gotoxy entrada de 2 parametros enteros
    HANDLE hCon; //definiendo identificador de tipo handle llamado hCon
    hCon=GetStdHandle(STD_OUTPUT_HANDLE); // obteniendo el handle estandar // parametro estandar de salida del handle
    COORD cord;  // Estructura de windows.h
    cord.X=x;// dato x de la estructura
    cord.Y=y; // dato y de la estructura
    SetConsoleCursorPosition(hCon,cord); // asignacion de la posicion del cursor de la consola
}
void proveedores(){
    int opc,s=1;
char cabecera[5][30]
    {
     "xxxxxxxxxxxxxxxxxxxxxxxxxxx",
     "x    ****REGRISTRO****    x",
     "x           DE            x",
     "x       PROOVEDORES       x",
	 "xxxxxxxxxxxxxxxxxxxxxxxxxxx"
    };
     char opcI[5][70]
    {
     "X//////////////////////////////////////////////////////////X",
     "X   *[1] REGISTRAR PROV*  *[2]CONSULTAR PROV*  [3]REGRESAR X",
     "X                                                          X",
	 "X//////////////////////////////////////////////////////////X"
    };
	    system("cls");
        ///////////////////////
        do{
            for(int y = 0; y <5; y++){
	    gotoxy(16,y);           // imprime cabezera
		for (int x = 0;x<30 ; x++){
        printf("%c",cabecera[y][x]);
        }
        }
        for(int y = 0; y <4; y++){
	    gotoxy(0,y+6);          // menuI
		for (int x = 0;x<60 ; x++){
        printf("%c",opcI[y][x]);
		}
	    }
        printf("\n\nDigite la Opcion que necesita :");
        scanf("%d",&opc);
        switch(opc)
        {
        case 1: regProv(); break;
        case 2: consultaP(); break;
        case 3:s=2; system("cls"); break;
            default: printf("opcion no valida");system("pause");
                  system("cls"); break;
        }
        }while(s!=2);
    }
void regProv(){
     ofstream archivop;
    char guard='n';
    int s=1,opc,opc2,s2=1,s3=0;
    char men[13][40]
    {
     "X/////////////////////////////X",
     "X *[1] NUEVO REGISTRO*        X",
     "X                             X",
     "X *[2] CORREGIR REGISTRO*     X",
     "X                             X",
     "X *[3] GUARDAR REGISTRO*      X",
     "X                             X",
     "X *[4] REGRESAR*              X",
     "X                             X",
	 "X/////////////////////////////X"
    };
     char men2[6][50]
    {
     "X//////////////////////////////////////////////X",
     "X *[1] NOMBRE PROV.*  *[3]RFC*     [5]TELEFONO X",
     "X                                              X",
     "X *[2] CONTACTO*      *[4]CORREO*  [6]REGRESAR X",
     "X                                              X",
	 "X//////////////////////////////////////////////X"
    };
    char Anuncio[6][50]
    {
     ":::::::::::::::::::::::::::::::::::::::::::",
     ":SEGURO QUE QUIERES GUARDARLO? Si(s) No(n):",
     ":                                         :",
	 ":::::::::::::::::::::::::::::::::::::::::::"
    };
    do{
    fflush(stdin);
    printf("NOMBRE DEL PROVEEDOR :\n");
    cin.getline(prov1.nombre,30,'\n');
    printf("CONTACTO :\n");
    cin.getline(prov1.contacto,30,'\n');
    printf("RFC :\n");
    cin.getline(prov1.rfc,20,'\n');
    printf("CORREO :\n");
    cin.getline(prov1.correo,30,'\n');
    printf("TELEFONO :\n");
    scanf("%d",&prov1.telefono);
    do{
     fflush(stdin);
      system("cls");
    for(int y = 0; y <10; y++){
	    gotoxy(0,y+2);          // imprime menu
		for (int x = 0;x<40 ; x++){
        printf("%c",men[y][x]);
            }}
        printf("\n");
        printf("\nDigite la opcion requerida :");
        scanf("%d",&opc);
        switch(opc)
        {
            case 1: s2=2; break;
            case 2: do{
                system("cls");
                for(int y = 0; y <6; y++){
                gotoxy(0,y+1);   // IMPRIME MENU 2
                for (int xx = 0;xx<50 ; xx++){
                printf("%c",men2[y][xx]);
                }
                }
                fflush(stdin);
                printf("\n"); printf("\nDigite la opcion requerida :");scanf("%d",&opc2);
                fflush(stdin);
                switch(opc2)
                {
                case 1:
                    printf("NOMBRE DEL PROVEEDOR :\n");
                    cin.getline(prov1.nombre,30,'\n');
                    printf("NOMBRE CORREGIDA\n"); system("pause");;break;
                    break;
                    case 2:printf("CONTACTO :\n");
                    cin.getline(prov1.contacto,30,'\n');
                    printf("CONTACTO CORREGIDA\n"); system("pause");;break;
                    case 3:printf("RFC :\n");
                    cin.getline(prov1.rfc,20,'\n');
                    printf("RFC CORREGIDO\n"); system("pause"); ;break;
                    case 4:printf("CORREO :\n");
                    cin.getline(prov1.correo,30,'\n');
                    printf("CORREO CORREGIDO\n"); system("pause"); break;
                    case 5:printf("TELEFONO :\n");
                    scanf("%d",&prov1.telefono);
                    printf("TELEFONO CORREGIDO\n"); system("pause"); break;
                    case 6:system("cls");s3=1; break;
                    default : printf("OPCION NO VALIDA");system("pause");
                  system("cls");break;
                }
                }while(s3!=1); break;
                case 3:
                        system("cls");
                    for(int y= 0; y <4; y++){
                    gotoxy(0,y+1);              // ANUNCIO 1
                    for (int xx = 0;xx<50 ; xx++){
                    printf("%c",Anuncio[y][xx]);
                    }
                    }
                    printf("\n");
                    printf("NOMBRE: %s\n",prov1.nombre);
                    printf("CONTACTO: %s\n",prov1.contacto);
                    printf("RFC: %s\n",prov1.rfc);
                    printf("CORREO: %s\n",prov1.correo);
                    printf("TELEFONO: %d\n",prov1.telefono);
                    fflush(stdin);
                    scanf("%c",&guard);
                    if(guard=='s'){
                        archivop.open("RegProv.txt",ios::app);// Abrimos el archivo añadiendo texto
                        if(archivop.fail()){
                        printf("\nErro al Abrir el archivo, contactar al administrador");
                        }
                        archivop <<prov1.nombre << endl;
                        archivop <<prov1.contacto <<endl;
                        archivop <<prov1.rfc<< endl ;
                        archivop <<prov1.correo<< endl;
                        archivop <<prov1.telefono<< endl;
                        printf("Registro realizado\n");
                        archivop.close();
                         system("pause");
                         system("cls");
                         s=2; s2=2;
                    }break;
                case 4:
                    system("cls");s=2; s2=2;
                     break;
            default : printf("\nOpcion no valida"); system("pause");
                  system("cls");break;

        }
    }while(s2!=2);
    }while(s!=2);
}
void consultaP(){
    system("cls");
    fstream archivo;
    string cadena,linea,linea1,linea2,linea3,linea4;
    int res=0,opcp;
    char ConP[6][55]
    {
     ":::::::::::::::::::::::::::::::::::::::::::::::::::",
     ":[1]CONSULTA POR NOM. [2]CONSULTAR TODOS LOS PROV.:",
     ":                                                 :",
	 ":::::::::::::::::::::::::::::::::::::::::::::::::::"
    };
    for(int y= 0; y <4; y++){
    gotoxy(0,y+1);              // ANUNCIO 1
    for (int xx = 0;xx<55 ; xx++){
    printf("%c",ConP[y][xx]);
    }} printf("\n");
    printf("\nDigite la opcion requerida :");
    scanf("%d",&opcp);
    switch(opcp){
    case 1:
        system("cls");
    printf("\nBuscar proveedor por nombre :");
    cin>>cadena;
    if(!archivo.is_open()){
        archivo.open("RegProv.txt",ios::in);
    }
    while(getline(archivo,linea)){
        if(linea.find(cadena)!=string::npos){
            printf("____________________\n");
            cout<<"NOMBRE :"<<linea<<endl;
            getline(archivo,linea1);
            cout<<"CONTACTO :"<<linea1<<endl;
            getline(archivo,linea2);
            cout<<"RFC :"<<linea2<<endl;
            getline(archivo,linea3);
            cout<<"CORREO :"<<linea3<<endl;
            getline(archivo,linea4);
            cout<<"TELEFONO :"<<linea4<<endl;
            printf("____________________\n");
            system("pause");
            system("cls");
            res=1;}
            }
            archivo.close();
    if(res==0){
        printf("\nproveedor no encontrado\n");
        system("pause");
        system("cls");
    } break;
    case 2:
        system("cls");
        ifstream lectura;
        lectura.open("RegProv.txt",ios::out|ios::in);
        if(lectura.is_open()){
            getline(lectura,linea);
            while(!lectura.eof()){
            //lectura>>linea>>linea1>>linea2>>linea3>>linea4;
            printf("____________________\n");
            cout<<"NOMBRE :"<<linea<<endl;
             getline(lectura,linea1);
            cout<<"CONTACTO :"<<linea1<<endl;
             getline(lectura,linea2);
            cout<<"RFC :"<<linea2<<endl;
             getline(lectura,linea3);
            cout<<"CORREO :"<<linea3<<endl;
             getline(lectura,linea4);
            cout<<"TELEFONO :"<<linea4<<endl;
             getline(lectura,linea);
            printf("____________________\n");
            }}
            else{
                printf("NO SE A PODIDO ABRIR EL ARCHIVO");
            }
            lectura.close();
            system("pause");
            system("cls");
             break;
        }
}
void consultaPROD(){
    system("cls");
    fstream archivo;
    string cadena,linea,linea1,linea2,linea3,linea4;
    int res=0,opcp;
    char ConP[6][55]
    {
     "::::::::::::::::::::::::::::::::::::::::::::::::::::",
     ":[1]CONSULTA POR CLAV. [2]CONSULTAR TODOS LOS PROD.:",
     ":                                                  :",
	 "::::::::::::::::::::::::::::::::::::::::::::::::::::"
    };
    for(int y= 0; y <4; y++){
    gotoxy(0,y+1);              // ANUNCIO 1
    for (int xx = 0;xx<55 ; xx++){
    printf("%c",ConP[y][xx]);
    }} printf("\n");
    printf("\nDigite la opcion requerida :");
    scanf("%d",&opcp);
    switch(opcp)
    {
    case 1:
        system("cls");
    printf("\nBUSCAR PRODUCTO POR CLAVE :");
    cin>>cadena;
    if(!archivo.is_open()){
        archivo.open("RegProd.txt",ios::in);
    }
    while(getline(archivo,linea)){
        if(linea.find(cadena)!=string::npos){
            printf("____________________\n");
            cout<<"CLAVE :"<<linea<<endl;
            getline(archivo,linea1);
            cout<<"NOMBRE :"<<linea1<<endl;
            getline(archivo,linea2);
            cout<<"DESCRIPCION  :"<<linea2<<endl;
            getline(archivo,linea3);
            cout<<"PRECIO :"<<linea3<<endl;
            getline(archivo,linea4);
            cout<<"TIPO :"<<linea4<<endl;
            printf("____________________\n");
            system("pause");
            system("cls");
            res=1;}
            }
            archivo.close();
    if(res==0){
        printf("\nPRODUCTO NO ENCONTRADO\n");
        system("pause");
        system("cls");
    } break;
    case 2:
        fflush(stdin);
        system("cls");
        ifstream lectura;
        lectura.open("RegProd.txt",ios::out|ios::in);
        if(lectura.is_open()){
            getline(lectura,linea);
            while(!lectura.eof()){
            //lectura>>linea>>linea1>>linea2>>linea3>>linea4;
            printf("____________________\n");
            cout<<"CLAVE :"<<linea<<endl;
            getline(lectura,linea1);
            cout<<"NOMBRE :"<<linea1<<endl;
            getline(lectura,linea2);
            cout<<"DESCRIPCION  :"<<linea2<<endl;
            getline(lectura,linea3);
            cout<<"PRECIO :"<<linea3<<endl;
            getline(lectura,linea4);
            cout<<"TIPO :"<<linea4<<endl;
            getline(lectura,linea);
            printf("____________________\n");
            }}
            else{
                printf("NO SE A PODIDO ABRIR EL ARCHIVO");
            }
            lectura.close();
            system("pause");
            system("cls");
             break;}}
///////////////////////////
void venta(){
    int s=0,opc;
    system("cls");
    system("color 0E");
  char cabecera[5][40]
    {
     "///////////////////////////////",
     "x      VENTA DE PRODUCTOS     x",
     "x                             x",
	 "///////////////////////////////"
    };
    char Anuncio[8][90]
    {
     ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::",
     ":                                                                              :",
     ": ///////////////////////   ///////////////////////   ///////////////////////  :",
     ": /[1] AGREGAR PRODCUTO /   /[2] QUITAR PRODUCTO  /   /      [3] PAGAR      /  :",
     ": /                     /   /                     /   /                     /  :",
     ": ///////////////////////   ///////////////////////   ///////////////////////  :",
     ":                                                                              :",
	 "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
    };

    do{
        system("cls");
        for(int y = 0; y <5; y++){
	    gotoxy(25,y);
		for (int x = 0;x<40 ; x++){
        printf("%c",cabecera[y][x]);
		}
	    }
	    for(int y = 0; y <8; y++){
	    gotoxy(0,y+5);
		for (int x = 0;x<90 ; x++){
        printf("%c",Anuncio[y][x]);
		}
	    }
         gotoxy(69,14);
		 printf(" [4]\" SALIR\"\n");
         gotoxy(0,16);printf("NOMBRE");
         gotoxy(12,16); printf("CLAVE");
         gotoxy(21,16); printf("DESCRIPCION");
         gotoxy(35,16); printf("TIPO\n");
         gotoxy(49,16); printf("PRECIOS");
         gotoxy(63,16); printf("IVA(16%)\n");
         gotoxy(77,16); printf("TOTAL\n");
         for(int i=0;i<posicion()-1;i++){
         iva[i]=precios[i]*0.16;
         total[i]=precios[i]+iva[i];
         gotoxy(0,i+17);printf("%s",nombre[i].c_str());
         gotoxy(12,i+17); printf("%s",clavP[i].c_str()); //printf("%s",[i].c_str());
         gotoxy(21,i+17); printf("%s",desc[i].c_str());
         gotoxy(35,i+17); printf("%s",tipe[i].c_str());//
         gotoxy(49,i+17); printf("%f",precios[i]);
         gotoxy(63,i+17); printf("%f",iva[i]);
         gotoxy(77,i+17); printf("%f",total[i]);
         }
        printf("\n");
		printf("\nDigite la opcion  que necesite :");
		scanf("%d",&opc);
		switch(opc){
		    case 1:agregarP(); break;
		    case 2:quitar();break;
		    case 3:pagar();break;
		    case 4:s=1; break;
		    default: printf("\nOPCION NO VALIDA\n"); system("pause"); break;
		}
        }while(s!=1);
}
void agregarP(){
    int s=0,opc;
    char wuard='n';
    int index;
    fstream archivo;
    string cadena,linea,linea1,linea2,linea3,linea4;
    int res=0;
    system("cls");
char AnuncioAP[6][50]
    {
     ":::::::::::::::::::::::::::::::::::::::::::",
     ":[1]BUSCAR PROD. [2]VER LISTA  [3]REGRESAR:",
     ":                                         :",
	 ":::::::::::::::::::::::::::::::::::::::::::"
    };
    do{
     system("cls");
         for(int y= 0; y <4; y++){
         gotoxy(0,y+1);              // ANUNCIO ap
         for (int xx = 0;xx<50 ; xx++){
         printf("%c",AnuncioAP[y][xx]);
         }
         }
         fflush(stdin);
         printf("\nDigite la opcion  que necesite : ");
		 scanf("%d",&opc);
		 switch(opc)
		 {
		     case 1:
            system("cls");
            printf("\nBUSCAR PRODUCTO POR CLAVE : ");
            cin>>cadena;
            if(!archivo.is_open()){
                archivo.open("RegProd.txt",ios::in);
            }
            while(getline(archivo,linea)){
            if(linea.find(cadena)!=string::npos){
            printf("____________________\n");
            cout<<"CLAVE :"<<linea<<endl;
            getline(archivo,linea1);
            cout<<"NOMBRE :"<<linea1<<endl;
            getline(archivo,linea2);
            cout<<"DESCRIPCION  :"<<linea2<<endl;
            getline(archivo,linea3);
            cout<<"PRECIO :"<<linea3<<endl;
            getline(archivo,linea4);
            cout<<"TIPO :"<<linea4<<endl;
            printf("____________________\n");
            fflush(stdin);
            printf("QUIERES AGREGAR EL PRODUCTO? SI(s) NO(n): ");
            scanf("%c",&wuard);
            if(wuard=='s'||wuard=='n')
            {
                if(wuard='s')
                {
                index=posicion()-1;
                clavP[index]=linea;
                nombre[index]=linea1;
                desc[index]=linea2;
                istringstream(linea3)>>precios[index];
                tipe[index]=linea4;
                printf("\nProducto Agregado");
                }
            }else{
                printf("\nOPCION NO VALIDA");
            }
            printf("\n");
            system("pause");
            system("cls");
            res=1;}
            }
            archivo.close();
            if(res==0){
            printf("\nPRODUCTO NO ENCONTRADO\n");
            system("pause");
            system("cls");
            } break;
             case 2:
                imprime();
                printf("\n"); system("pause");
                break;
            case 3: system("cls"); s=1;break;
            default:printf("\nOPCION NO VALIDA\n");
            system("pause");
            system("cls"); break;
             }
    }while(s!=1);
}
int posicion(){
    int contador=1;
    for(int i=0;i<15;i++){
        if(nombre[i].empty()){
            break;
        }else
        contador++;
    }
    return contador;
}
void imprime()
{
    system("cls");
    printf("NOMBRE");
     gotoxy(12,0); printf("CLAVE");
     gotoxy(21,0); printf("DESCRIPCION");
     gotoxy(35,0); printf("TIPO\n");
     gotoxy(49,0); printf("PRECIOS");
     gotoxy(63,0); printf("IVA(16%)\n");
     gotoxy(77,0); printf("TOTAL\n");
     //gotoxy(49,0); printf("TIPO\n");
     for(int i=0;i<posicion()-1;i++){
     iva[i]=precios[i]*0.16;
     total[i]=precios[i]+iva[i];
     gotoxy(0,i+1);printf("%s",nombre[i].c_str());
     gotoxy(12,i+1); printf("%s",clavP[i].c_str()); //printf("%s",[i].c_str());
     gotoxy(21,i+1); printf("%s",desc[i].c_str());
     gotoxy(35,i+1); printf("%s",tipe[i].c_str());//
     gotoxy(49,i+1); printf("%f",precios[i]);
     gotoxy(63,i+1); printf("%f",iva[i]);
     gotoxy(77,i+1); printf("%f",total[i]);
     }
}
void quitar(){
    int s=0,opc;
    char wuard='n';
    int index;
    fstream archivo;
    string cadena,linea,linea1,linea2,linea3,linea4;
    int res=0;
     system("cls");
     printf("\nDIGITE LA CLAVE DEL PRODUCTO QUE DESEA QUITAR : ");
     cin>>cadena;
     if(!archivo.is_open()){
     archivo.open("RegProd.txt",ios::in);
     }
     while(getline(archivo,linea)){
     if(linea.find(cadena)!=string::npos){
     printf("____________________\n");
     cout<<"CLAVE :"<<linea<<endl;
     getline(archivo,linea1);
     cout<<"NOMBRE :"<<linea1<<endl;
     getline(archivo,linea2);
     cout<<"DESCRIPCION  :"<<linea2<<endl;
     getline(archivo,linea3);
     cout<<"PRECIO :"<<linea3<<endl;
     getline(archivo,linea4);
     cout<<"TIPO :"<<linea4<<endl;
     printf("____________________\n");
     fflush(stdin);
     printf("QUIERES QUITAR ESTE PRODUCTO? SI(s) NO(n): ");
     scanf("%c",&wuard);
     if(wuard=='s'||wuard=='n')
     {
     if(wuard='s')
     {
     index=posicion()-1;
     clavP[index]=linea;
     nombre[index]=linea1;
     desc[index]=linea2;
     istringstream(linea3)>>precios[index];
     precios[index]=precios[index]*-1;
     tipe[index]=linea4;
     printf("\nPRODUCTO REMOVIDO");
      }
      }else{
       printf("\nOPCION NO VALIDA");
       }
       printf("\n");
       system("pause");
       system("cls");
       res=1;}
        }
       archivo.close();
       if(res==0){
       printf("\nPRODUCTO NO ENCONTRADO\n");
       system("pause");
       system("cls");
      }
}
void pagar(){
imprime();
int index=posicion()-1,ind=0;
float acum=0,pago,cambio;
for(int i=0;i<index;i++)
{
 acum=acum+total[i];
}
fflush(stdin);
do{
printf("\nTOTAL A PAGAR:..%f",acum);
printf("\nINGRESE EL PAGO: ");
scanf("%f",&pago);
if(pago<acum)
{
    printf("\nEL PAGO ES MENOR A EL TOTAL. VERIFIQUE LA CANTIDAD");
}
else
    if(pago>=acum)
{
    cambio=pago-acum;
     printf("\nVENTA CONCLUIDO....\n");
     printf("CAMBIO: %f\n",cambio);
     for(int i=0;i<index;i++){
        nombre[i]=""; desc[i]=""; clavP[i]="";tipe[i]="";
       precios[i]=NULL;iva[i]=NULL;total[i]=NULL;
     }
}
     ind=1;
}while(ind!=1);
system("pause");
}
void MenuP(){
int oop;
do{system("cls");
printf("[1] CREAR MENU DEL DIA\n");
printf("[2] MOSTRAR MENU\n");
printf("[3] REGRESAR\n");
printf("DIGITE LA OPCION QUE NECESITA: ");
fflush(stdin);scanf("%d",&oop);
switch(oop)
{
    case 1:CMenu();break;
    case 2: imprimeMen();break;
}
}while(oop!=3);
}
void CMenu(){
    FILE *fich;
    int num;
    system("cls");
    if((fich=fopen("MenDia","ab"))==NULL){
        printf("No se ha encontrado el archivo necesario");
    }else{
        printf("INGRESE NOMBRE Y PRECIO DEL MENU \"PROCURE HACERLO CON PRECAUCION\"\n");
        printf("DIGITE EL NUMERO DE PLATILLOS QUE DESEA REGISTRAR\n");
        fflush(stdin);scanf("%d",&num);
        for(int i=1;i<=num;i++){
           MenuM.numM=i;
           fflush(stdin);
           printf("\nNOMBRE DEL PLATILLO: ");
           cin.getline(MenuM.nomM,50,'\n');
           printf("PRECIO DEL PLATILLO: ");
           scanf("%f",&MenuM.precioM);
           fwrite(&MenuM,sizeof(MenuM),1,fich);
        }
        fclose(fich);
    }
}
void imprimeMen(){
system("cls");
FILE *fich;
menud menuv;
if((fich=fopen("MenDia","rb"))==NULL){
        printf("No se ha encontrado el archivo necesario");
    }else{
        fread(&menuv,sizeof(menuv),1,fich);
        printf("   \"MENU PLATILLOS\"\n");
        printf("___________________\n");
        printf("///////////////////\n");
        while(!feof(fich)){
        cout<<"CLAVE  :"<<menuv.numM<<endl;
        cout<<"NOMBRE :"<<menuv.nomM<<endl;
        cout<<"PRECIO :"<<menuv.precioM<<endl;
        fread(&menuv,sizeof(menuv),1,fich);
        }
        printf("///////////////////\n");
    }
    fclose(fich);
    calc();
}
void calc(){
FILE *fich;
menud menuv;
int op,cant,ind=0;
int pedidos[10],cantidad[10],contador=0;
float pago=0,subtotal=0,iva=0,total=0,cambio=0;
if((fich=fopen("MenDia","rb"))==NULL){
        printf("No se ha encontrado el archivo necesario");
    }else{
        printf("DIGITE LA OPCION QUE DESEA COMPRAR  \nPRECIONE(0) si ya no desea seguir comprando\n");
        do{
            contador++;
            fflush(stdin);
            printf("\nNum de Pedido #%d : ",contador);
            scanf("%d",&op);
            if(op!=0){
             pedidos[contador]=op;
             printf("\nCANTIDAD PEDIDO %d : ",contador);
              scanf("%d",&cant);
              cantidad[contador]=cant;
            }
        }while(op!=0);
         contador=0;
         system("cls");
          /*printf("%d",pedidos[1]);
              printf("%d",cantidad[1]);
              printf("%d",pedidos[3]);
              printf("%d",cantidad[3]);*/
         fread(&menuv,sizeof(menuv),1,fich);
          while(!feof(fich)){
                contador++;
              if(pedidos[contador] == menuv.numM){
                printf("\n\t Cantidad:%i.....Platillo:%s......Precio:$%.2f....Subtotal:$%.2f",cantidad[contador],menuv.nomM,menuv.precioM,(cantidad[contador]*menuv.precioM));
                subtotal=subtotal+(cantidad[contador]*menuv.precioM);
              }
            fread(&menuv,sizeof(menuv),1,fich);
          }
          iva=subtotal*0.16;
          total=subtotal+iva;
          printf("\n");
          do{
          printf("SUBTOTAL:---------------%f\n",subtotal);
          printf("IVA:--------------------%f\n",iva);
          printf("TOTAL A PAGAR:----------%f\n",total);
          printf("\nINGRESE EL PAGO: ");
          fflush(stdin);
          scanf("%f",&pago);
          if(pago<total)
          {
            printf("\nEL PAGO ES MENOR A EL TOTAL. VERIFIQUE LA CANTIDAD");
            system("pause");
          }
          else
          if(pago>=total)
          {
              cambio=pago-total;
             printf("\nVENTA CONCLUIDO....\n");
             printf("CAMBIO: %f\n",cambio);
             system("pause");
             ind=1;
          }
            system("cls");
          }while(ind!=1);
          fclose(fich);
           system("pause");}
}
/*0 = Negro
1 = Azul
2 = Verde
3 = Aguamarina
4 = Rojo
5 = Púrpura
6 = Amarillo
7 = Blanco
8 = Gris
9 = Azul Claro
A = Verde Claro
B = Aguamarina Claro
C = Rojo Claro
D = Púrpura Claro
E = Amarillo Claro
F = Blanco Brillante*/
