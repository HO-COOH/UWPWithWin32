#include "pch.h"
#include "ServiceFactory.h"
#include "../Idl/CLSID.h"

int main()
{
    winrt::init_apartment();
    
    auto factory = winrt::make<ServiceClassFactory>();
    DWORD cookie;
    winrt::check_hresult(CoRegisterClassObject(
        CLSID_ServerService,
        factory.get(),
        CLSCTX_LOCAL_SERVER,
        REGCLS_MULTIPLEUSE,
        &cookie
    ));

    winrt::handle shutdownEvent{ CreateEvent(nullptr, TRUE, FALSE, nullptr) };
    WaitForSingleObject(shutdownEvent.get(), INFINITE);
    CoRevokeClassObject(cookie);
}
