package com.example.stephencao.jnireflectreview;

import android.content.Context;
import android.widget.Toast;

public class JNIcCallJava {
    Context context;

    public JNIcCallJava(Context context) {
        this.context = context;
    }

    static {
        System.loadLibrary("callJavaMethod");
    }
    public void helloFromJava() {
        System.out.println("hello from java");
    }

    public int addition(int x, int y) {
        return x + y;
    }

    public void printString(String s){
        System.out.println("Hi, i am " + s);
    }

    public void showFeedback(String reply){
        Toast.makeText(context,reply,Toast.LENGTH_SHORT).show();
    }

    public native void callHello();
    public native int callAddition(int x, int y);
    public native void callPrint(String s);
    public native void callFeedBack();
}
