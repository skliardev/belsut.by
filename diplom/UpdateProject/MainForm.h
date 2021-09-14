//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
#include <ImgList.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TSelectForm : public TForm
{
__published:	// IDE-managed Components
    TListBox *List;
    TMainMenu *MainMenu;
    TMenuItem *Mode;
    TMenuItem *About;
    TMenuItem *Author;
    TMenuItem *GodMode;
    TImageList *IList;
    TADOConnection *Connect;
    TADOQuery *Query;
    TADOQuery *IQuery;
    void __fastcall AuthorClick(TObject *Sender);
    void __fastcall ListDblClick(TObject *Sender);
    void __fastcall ListDrawItem(TWinControl *Control, int Index,
          TRect &Rect, TOwnerDrawState State);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall GodModeClick(TObject *Sender);
    void __fastcall ListKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
    unsigned selDevice;
    unsigned selConfig;
    unsigned selLevel;
    AnsiString lastUpdate;
    bool stdSelect;
public:		// User declarations
    __fastcall TSelectForm(TComponent* Owner);
    Graphics::TBitmap *bmp;
    TPicture *bSelect;
    TLocateOptions S;
    TMemoryStream *mem;
    unsigned GetDevice() { return selDevice; }
    unsigned GetConfig() { return selConfig; }
    unsigned GetLevel()  { return selLevel; }
    void LoadList();
};
//---------------------------------------------------------------------------
extern PACKAGE TSelectForm *SelectForm;
//---------------------------------------------------------------------------
#endif
