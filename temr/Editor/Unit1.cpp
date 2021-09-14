//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define PUT ExtractFilePath(ParamStr(0))+"test.ft"
TFormLoad *FormLoad;
//---------------------------------------------------------------------------
__fastcall TFormLoad::TFormLoad(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormLoad::FormCreate(TObject *Sender)
{
 ft=new TIniFile(PUT);
 InfoRead();
}
//---------------------------------------------------------------------------
void __fastcall TFormLoad::ListLoadMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
 if(ListLoad->ItemAtPos(TPoint(X, Y), true) != -1)
  ListLoad->Hint = ListLoad->Items->Strings[ListLoad->ItemAtPos(TPoint(X, Y), true)];
 BthEdit->Enabled=ListLoad->ItemIndex+1;
 BthDel->Enabled=ListLoad->ItemIndex+1;
 /*if(ListLoad->ItemIndex > 0) BthUp->Enabled=ListLoad->ItemIndex+1;
 else BthUp->Enabled=false;
 if(ListLoad->ItemIndex < ListLoad->Items->Count-1) BthDown->Enabled=ListLoad->ItemIndex+1;
 else BthDown->Enabled=false;*/
}
//---------------------------------------------------------------------------
void __fastcall TFormLoad::BthDelClick(TObject *Sender)
{
 int i=ListLoad->ItemIndex+2;
 ft->EraseSection(IntToStr(i-1));
 ft->WriteString("Info","K","\""+IntToStr(ft->ReadInteger("Info","K",0)-1)+"\"");
 delete ft;
 FormEdit->T1->Lines->LoadFromFile(PUT);

 for(int str=0;str<FormEdit->T1->Lines->Count;str++)
  if(FormEdit->T1->Lines->Strings[str]=="["+IntToStr(i)+"]")
  {
   FormEdit->T1->Lines->Strings[str]="["+IntToStr(i-1)+"]";
   i++;
  }

 FormEdit->T1->Lines->SaveToFile(PUT);
 FormEdit->T1->Clear();
 ft=new TIniFile(PUT);
 ListLoad->DeleteSelected();
 InfoRead();
}
//---------------------------------------------------------------------------
void __fastcall TFormLoad::BthAddClick(TObject *Sender)
{
 //ListLoad->Items->Add(IntToStr(QMax)+'.'+"New");
 QMax++;
 ft->WriteString("Info","K","\""+IntToStr(QMax)+"\"");
 ft->WriteString(IntToStr(QMax),"Q","\"Новый вопрос\"");
 ft->WriteString(IntToStr(QMax),"K","\"2\"");
 ft->WriteString(IntToStr(QMax),"Q1","\"1) Вариант 1\"");
 ft->WriteString(IntToStr(QMax),"Q2","\"2) Вариант 2\"");
 ft->WriteString(IntToStr(QMax),"A1","\"а Ответ 1\"");
 ft->WriteString(IntToStr(QMax),"A2","\"б Ответ 2\"");
 ft->WriteString(IntToStr(QMax),"A","\"<<\"");
 InfoRead();
}
//---------------------------------------------------------------------------
void __fastcall TFormLoad::BthEditClick(TObject *Sender)
{
    TEdit* Be[7]={FormEdit->Be1,FormEdit->Be2,FormEdit->Be3,FormEdit->Be4,FormEdit->Be5,FormEdit->Be6,FormEdit->Be7};
    TEdit* Le[7]={FormEdit->Le1,FormEdit->Le2,FormEdit->Le3,FormEdit->Le4,FormEdit->Le5,FormEdit->Le6,FormEdit->Le7};
 FormEdit->Ques(ListLoad->ItemIndex+1);
 Sel=ListLoad->ItemIndex;
 FormEdit->ShowModal();
 InfoRead();
 ListLoad->ItemIndex=Sel;
    FormEdit->T1->Clear();
    for(int i=0;i<7;i++)
    {
        Le[i]->Clear();
        Be[i]->Clear();
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormLoad::ListLoadKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if(BthDel->Enabled)
    if(Key==46) ListLoad->DeleteSelected(); //delete
}
//---------------------------------------------------------------------------
void __fastcall TFormLoad::FormDestroy(TObject *Sender)
{
 delete ft;        
}
//---------------------------------------------------------------------------

void __fastcall TFormLoad::ListLoadDblClick(TObject *Sender)
{
 BthEditClick(FormLoad);
}
//---------------------------------------------------------------------------



void __fastcall TFormLoad::BthUpClick(TObject *Sender)
{
//    
}
//---------------------------------------------------------------------------

void __fastcall TFormLoad::BthDownClick(TObject *Sender)
{
//    
}
//---------------------------------------------------------------------------

