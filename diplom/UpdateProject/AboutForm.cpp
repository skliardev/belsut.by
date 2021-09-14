//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AboutForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAboutMe *AboutMe;
//---------------------------------------------------------------------------
__fastcall TAboutMe::TAboutMe(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TAboutMe::SetUpdateProgram(AnsiString DateProgram)
{
    Memo1->Lines->Strings[3] = "--> " + DateProgram;
}
//---------------------------------------------------------------------------
void TAboutMe::SetUpdateVer(AnsiString Version)
{
    Memo1->Lines->Strings[5] = "--> " + Version;
}
//---------------------------------------------------------------------------
void TAboutMe::SetAuthor(AnsiString AuthorName)
{
    Memo1->Lines->Strings[7] = "--> " + AuthorName;
}
//---------------------------------------------------------------------------
void TAboutMe::SetMail(AnsiString PostMail)
{
    Memo1->Lines->Strings[9] = "--> " + PostMail;
}
//---------------------------------------------------------------------------
void TAboutMe::SetUpdateBase(AnsiString DateBase)
{
    Memo1->Lines->Strings[13] = "--> " + DateBase;
}
//---------------------------------------------------------------------------
