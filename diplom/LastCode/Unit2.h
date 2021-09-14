//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class ThrFindDevice : public TThread
{            
private:
protected:
    void __fastcall Execute();
public:
    __fastcall ThrFindDevice(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
 