# UWPWithWin32
This project act as a starting project template for a UWP bundled with a full-trust win32 application.

## How
1. Create a new UWP C++/WinRT project
2. Create a new Windows Application Packaging Project
3. **Add reference to the UWP project**
4. Select the packaging project as the startup project, disable deployment of the UWP project (in configuration manager)
5. Right click the packaging project -> properties -> Debugging, select native debugging
6. Add a new C++ console application project
7. **Add reference to the console application project in the packaging project**
8. Modify the `Package.appxmanifest` file in the packaging project (see code)
9. Ensure the target platform version of the UWP project is the same as the packing project (I used 22621 in this project)
10. **Add a reference to the corresponding `Windows Desktop Extensions` in the UWP project** (so you have `Windows.ApplicationModel.FullTrustProcessLauncher` available)


----
The console application is launched like this:

```cpp
winrt::Windows::ApplicationModel::FullTrustProcessLauncher::LaunchFullTrustProcessForCurrentAppAsync();
```