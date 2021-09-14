//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TFormEdit *FormEdit;
bool mod=0;
int vopr;
//---------------------------------------------------------------------------
__fastcall TFormEdit::TFormEdit(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormEdit::T1KeyPress(TObject *Sender, char &Key)
{
 if(Key==13) Key=0; //Enter off
 else mod=1;
}
//---------------------------------------------------------------------------
void __fastcall TFormEdit::FormCloseQuery(TObject *Sender, bool &CanClose)
{
 __int8 i;
 TEdit* Be[7]={Be1,Be2,Be3,Be4,Be5,Be6,Be7};
 TEdit* Le[7]={Le1,Le2,Le3,Le4,Le5,Le6,Le7};
 if(mod==1)
 {
  switch (MessageBox(NULL,"Сохранить изменения в файле?","Сохранение",MB_YESNOCANCEL | MB_ICONQUESTION))
  {
    case IDYES :
     i=Check(K->Value);
     if(i==0)
     {
      //Clear useless strings
      if(K->Value < fti->ReadInteger(IntToStr(FormLoad->ListLoad->ItemIndex+1),"K",0))
       for(i=K->Value+1; i<fti->ReadInteger(IntToStr(FormLoad->ListLoad->ItemIndex+1),"K",0); i++)
       {
        fti->DeleteKey(IntToStr(FormLoad->ListLoad->ItemIndex+1),"Q"+IntToStr(i));
        fti->DeleteKey(IntToStr(FormLoad->ListLoad->ItemIndex+1),"A"+IntToStr(i));
       }
      //Change Q
      fti->WriteString(IntToStr(FormLoad->ListLoad->ItemIndex+1),"Q","\""+T1->Text+"\"");
      //Change K Qn An
       fti->WriteString(IntToStr(FormLoad->ListLoad->ItemIndex+1),"K","\""+IntToStr(K->Value)+"\"");
       for(i=1; i<=K->Value; i++)
       {
        fti->WriteString(IntToStr(FormLoad->ListLoad->ItemIndex+1),"Q"+IntToStr(i),"\""+Le[i-1]->Text+"\"");
        fti->WriteString(IntToStr(FormLoad->ListLoad->ItemIndex+1),"A"+IntToStr(i),"\""+Be[i-1]->Text+"\"");
       }
      //Change A
      fti->WriteString(IntToStr(FormLoad->ListLoad->ItemIndex+1),"A","\""+Str2A()+"\"");
     }
     else
     {
      if(i==1) ShowMessage("Не соотнесены все варианты ответов!");
      else ShowMessage("Варианты ответов повторяются!");
      CanClose=false;
      break;
     }
     mod=0;
     break;
    case IDNO :
     mod=0;
     break;
    case IDCANCEL :
     CanClose=false;
     break;
  }
 }
}
//---------------------------------------------------------------------------
void __fastcall TFormEdit::FormCreate(TObject *Sender)
{
 fti=new TIniFile(ExtractFilePath(ParamStr(0))+"test.ft");
}
//---------------------------------------------------------------------------

void __fastcall TFormEdit::FormDestroy(TObject *Sender)
{
 delete fti;        
}
//---------------------------------------------------------------------------
void __fastcall TFormEdit::T3oKeyPress(TObject *Sender, char &Key)
{
 if((Key>='0')&&(Key<='9'));
        else if(Key==8);
             else Key=0;
}
//---------------------------------------------------------------------------


void __fastcall TFormEdit::KChange(TObject *Sender)
{
 K_Change();
 mod=1;
}
//---------------------------------------------------------------------------
void __fastcall TFormEdit::B1Change(TObject *Sender)
{
 mod=1;        
}
//---------------------------------------------------------------------------

void __fastcall TFormEdit::FormShow(TObject *Sender)
{
 mod=0;        
}
//---------------------------------------------------------------------------

void __fastcall TFormEdit::KKeyPress(TObject *Sender, char &Key)
{
 Key=0;        
}
//---------------------------------------------------------------------------



void __fastcall TFormEdit::Le1KeyPress(TObject *Sender, char &Key)
{
 mod=1;    
}
//---------------------------------------------------------------------------

