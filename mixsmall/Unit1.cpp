//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdlib.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define SIZE 10
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BthRNDClick(TObject *Sender)
{
 Memo->Clear();
 unsigned __int8 a[SIZE],i,temp,n;
 for(i=0; i<SIZE; i++) a[i]=i;
 for(i=SIZE-1; i>=0; i--)
 {
  randomize();
  n=random(i);
  Memo->Lines->Strings[0]=Memo->Lines->Strings[0]+" "+AnsiString(a[n]);
  a[n]=a[i];
  if(i==0) break; //“ак как без этого будет бесконечный чикл!
 }
}
//---------------------------------------------------------------------------
 