#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include <winrt/Windows.ApplicationModel.h>
#include <winrt/Server.h>
#include <winrt/Windows.UI.Core.h>
#include <wil/cppwinrt_helpers.h>
#include "../Idl/CLSID.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::UWPMain::implementation
{
    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::fire_and_forget MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
        auto service = winrt::create_instance<winrt::Server::Service>(CLSID_ServerService, CLSCTX_LOCAL_SERVER);
        auto r = service.Add(1, 2);

        auto iterateResult = service.Iterate(L"C:\\");
        co_await wil::resume_foreground(Dispatcher());
        FileList().ItemsSource(iterateResult);
    }
}
