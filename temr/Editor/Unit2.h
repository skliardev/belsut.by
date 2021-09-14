//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <inifiles.hpp>
#include "CSPIN.h"
//---------------------------------------------------------------------------
class TFormEdit : public TForm
{
__published:
        TMemo *T1;
        TLabel *Label;
        TLabel *L1;
        TLabel *L2;
        TLabel *L3;
        TLabel *L4;
        TLabel *L5;
        TLabel *L6;
        TLabel *L7;
        TLabel *Lb1;
        TLabel *Lb2;
        TLabel *Lb3;
        TLabel *Lb4;
        TLabel *Lb5;
        TLabel *Lb6;
        TLabel *Lb7;
        TComboBox *B1;
        TComboBox *B2;
        TComboBox *B3;
        TComboBox *B4;
        TComboBox *B5;
        TComboBox *B6;
        TComboBox *B7;
        TCSpinEdit *K;
        TEdit *T3o;
    TEdit *Le1;
    TEdit *Le2;
    TEdit *Le4;
    TEdit *Le3;
    TEdit *Le6;
    TEdit *Le5;
    TEdit *Le7;
    TEdit *Be1;
    TEdit *Be2;
    TEdit *Be3;
    TEdit *Be4;
    TEdit *Be5;
    TEdit *Be6;
    TEdit *Be7;
        void __fastcall T1KeyPress(TObject *Sender, char &Key);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall T3oKeyPress(TObject *Sender, char &Key);
        void __fastcall KChange(TObject *Sender);
        void __fastcall B1Change(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall KKeyPress(TObject *Sender, char &Key);
    void __fastcall Le1KeyPress(TObject *Sender, char &Key);
private:
public:
        __fastcall TFormEdit(TComponent* Owner);
        AnsiString Code(char *strings);
        AnsiString Str2A();
        __int8 Check(int n);
        void K_Change();
        void Ques(int n);
        TIniFile *fti;
};
//---------------------------------------------------------------------------
AnsiString TFormEdit::Code(char *strings)
{
 AnsiString temp="";
 for(int i=0; i<(int)strlen(strings); i++ )
       temp+=(char)(strings[i]^(char)i-strlen(strings)+15);
 return temp;
}
//---------------------------------------------------------------------------
AnsiString TFormEdit::Str2A()
{
 __int8 i;
 AnsiString str="";
 TComboBox* B[7]={B1,B2,B3,B4,B5,B6,B7};

 for(i=0; i<K->Value; i++)
      str=str+IntToStr(B[i]->ItemIndex);
 str=Code(str.c_str());
 return str;
}
//---------------------------------------------------------------------------
__int8 TFormEdit::Check(int n)
{
typedef Set <__int8, 1, 7> QuesSet;
 __int8 i;
 __int8 Xpenb=0;
 QuesSet q;
 TComboBox* B[7]={B1,B2,B3,B4,B5,B6,B7};

 for(i=0;i<n;i++)
  if(B[i]->ItemIndex<1)
  {
        Xpenb=1;
        break;
  }
  else
   if(q.Contains(B[i]->ItemIndex))
   {
        Xpenb=2;
        break;
   }
   else q << B[i]->ItemIndex;

 return Xpenb;
}
//---------------------------------------------------------------------------
void TFormEdit::K_Change()
{
 __int8 i,j;
 AnsiString str;
 TComboBox* B[7]={B1,B2,B3,B4,B5,B6,B7};
 TLabel* L[7]={L1,L2,L3,L4,L5,L6,L7};
 TLabel* Lb[7]={Lb1,Lb2,Lb3,Lb4,Lb5,Lb6,Lb7};
 TEdit* Be[7]={Be1,Be2,Be3,Be4,Be5,Be6,Be7};
 TEdit* Le[7]={Le1,Le2,Le3,Le4,Le5,Le6,Le7};
 
 if(B[0]->Items->Count == K->Value+2)
 {
  j=B[0]->ItemIndex;
  B[0]->Items->Delete(B[0]->Items->Count-1);
  if(j < B[0]->Items->Count) B[0]->ItemIndex=j;
  else B[0]->ItemIndex=0;

  Le[K->Value+1]->Enabled=false;
  Be[K->Value+1]->Enabled=false;
  /*
  T2->Lines->Delete(T2->Lines->Count-1);
  str=T2->Lines->Strings[T2->Lines->Count-1];
  T2->Lines->Delete(T2->Lines->Count-1);
  T2->Lines->Strings[T2->Lines->Count]=str;

  T3->Lines->Delete(T3->Lines->Count-1);
  str=T3->Lines->Strings[T3->Lines->Count-1];
  T3->Lines->Delete(T3->Lines->Count-1);
  T3->Lines->Strings[T3->Lines->Count]=str;
  */
 }
 else if(B[0]->Items->Count == K->Value)
 {
  B[0]->Items->Add(IntToStr(K->Value)+")");
  Le[K->Value]->Enabled=true;
  Be[K->Value]->Enabled=true;
  /*
  T2->Lines->Add(IntToStr(K->Value)+") ");
  T3->Lines->Add(AnsiString(char(K->Value-33))+" ");
  */
 }

 for(i=1;i<K->Value;i++)
 {
  j=B[i]->ItemIndex;
  B[i]->Items=B[0]->Items;
  if(j < B[0]->Items->Count)
   B[i]->ItemIndex=j;
  else
   B[i]->ItemIndex=0;
 }

 for(i=0;i<=7;i++)
        if(i<=K->Value)
        {
                B[i-1]->Enabled=true;
                L[i-1]->Enabled=true;
                Lb[i-1]->Enabled=true;
                Le[i-1]->Enabled=true;
                Be[i-1]->Enabled=true;
        }
        else
        {
                B[i-1]->Enabled=false;
                B[i-1]->ItemIndex=0;
                L[i-1]->Enabled=false;
                Lb[i-1]->Enabled=false;
                Le[i-1]->Enabled=false;
                Be[i-1]->Enabled=false;
        }
}
//---------------------------------------------------------------------------
void TFormEdit::Ques(int n)
{
 __int8 i;
 AnsiString s;
 TComboBox* B[7]={B1,B2,B3,B4,B5,B6,B7};
 TLabel* L[7]={L1,L2,L3,L4,L5,L6,L7};
 TLabel* Lb[7]={Lb1,Lb2,Lb3,Lb4,Lb5,Lb6,Lb7};
 TEdit* Be[7]={Be1,Be2,Be3,Be4,Be5,Be6,Be7};
 TEdit* Le[7]={Le1,Le2,Le3,Le4,Le5,Le6,Le7};
 
 //Загрузка T1
 T1->Text=fti->ReadString(IntToStr(n),"Q","-");
 s=Code(fti->ReadString(IntToStr(n),"A","-").c_str());
 B[0]->Items->Clear();
 B[0]->Items->Add(" - ");
 K->Value=fti->ReadInteger(IntToStr(n),"K",0);
 for(i=1;i<=K->Value;i++)
        B[0]->Items->Add(IntToStr(i)+")");
 //Загрузка T2 и T3
 for(i=1;i<=K->Value;i++)
 {
        if(i!=1)
            B[i-1]->Items=B[0]->Items;
        Le[i-1]->Text=fti->ReadString(IntToStr(n),"Q"+IntToStr(i),0);
        Be[i-1]->Text=fti->ReadString(IntToStr(n),"A"+IntToStr(i),0);
        B[i-1]->ItemIndex=StrToInt(s[i]);
 }
 //Загрузка T3o
 T3o->Text=fti->ReadString(n,"A","-");
}
//---------------------------------------------------------------------------
extern PACKAGE TFormEdit *FormEdit;
//---------------------------------------------------------------------------
#endif
