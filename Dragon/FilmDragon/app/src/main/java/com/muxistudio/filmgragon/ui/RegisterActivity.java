package com.muxistudio.filmgragon.ui;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.text.method.PasswordTransformationMethod;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.alibaba.android.arouter.facade.annotation.Route;
import com.alibaba.android.arouter.launcher.ARouter;
import com.muxistudio.filmgragon.R;
import com.muxistudio.filmgragon.data.user.User;
import com.muxistudio.filmgragon.data.user.UserId;
import com.muxistudio.filmgragon.net.MyRetrofit;
import com.muxistudio.filmgragon.net.UserService;
import com.rengwuxian.materialedittext.MaterialEditText;

import org.jetbrains.annotations.Nullable;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;

/**
 * Created by zdf on 18-4-1.
 */
@Route(path = "/ui/RegisterActivity")
public class RegisterActivity extends AppCompatActivity {
    private MaterialEditText numberTextRe;
    private MaterialEditText passwordTextRe;
    private MaterialEditText passwordTextT;
    private Button logupButton;
    private TextView mTextView;
    private User mUser;

    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.activity_register);

        initView();
        setEditTexts();

        Window window = getWindow();
        window.addFlags(WindowManager.LayoutParams.FLAG_TRANSLUCENT_STATUS);
    }

    private void setEditTexts() {
        setEditText(numberTextRe,"用户名");
        setEditText(passwordTextRe,"密码");
        setEditText(passwordTextT,"确认密码");

        passwordTextRe.setTransformationMethod(PasswordTransformationMethod.getInstance());
        passwordTextRe.setMinCharacters(8);
        passwordTextRe.setMaxCharacters(16);

        passwordTextT.setTransformationMethod(PasswordTransformationMethod.getInstance());

    }

    private void setEditText(MaterialEditText edittext, String hint){
        edittext.setBaseColor(getResources().getColor(R.color.colorGray));
        edittext.setFloatingLabel(MaterialEditText.FLOATING_LABEL_HIGHLIGHT);
        edittext.setHint(hint);
        edittext.setHintTextColor(getResources().getColor(R.color.colorGray));
    }

    private void initView() {
        numberTextRe = findViewById(R.id.register_number);
        passwordTextRe = findViewById(R.id.register_password);
        passwordTextT = findViewById(R.id.register_password_re);

        logupButton = findViewById(R.id.register_register);
        logupButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                register();
            }
        });

        mTextView = findViewById(R.id.register_goto_login);
        mTextView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(getApplicationContext(),LoginActivity.class);
                startActivity(i);
            }
        });
    }

    private void register() {

        String name = numberTextRe.getText().toString();
        String passWord = passwordTextRe.getText().toString();
        mUser = new User(name,passWord);

        MyRetrofit mr = new MyRetrofit();
        Retrofit r = mr.getRetrofit();
        final UserService request = r.create(UserService.class);

        request.signup(mUser).enqueue(new Callback<UserId>() {
            @Override
            public void onResponse(Call<UserId> call, Response<UserId> response) {
                if (response.body().getMessage() == 1){
                    Toast.makeText(getBaseContext(),"注册成功!",Toast.LENGTH_SHORT).show();
                    Intent i = new Intent(getApplicationContext(),LoginActivity.class);
                    startActivity(i);
                    Toast.makeText(getBaseContext(),"注册成功",Toast.LENGTH_SHORT).show();
                }else {
                    Toast.makeText(getBaseContext(),"这个名字已经被使用了",Toast.LENGTH_SHORT).show();
                }
            }

            @Override
            public void onFailure(Call<UserId> call, Throwable t) {
                Toast.makeText(getBaseContext(),"服务器爆炸",Toast.LENGTH_SHORT).show();

            }
        });

    }

}
