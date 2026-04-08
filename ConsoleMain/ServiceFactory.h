#pragma once
#include <Unknwnbase.h>

struct ServiceClassFactory : winrt::implements<ServiceClassFactory, IClassFactory>
{
	HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown* outer, REFIID riid, void** result) override;
	HRESULT STDMETHODCALLTYPE LockServer(BOOL lock) override;
};