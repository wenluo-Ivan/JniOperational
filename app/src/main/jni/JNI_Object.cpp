#include "logutil.h"
#include "stdint.h"
#include "JNI_Object.h"


extern "C" JavaVM *g_pJVM;
extern "C" jint    g_JNIVersion;

namespace {//NOLINT(legal/name)
	unsigned int g_JNIObject_ID = 1;
}


JNI_Object::JNI_Object(JNIEnv* pEnv, jobject obj, jobject uiObj):_nID(g_JNIObject_ID++)
{
	if(uiObj != 0)
	{
		_j_object = (jobject)pEnv->NewGlobalRef(uiObj);
	}
	else
	{
		_j_object = 0;
	}
}

JNI_Object::~JNI_Object()
{
	LOGE("JNI_Object::JNI_Object destruct start");
	if (_j_object != 0)
	{
		JNIEnv *pEnv = NULL;
		int status = (g_pJVM)->GetEnv((void **)&pEnv, g_JNIVersion);
		bool isAttacked = false;
		if (status == JNI_OK)
		{
			LOGE("JNI_ObjectManager::JNI_Object destruct-1 id = %d", _nID);
			pEnv->DeleteGlobalRef(_j_object);
		}
		else
		{
			status = g_pJVM->AttachCurrentThread(&pEnv, NULL);
			if (status == JNI_OK)
			{
				LOGE("JNI_ObjectManager::JNI_Object destruct-2 id = %d", _nID);
				pEnv->DeleteGlobalRef(_j_object);
				g_pJVM->DetachCurrentThread();
			}
			else {
				LOGE("JNI_ObjectManager::JNI_Object destruct error : AttachCurrentThread error");
			}
		}
		_j_object = NULL;
		pEnv = NULL;
	}
}

const unsigned int JNI_Object::GET_ID() const
{
	return _nID;
}

const unsigned int JNI_Object::GET_TYPE() const
{
	return _type;
}

const void JNI_Object::SET_TYPE(const unsigned int type)
{
	_type = type;
}

int JNI_Object::BeforeCallToJava(JNIEnv **ppEnv)
{
	if (NULL == g_pJVM)
	{
		LOGE("g_JVM == NULL");
		return -1;
	}
	int status = (g_pJVM)->GetEnv((void **)ppEnv, g_JNIVersion);
	bool isAttacked = false;
	if (status != JNI_OK)
	{
		status = g_pJVM->AttachCurrentThread(ppEnv, NULL);
		if (status != JNI_OK)
		{
			LOGE("BeforeCallToJava: failed to attach current thread. %d.", status);
			return -1;
		}
		isAttacked = true;
	}

	return isAttacked;
}

void JNI_Object::AfterCallToJava( const int nRet )
{
	//LOGW("AfterCallToJava");
	if(nRet == 1)
	{
		//LOGW("AfterCallToJava DetachCurrentThread");
		g_pJVM->DetachCurrentThread();
	}
}