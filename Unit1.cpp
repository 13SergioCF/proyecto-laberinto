//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
CMatriz *A;
pila *b;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{   A=new CMatriz;
	b=new pila;
}
//---------------------------------------------------------------------------
int s=0;
int ii=0;
void TForm1::ClaseAForm(CMatriz *M, TStringGrid *SG)
{  SG->RowCount=M->Filas;
   SG->ColCount=M->Columnas;
   for(int i=0;i<M->Filas;i++)
   {  for(int j=0;j<M->Columnas;j++)
	  {  SG->Cells[j][i]=FloatToStr(M->Celda[i][j]);  }
   }
}

void TForm1::FormAClase(TStringGrid *SG, CMatriz *M)
{  M->Filas=SG->RowCount;
   M->Columnas=SG->ColCount;
   for(int i=0;i<M->Filas;i++)
   {  for(int j=0;j<M->Columnas;j++)
	  {  M->Celda[i][j]=StrToFloat(SG->Cells[j][i]);  }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{  int n=10,m=10;
A->Filas=n;
A->Columnas=m;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{    int n=20,m=20;
A->Filas=n;
A->Columnas=m;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{     int n=30,m=30;
A->Filas=n;
A->Columnas=m;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
A->matriz();
ClaseAForm(A,SGA);
FormAClase(SGA,A);
A->generar();
ClaseAForm(A,SGA);
}
TRect Casilla;
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
tiempo->Enabled=true;
for (int i = 0; i < SGA->RowCount; i++)
 {
 for (int j= 0; j < SGA->ColCount; j++)
  {
   if(SGA->Cells[i][j]==1)
   {
   SGA->Canvas->Brush->Color=clBlack;
	Casilla=SGA->CellRect(i,j);
	SGA->Canvas->FillRect(Casilla);
   }
   else if(SGA->Cells[i][j]==2)
   {
	SGA->Canvas->Brush->Color=clGreen;
	Casilla=SGA->CellRect(i,j);
	SGA->Canvas->FillRect(Casilla);
   }
   else if(SGA->Cells[i][j]==3)
   {
	SGA->Canvas->Brush->Color=clGreen;
	Casilla=SGA->CellRect(i,j);
	SGA->Canvas->FillRect(Casilla);
   }
   else if(SGA->Cells[i][j]==7){
   SGA->Canvas->Brush->Color=clRed;
	Casilla=SGA->CellRect(i,j);
	SGA->Canvas->FillRect(Casilla);
   }else
	SGA->Canvas->Brush->Color=clWhite;
	Casilla=SGA->CellRect(i,j);
	SGA->Canvas->FillRect(Casilla);
  }
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
A->iniciar();
ClaseAForm(A,SGA);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::tiempoTimer(TObject *Sender)
{
if (s<0) {
	s++;
}
else {
 for (int j = 0; j < SGA->ColCount; j++) {
	if(SGA->Cells[ii][j]==9){
   SGA->Canvas->Brush->Color=clBlue;
	Casilla=SGA->CellRect(ii,j);
	SGA->Canvas->FillRect(Casilla);
 }
}
 }
 ii++;
}

//---------------------------------------------------------------------------





