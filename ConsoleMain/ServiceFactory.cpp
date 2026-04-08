#include "pch.h"
#include "ServiceFactory.h"
#include "Service.h"

HRESULT STDMETHODCALLTYPE ServiceClassFactory::CreateInstance(IUnknown* outer, REFIID riid, void** result)
{
	if (outer)
		return CLASS_E_NOAGGREGATION;

	return winrt::make<winrt::Server::implementation::Service>().as<IUnknown>()->QueryInterface(riid, result);
}

HRESULT STDMETHODCALLTYPE ServiceClassFactory::LockServer(BOOL lock)
{
	return S_OK;;
}
