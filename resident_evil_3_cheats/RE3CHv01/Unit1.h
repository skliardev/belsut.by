//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <stdio.h>
#include <iostream.h>
#include <fstream>
#include <iostream>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TComboBox *ComboBox1;
    TLabel *Label2;
    TComboBox *ComboBox2;
    TLabel *Label3;
    TComboBox *ComboBox3;
    TLabel *Label4;
    TComboBox *ComboBox4;
    TLabel *Label5;
    TComboBox *ComboBox5;
    TLabel *Label6;
    TComboBox *ComboBox6;
    TLabel *Label7;
    TComboBox *ComboBox7;
    TLabel *Label8;
    TComboBox *ComboBox8;
    TLabel *Label9;
    TComboBox *ComboBox9;
    TLabel *Label10;
    TComboBox *ComboBox10;
    TLabel *Label11;
    TCheckBox *CheckBox1;
    TListBox *ListBox1;
    TLabel *Label12;
    TComboBox *ComboBox11;
    TCheckBox *CheckBox2;
    TCheckBox *CheckBox3;
    TCheckBox *CheckBox4;
    TCheckBox *CheckBox5;
    TCheckBox *CheckBox6;
    TCheckBox *CheckBox7;
    TCheckBox *CheckBox8;
    TCheckBox *CheckBox9;
    TCheckBox *CheckBox10;
    TCheckBox *CheckBox11;
    TCheckBox *CheckBox12;
    TButton *Button1;
    TButton *Button2;
    TLabel *Label13;
    TEdit *Edit11;
    void __fastcall N1Click(TObject *Sender);
    void __fastcall CheckBox1Click(TObject *Sender);
    void __fastcall ComboBox1Change(TObject *Sender);
    void __fastcall CheckBox2Click(TObject *Sender);
    void __fastcall ListBox1Click(TObject *Sender);
    void __fastcall ComboBox11Change(TObject *Sender);
    void __fastcall CheckBox12Click(TObject *Sender);
    void __fastcall Edit11KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit11Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
    void LoadCheckBox();
    void __fastcall Edit10Change(TObject *Sender);
    TEdit *Edit[10];

   typedef struct {
        unsigned char ID;
        unsigned char Number;
        unsigned char Attrib;
        unsigned char zByte;
    }tSlotItem;

    typedef struct {
        unsigned char State;
        unsigned Offset;
    } tSidePack;

    typedef struct{
        unsigned Offset;
        tSlotItem Slot[10];
    }tInventory;

    typedef struct{
        unsigned Offset;
        tSlotItem Slot[64];
    }tItemBox;

    typedef struct{
        AnsiString Name;
        tInventory Inventory;
        tItemBox   ItemBox;
        tSidePack  SidePack;
    }tActor;

    FILE *fi;
    AnsiString file;
    unsigned char selActor;
    tActor Actor[2];
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
