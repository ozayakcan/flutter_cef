#ifndef WEBVIEW_CEF_TEXTURE_H_
#define WEBVIEW_CEF_TEXTURE_H_

#include <flutter_linux/flutter_linux.h>
#include <gtk/gtk.h>

struct FlutterCefTexture{
    FlPixelBufferTexture parent_instance;
    uint8_t *buffer = nullptr; // your pixel buffer.
    uint32_t width = 0;
    uint32_t height = 0;
};

struct FlutterCefTextureClass{
    FlPixelBufferTextureClass parent_class;
};

G_DEFINE_TYPE(FlutterCefTexture,
              flutter_cef_texture,
              fl_pixel_buffer_texture_get_type())

#define WEBVIEW_CEF_TEXTURE(obj) \
    (G_TYPE_CHECK_INSTANCE_CAST((obj), flutter_cef_texture_get_type(), FlutterCefTexture))

static gboolean flutter_cef_texture_copy_pixels(FlPixelBufferTexture *texture,
                                                const uint8_t **out_buffer,
                                                uint32_t *width,
                                                uint32_t *height,
                                                GError **error) {
    // This method is called on Render Thread. Be careful with your
    // cross-thread operation.

    // @width and @height are initially stored the canvas size in Flutter.

    // You must prepare your pixel buffer in RGBA format.
    // So you may do some format conversion first if your original pixel
    // buffer is not in RGBA format.
    FlutterCefTexture *_texture = WEBVIEW_CEF_TEXTURE(texture);
    if(_texture == nullptr){
        return TRUE;
    }
    *out_buffer = _texture->buffer;
    *width = _texture->width;
    *height = _texture->height;
    return TRUE;
}
static FlutterCefTexture* flutter_cef_texture_new(){
    return WEBVIEW_CEF_TEXTURE(g_object_new(flutter_cef_texture_get_type(), nullptr));
}

static void flutter_cef_texture_class_init(FlutterCefTextureClass *klass)
{
    FL_PIXEL_BUFFER_TEXTURE_CLASS(klass)->copy_pixels = flutter_cef_texture_copy_pixels;
}
static void flutter_cef_texture_init(FlutterCefTexture *self) {}


#endif // WEBVIEW_CEF_TEXTURE_H_
