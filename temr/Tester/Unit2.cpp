//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm2::BOkClick(TObject *Sender)
{
   if (NEdit->Text != "") Form1->Caption="Тестируется "+NEdit->Text;
   else Form1->Caption="Тестируется НектоНеизвестный";
   Form1->Timer->Enabled=true;
   Form2->ModalResult=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::NEditKeyPress(TObject *Sender, char &Key)
{
   if (Key == 13) BOk->OnClick(BOk);
}
//---------------------------------------------------------------------------
