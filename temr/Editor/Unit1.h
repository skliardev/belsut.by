//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <inifiles.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormLoad : public TForm
{
__published:
        TListBox *ListLoad;
        TLabel *Label;
        TBitBtn *BthEdit;
        TBitBtn *BthAdd;
        TBitBtn *BthDel;
    TBitBtn *BthUp;
    TBitBtn *BthDown;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ListLoadMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall BthDelClick(TObject *Sender);
        void __fastcall BthAddClick(TObject *Sender);
        void __fastcall BthEditClick(TObject *Sender);
        void __fastcall ListLoadKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall ListLoadDblClick(TObject *Sender);
    void __fastcall BthUpClick(TObject *Sender);
    void __fastcall BthDownClick(TObject *Sender);
private:
        int QMax,Sel;
public:
        __fastcall TFormLoad(TComponent* Owner);
        TIniFile *ft;
        void InfoRead();
};
//---------------------------------------------------------------------------
void TFormLoad::InfoRead()
{
 ListLoad->Clear();
  QMax=ft->ReadInteger("Info","K",0);
 if(QMax!=0)
 {
   for(int i=1; i<=QMax; i++)
        ListLoad->Items->Add(IntToStr(i)+'.'+ft->ReadString(IntToStr(i),"Q",0));
 }
}
//---------------------------------------------------------------------------
extern PACKAGE TFormLoad *FormLoad;
//---------------------------------------------------------------------------
#endif
