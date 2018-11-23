#include<stdlib.h>
#include<stdio.h>
#include<jni.h>

JNIEXPORT void JNICALL Java_com_example_stephencao_jnireflectreview_JNIcCallJava_callHello
  (JNIEnv * env, jobject thiz){
  //通过反射的原理， 从c中调用java的方法
  //1 找到字节码 参数1 env 参数2 找到字节码对应类的路径
  //jclass FindClass(JNIEnv *env, const char *name);
  jclass cls = (*env)->FindClass(env,"com/example/stephencao/jnireflectreview/JNIcCallJava");
  //2 找到方法 参数3 方法名 参数4 具体的参数
  //jmethodID GetMethodID(JNIEnv *env, jclass clazz, const char *name, const char *sig);
  jmethodID methodID= (*env)->GetMethodID(env, cls, "helloFromJava","()V");//方法签名，需要进入所在包内，先javac 文件.java 编译通过后，再使用 javap -s 文件.class
  //3 创建对象 如果回调的java方法和native 方法在同一个类中，就不需要创建对象 直接使用 传进来的jobject 作为对象调用方法
  //4 通过对象找到方法
  (*env)->CallVoidMethod(env,thiz,methodID);
  }

JNIEXPORT jint JNICALL Java_com_example_stephencao_jnireflectreview_JNIcCallJava_callAddition
  (JNIEnv * env, jobject thiz, jint x, jint y){
  jclass cls = (*env)->FindClass(env,"com/example/stephencao/jnireflectreview/JNIcCallJava");
  jmethodID methodID = (*env)->GetMethodID(env, cls, "addition","(II)I");
  jint result = (*env)->CallIntMethod(env,thiz,methodID,x,y);
  return result;
  }

JNIEXPORT void JNICALL Java_com_example_stephencao_jnireflectreview_JNIcCallJava_callPrint
  (JNIEnv * env, jobject thiz, jstring str){
  jclass cls = (*env)->FindClass(env, "com/example/stephencao/jnireflectreview/JNIcCallJava");
  jmethodID methodID = (*env)->GetMethodID(env, cls, "printString","(Ljava/lang/String;)V");
  (*env)->CallVoidMethod(env,thiz,methodID,str);//java 的string类型是 jstring，但是 c能处理的是char*
  }

 JNIEXPORT void JNICALL Java_com_example_stephencao_jnireflectreview_JNIcCallJava_callFeedBack
   (JNIEnv * env, jobject thiz){
    jclass cls = (*env)->FindClass(env,"com/example/stephencao/jnireflectreview/JNIcCallJava");
    jmethodID methodID = (*env)->GetMethodID(env,cls,"showFeedback","(Ljava/lang/String;)V");
    //创建对象
    //jobject AllocObject(JNIEnv *env, jclass clazz);

//    jobject obj = (*env)->AllocObject(env,cls);// 四大组件， 不能直接创建一个新的对象 有两种方法：1， 把native方法写在mainactivity中 2，传一个context给jni

    char* string = "Hi, I am dabao!";
    jstring str = (*env)->NewStringUTF(env,string);
    (*env)->CallVoidMethod(env, thiz, methodID, str);
    }