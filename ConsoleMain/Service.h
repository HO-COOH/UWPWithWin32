#pragma once
#include <Server.Service.g.h>

namespace winrt::Server
{
	namespace implementation
	{
		struct Service : ServiceT<Service>
		{
			Service() = default;

			int Add(int a, int b);
			winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Foundation::IInspectable> Iterate(winrt::hstring const& path);
		};
	}

	namespace factory_implementation
	{
		struct Service : ServiceT<Service, implementation::Service>
		{
		};
	}
}
