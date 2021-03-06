/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class x10_x10rt_TeamSupport */

#ifndef _Included_x10_x10rt_TeamSupport
#define _Included_x10_x10rt_TeamSupport
#ifdef __cplusplus
extern "C" {
#endif
#undef x10_x10rt_TeamSupport_RED_TYPE_BYTE
#define x10_x10rt_TeamSupport_RED_TYPE_BYTE 1L
#undef x10_x10rt_TeamSupport_RED_TYPE_SHORT
#define x10_x10rt_TeamSupport_RED_TYPE_SHORT 2L
#undef x10_x10rt_TeamSupport_RED_TYPE_INT
#define x10_x10rt_TeamSupport_RED_TYPE_INT 4L
#undef x10_x10rt_TeamSupport_RED_TYPE_LONG
#define x10_x10rt_TeamSupport_RED_TYPE_LONG 6L
#undef x10_x10rt_TeamSupport_RED_TYPE_DOUBLE
#define x10_x10rt_TeamSupport_RED_TYPE_DOUBLE 8L
#undef x10_x10rt_TeamSupport_RED_TYPE_FLOAT
#define x10_x10rt_TeamSupport_RED_TYPE_FLOAT 9L
#undef x10_x10rt_TeamSupport_RED_TYPE_COMPLEX
#define x10_x10rt_TeamSupport_RED_TYPE_COMPLEX 11L
#undef x10_x10rt_TeamSupport_RED_TYPE_LOGICAL
#define x10_x10rt_TeamSupport_RED_TYPE_LOGICAL 12L
/*
 * Class:     x10_x10rt_TeamSupport
 * Method:    nativeMakeImpl
 * Signature: ([II[ILx10/xrx/FinishState;)V
 */
JNIEXPORT void JNICALL Java_x10_x10rt_TeamSupport_nativeMakeImpl
  (JNIEnv *, jclass, jintArray, jint, jintArray, jobject);

/*
 * Class:     x10_x10rt_TeamSupport
 * Method:    nativeSizeImpl
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_x10_x10rt_TeamSupport_nativeSizeImpl
  (JNIEnv *, jclass, jint);

/*
 * Class:     x10_x10rt_TeamSupport
 * Method:    nativeBarrierImpl
 * Signature: (IILx10/xrx/FinishState;)V
 */
JNIEXPORT void JNICALL Java_x10_x10rt_TeamSupport_nativeBarrierImpl
  (JNIEnv *, jclass, jint, jint, jobject);

/*
 * Class:     x10_x10rt_TeamSupport
 * Method:    nativeScatterImpl
 * Signature: (IIILjava/lang/Object;ILjava/lang/Object;IIILx10/xrx/FinishState;)V
 */
JNIEXPORT void JNICALL Java_x10_x10rt_TeamSupport_nativeScatterImpl
  (JNIEnv *, jclass, jint, jint, jint, jobject, jint, jobject, jint, jint, jint, jobject);

/*
 * Class:     x10_x10rt_TeamSupport
 * Method:    nativeBcastImpl
 * Signature: (IIILjava/lang/Object;ILjava/lang/Object;IIILx10/xrx/FinishState;)Ljava/lang/Boolean;
 */
JNIEXPORT jobject JNICALL Java_x10_x10rt_TeamSupport_nativeBcastImpl
  (JNIEnv *, jclass, jint, jint, jint, jobject, jint, jobject, jint, jint, jint, jobject);

/*
 * Class:     x10_x10rt_TeamSupport
 * Method:    nativeAllToAllImpl
 * Signature: (IILjava/lang/Object;ILjava/lang/Object;IIILx10/xrx/FinishState;)V
 */
JNIEXPORT void JNICALL Java_x10_x10rt_TeamSupport_nativeAllToAllImpl
  (JNIEnv *, jclass, jint, jint, jobject, jint, jobject, jint, jint, jint, jobject);

/*
 * Class:     x10_x10rt_TeamSupport
 * Method:    nativeReduceImpl
 * Signature: (IIILjava/lang/Object;ILjava/lang/Object;IIIILx10/xrx/FinishState;)V
 */
JNIEXPORT void JNICALL Java_x10_x10rt_TeamSupport_nativeReduceImpl
  (JNIEnv *, jclass, jint, jint, jint, jobject, jint, jobject, jint, jint, jint, jint, jobject);

/*
 * Class:     x10_x10rt_TeamSupport
 * Method:    nativeAllReduceImpl
 * Signature: (IILjava/lang/Object;ILjava/lang/Object;IIIILx10/xrx/FinishState;)Ljava/lang/Boolean;
 */
JNIEXPORT jobject JNICALL Java_x10_x10rt_TeamSupport_nativeAllReduceImpl
  (JNIEnv *, jclass, jint, jint, jobject, jint, jobject, jint, jint, jint, jint, jobject);

/*
 * Class:     x10_x10rt_TeamSupport
 * Method:    nativeIndexOfMaxImpl
 * Signature: (IILx10/util/Team/DoubleIdx;Lx10/util/Team/DoubleIdx;Lx10/xrx/FinishState;)V
 */
JNIEXPORT void JNICALL Java_x10_x10rt_TeamSupport_nativeIndexOfMaxImpl
  (JNIEnv *, jclass, jint, jint, jobject, jobject, jobject);

/*
 * Class:     x10_x10rt_TeamSupport
 * Method:    nativeIndexOfMinImpl
 * Signature: (IILx10/util/Team/DoubleIdx;Lx10/util/Team/DoubleIdx;Lx10/xrx/FinishState;)V
 */
JNIEXPORT void JNICALL Java_x10_x10rt_TeamSupport_nativeIndexOfMinImpl
  (JNIEnv *, jclass, jint, jint, jobject, jobject, jobject);

/*
 * Class:     x10_x10rt_TeamSupport
 * Method:    nativeSplitImpl
 * Signature: (IIII[ILx10/xrx/FinishState;)V
 */
JNIEXPORT void JNICALL Java_x10_x10rt_TeamSupport_nativeSplitImpl
  (JNIEnv *, jclass, jint, jint, jint, jint, jintArray, jobject);

/*
 * Class:     x10_x10rt_TeamSupport
 * Method:    nativeDelImpl
 * Signature: (IILx10/xrx/FinishState;)V
 */
JNIEXPORT void JNICALL Java_x10_x10rt_TeamSupport_nativeDelImpl
  (JNIEnv *, jclass, jint, jint, jobject);

/*
 * Class:     x10_x10rt_TeamSupport
 * Method:    initialize
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_x10_x10rt_TeamSupport_initialize
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
