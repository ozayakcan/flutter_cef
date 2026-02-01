#import "FlutterCefPlugin.h"
#import "CefWrapper.h"

@implementation FlutterCefPlugin{
    CefWrapper *_cefWrapper;
}

+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {

    FlutterMethodChannel* channel = [FlutterMethodChannel
                                     methodChannelWithName:@"flutter_cef"
                                     binaryMessenger:[registrar messenger]];
    
    FlutterCefPlugin *instance = [[FlutterCefPlugin alloc] init];
    
    [registrar addMethodCallDelegate:instance channel:channel];
    instance->_cefWrapper = [[CefWrapper alloc] init];
    instance->_cefWrapper.channel = channel;
    instance->_cefWrapper.textureRegistry = registrar.textures;
    [webviewPlugins setObject:instance->_cefWrapper forKey: registrar.view.superview];
}

- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
    [self->_cefWrapper handleMethodCallWrapper:call result:result];
}
@end
