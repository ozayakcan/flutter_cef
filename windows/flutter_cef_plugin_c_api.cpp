#include "include/flutter_cef/flutter_cef_plugin_c_api.h"


#include <include/cef_base.h>
#include "flutter_cef_plugin.h"

void FlutterCefPluginCApiRegisterWithRegistrar(
	FlutterDesktopPluginRegistrarRef registrar) {
	flutter_cef::FlutterCefPlugin::RegisterWithRegistrar(registrar);
}

FLUTTER_PLUGIN_EXPORT int initCEFProcesses(HINSTANCE hInstance)
{
	return flutter_cef::initCEFProcesses(CefMainArgs(hInstance));
}
 
FLUTTER_PLUGIN_EXPORT void handleWndProcForCEF(HWND hwnd, unsigned int message, unsigned __int64 wParam, __int64 lParam)
{
	flutter_cef::FlutterCefPlugin::handleMessageProc(hwnd, message, wParam, lParam);
}
