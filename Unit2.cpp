//---------------------------------------------------------------------------
#include <vcl.h>
#include <windows.h>

#include "conio.h"
#pragma hdrstop
#include"vcl.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
CMatriz::CMatriz()
{ n=0;
  m=0;
}

void CMatriz::SetN(int valor)
{  if(valor<=maxc)
   {n=valor;}
   else
   { ShowMessage("Cantidad de columnas err�nea");}
}

int CMatriz::GetN()
{  return n;}

void CMatriz::SetM(int valor)
{  if(valor<=maxf)
   {m=valor;}
   else
   { ShowMessage("Cantidad de filas err�nea");}
}

int CMatriz::GetM()
{  return m;}

void CMatriz::SetElem(int f,int c, float elem)
{   if(f<m && c<n)
	{  Matriz[f][c]=elem;}
	else
	{ ShowMessage("Error de posici�n");}
}

float CMatriz::GetElem(int f, int c)
{  if(f<m && c<n)
	{  return Matriz[f][c];}
	else
	{ ShowMessage("Error de posici�n");}
}
/*EL GENERAR= este codigo utiliza el randomize(random) para tomar posiciones aleatorias
donde colocar los muros representados por un "1" la variable "p" del primer for contrala
el llenado del 40% de la matriz  */
void CMatriz::generar()
{  int p=n*m;
   p=p*0.4;
 Randomize();
 int x,y;
 /*llenado de los muros */
  for (int i = 0; i < p; i++) {
	x=random(n)+1;
	y=random(n)+1;
	Matriz[x][y]=1;
  }

  for (int i = 0; i < n; i++) {
	 int h=random(2)+1;
	 if(h==2){
	 Matriz[1][i]=1;
	 Matriz[n-1][i]=1;
	 Matriz[i][1]=1;
	 Matriz[i][n-1]=1;
	 }
  }

  for (int i = 0; i < n; i++) {
	 int h=random(2)+1;
	 if(h==2){
	 Matriz[1][i]=1;
	 Matriz[n-1][i]=1;
	 Matriz[i][1]=1;
	 Matriz[i][n-1]=1;
	 }
  }
// ------------------------------------------------------
/* esta ultimo for coloca los muros en la parte del borde de la matriz  */
  for (int i = 0; i < n; i++) {
	Matriz[0][i]=1;
	Matriz[n-1][i]=1;
	Matriz[i][0]=1;
	Matriz[i][n-1]=1;
  }
  entrada();
  salida();

}
/*este codigo llena toda la matriz de ceros que representaran los espacios para recorrer
 despues de este es que se adieren os muros con el procedimiento (generar) */
void CMatriz::matriz(){

for(int i=0;i<n;i++)
 {
 for (int j= 0; j < m; j++)
  {
  Matriz[i][j]=0;
  }
 }
}
/*este codigo busca una posicion en donde colocar la entrada de el laberinto si no hay
fuerza creando una en la parte del borde izquierdo
111111111111111111111
1                   1
1                   1
0                   1
1                   1
1                   1
1                   1
1                   1
1                   1
111111111111111111111  */
int CMatriz::entrada()
{  int p=0;
int i=random(n-1),j=0;
  while(j<n)
  {  p=i;
  if(Matriz[i][1]==0)
  {
   if(Matriz[i][2]==0)
   {
   Matriz[i][0]=2;
   j=n;
   }
  else
  if(Matriz[i+1][1]==0)
   {
   Matriz[i][0]=2;
   j=n;
   }
  else
  if(Matriz[i-1][1]==0)
   {
   Matriz[i][0]=2;
   j=n;
   }
   else
   Matriz[i][2]=0;
   Matriz[i][0]=2;
   j=n;
  }
  j++;
  i=random(n);
 }return p;
}
/*cumple el mismo procedimiento de la funcion(entrada) creando una salida en el
borde derecho
111111111111111111111
1                   1
1                   1
1                   1
1                   1
1                   0
1                   1
1                   1
1                   1
111111111111111111111 */
int CMatriz::salida()
{
int i=random(m-1),j=0;
while(j<m)
 {
 if(Matriz[i][m-2]==0)
  {
	if(Matriz[i][m-3]==0)
	{
	Matriz[i][m-1]=3;
	j=m;
	}
	else
	if(Matriz[i-1][m-2]==0)
	{
	Matriz[i][m-1]=3;
	Matriz[i][m-3]=0;
	j=m;
	}
	else
	if(Matriz[i-1][m-2]==0)
	{
	Matriz[i][m-1]=3;
	j=m;
	}else
	Matriz[i][m-3]=0;
	Matriz[i][m-1]=3;
	j=m;
  }
  j++;
  i=random(m-1);
  }
  return i;
}
/*pregunto en el sentido de las manecillas del reloj si en la siguiente casilla
no hay un muro si no hay coloca un (9) y guarda la posicion (i, j) en la clase pila
y si no tiene donde avanzar retrocede con el procedimiento(atras) al encontrar la salida
va a el procedimiento(recorrido) */
 void CMatriz::recorrer(int fil, int col)
{    int i=fil,j=col;
if(Matriz[i][j+1]==3){
   j++;
   Matriz[i][j]=3;
  ShowMessage("Laberinto solucionado");
  recorrido();
}
//------recorrer arriba-----
if(Matriz[i-1][j]==0){
   i--;
   Matriz[i][j]=9;
   InsertarFinal(j);
   InsertarFinal(i);
   recorrer(i,j);
   }
//-------recorrer derecha----
 if(Matriz[i][j+1]==0){
	 j++;
   Matriz[i][j]=9;
   InsertarFinal(j);
   InsertarFinal(i);
   recorrer(i,j);
   }
//------recorrer abajo
 if(Matriz[i+1][j]==0){
	i++;
   Matriz[i][j]=9;
   InsertarFinal(j);
   InsertarFinal(i);
   recorrer(i,j);
   }
//------recorrer izquierda---
 if(Matriz[i][j-1]==0){
	j--;
   Matriz[i][j]=9;
   InsertarFinal(j);
   InsertarFinal(i);
   recorrer(i,j);
   }
  atras();

}
/*este codigo retrocede cuando se necesite volver atras para buscar otra salida
y borra la posicion que se guardo en la clase pila y marca la posicion con un 7
para resaltar que se retrocedio */
void CMatriz::atras(){
 int i=0,j=0,x=0,y=0;
	 x=nodoFinal()->dato;
	 EliminarFinal();
	 y=nodoFinal()->dato;
	 EliminarFinal();
	 Matriz[x][y]=7;
	 i=nodoFinal()->dato;
	 EliminarFinal();
	 j=nodoFinal()->dato;
	 InsertarFinal(i);
	 recorrer(i,j);

}
/*este codigo pide de la clase pila las posiciones que guardo del recorrido
y las modifica dandole un valor de 9 en el laberinto al perdir la posicion despues
la elimina para pedir la siguiente */
void CMatriz::recorrido(){
int i=0,j=0;
j=inicio()->dato;
eliminarInicio();
i=inicio()->dato;
eliminarInicio();
if(Matriz[i][j]==3){
Matriz[i][j]=9;
}else{
Matriz[i][j]=9;
recorrido();
}
}
/*este codigo es como un comando que inicia todo el funcionamiento buscando la entrada
guardando la posicion en la pila y llama el procedimiento recorrer para empezar a
recorrer el laberinto */
void CMatriz::iniciar(){
 int j=0;
 for (int i = 0; i < n; i++) {
	if(Matriz[i][j]==2){
	  if (Matriz[i][j+1]==0) {
			  j++;
		 Matriz[i][j]=9;
				 InsertarFinal(j);
				 InsertarFinal(i);
		 recorrer(i,j);
	  }
   }
 }
}

pila::pila(){
cabeza=NULL; numNodos = 0;
}

nodo* pila::cab() {
  return cabeza;}

bool pila::esVacia() {
				if (cabeza == NULL)
						return true;
				else
						return false;
}

void pila::Insertar_Ini(int x)
{
	nodo* p;
	p=new nodo();
	p->dato=x;
	if (cabeza==NULL) {
		cabeza=p;
	}
	else{
		p->enlace_Der=cabeza;
		cabeza->enlace_Iz=p;
		cabeza=p;
	}
}

void pila::InsertarFinal(int x)
{
	nodo* n;
	n=new nodo();
	n->dato=x;
	nodo* v;
	if (cabeza==NULL) {
		cabeza=n;
	}
	else{
		v=nodoFinal();
		v->enlace_Der=n;
		n->enlace_Iz=v;
	}
}

nodo* pila::inicio()
{
	return cabeza;
}

nodo* pila::nodoFinal()
{
	nodo* v;
	v=cabeza;
	while (v->enlace_Der!=NULL)
		{
			v=v->enlace_Der;
		}
		return v;
}

void pila::EliminarFinal()
{
	nodo* p;
	p=nodoFinal();

	nodo* v=p->enlace_Iz;
	v->enlace_Der=0;

	delete p;
}
void pila::eliminarInicio(){
		if (cabeza != NULL) {
				nodo* v;
				v =cab();
				cabeza = cabeza->enlace_Der;
				delete v;   // libera el espacio de memoria asignado a "n"
		}
}
