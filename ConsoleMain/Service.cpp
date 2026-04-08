#include "pch.h"
#include "Service.h"
#include <Server.Service.g.cpp>
#include <filesystem>
namespace winrt::Server::implementation
{
	int Service::Add(int a, int b)
	{
		return a + b;
	}

	winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Foundation::IInspectable> Service::Iterate(winrt::hstring const& path)
	{
		std::vector<winrt::Windows::Foundation::IInspectable> result;
		std::transform(
			std::filesystem::directory_iterator{ path.data() },
			std::filesystem::directory_iterator{},
			std::back_inserter(result),
			[](std::filesystem::directory_entry const& entry)
			{
				return winrt::box_value(entry.path().wstring().data());
			}
		);
		return winrt::single_threaded_vector(std::move(result));
	}
}