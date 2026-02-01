#include "include/webview_cef/webview_cef_plugin_c_api.h"


#include <include/cef_base.h>
#include "webview_cef_plugin.h"

void WebviewCefPluginCApiRegisterWithRegistrar(
	FlutterDesktopPluginRegistrarRef registrar) {
	webview_cef::WebviewCefPlugin::RegisterWithRegistrar(registrar);
}

FLUTTER_PLUGIN_EXPORT int initCEFProcesses(HINSTANCE hInstance)
{
	return webview_cef::initCEFProcesses(CefMainArgs(hInstance));
}
 
FLUTTER_PLUGIN_EXPORT void handleWndProcForCEF(HWND hwnd, unsigned int message, unsigned __int64 wParam, __int64 lParam)
{
	webview_cef::WebviewCefPlugin::handleMessageProc(hwnd, message, wParam, lParam);
}
