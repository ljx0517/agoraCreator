LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)



#============== agora rtm creator include so ====================
include $(CLEAR_VARS)
LOCAL_MODULE := agora-rtm
LOCAL_SRC_FILES := $(LOCAL_PATH)/rtmEngine/$(TARGET_ARCH_ABI)/libagora-rtm-sdk-jni.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/rtmEngine/include
include $(PREBUILT_SHARED_LIBRARY)
#============== end agora rtm creator include so ====================





LOCAL_MODULE := cocos2djs_shared

LOCAL_MODULE_FILENAME := libcocos2djs

ifeq ($(USE_ARM_MODE),1)
LOCAL_ARM_MODE := arm
endif

LOCAL_SRC_FILES := hellojavascript/main.cpp \
				   ../../Classes/AppDelegate.cpp \
				   ../../Classes/jsb_module_register.cpp \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes


#========== agora creator js bridge===========
LOCAL_SRC_FILES += ../../Classes/rtmEngine/include/AgoraManager.cpp \
        ../../Classes/rtmEngine/jsb_cocos2dx_agora_rtm_auto.cpp

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../Classes/rtmEngine \
        $(LOCAL_PATH)/../../../Classes/rtmEngine/include \


LOCAL_SHARED_LIBRARIES := agora-rtm

#========== agora creator js bridge===========

LOCAL_STATIC_LIBRARIES := cocos2dx_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module, cocos)
