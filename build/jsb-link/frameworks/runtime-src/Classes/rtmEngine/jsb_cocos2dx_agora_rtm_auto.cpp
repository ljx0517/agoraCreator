#include "jsb_cocos2dx_agora_rtm_auto.hpp"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "include/IAgoraRtmService.h"
#include "cocos2d.h"
#include "platform/CCApplication.h"
#include "base/CCScheduler.h"

#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>

#include <string>
#include <vector>

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#define AGORA_CALL __cdecl
#if defined(AGORARTC_EXPORT)
#define AGORA_API extern "C" __declspec(dllexport)
#else
#define AGORA_API extern "C" __declspec(dllimport)
#endif
#elif defined(__APPLE__)
#define AGORA_API __attribute__((visibility("default"))) extern "C"
#define AGORA_CALL
#elif defined(__ANDROID__) || defined(__linux__) || defined(__linux)
#define AGORA_API extern "C" __attribute__((visibility("default")))
#define AGORA_CALL
#else
#define AGORA_API extern "C"
#define AGORA_CALL
#endif





using namespace cocos2d;
using namespace agora::rtm;

class CagoraRtmJsWrapper;
CagoraRtmJsWrapper* g_rtmSingleInstance;

se::Object* __jsb_agora_rtm_IRtmCallEventHandler_proto = nullptr;
se::Class* __jsb_agora_rtm_IRtmCallEventHandler_class = nullptr;

class CagoraRtmJsWrapper:public agora::rtm::IRtmServiceEventHandler {
public:
    CagoraRtmJsWrapper();
    ~CagoraRtmJsWrapper();
    

public:
    se::Object* _refObj;
    virtual void onLoginSuccess();
    
};

CagoraRtmJsWrapper::CagoraRtmJsWrapper()
{
}

CagoraRtmJsWrapper::~CagoraRtmJsWrapper()
{

}
void CagoraRtmJsWrapper::onLoginSuccess()
{
    CCLOG("[Agora cocos rtm]:onLoginSuccess");
}







//////////////////////


static bool js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationReceivedByPeer(se::State& s)
{
    agora::rtm::IRtmCallEventHandler* cobj = (agora::rtm::IRtmCallEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationReceivedByPeer : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        agora::rtm::ILocalCallInvitation* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationReceivedByPeer : Error processing arguments");
        cobj->onLocalInvitationReceivedByPeer(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationReceivedByPeer)

static bool js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationRefused(se::State& s)
{
    agora::rtm::IRtmCallEventHandler* cobj = (agora::rtm::IRtmCallEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationRefused : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        agora::rtm::IRemoteCallInvitation* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationRefused : Error processing arguments");
        cobj->onRemoteInvitationRefused(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationRefused)

static bool js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationRefused(se::State& s)
{
    agora::rtm::IRtmCallEventHandler* cobj = (agora::rtm::IRtmCallEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationRefused : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        agora::rtm::ILocalCallInvitation* arg0 = nullptr;
        const char* arg1 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        std::string arg1_tmp; ok &= seval_to_std_string(args[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationRefused : Error processing arguments");
        cobj->onLocalInvitationRefused(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationRefused)

static bool js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationCanceled(se::State& s)
{
    agora::rtm::IRtmCallEventHandler* cobj = (agora::rtm::IRtmCallEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationCanceled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        agora::rtm::IRemoteCallInvitation* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationCanceled : Error processing arguments");
        cobj->onRemoteInvitationCanceled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationCanceled)

static bool js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationFailure(se::State& s)
{
    agora::rtm::IRtmCallEventHandler* cobj = (agora::rtm::IRtmCallEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationFailure : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        agora::rtm::ILocalCallInvitation* arg0 = nullptr;
        agora::rtm::LOCAL_INVITATION_ERR_CODE arg1;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationFailure : Error processing arguments");
        cobj->onLocalInvitationFailure(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationFailure)

static bool js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationReceived(se::State& s)
{
    agora::rtm::IRtmCallEventHandler* cobj = (agora::rtm::IRtmCallEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationReceived : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        agora::rtm::IRemoteCallInvitation* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationReceived : Error processing arguments");
        cobj->onRemoteInvitationReceived(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationReceived)

static bool js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationAccepted(se::State& s)
{
    agora::rtm::IRtmCallEventHandler* cobj = (agora::rtm::IRtmCallEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationAccepted : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        agora::rtm::IRemoteCallInvitation* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationAccepted : Error processing arguments");
        cobj->onRemoteInvitationAccepted(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationAccepted)

static bool js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationAccepted(se::State& s)
{
    agora::rtm::IRtmCallEventHandler* cobj = (agora::rtm::IRtmCallEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationAccepted : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        agora::rtm::ILocalCallInvitation* arg0 = nullptr;
        const char* arg1 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        std::string arg1_tmp; ok &= seval_to_std_string(args[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationAccepted : Error processing arguments");
        cobj->onLocalInvitationAccepted(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationAccepted)

static bool js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationCanceled(se::State& s)
{
    agora::rtm::IRtmCallEventHandler* cobj = (agora::rtm::IRtmCallEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationCanceled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        agora::rtm::ILocalCallInvitation* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationCanceled : Error processing arguments");
        cobj->onLocalInvitationCanceled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationCanceled)

static bool js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationFailure(se::State& s)
{
    agora::rtm::IRtmCallEventHandler* cobj = (agora::rtm::IRtmCallEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationFailure : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        agora::rtm::IRemoteCallInvitation* arg0 = nullptr;
        agora::rtm::REMOTE_INVITATION_ERR_CODE arg1;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationFailure : Error processing arguments");
        cobj->onRemoteInvitationFailure(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationFailure)



static bool js_agora_rtm_IRtmCallEventHandler_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (agora::rtm::IRtmCallEventHandler)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        agora::rtm::IRtmCallEventHandler* cobj = (agora::rtm::IRtmCallEventHandler*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_agora_rtm_IRtmCallEventHandler_finalize)

bool js_register_cocos2dx_agora_rtm_IRtmCallEventHandler(se::Object* obj)
{
    auto cls = se::Class::create("IRtmCallEventHandler", obj, nullptr, nullptr);

    cls->defineFunction("onLocalInvitationReceivedByPeer", _SE(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationReceivedByPeer));
    cls->defineFunction("onRemoteInvitationRefused", _SE(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationRefused));
    cls->defineFunction("onLocalInvitationRefused", _SE(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationRefused));
    cls->defineFunction("onRemoteInvitationCanceled", _SE(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationCanceled));
    cls->defineFunction("onLocalInvitationFailure", _SE(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationFailure));
    cls->defineFunction("onRemoteInvitationReceived", _SE(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationReceived));
    cls->defineFunction("onRemoteInvitationAccepted", _SE(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationAccepted));
    cls->defineFunction("onLocalInvitationAccepted", _SE(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationAccepted));
    cls->defineFunction("onLocalInvitationCanceled", _SE(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onLocalInvitationCanceled));
    cls->defineFunction("onRemoteInvitationFailure", _SE(js_cocos2dx_agora_rtm_IRtmCallEventHandler_onRemoteInvitationFailure));
    cls->defineFinalizeFunction(_SE(js_agora_rtm_IRtmCallEventHandler_finalize));
    cls->install();
    JSBClassType::registerClass<agora::rtm::IRtmCallEventHandler>(cls);

    __jsb_agora_rtm_IRtmCallEventHandler_proto = cls->getProto();
    __jsb_agora_rtm_IRtmCallEventHandler_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_agora_rtm_IRtmServiceEventHandler_proto = nullptr;
se::Class* __jsb_agora_rtm_IRtmServiceEventHandler_class = nullptr;

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaDownloadingProgress(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaDownloadingProgress : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        long long arg0 = 0;
        agora::rtm::MediaOperationProgress arg1;
        ok &= seval_to_longlong(args[0], &arg0);
        #pragma warning NO CONVERSION TO NATIVE FOR MediaOperationProgress
        ok = false;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaDownloadingProgress : Error processing arguments");
        cobj->onMediaDownloadingProgress(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaDownloadingProgress)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onGetUserAttributesResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onGetUserAttributesResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 5) {
        long long arg0 = 0;
        const char* arg1 = nullptr;
        const agora::rtm::RtmAttribute* arg2 = nullptr;
        int arg3 = 0;
        agora::rtm::ATTRIBUTE_OPERATION_ERR arg4;
        ok &= seval_to_longlong(args[0], &arg0);
        std::string arg1_tmp; ok &= seval_to_std_string(args[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
        #pragma warning NO CONVERSION TO NATIVE FOR RtmAttribute*
        ok = false;
        do { int32_t tmp = 0; ok &= seval_to_int32(args[3], &tmp); arg3 = (int)tmp; } while(false);
        ok &= seval_to_uint32(args[4], (uint32_t*)&arg4);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onGetUserAttributesResult : Error processing arguments");
        cobj->onGetUserAttributesResult(arg0, arg1, arg2, arg3, arg4);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onGetUserAttributesResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSendMessageResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSendMessageResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        long long arg0 = 0;
        agora::rtm::PEER_MESSAGE_ERR_CODE arg1;
        ok &= seval_to_longlong(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSendMessageResult : Error processing arguments");
        cobj->onSendMessageResult(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSendMessageResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onAddOrUpdateChannelAttributesResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onAddOrUpdateChannelAttributesResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        long long arg0 = 0;
        agora::rtm::ATTRIBUTE_OPERATION_ERR arg1;
        ok &= seval_to_longlong(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onAddOrUpdateChannelAttributesResult : Error processing arguments");
        cobj->onAddOrUpdateChannelAttributesResult(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onAddOrUpdateChannelAttributesResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onImageMessageReceivedFromPeer(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onImageMessageReceivedFromPeer : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        const agora::rtm::IImageMessage* arg1 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_native_ptr(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onImageMessageReceivedFromPeer : Error processing arguments");
        cobj->onImageMessageReceivedFromPeer(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onImageMessageReceivedFromPeer)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaUploadingProgress(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaUploadingProgress : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        long long arg0 = 0;
        agora::rtm::MediaOperationProgress arg1;
        ok &= seval_to_longlong(args[0], &arg0);
        #pragma warning NO CONVERSION TO NATIVE FOR MediaOperationProgress
        ok = false;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaUploadingProgress : Error processing arguments");
        cobj->onMediaUploadingProgress(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaUploadingProgress)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onFileMediaUploadResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onFileMediaUploadResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        long long arg0 = 0;
        agora::rtm::IFileMessage* arg1 = nullptr;
        agora::rtm::UPLOAD_MEDIA_ERR_CODE arg2;
        ok &= seval_to_longlong(args[0], &arg0);
        ok &= seval_to_native_ptr(args[1], &arg1);
        ok &= seval_to_uint32(args[2], (uint32_t*)&arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onFileMediaUploadResult : Error processing arguments");
        cobj->onFileMediaUploadResult(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onFileMediaUploadResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onConnectionStateChanged(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onConnectionStateChanged : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        agora::rtm::CONNECTION_STATE arg0;
        agora::rtm::CONNECTION_CHANGE_REASON arg1;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onConnectionStateChanged : Error processing arguments");
        cobj->onConnectionStateChanged(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onConnectionStateChanged)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onRenewTokenResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onRenewTokenResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        agora::rtm::RENEW_TOKEN_ERR_CODE arg1;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onRenewTokenResult : Error processing arguments");
        cobj->onRenewTokenResult(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onRenewTokenResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSetLocalUserAttributesResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSetLocalUserAttributesResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        long long arg0 = 0;
        agora::rtm::ATTRIBUTE_OPERATION_ERR arg1;
        ok &= seval_to_longlong(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSetLocalUserAttributesResult : Error processing arguments");
        cobj->onSetLocalUserAttributesResult(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSetLocalUserAttributesResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onImageMediaUploadResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onImageMediaUploadResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        long long arg0 = 0;
        agora::rtm::IImageMessage* arg1 = nullptr;
        agora::rtm::UPLOAD_MEDIA_ERR_CODE arg2;
        ok &= seval_to_longlong(args[0], &arg0);
        ok &= seval_to_native_ptr(args[1], &arg1);
        ok &= seval_to_uint32(args[2], (uint32_t*)&arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onImageMediaUploadResult : Error processing arguments");
        cobj->onImageMediaUploadResult(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onImageMediaUploadResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onDeleteLocalUserAttributesResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onDeleteLocalUserAttributesResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        long long arg0 = 0;
        agora::rtm::ATTRIBUTE_OPERATION_ERR arg1;
        ok &= seval_to_longlong(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onDeleteLocalUserAttributesResult : Error processing arguments");
        cobj->onDeleteLocalUserAttributesResult(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onDeleteLocalUserAttributesResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onLoginSuccess(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onLoginSuccess : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->onLoginSuccess();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onLoginSuccess)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaDownloadToFileResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaDownloadToFileResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        long long arg0 = 0;
        agora::rtm::DOWNLOAD_MEDIA_ERR_CODE arg1;
        ok &= seval_to_longlong(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaDownloadToFileResult : Error processing arguments");
        cobj->onMediaDownloadToFileResult(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaDownloadToFileResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onLoginFailure(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onLoginFailure : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        agora::rtm::LOGIN_ERR_CODE arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onLoginFailure : Error processing arguments");
        cobj->onLoginFailure(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onLoginFailure)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaCancelResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaCancelResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        long long arg0 = 0;
        agora::rtm::CANCEL_MEDIA_ERR_CODE arg1;
        ok &= seval_to_longlong(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaCancelResult : Error processing arguments");
        cobj->onMediaCancelResult(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaCancelResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onClearLocalUserAttributesResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onClearLocalUserAttributesResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        long long arg0 = 0;
        agora::rtm::ATTRIBUTE_OPERATION_ERR arg1;
        ok &= seval_to_longlong(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onClearLocalUserAttributesResult : Error processing arguments");
        cobj->onClearLocalUserAttributesResult(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onClearLocalUserAttributesResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onGetChannelMemberCountResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onGetChannelMemberCountResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        long long arg0 = 0;
        const agora::rtm::ChannelMemberCount* arg1 = nullptr;
        int arg2 = 0;
        agora::rtm::GET_CHANNEL_MEMBER_COUNT_ERR_CODE arg3;
        ok &= seval_to_longlong(args[0], &arg0);
        #pragma warning NO CONVERSION TO NATIVE FOR ChannelMemberCount*
        ok = false;
        do { int32_t tmp = 0; ok &= seval_to_int32(args[2], &tmp); arg2 = (int)tmp; } while(false);
        ok &= seval_to_uint32(args[3], (uint32_t*)&arg3);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onGetChannelMemberCountResult : Error processing arguments");
        cobj->onGetChannelMemberCountResult(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onGetChannelMemberCountResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onFileMessageReceivedFromPeer(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onFileMessageReceivedFromPeer : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        const agora::rtm::IFileMessage* arg1 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_native_ptr(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onFileMessageReceivedFromPeer : Error processing arguments");
        cobj->onFileMessageReceivedFromPeer(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onFileMessageReceivedFromPeer)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onDeleteChannelAttributesResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onDeleteChannelAttributesResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        long long arg0 = 0;
        agora::rtm::ATTRIBUTE_OPERATION_ERR arg1;
        ok &= seval_to_longlong(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onDeleteChannelAttributesResult : Error processing arguments");
        cobj->onDeleteChannelAttributesResult(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onDeleteChannelAttributesResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onLogout(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onLogout : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        agora::rtm::LOGOUT_ERR_CODE arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onLogout : Error processing arguments");
        cobj->onLogout(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onLogout)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSubscriptionRequestResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSubscriptionRequestResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        long long arg0 = 0;
        agora::rtm::PEER_SUBSCRIPTION_STATUS_ERR arg1;
        ok &= seval_to_longlong(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSubscriptionRequestResult : Error processing arguments");
        cobj->onSubscriptionRequestResult(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSubscriptionRequestResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSetChannelAttributesResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSetChannelAttributesResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        long long arg0 = 0;
        agora::rtm::ATTRIBUTE_OPERATION_ERR arg1;
        ok &= seval_to_longlong(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSetChannelAttributesResult : Error processing arguments");
        cobj->onSetChannelAttributesResult(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSetChannelAttributesResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onClearChannelAttributesResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onClearChannelAttributesResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        long long arg0 = 0;
        agora::rtm::ATTRIBUTE_OPERATION_ERR arg1;
        ok &= seval_to_longlong(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onClearChannelAttributesResult : Error processing arguments");
        cobj->onClearChannelAttributesResult(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onClearChannelAttributesResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaDownloadToMemoryResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaDownloadToMemoryResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        long long arg0 = 0;
        const char* arg1 = nullptr;
        long long arg2 = 0;
        agora::rtm::DOWNLOAD_MEDIA_ERR_CODE arg3;
        ok &= seval_to_longlong(args[0], &arg0);
        std::string arg1_tmp; ok &= seval_to_std_string(args[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
        ok &= seval_to_longlong(args[2], &arg2);
        ok &= seval_to_uint32(args[3], (uint32_t*)&arg3);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaDownloadToMemoryResult : Error processing arguments");
        cobj->onMediaDownloadToMemoryResult(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaDownloadToMemoryResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onQueryPeersOnlineStatusResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onQueryPeersOnlineStatusResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        long long arg0 = 0;
        const agora::rtm::PeerOnlineStatus* arg1 = nullptr;
        int arg2 = 0;
        agora::rtm::QUERY_PEERS_ONLINE_STATUS_ERR arg3;
        ok &= seval_to_longlong(args[0], &arg0);
        #pragma warning NO CONVERSION TO NATIVE FOR PeerOnlineStatus*
        ok = false;
        do { int32_t tmp = 0; ok &= seval_to_int32(args[2], &tmp); arg2 = (int)tmp; } while(false);
        ok &= seval_to_uint32(args[3], (uint32_t*)&arg3);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onQueryPeersOnlineStatusResult : Error processing arguments");
        cobj->onQueryPeersOnlineStatusResult(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onQueryPeersOnlineStatusResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMessageReceivedFromPeer(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMessageReceivedFromPeer : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        const agora::rtm::IMessage* arg1 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_native_ptr(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMessageReceivedFromPeer : Error processing arguments");
        cobj->onMessageReceivedFromPeer(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMessageReceivedFromPeer)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onAddOrUpdateLocalUserAttributesResult(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onAddOrUpdateLocalUserAttributesResult : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        long long arg0 = 0;
        agora::rtm::ATTRIBUTE_OPERATION_ERR arg1;
        ok &= seval_to_longlong(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onAddOrUpdateLocalUserAttributesResult : Error processing arguments");
        cobj->onAddOrUpdateLocalUserAttributesResult(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onAddOrUpdateLocalUserAttributesResult)

static bool js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onTokenExpired(se::State& s)
{
    agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onTokenExpired : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->onTokenExpired();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onTokenExpired)



static bool js_agora_rtm_IRtmServiceEventHandler_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (agora::rtm::IRtmServiceEventHandler)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        agora::rtm::IRtmServiceEventHandler* cobj = (agora::rtm::IRtmServiceEventHandler*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_agora_rtm_IRtmServiceEventHandler_finalize)

bool js_register_cocos2dx_agora_rtm_IRtmServiceEventHandler(se::Object* obj)
{
    auto cls = se::Class::create("IRtmServiceEventHandler", obj, nullptr, nullptr);

    cls->defineFunction("onMediaDownloadingProgress", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaDownloadingProgress));
    cls->defineFunction("onGetUserAttributesResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onGetUserAttributesResult));
    cls->defineFunction("onSendMessageResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSendMessageResult));
    cls->defineFunction("onAddOrUpdateChannelAttributesResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onAddOrUpdateChannelAttributesResult));
    cls->defineFunction("onImageMessageReceivedFromPeer", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onImageMessageReceivedFromPeer));
    cls->defineFunction("onMediaUploadingProgress", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaUploadingProgress));
    cls->defineFunction("onFileMediaUploadResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onFileMediaUploadResult));
    cls->defineFunction("onConnectionStateChanged", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onConnectionStateChanged));
    cls->defineFunction("onRenewTokenResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onRenewTokenResult));
    cls->defineFunction("onSetLocalUserAttributesResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSetLocalUserAttributesResult));
    cls->defineFunction("onImageMediaUploadResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onImageMediaUploadResult));
    cls->defineFunction("onDeleteLocalUserAttributesResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onDeleteLocalUserAttributesResult));
    cls->defineFunction("onLoginSuccess", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onLoginSuccess));
    cls->defineFunction("onMediaDownloadToFileResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaDownloadToFileResult));
    cls->defineFunction("onLoginFailure", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onLoginFailure));
    cls->defineFunction("onMediaCancelResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaCancelResult));
    cls->defineFunction("onClearLocalUserAttributesResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onClearLocalUserAttributesResult));
    cls->defineFunction("onGetChannelMemberCountResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onGetChannelMemberCountResult));
    cls->defineFunction("onFileMessageReceivedFromPeer", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onFileMessageReceivedFromPeer));
    cls->defineFunction("onDeleteChannelAttributesResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onDeleteChannelAttributesResult));
    cls->defineFunction("onLogout", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onLogout));
    cls->defineFunction("onSubscriptionRequestResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSubscriptionRequestResult));
    cls->defineFunction("onSetChannelAttributesResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onSetChannelAttributesResult));
    cls->defineFunction("onClearChannelAttributesResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onClearChannelAttributesResult));
    cls->defineFunction("onMediaDownloadToMemoryResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMediaDownloadToMemoryResult));
    cls->defineFunction("onQueryPeersOnlineStatusResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onQueryPeersOnlineStatusResult));
    cls->defineFunction("onMessageReceivedFromPeer", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onMessageReceivedFromPeer));
    cls->defineFunction("onAddOrUpdateLocalUserAttributesResult", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onAddOrUpdateLocalUserAttributesResult));
    cls->defineFunction("onTokenExpired", _SE(js_cocos2dx_agora_rtm_IRtmServiceEventHandler_onTokenExpired));
    cls->defineFinalizeFunction(_SE(js_agora_rtm_IRtmServiceEventHandler_finalize));
    cls->install();
    JSBClassType::registerClass<agora::rtm::IRtmServiceEventHandler>(cls);

    __jsb_agora_rtm_IRtmServiceEventHandler_proto = cls->getProto();
    __jsb_agora_rtm_IRtmServiceEventHandler_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_agora_rtm_IRtmService_proto = nullptr;
se::Class* __jsb_agora_rtm_IRtmService_class = nullptr;

static bool js_cocos2dx_agora_rtm_IRtmService_setParameters(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_setParameters : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_setParameters : Error processing arguments");
        int result = cobj->setParameters(arg0);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_setParameters : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_setParameters)

static bool js_cocos2dx_agora_rtm_IRtmService_setLogFileSize(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_setLogFileSize : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_setLogFileSize : Error processing arguments");
        int result = cobj->setLogFileSize(arg0);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_setLogFileSize : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_setLogFileSize)

static bool js_cocos2dx_agora_rtm_IRtmService_cancelMediaUpload(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_cancelMediaUpload : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        long long arg0 = 0;
        ok &= seval_to_longlong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_cancelMediaUpload : Error processing arguments");
        int result = cobj->cancelMediaUpload(arg0);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_cancelMediaUpload : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_cancelMediaUpload)

static bool js_cocos2dx_agora_rtm_IRtmService_downloadMediaToFile(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_downloadMediaToFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        const char* arg0 = nullptr;
        const char* arg1 = nullptr;
        long long arg2 = 0;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= seval_to_std_string(args[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
        ok &= seval_to_longlong(args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_downloadMediaToFile : Error processing arguments");
        int result = cobj->downloadMediaToFile(arg0, arg1, arg2);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_downloadMediaToFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_downloadMediaToFile)

static bool js_cocos2dx_agora_rtm_IRtmService_renewToken(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_renewToken : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_renewToken : Error processing arguments");
        int result = cobj->renewToken(arg0);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_renewToken : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_renewToken)

static bool js_cocos2dx_agora_rtm_IRtmService_setLogFile(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_setLogFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_setLogFile : Error processing arguments");
        int result = cobj->setLogFile(arg0);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_setLogFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_setLogFile)

static bool js_cocos2dx_agora_rtm_IRtmService_downloadMediaToMemory(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_downloadMediaToMemory : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        long long arg1 = 0;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_longlong(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_downloadMediaToMemory : Error processing arguments");
        int result = cobj->downloadMediaToMemory(arg0, arg1);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_downloadMediaToMemory : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_downloadMediaToMemory)

static bool js_cocos2dx_agora_rtm_IRtmService_createImageMessageByMediaId(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_createImageMessageByMediaId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_createImageMessageByMediaId : Error processing arguments");
        agora::rtm::IImageMessage* result = cobj->createImageMessageByMediaId(arg0);
        ok &= native_ptr_to_seval<agora::rtm::IImageMessage>((agora::rtm::IImageMessage*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_createImageMessageByMediaId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_createImageMessageByMediaId)

static bool js_cocos2dx_agora_rtm_IRtmService_queryPeersBySubscriptionOption(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_queryPeersBySubscriptionOption : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        agora::rtm::PEER_SUBSCRIPTION_OPTION arg0;
        long long arg1 = 0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        ok &= seval_to_longlong(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_queryPeersBySubscriptionOption : Error processing arguments");
        int result = cobj->queryPeersBySubscriptionOption(arg0, arg1);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_queryPeersBySubscriptionOption : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_queryPeersBySubscriptionOption)

static bool js_cocos2dx_agora_rtm_IRtmService_createFileMessageByMediaId(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_createFileMessageByMediaId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_createFileMessageByMediaId : Error processing arguments");
        agora::rtm::IFileMessage* result = cobj->createFileMessageByMediaId(arg0);
        ok &= native_ptr_to_seval<agora::rtm::IFileMessage>((agora::rtm::IFileMessage*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_createFileMessageByMediaId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_createFileMessageByMediaId)

static bool js_cocos2dx_agora_rtm_IRtmService_createMessage(se::State& s)
{
    CC_UNUSED bool ok = true;
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_agora_rtm_IRtmService_createMessage : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            agora::rtm::IMessage* result = cobj->createMessage(arg0);
            ok &= native_ptr_to_seval<agora::rtm::IMessage>((agora::rtm::IMessage*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_createMessage : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 0) {
            agora::rtm::IMessage* result = cobj->createMessage();
            ok &= native_ptr_to_seval<agora::rtm::IMessage>((agora::rtm::IMessage*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_createMessage : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            const unsigned char* arg0 = nullptr;
            #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
            ok = false;
            if (!ok) { ok = true; break; }
            int arg1 = 0;
            do { int32_t tmp = 0; ok &= seval_to_int32(args[1], &tmp); arg1 = (int)tmp; } while(false);
            if (!ok) { ok = true; break; }
            agora::rtm::IMessage* result = cobj->createMessage(arg0, arg1);
            ok &= native_ptr_to_seval<agora::rtm::IMessage>((agora::rtm::IMessage*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_createMessage : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 3) {
            const unsigned char* arg0 = nullptr;
            #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
            ok = false;
            if (!ok) { ok = true; break; }
            int arg1 = 0;
            do { int32_t tmp = 0; ok &= seval_to_int32(args[1], &tmp); arg1 = (int)tmp; } while(false);
            if (!ok) { ok = true; break; }
            const char* arg2 = nullptr;
            std::string arg2_tmp; ok &= seval_to_std_string(args[2], &arg2_tmp); arg2 = arg2_tmp.c_str();
            if (!ok) { ok = true; break; }
            agora::rtm::IMessage* result = cobj->createMessage(arg0, arg1, arg2);
            ok &= native_ptr_to_seval<agora::rtm::IMessage>((agora::rtm::IMessage*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_createMessage : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_createMessage)

static bool js_cocos2dx_agora_rtm_IRtmService_getChannelAttributes(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_getChannelAttributes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        long long arg1 = 0;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_longlong(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_getChannelAttributes : Error processing arguments");
        int result = cobj->getChannelAttributes(arg0, arg1);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_getChannelAttributes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_getChannelAttributes)

static bool js_cocos2dx_agora_rtm_IRtmService_sendMessageToPeer(se::State& s)
{
    CC_UNUSED bool ok = true;
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_agora_rtm_IRtmService_sendMessageToPeer : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 3) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            const agora::rtm::IMessage* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            agora::rtm::SendMessageOptions arg2;
            #pragma warning NO CONVERSION TO NATIVE FOR SendMessageOptions
            ok = false;
            if (!ok) { ok = true; break; }
            int result = cobj->sendMessageToPeer(arg0, arg1, arg2);
            ok &= int32_to_seval(result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_sendMessageToPeer : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            const agora::rtm::IMessage* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            int result = cobj->sendMessageToPeer(arg0, arg1);
            ok &= int32_to_seval(result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_sendMessageToPeer : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_sendMessageToPeer)

static bool js_cocos2dx_agora_rtm_IRtmService_clearLocalUserAttributes(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_clearLocalUserAttributes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        long long arg0 = 0;
        ok &= seval_to_longlong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_clearLocalUserAttributes : Error processing arguments");
        int result = cobj->clearLocalUserAttributes(arg0);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_clearLocalUserAttributes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_clearLocalUserAttributes)

static bool js_cocos2dx_agora_rtm_IRtmService_clearChannelAttributes(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_clearChannelAttributes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        const char* arg0 = nullptr;
        agora::rtm::ChannelAttributeOptions arg1;
        long long arg2 = 0;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        #pragma warning NO CONVERSION TO NATIVE FOR ChannelAttributeOptions
        ok = false;
        ok &= seval_to_longlong(args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_clearChannelAttributes : Error processing arguments");
        int result = cobj->clearChannelAttributes(arg0, arg1, arg2);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_clearChannelAttributes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_clearChannelAttributes)

static bool js_cocos2dx_agora_rtm_IRtmService_setLocalUserAttributes(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_setLocalUserAttributes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        const agora::rtm::RtmAttribute* arg0 = nullptr;
        int arg1 = 0;
        long long arg2 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR RtmAttribute*
        ok = false;
        do { int32_t tmp = 0; ok &= seval_to_int32(args[1], &tmp); arg1 = (int)tmp; } while(false);
        ok &= seval_to_longlong(args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_setLocalUserAttributes : Error processing arguments");
        int result = cobj->setLocalUserAttributes(arg0, arg1, arg2);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_setLocalUserAttributes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_setLocalUserAttributes)

static bool js_cocos2dx_agora_rtm_IRtmService_createImageMessageByUploading(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_createImageMessageByUploading : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        long long arg1 = 0;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_longlong(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_createImageMessageByUploading : Error processing arguments");
        int result = cobj->createImageMessageByUploading(arg0, arg1);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_createImageMessageByUploading : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_createImageMessageByUploading)

static bool js_cocos2dx_agora_rtm_IRtmService_cancelMediaDownload(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_cancelMediaDownload : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        long long arg0 = 0;
        ok &= seval_to_longlong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_cancelMediaDownload : Error processing arguments");
        int result = cobj->cancelMediaDownload(arg0);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_cancelMediaDownload : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_cancelMediaDownload)

static bool js_cocos2dx_agora_rtm_IRtmService_setLogFilter(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_setLogFilter : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        agora::rtm::LOG_FILTER_TYPE arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_setLogFilter : Error processing arguments");
        int result = cobj->setLogFilter(arg0);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_setLogFilter : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_setLogFilter)

static bool js_cocos2dx_agora_rtm_IRtmService_logout(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_logout : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->logout();
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_logout : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_logout)

static bool js_cocos2dx_agora_rtm_IRtmService_initialize(se::State& s)
{

    CCLOG("aaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    CCLOG("bbbbbbbbbbbbbbbbbbbbbbbbb" );
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_initialize : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        agora::rtm::IRtmServiceEventHandler* arg1 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_native_ptr(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_initialize : Error processing arguments");
        CCLOG("ccccccccccccccccccccccccccc");
        int result = cobj->initialize(arg0, arg1);
        CCLOG("dddddddddddddddddddddddddd");
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_initialize : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_initialize)

static bool js_cocos2dx_agora_rtm_IRtmService_createFileMessageByUploading(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_createFileMessageByUploading : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        long long arg1 = 0;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_longlong(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_createFileMessageByUploading : Error processing arguments");
        int result = cobj->createFileMessageByUploading(arg0, arg1);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_createFileMessageByUploading : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_createFileMessageByUploading)

static bool js_cocos2dx_agora_rtm_IRtmService_addEventHandler(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_addEventHandler : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        agora::rtm::IRtmServiceEventHandler* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_addEventHandler : Error processing arguments");
        cobj->addEventHandler(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_addEventHandler)

static bool js_cocos2dx_agora_rtm_IRtmService_removeEventHandler(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_removeEventHandler : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        agora::rtm::IRtmServiceEventHandler* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_removeEventHandler : Error processing arguments");
        cobj->removeEventHandler(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_removeEventHandler)

static bool js_cocos2dx_agora_rtm_IRtmService_createChannelAttribute(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_createChannelAttribute : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        agora::rtm::IRtmChannelAttribute* result = cobj->createChannelAttribute();
        ok &= native_ptr_to_seval<agora::rtm::IRtmChannelAttribute>((agora::rtm::IRtmChannelAttribute*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_createChannelAttribute : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_createChannelAttribute)

static bool js_cocos2dx_agora_rtm_IRtmService_addOrUpdateLocalUserAttributes(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_addOrUpdateLocalUserAttributes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        const agora::rtm::RtmAttribute* arg0 = nullptr;
        int arg1 = 0;
        long long arg2 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR RtmAttribute*
        ok = false;
        do { int32_t tmp = 0; ok &= seval_to_int32(args[1], &tmp); arg1 = (int)tmp; } while(false);
        ok &= seval_to_longlong(args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_addOrUpdateLocalUserAttributes : Error processing arguments");
        int result = cobj->addOrUpdateLocalUserAttributes(arg0, arg1, arg2);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_addOrUpdateLocalUserAttributes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_addOrUpdateLocalUserAttributes)

static bool js_cocos2dx_agora_rtm_IRtmService_getUserAttributes(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_getUserAttributes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        long long arg1 = 0;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_longlong(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_getUserAttributes : Error processing arguments");
        int result = cobj->getUserAttributes(arg0, arg1);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_getUserAttributes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_getUserAttributes)

static bool js_cocos2dx_agora_rtm_IRtmService_createChannel(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_createChannel : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        agora::rtm::IChannelEventHandler* arg1 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_native_ptr(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_createChannel : Error processing arguments");
        agora::rtm::IChannel* result = cobj->createChannel(arg0, arg1);
        ok &= native_ptr_to_seval<agora::rtm::IChannel>((agora::rtm::IChannel*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_createChannel : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_createChannel)

static bool js_cocos2dx_agora_rtm_IRtmService_release(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_release : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cobj->release();
        return true;
    }
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_release : Error processing arguments");
        cobj->release(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_release)

static bool js_cocos2dx_agora_rtm_IRtmService_getRtmCallManager(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_getRtmCallManager : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        agora::rtm::IRtmCallEventHandler* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_getRtmCallManager : Error processing arguments");
        agora::rtm::IRtmCallManager* result = cobj->getRtmCallManager(arg0);
        ok &= native_ptr_to_seval<agora::rtm::IRtmCallManager>((agora::rtm::IRtmCallManager*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_getRtmCallManager : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_getRtmCallManager)

static bool js_cocos2dx_agora_rtm_IRtmService_login(se::State& s)
{
    agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_agora_rtm_IRtmService_login : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        const char* arg1 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= seval_to_std_string(args[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_login : Error processing arguments");
        int result = cobj->login(arg0, arg1);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_agora_rtm_IRtmService_login : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_agora_rtm_IRtmService_login)


/*
static bool js_agora_rtm_IRtmService_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (agora::rtm::IRtmService)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_agora_rtm_IRtmService_finalize)
*/
static bool js_agora_rtm_IRtmService_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (agora::rtm::IRtmService)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        agora::rtm::IRtmService* cobj = (agora::rtm::IRtmService*)s.nativeThisObject();
        if(cobj){
            cobj->release();
        }

        if(g_rtmSingleInstance){
            delete g_rtmSingleInstance;
            g_rtmSingleInstance = NULL;
        }
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_agora_rtm_IRtmService_finalize)


static bool js_cocos2dx_extension_IRtmService_constructor(se::State& s)
{
    CCLOG("[Agora] constructor");

    if (g_rtmSingleInstance == NULL){
        g_rtmSingleInstance = new CagoraRtmJsWrapper();
    }

    se::Object* obj = s.thisObject();

    // link the native object with the javascript object
    g_rtmSingleInstance->_refObj = obj;


    //编译的时候这里报错找不到createRtmService
    IRtmService *mAgoraEngine = (IRtmService *)agora::rtm::createRtmService();
    if (obj) {
        obj->setPrivateData(mAgoraEngine);
        se::Value func;
        if (obj->getProperty("_ctor", &func)) {
            func.toObject()->call(se::EmptyValueArray, obj);
        }
    }

    return true;
}
SE_BIND_CTOR(js_cocos2dx_extension_IRtmService_constructor, __jsb_agora_rtm_IRtmCallEventHandler_class, js_agora_rtm_IRtmService_finalize)


bool js_register_cocos2dx_agora_rtm_IRtmService(se::Object* obj)
{

    CCLOGINFO("111111111111");
//    auto cls = se::Class::create("RtmClient", obj, nullptr, nullptr);
    auto cls = se::Class::create("RtmClient", obj, nullptr, _SE(js_cocos2dx_extension_IRtmService_constructor));

    cls->defineFunction("setParameters", _SE(js_cocos2dx_agora_rtm_IRtmService_setParameters));
    cls->defineFunction("setLogFileSize", _SE(js_cocos2dx_agora_rtm_IRtmService_setLogFileSize));
    cls->defineFunction("cancelMediaUpload", _SE(js_cocos2dx_agora_rtm_IRtmService_cancelMediaUpload));
    cls->defineFunction("downloadMediaToFile", _SE(js_cocos2dx_agora_rtm_IRtmService_downloadMediaToFile));
    cls->defineFunction("renewToken", _SE(js_cocos2dx_agora_rtm_IRtmService_renewToken));
    cls->defineFunction("setLogFile", _SE(js_cocos2dx_agora_rtm_IRtmService_setLogFile));
    cls->defineFunction("downloadMediaToMemory", _SE(js_cocos2dx_agora_rtm_IRtmService_downloadMediaToMemory));
    cls->defineFunction("createImageMessageByMediaId", _SE(js_cocos2dx_agora_rtm_IRtmService_createImageMessageByMediaId));
    cls->defineFunction("queryPeersBySubscriptionOption", _SE(js_cocos2dx_agora_rtm_IRtmService_queryPeersBySubscriptionOption));
    cls->defineFunction("createFileMessageByMediaId", _SE(js_cocos2dx_agora_rtm_IRtmService_createFileMessageByMediaId));
    cls->defineFunction("createMessage", _SE(js_cocos2dx_agora_rtm_IRtmService_createMessage));
    cls->defineFunction("getChannelAttributes", _SE(js_cocos2dx_agora_rtm_IRtmService_getChannelAttributes));
    cls->defineFunction("sendMessageToPeer", _SE(js_cocos2dx_agora_rtm_IRtmService_sendMessageToPeer));
    cls->defineFunction("clearLocalUserAttributes", _SE(js_cocos2dx_agora_rtm_IRtmService_clearLocalUserAttributes));
    cls->defineFunction("clearChannelAttributes", _SE(js_cocos2dx_agora_rtm_IRtmService_clearChannelAttributes));
    cls->defineFunction("setLocalUserAttributes", _SE(js_cocos2dx_agora_rtm_IRtmService_setLocalUserAttributes));
    cls->defineFunction("createImageMessageByUploading", _SE(js_cocos2dx_agora_rtm_IRtmService_createImageMessageByUploading));
    cls->defineFunction("cancelMediaDownload", _SE(js_cocos2dx_agora_rtm_IRtmService_cancelMediaDownload));
    cls->defineFunction("setLogFilter", _SE(js_cocos2dx_agora_rtm_IRtmService_setLogFilter));
    cls->defineFunction("logout", _SE(js_cocos2dx_agora_rtm_IRtmService_logout));
    cls->defineFunction("initialize", _SE(js_cocos2dx_agora_rtm_IRtmService_initialize));
    cls->defineFunction("createFileMessageByUploading", _SE(js_cocos2dx_agora_rtm_IRtmService_createFileMessageByUploading));
    cls->defineFunction("addEventHandler", _SE(js_cocos2dx_agora_rtm_IRtmService_addEventHandler));
    cls->defineFunction("removeEventHandler", _SE(js_cocos2dx_agora_rtm_IRtmService_removeEventHandler));
    cls->defineFunction("createChannelAttribute", _SE(js_cocos2dx_agora_rtm_IRtmService_createChannelAttribute));
    cls->defineFunction("addOrUpdateLocalUserAttributes", _SE(js_cocos2dx_agora_rtm_IRtmService_addOrUpdateLocalUserAttributes));
    cls->defineFunction("getUserAttributes", _SE(js_cocos2dx_agora_rtm_IRtmService_getUserAttributes));
    cls->defineFunction("createChannel", _SE(js_cocos2dx_agora_rtm_IRtmService_createChannel));
    cls->defineFunction("release", _SE(js_cocos2dx_agora_rtm_IRtmService_release));
    cls->defineFunction("getRtmCallManager", _SE(js_cocos2dx_agora_rtm_IRtmService_getRtmCallManager));
    cls->defineFunction("login", _SE(js_cocos2dx_agora_rtm_IRtmService_login));
    cls->defineFinalizeFunction(_SE(js_agora_rtm_IRtmService_finalize));
    cls->install();
    JSBClassType::registerClass<agora::rtm::IRtmService>(cls);

    __jsb_agora_rtm_IRtmService_proto = cls->getProto();
    __jsb_agora_rtm_IRtmService_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_cocos2dx_agora_rtm(se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("rtm", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject());
        nsVal.setObject(jsobj);
        obj->setProperty("rtm", nsVal);
    }
    se::Object* ns = nsVal.toObject();

//    js_register_cocos2dx_agora_rtm_IRtmCallEventHandler(ns);
    js_register_cocos2dx_agora_rtm_IRtmServiceEventHandler(ns);
    js_register_cocos2dx_agora_rtm_IRtmService(ns);
    return true;
}

#endif //#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
