//---------------------------------------------------------------------------

#ifndef EditFormH
#define EditFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include "MainForm.h"
//---------------------------------------------------------------------------
class TEditSelect : public TForm
{
__published:	// IDE-managed Components
    TEdit *Edit;
    TLabel *Label1;
    TLabel *Label2;
    TComboBox *ComboBox;
    TPanel *Panel1;
    TButton *bthExec;
    TShape *Shape1;
    TImage *Image;
    TOpenPictureDialog *ODialog;
    TCheckBox *CheckWLAN;
    TCheckBox *CheckVPN;
    void __fastcall ComboBoxChange(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall bthExecClick(TObject *Sender);
private:	// User declarations
    unsigned short status;
public:		// User declarations
    __fastcall TEditSelect(TComponent* Owner);
    void AddDevice()
    {
        status = 0;
        ReLoadBox();
        Edit->Clear();
        Caption = "Добавить устройство";
        bthExec->Caption = "Добавить";
        ComboBox->ItemIndex = -1;
        Image->Picture->Bitmap->FreeImage();
        Image->Picture->Bitmap = NULL;
        ShowModal();
    }
    void EditDevice()
    {
        status = 1;
        ReLoadBox();
        Caption = "Редактировать устройство";
        bthExec->Caption = "Применить";
        Edit->Text = SelectForm->List->Items->Strings[SelectForm->List->ItemIndex];
        Query->SQL->Text = "SELECT * FROM tName";
        Query->Active = true;
        Query->Locate("Label", Edit->Text, SelectForm->S);
        IQuery->Locate("Code", Query->FieldByName("ImgCode")->Value, SelectForm->S);
        ComboBox->ItemIndex = ComboBox->Items->IndexOf(IQuery->FieldByName("Name")->AsString);
        ComboBox->OnChange(this);
        ShowModal();
    }
    void AddConfig()
    {
        status = 2;
        ReLoadBox();
        Edit->Clear();
        Caption = "Добавить профиль";
        bthExec->Caption = "Добавить";
        ComboBox->ItemIndex = -1;
        Image->Picture->Bitmap->FreeImage();
        Image->Picture->Bitmap = NULL;
        CheckWLAN->Visible = true;
        CheckVPN->Visible = true;
        CheckWLAN->Checked = false;
        CheckVPN->Checked = false;
        ShowModal();
        CheckWLAN->Visible = false;
        CheckVPN->Visible = false;
    }
    void EditConfig()
    {
        status = 3;
        ReLoadBox();
        Caption = "Редактировать профиль";
        bthExec->Caption = "Применить";
        Edit->Text = SelectForm->List->Items->Strings[SelectForm->List->ItemIndex];
        Query->SQL->Text = "SELECT * FROM tName";
        Query->Active = true;
        Query->Locate("Label", Edit->Text, SelectForm->S);
        IQuery->Locate("Code", Query->FieldByName("ImgCode")->Value, SelectForm->S);
        ComboBox->ItemIndex = ComboBox->Items->IndexOf(IQuery->FieldByName("Name")->AsString);
        ComboBox->OnChange(this);
        CheckWLAN->Visible = true;
        CheckVPN->Visible = true;
        CheckWLAN->Checked = (Query->FieldByName("FormWiFi")->AsString == "True")?true:false;
        CheckVPN->Checked = (Query->FieldByName("FormVPN")->AsString == "True")?true:false;
        ShowModal();
        CheckWLAN->Visible = false;
        CheckVPN->Visible = false;
    }
    AnsiString GetFileName(AnsiString strPath);
    void ReLoadBox();
    TMemoryStream *mem;
    TADOQuery *Query;
    TADOQuery *IQuery;
};
//---------------------------------------------------------------------------
extern PACKAGE TEditSelect *EditSelect;
//---------------------------------------------------------------------------
#endif
