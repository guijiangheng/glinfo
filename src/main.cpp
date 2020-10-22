#include <napi.h>
#include <glinfo/glinfo.h>

Napi::String getGlInfo(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    std::string glInfo = glinfo::getGlInfo();
    return Napi::String::New(env, glInfo);
}

Napi::String displayWindow(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    std::string result = glinfo::displayWindow();
    return Napi::String::New(env, result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("getGlInfo", Napi::Function::New(env, getGlInfo));
    exports.Set("displayWindow", Napi::Function::New(env, displayWindow));
    return exports;
}

NODE_API_MODULE(glinfo, Init)