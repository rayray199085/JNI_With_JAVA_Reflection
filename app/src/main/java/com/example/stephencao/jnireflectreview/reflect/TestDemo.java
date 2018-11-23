package com.example.stephencao.jnireflectreview.reflect;

import java.lang.reflect.Method;

public class TestDemo {
    public static void main(String[] args) {
        //1。获取字节码
        Class cls = Demo.class;
        //2。获取方法

        try {
            Method method = cls.getMethod("hello", new Class[]{String.class});//参数1 方法名字, 参数2 参数类型， 参数的字节码
            //3。创建对象。
            Object object = cls.newInstance();
            //4。通过对象获取方法
            method.invoke(object,new Object[]{"hello"});
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
