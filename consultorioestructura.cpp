#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <windows.h>

#define  TITULO1  " 같같� CONSULTORIO MEDICO 같같�";
#define  TITULO2  "CAPTURA" ;
#define  TITULO3  "CONSULTA" ;
#define  TITULO4  "ATENDER A PACIENTES ";

using namespace std;

int gotoxy(USHORT x,USHORT y){                                  
COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   
}

int MENU();
void  CREAR();
void  CONSULTA();
void  ATENDER();
void CONSULTATOTAL();

struct COLA {
       long   CEDULA ;
       char   NOMBRE[50];
       long    TELEFONO;
 
       COLA *SIG;
       };

 COLA  *FRENTE, *FINAL ;

 // ******  PRORAMA PRINCIPAL ********

main()
     {
     char CONTROL = 'S';
     int  OPCION ;
     FRENTE = NULL ;
     while ( CONTROL == 'S')
        {
         OPCION = MENU();
         switch (OPCION) {
             case 1 : CREAR();
		              break;
             case 2 : CONSULTA();
		              break;
		     case 3:CONSULTATOTAL();
		              break;
             case 4 : ATENDER();
	                  break;
             case 5 : CONTROL = 'N';
           }
        }
    }

//****** FUNCION MENU *********

int MENU()
  {
  int OP ;
  system("cls");
  system("color 3f");
  gotoxy(22,8) ; cout  << TITULO1;
  //gotoxy(24,7) ; cout << TITULO2;
  //cout <<", " << TITULO3;
  //cout <<" Y " << TITULO4
  gotoxy(20,11); cout << "1. CAPTURA" ;
  gotoxy(20,12); cout << "2. CONSULTAR PACIENTE POR PACIENTE";
  gotoxy(20,13); cout << "3. CONSULTA TODOS LOS PACIENTES";
  gotoxy(20,14); cout << "4. ATENDER";
  gotoxy(20,15); cout << "5. SALIR";
  do {
       gotoxy(22,18); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
       cin >> OP ;
       gotoxy(30,22); cout << "VALOR FUERA DE RANGO";
   } while((OP < 1) || (OP > 4)) ;
   gotoxy(30,22); cout << "                          ";
   return OP ;
  }

// ********  FUNCION CREAR Y/O ADICIONAR *******

void  CREAR()
  {
  COLA *P ;
  char OP = 'S';
  while (OP == 'S')
    {
    system("cls");
    gotoxy(22,6) ; cout << TITULO1;
    gotoxy(36,8) ; cout << TITULO2;
    gotoxy(20,12); cout <<"CEDULA : ";
    gotoxy(20,14); cout <<"NOMBRE : ";
    gotoxy(20,16); cout <<"TELEFONO : ";

    P = new COLA;
    if ( P == NULL )
       {
       gotoxy(25,22); cout << "NO HAY ESPACIO DE MEMORIA PARA ASIGNAR";
       getch(); OP = 'N';
       }
     else
       {
       do {
	      gotoxy(29,12); cin >> P->CEDULA ;
	      gotoxy(30,22); cout << "VALOR FUERA DE RANGO";
       } while((P->CEDULA < 0) || (P->CEDULA > 2147483647)) ;
       gotoxy(30,22); cout << "                      ";
       cin.sync();
       gotoxy(29,14); 
	   gets(P->NOMBRE);
       do {
	      gotoxy(30,16); cin >> P->TELEFONO ;
	      gotoxy(30,22); cout << "VALOR FUERA DE RANGO";
       } while((P->TELEFONO < 0) || (P->TELEFONO > 2147483647)) ;
       gotoxy(30,22); cout << "                       ";
       P->SIG = NULL ;
 	   if (FRENTE == NULL)
	      FRENTE =  P ;
	    else
	      FINAL->SIG = P;
       FINAL = P;
       do {
	      gotoxy(29,19); cout <<"DESEA CONTINUAR S/N : ";
	      OP = getch();
	      OP = toupper(OP);
       } while((OP != 'S') && (OP != 'N'));
      }
    }
 }
 
 // ********* FUNCION CONSULTA *******

void CONSULTA()
  {
  char OP = 'S' ;
  COLA *P = FRENTE;
  if (FRENTE == NULL)
     {
     	system("cls");
     gotoxy(22,10); cout << " NO HAY PACIENTES EN LA LISTA";
     OP = 'N'; getch();
     }
  gotoxy(22,31) ; cout << "                  ";
  while (( P != NULL) && (OP == 'S'))
      {
      system("cls") ;
      gotoxy(22,6) ; cout << TITULO1;
      gotoxy(36,8) ; cout << TITULO3;
      gotoxy(20,12); cout <<"CEDULA : " << P->CEDULA;
      gotoxy(20,14); cout <<"NOMBRE DEL PACIENTE : " << P->NOMBRE;
      gotoxy(20,16); cout <<"TELEFONO " << P->TELEFONO;

      P = P->SIG ;
      do {
         gotoxy(29,19); cout <<"DESEA CONTINUAR  S/N : ";
         OP = getch();
         OP = toupper(OP);
      } while((OP != 'S') && (OP != 'N'));
     }
  }

// ********* FUNCION ATENDER A PACIENTES ***********
void CONSULTATOTAL()
  {
  	system("cls") ;

  COLA *K = FRENTE;
  int pos=0;
  if (FRENTE == NULL)
     {
     	system("cls");
     gotoxy(22,31); cout << " NO HAY PACIENTES PARA ATENDER";

	 getch();
     }
  gotoxy(22,31) ; cout << "                  ";
  system("cls") ;
      gotoxy(22,6) ; cout << TITULO1;
      gotoxy(36,7) ; cout << TITULO3;
      gotoxy(20,10); cout <<"CEDULA " ;
      gotoxy(40,10); cout <<"NOMBRE " ;
      gotoxy(60,10); cout <<"TELEFONO " ;

      pos=12;
  while ( K != NULL) 
      {
      gotoxy(20,pos); cout << K->CEDULA;
      gotoxy(40,pos); cout << K->NOMBRE;
      gotoxy(60,pos); cout << K->TELEFONO;
      K = K->SIG ;
      pos++;
     }
        gotoxy(80,pos); cout<<" PRESIONE -> ENTER PARA VOLVER ";
     getch();
  
  }

void  ATENDER()
     {
     COLA  *P  ;
     char  OP = 'S';
     char OPC = 'S';
     while  (OP == 'S')
         {
         if  ( FRENTE == NULL)
             {
             	system("cls");
	         gotoxy(10,10); cout << " NO HAY MAS PACIENTES POR ATENDER, EL DOCTOR PUEDE DESCANSAR";
	         OP = 'N' ; getch() ;
	         }
           else
	         {
	         P = FRENTE;
	         system("cls");
	         gotoxy(10,6) ; cout << TITULO1;
	         gotoxy(36,7) ; cout << TITULO4;
	         gotoxy(20,10); cout <<"EL PACIENTE QUE SERA ATENDIDO ES: ";
	         gotoxy(20,12); cout <<"CEDULA : " << P->CEDULA ;
	         gotoxy(20,14); cout <<"NOMBRE : " << P->NOMBRE;
	         gotoxy(20,16); cout <<"TELEFONO : " << P->TELEFONO;
			 getch() ;
                do  {
	             gotoxy(20,19); cout << "DESEA ATENDER A ESTE PACIENTE ? S/N : ";
	             OPC = getche();
	             OPC = toupper(OPC); 
	           }  while((OPC != 'S') && (OPC != 'N'));
			    if (OPC=='S'){ 

	                  gotoxy(30,21); cout <<"PACIENTE ATENDIDO";  getch();
	                 FRENTE = FRENTE -> SIG ;
	                 delete(P);
				 }
	               else{
				  
	         do  {
	             gotoxy(20,20); cout <<"DESEA ATENDER AL PACIENTE QUE SIGUE ? S/N : ";
	             
	             OP = getche();
	             OP = toupper(OP);
	          }  while((OP != 'S') && (OP != 'N'));
             }
            }
        }
    }
