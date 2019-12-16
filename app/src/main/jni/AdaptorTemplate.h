
#ifndef __AdaptorTemplate__H__
#define __AdaptorTemplate__H__ //NOLINT(legal/name)

#include <jni.h>
#include <string>
#include <vector>
#include <list>
#include "StringFunction.h"

#define def_jni_adaptor_class(cls) class cls##Adaptor:public AdaptorTemplate<cls> //NOLINT(legal/name)


extern "C" JavaVM *g_pJVM;

template<class T>
class AdaptorTemplate
{
public:

	static jclass    _j_class_Adaptor;
	static jmethodID _j_method_Init;

	operator const T &()const
	{
		return cObj;
	};

	operator const jobject &()const
	{
		return jObj;
	};


	inline void get_field_byte( JNIEnv *pEnv,const jobject &jObj,const jfieldID &field,
								unsigned char &value )// NOLINT(runtime/references)
	{
		value = false;

		jbyte _temp = pEnv->GetByteField(jObj,field);

		if(pEnv->ExceptionCheck())
			return;

		value = _temp;
	};

	inline void get_field_byte( JNIEnv *pEnv,const jobject &jObj,const jfieldID &field,
								bool &value )// NOLINT(runtime/references)
	{
		value = false;

		jbyte _temp = pEnv->GetByteField(jObj,field);

		if(pEnv->ExceptionCheck())
			return;

		value = _temp;
	};

	inline void get_field_char( JNIEnv *pEnv,const jobject &jObj,const jfieldID &field,
								char &value )// NOLINT(runtime/references)
	{
		value = false;

		jchar _temp = pEnv->GetCharField(jObj,field);

		if(pEnv->ExceptionCheck())
			return;

		value = _temp;
	};

	inline void get_field_bool( JNIEnv *pEnv,const jobject &jObj,const jfieldID &field,
								bool &value )// NOLINT(runtime/references)
	{
		value = false;

		jboolean _temp = pEnv->GetBooleanField(jObj,field);

		if(pEnv->ExceptionCheck())
			return;

		value = _temp;
	};


	inline void get_field_int( JNIEnv *pEnv,const jobject &jObj,const jfieldID &field,
							   int &value )// NOLINT(runtime/references)
	{
		value = false;

		jint _temp = pEnv->GetIntField(jObj,field);

		if(pEnv->ExceptionCheck())
			return;

		value = _temp;
	};

	inline void get_field_int( JNIEnv *pEnv,const jobject &jObj,const jfieldID &field,
							   long &value )// NOLINT(runtime/references)
	{
		value = false;

		jint _temp = pEnv->GetIntField(jObj,field);

		if(pEnv->ExceptionCheck())
			return;

		value = _temp;
	};

	inline void get_field_float( JNIEnv *pEnv,const jobject &jObj,const jfieldID &field,
								 float &value )// NOLINT(runtime/references)
	{
		value = false;

		jint _temp = pEnv->GetFloatField(jObj,field);

		if(pEnv->ExceptionCheck())
			return;

		value = _temp;
	};

	inline void get_field_float( JNIEnv *pEnv,const jobject &jObj,const jfieldID &field,
								 long &value )// NOLINT(runtime/references)
	{
		value = false;

		jint _temp = pEnv->GetFloatField(jObj,field);

		if(pEnv->ExceptionCheck())
			return;

		value = _temp;
	};

	inline void get_field_long( JNIEnv *pEnv,const jobject &jObj,const jfieldID &field,
								long &value )// NOLINT(runtime/references)
	{
		value = false;

		jlong _temp = pEnv->GetLongField(jObj,field);

		if(pEnv->ExceptionCheck())
			return;

		value = _temp;
	};

	inline void get_field_long( JNIEnv *pEnv,const jobject &jObj,const jfieldID &field,
								uint32_t &value )// NOLINT(runtime/references)
	{
		value = false;

		jlong _temp = pEnv->GetLongField(jObj,field);

		if(pEnv->ExceptionCheck())
			return;

		value = _temp;
	};

	inline void get_field_string( JNIEnv *pEnv,const jobject &jObj,const jfieldID &field,
								  std::string &value )// NOLINT(runtime/references)
	{
		jstring _temp = (jstring)pEnv->GetObjectField(jObj,field);

		if(pEnv->ExceptionCheck())
			return;

		StringFunction::J2C(pEnv,_temp,value);
	};

	inline void get_field_string( JNIEnv *pEnv,const jobject &jObj,const jfieldID &field,
								  std::wstring &value )// NOLINT(runtime/references)
	{
		jstring _temp = (jstring)pEnv->GetObjectField(jObj,field);

		if(pEnv->ExceptionCheck())
			return;

		StringFunction::J2C(pEnv,_temp,value);
	};

	inline void get_field_string_array( JNIEnv *pEnv,const jobject &jObj,const jfieldID &field,
										std::list<std::string> &value )// NOLINT(runtime/references)
	{
		jobjectArray _temp = (jobjectArray)pEnv->GetObjectField(jObj,field);

		if(pEnv->ExceptionCheck())
			return;

		StringFunction::J2C(pEnv,_temp,value);
	};

	inline void get_field_string_array( JNIEnv *pEnv,const jobject &jObj,const jfieldID &field,
										std::list<std::wstring> &value )// NOLINT(runtime/references)
	{
		jobjectArray _temp = (jobjectArray)pEnv->GetObjectField(jObj,field);

		if(pEnv->ExceptionCheck())
			return;

		StringFunction::J2C(pEnv,_temp,value);
	};

	inline void get_field_string_array( JNIEnv *pEnv,const jobject &jObj,const jfieldID &field,
										std::vector<std::string> &value ) // NOLINT(runtime/references)
	{
		jobjectArray _temp = (jobjectArray)pEnv->GetObjectField(jObj,field);

		if(pEnv->ExceptionCheck())
			return;

		StringFunction::J2C(pEnv,_temp,value);
	};

	inline void get_field_int_array(JNIEnv* pEnv, const jobject& jObj, const jfieldID& field,
									std::list<int>& value) // NOLINT(runtime/references)
	{
		jintArray intArray_ = (jintArray)pEnv->GetObjectField(jObj, field);
		if (pEnv->ExceptionCheck())
			return;
		jint* intArray;
		intArray = pEnv->GetIntArrayElements(intArray_, NULL);
		if (intArray == NULL) {
			return;
		}
		int length = pEnv->GetArrayLength(intArray_);
		for (int i = 0; i < length; i++) {
			value.push_back(intArray[i]);
		}
		pEnv->ReleaseIntArrayElements(intArray_, intArray, 0);
	};
	inline void set_field_byte( JNIEnv *pEnv,jobject &jObj,const jfieldID &field,// NOLINT(runtime/references)
								const u_char value )
	{
		pEnv->SetByteField(jObj,field,(jbyte)value);
	};

	inline void set_field_char( JNIEnv *pEnv,jobject &jObj,const jfieldID &field,// NOLINT(runtime/references)
								const char value )
	{
		pEnv->SetCharField(jObj,field,(jchar)value);
	};

	inline void set_field_double( JNIEnv *pEnv,jobject &jObj,const jfieldID &field,// NOLINT(runtime/references)
								  const double value )
	{
		pEnv->SetDoubleField(jObj,field,(jdouble)value);
	};

	inline void set_field_bool( JNIEnv *pEnv,jobject &jObj,const jfieldID &field,// NOLINT(runtime/references)
								const bool value )
	{
		pEnv->SetBooleanField(jObj,field,(jboolean)value);

//  		if(pEnv->ExceptionCheck())
//  			pEnv->ExceptionClear();
	};

	inline void set_field_int( JNIEnv *pEnv,jobject &jObj,const jfieldID &field,// NOLINT(runtime/references)
							   const int value )
	{
		pEnv->SetIntField(jObj,field,(jint)value);
	};

	inline void set_field_float( JNIEnv *pEnv,jobject &jObj,const jfieldID &field,// NOLINT(runtime/references)
								 const float value )
	{
		pEnv->SetFloatField(jObj,field,(jfloat)value);
	};

	inline void set_field_float( JNIEnv *pEnv,jobject &jObj,const jfieldID &field,// NOLINT(runtime/references)
								 const long value )
	{
		pEnv->SetFloatField(jObj,field,(jfloat)value);
	};

	inline void set_field_long( JNIEnv *pEnv,jobject &jObj,const jfieldID &field,// NOLINT(runtime/references)
								const long value )
	{
		pEnv->SetLongField(jObj,field,(jlong)value);
	};


	inline void set_field_string( JNIEnv *pEnv,jobject &jObj,const jfieldID &field,// NOLINT(runtime/references)
								  const std::string &value )
	{
		jstring _temp = 0;
		StringFunction::C2J(pEnv,value,_temp);
		if(_temp != 0)
		{
			pEnv->SetObjectField(jObj,field,_temp);
			pEnv->DeleteLocalRef(_temp);
		}
	};

	inline void set_field_string( JNIEnv *pEnv,jobject &jObj,const jfieldID &field,// NOLINT(runtime/references)
								  const std::wstring &value )
	{
		jstring _temp = 0;
		StringFunction::C2J(pEnv,value,_temp);
		if(_temp != 0)
		{
			pEnv->SetObjectField(jObj,field,_temp);
			pEnv->DeleteLocalRef(_temp);
		}
	};

	inline void set_field_string_array(JNIEnv *pEnv,jobject &jObj,const jfieldID &field,// NOLINT(runtime/references)
									   const std::list<std::string> &value)
	{
		jobjectArray _temp = 0;
		StringFunction::C2J(pEnv,value,_temp);
		if(_temp != 0)
		{
			pEnv->SetObjectField(jObj,field,_temp);
			pEnv->DeleteLocalRef(_temp);
		}
	}

	inline void set_field_string_array(JNIEnv *pEnv,jobject &jObj,const jfieldID &field,// NOLINT(runtime/references)
									   const std::list<std::wstring> &value)
	{
		jobjectArray _temp = 0;
		StringFunction::C2J(pEnv,value,_temp);
		if(_temp != 0)
		{
			pEnv->SetObjectField(jObj,field,_temp);
			pEnv->DeleteLocalRef(_temp);
		}
	}

	inline void set_field_string_array(JNIEnv *pEnv,jobject &jObj,const jfieldID &field,// NOLINT(runtime/references)
									   const std::vector<std::string> &value)
	{
		jobjectArray _temp = 0;
		StringFunction::C2J(pEnv,value,_temp);
		if(_temp != 0)
		{
			pEnv->SetObjectField(jObj,field,_temp);
			pEnv->DeleteLocalRef(_temp);
		}
	}

	inline void set_field_jbyte_array(JNIEnv *pEnv, jobject &jObj, const jfieldID &field,// NOLINT(runtime/references)
									  jbyteArray value)
	{
		if (value != 0)
		{
			pEnv->SetObjectField(jObj, field, value);
		}
	}

	inline void set_field_jint_array(JNIEnv* pEnv, jobject& jObj, const jfieldID& field,// NOLINT(runtime/references)
									 jintArray value)
	{
		if (value != 0)
		{
			pEnv->SetObjectField(jObj, field, value);
		}
	};
protected:
	AdaptorTemplate()
	{
		jObj = 0;
	}

	~AdaptorTemplate()
	{

	}

	virtual void init(JNIEnv *pEnv) = 0;

	void initMethod(JNIEnv *pEnv) //NOLINT(legal/name)
	{
		if (_j_class_Adaptor != 0)
		{
			_j_method_Init = pEnv->GetMethodID(_j_class_Adaptor, "<init>", "()V");
		}
	};

	bool allocJobject(JNIEnv *pEnv) //NOLINT(legal/name) 
	{
		if (_j_class_Adaptor != 0 && _j_method_Init != 0)
			jObj = pEnv->NewObject(_j_class_Adaptor, _j_method_Init);

		return jObj != 0;
	};

	T cObj;
	jobject    jObj;
};

template <typename T>
jclass    AdaptorTemplate<T>::_j_class_Adaptor = 0;

template <typename T>
jmethodID AdaptorTemplate<T>::_j_method_Init   = 0;

#endif