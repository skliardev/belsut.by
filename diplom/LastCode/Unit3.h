//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <IdTCPClient.hpp>
//---------------------------------------------------------------------------
class TrRun : public TThread
{            
private:
protected:
    void __fastcall Execute();
public:
    AnsiString dir;
    TIdIcmpClient *IcmpClient;
    void __fastcall IcmpClientReply(TComponent *ASender, const TReplyStatus &AReplyStatus);
    bool Ping(AnsiString ip);
    __fastcall TrRun(bool CreateSuspended);
    AnsiString tmp;
    TStringList *mem;
    bool PING;
};
//---------------------------------------------------------------------------
void __fastcall TrRun::IcmpClientReply(TComponent *ASender,
      const TReplyStatus &AReplyStatus)
{
    if(AReplyStatus.BytesReceived > 0) PING = true;
    else PING = false;
}
//---------------------------------------------------------------------------
bool TrRun::Ping(AnsiString ip)
{
    PING = false;
    IcmpClient->ReceiveTimeout = 1000;
    IcmpClient->Host = ip;
    IcmpClient->Ping();
    return PING;
}
#endif
 