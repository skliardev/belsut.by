//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGAUGES"
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::AgainClick(TObject *Sender)
{
Form1->Timer->Enabled=true;
Form3->ModalResult=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ExitClick(TObject *Sender)
{
Form3->ModalResult=1;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCreate(TObject *Sender)
{
//Form3->Again->Glyph=0;
Form1->IconList->GetBitmap(5,Again->Glyph);
//Form3->Exit->Glyph=0;
Form1->IconList->GetBitmap(4,Exit->Glyph);

//Áåç ýòîãî òðþêà ïîñëåäíèé ShowMessageñêàæåò,÷òî ó íàñ ÍÎËÜ ñòðîê 0_o
Form3->AlphaBlendValue=0;
Form3->Show();
Form3->Hide();
Form3->AlphaBlendValue=255;
//ShowMessage(IntToStr(Form3->Stat->Items->Count));
}
//---------------------------------------------------------------------------

