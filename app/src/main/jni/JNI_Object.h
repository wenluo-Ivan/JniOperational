#pragma once

#include <jni.h>
#include "JNI_ObjectType.h"

#define def_j_class(cls) jclass _j_class_##cls//NOLINT(legal/name)
#define get_j_class(cls) _j_class_##cls//NOLINT(legal/name)

#define def_j_static_class(cls) static jclass _j_class_##cls//NOLINT(legal/name)
#define get_j_static_class(type,cls) type::_j_class_##cls//NOLINT(legal/name)

#define def_j_field(j_field) jfieldID _j_field_##j_field//NOLINT(legal/name)
#define get_j_field(j_field) _j_field_##j_field//NOLINT(legal/name)

#define def_j_static_field(j_field) static jfieldID _j_field_##j_field//NOLINT(legal/name)
#define get_j_static_field(type,j_field) type::_j_field_##j_field//NOLINT(legal/name)

#define def_j_method(j_function) jmethodID _j_method_##j_function//NOLINT(legal/name)
#define get_j_method(j_function) _j_method_##j_function//NOLINT(legal/name)

#define def_j_static_method(j_function) static jmethodID _j_method_##j_function//NOLINT(legal/name)
#define get_j_static_method(type,j_function) type::_j_method_##j_function//NOLINT(legal/name)

/*
#define set_j_obj_field_bool(env,cObj,jObj,field) env->SetBooleanField(jObj,get_j_field(field),(jboolean)cObj.field);

#define set_j_obj_field_char(env,cObj,jObj,field) env->SetCharField(jObj,get_j_field(field),(jchar)cObj.field);

#define set_j_obj_field_byte(env,cObj,jObj,field) env->SetByteField(jObj,get_j_field(field),(jbyte)cObj.field);

#define set_j_obj_field_int(env,cObj,jObj,field) env->SetIntField(jObj,get_j_field(field),(jint)cObj.field);

#define set_j_obj_field_long(env,cObj,jObj,field) env->SetLongField(jObj,get_j_field(field),(jlong)cObj.field); 

#define set_j_obj_field_object(env,cObj,jObj,fieldType,field) \
	{\
	fieldType##Adaptor _temp(env,cObj.field);\
	env->SetObjectField(jObj,get_j_field(field),(jobject)_temp);\
	}\


#define set_j_obj_field_string(env,cObj,jObj,field)\
	{\
	jstring _temp = 0;\
	StringFunction::C2J(env,cObj.field,_temp);\
	env->SetObjectField(jObj,get_j_field(field),_temp);\
	}\

#define set_j_obj_field_stringarray(env,cObj,jObj,field)\
	{\
	jobjectArray _temp = 0;\
	StringFunction::C2J(env,cObj.field,_temp);\
	env->SetObjectField(jObj,get_j_field(field),_temp);\
	}\

#define get_j_obj_field_bool(env,jObj,cObj,field) cObj.field = env->GetBooleanField(jObj,get_j_field(field));

#define get_j_obj_field_char(env,jObj,cObj,field) cObj.field = env->GetCharField(jObj,get_j_field(field));

#define get_j_obj_field_byte(env,jObj,cObj,field) cObj.field = env->GetByteField(jObj,get_j_field(field));

#define get_j_obj_field_int(env,jObj,cObj,field) cObj.field = env->GetIntField(jObj,get_j_field(field));

#define get_j_obj_field_long(env,jObj,cObj,field) cObj.field = env->GetLongField(jObj,get_j_field(field));

#define get_j_obj_field_object(env,jObj,cObj,fieldType,field) \
	{\
	jobject _temp = env->GetObjectField(jObj,get_j_field(field));\
	fieldType##Adaptor _tempAdaptor(env,_temp);\
	cObj.field = (fieldType)_tempAdaptor;\
	}\

#define get_j_obj_field_string(env,jObj,cObj,field) \
	{\
	jstring _temp = (jstring)env->GetObjectField(jObj,get_j_field(field));\
	StringFunction::J2C(env,_temp,cObj.field);\
	}\

#define get_j_obj_field_stringarray(env,jObj,cObj,field) \
	{\
	jobjectArray _temp = (jobjectArray)env->GetObjectField(jObj,get_j_field(field));\
	StringFunction::J2C(env,_temp,cObj.field);\
	}\

*/


	
/*
#define call_void_method_0_param(j_function) \
	do{\
	JNIEnv *pEnv = NULL;\
	const int nRet = beforeCallToJava(&pEnv);\
	if(nRet == -1){break;}\
	LOGW("CallVoidMethod");\
	pEnv->CallVoidMethod(_j_object,get_j_method(j_function));\
	AfterCallToJava(nRet);\
	}while(0);

#define call_void_method_1_param(j_function,_1) \
	do{\
	JNIEnv *pEnv = NULL;\
	const int nRet = beforeCallToJava(&pEnv);\
	if(nRet == -1){break;}\
	pEnv->CallVoidMethod(_j_object,get_j_method(j_function),_1);\
	AfterCallToJava(nRet);\
	}while(0);

#define call_void_method_2_param(j_function,_1,_2) \
	do{\
	JNIEnv *pEnv = NULL;\
	const int nRet = beforeCallToJava(&pEnv);\
	if(nRet == -1){break;}\
	pEnv->CallVoidMethod(_j_object,get_j_method(j_function),_1,_2);\
	AfterCallToJava(nRet);\
	}while(0);

#define call_void_method_3_param(j_function,_1,_2,_3) \
	do{\
	JNIEnv *pEnv = NULL;\
	const int nRet = beforeCallToJava(&pEnv);\
	if(nRet == -1){break;}\
	pEnv->CallVoidMethod(_j_object,get_j_method(j_function),_1,_2,_3);\
	AfterCallToJava(nRet);\
	}while(0);

#define call_void_method_4_param(j_function,_1,_2,_3,_4) \
	do{\
	JNIEnv *pEnv = NULL;\
	const int nRet = beforeCallToJava(&pEnv);\
	if(nRet == -1){break;}\
	pEnv->CallVoidMethod(_j_object,get_j_method(j_function),_1,_2,_3,_4);\
	AfterCallToJava(nRet);\
	}while(0);

#define call_void_method_5_param(j_function,_1,_2,_3,_4,_5) \
	do{\
	JNIEnv *pEnv = NULL;\
	const int nRet = beforeCallToJava(&pEnv);\
	if(nRet == -1){break;}\
	pEnv->CallVoidMethod(_j_object,get_j_method(j_function),_1,_2,_3,_4,_5);\
	AfterCallToJava(nRet);\
	}while(0);

	*/
#define CALLJAVAFUNCTION_NONE_PARAM(Obj,Func) \
	do{\
	JNIEnv *pEnv = NULL;\
	int ret = BeforeCallToJava(&pEnv);\
	if(ret == -1){break;}\
	pEnv->CallVoidMethod(Obj,Func);\
	AfterCallToJava(ret);\
	}while(0);

#define CALLJAVAFUNCTION(Obj,Func,...)	\
	do{\
	JNIEnv *pEnv = NULL;\
	int ret = BeforeCallToJava(&pEnv);\
	if(ret == -1){break;}\
	pEnv->CallVoidMethod(Obj,Func,__VA_ARGS__);\
	AfterCallToJava(ret);\
	}while(0);

#define CALLINGTOJAVA(JniEnv,Obj,Func,...)\
    JniEnv->CallVoidMethod(Obj,Func,__VA_ARGS__);
#define CALLINGTOBOOLEANJAVA(JniEnv,Obj,Func,...)\
    JniEnv->CallBooleanMethod(Obj,Func,__VA_ARGS__);
#define CALLINGTOOBJECTJAVA(JniEnv,Obj,Func,...)\
    JniEnv->CallObjectMethod(Obj,Func,__VA_ARGS__);

class JNI_Object//NOLINT(legal/name)
{
public:
	JNI_Object(JNIEnv* pEnv, jobject obj, jobject uiObj);
	virtual ~JNI_Object();

	const unsigned int GET_ID() const;//NOLINT(build/class_order)

	const unsigned int GET_TYPE() const;

	const void SET_TYPE(const unsigned int type);

	//void callJavaFunction(jmethodID jFunction,...);

	static int BeforeCallToJava(JNIEnv **ppEnv);

	//void callingToJava(JNIEnv *pEnv,jmethodID jFunction,...);

	static void AfterCallToJava(const int nRet);

protected:
	jobject   _j_object;
	unsigned int _nID;//NOLINT(legal/name)
	unsigned int _type;//NOLINT(legal/name)
};


