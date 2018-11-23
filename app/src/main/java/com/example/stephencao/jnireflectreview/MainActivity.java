package com.example.stephencao.jnireflectreview;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    private Button helloBtn, additionBtn, printBtn,toastBtn;
    private JNIcCallJava jnIcCallJava;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        helloBtn = findViewById(R.id.say_hello_btn);
        helloBtn.setOnClickListener(this);

        additionBtn = findViewById(R.id.addition_btn);
        additionBtn.setOnClickListener(this);

        printBtn = findViewById(R.id.print_string_btn);
        printBtn.setOnClickListener(this);

        toastBtn = findViewById(R.id.show_toast_btn);
        toastBtn.setOnClickListener(this);

        jnIcCallJava = new JNIcCallJava(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.say_hello_btn: {
                jnIcCallJava.callHello();
                break;
            }
            case R.id.addition_btn: {
                int result = jnIcCallJava.callAddition(15,88);
                Toast.makeText(this,"Result is: "+ result, Toast.LENGTH_SHORT).show();
                break;
            }
            case R.id.print_string_btn: {
                jnIcCallJava.callPrint("xiaohema");
                break;
            }
            case R.id.show_toast_btn:{
                jnIcCallJava.callFeedBack();
            }
        }
    }

}
