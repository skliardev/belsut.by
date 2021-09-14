//---------------------------------------------------------------------------

#ifndef AboutFormH
#define AboutFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TAboutMe : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel;
    TImage *Image;
    TPanel *Panel1;
    TButton *Button;
    TMemo *Memo1;
private:	// User declarations
public:		// User declarations
    __fastcall TAboutMe(TComponent* Owner);
    void SetUpdateProgram(AnsiString DateProgram);
    void SetUpdateVer(AnsiString Version);
    void SetAuthor(AnsiString AuthorName);
    void SetMail(AnsiString PostMail);
    void SetUpdateBase(AnsiString DateBase);
};
//---------------------------------------------------------------------------
extern PACKAGE TAboutMe *AboutMe;
//---------------------------------------------------------------------------
#endif
