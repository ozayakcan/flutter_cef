#ifndef FLUTTER_PLUGIN_WEBVIEW_CEF_PLUGIN_H_
#define FLUTTER_PLUGIN_WEBVIEW_CEF_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <webview_plugin.h>
#include <memory>

namespace flutter_cef {

class FlutterCefPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(FlutterDesktopPluginRegistrarRef registrar);
  static void handleMessageProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

  FlutterCefPlugin();
  virtual ~FlutterCefPlugin();

  // Disallow copy and assign.
  FlutterCefPlugin(const FlutterCefPlugin&) = delete;
  FlutterCefPlugin& operator=(const FlutterCefPlugin&) = delete;

 private:
  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::shared_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
  std::shared_ptr<WebviewPlugin> m_plugin;
  
	FlutterDesktopTextureRegistrarRef m_textureRegistrar;

	std::unique_ptr<
		flutter::MethodChannel<flutter::EncodableValue>,
		std::default_delete<flutter::MethodChannel<flutter::EncodableValue>>>
		m_channel = nullptr;

  DWORD m_mainThreadId;
  HWND m_hwnd;
};

}  // namespace flutter_cef

#endif  // FLUTTER_PLUGIN_WEBVIEW_CEF_PLUGIN_H_
