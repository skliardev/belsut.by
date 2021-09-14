//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CGAUGES.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *TimeLabel;
        TCGauge *Progr;
        TLabel *Stat;
        TTimer *Timer;
        TImageList *IconList;
        TListView *List;
        TListBox *List2;
        TBitBtn *Next;
        TEdit *Edit2;
        TLabel *Label1;
        TMemo *Memo;
        TBitBtn *Abort;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormCanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
        void __fastcall TimerTimer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Func_CheckForEnd();
        void __fastcall NextClick(TObject *Sender);
        void __fastcall List2Click(TObject *Sender);
        void __fastcall EndClick(TObject *Sender);
        void __fastcall CheckClick(TObject *Sender);
        void __fastcall SkipClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ListMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall AbortClick(TObject *Sender);
    void __fastcall ListCustomDrawItem(TCustomListView *Sender,
          TListItem *Item, TCustomDrawState State, bool &DefaultDraw);
private:	// User declarations
        void __fastcall ClearValues();
        void __fastcall ProgressBarRepaint();
        void __fastcall GetUserName();
        void __fastcall TestStart(TObject *Sender);
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        AnsiString Code(char *strings);
};
//---------------------------------------------------------------------------
AnsiString TForm1::Code(char *strings)
{
 AnsiString temp="";
 for(int i=0; i<(int)strlen(strings); i++ )
       temp+=(char)(strings[i]^(char)i-strlen(strings)+15);
 return temp;
}
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
