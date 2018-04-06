package com.muxistudio.filmgragon.ui;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.text.InputType;
import android.text.method.PasswordTransformationMethod;
import android.util.Log;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.alibaba.android.arouter.facade.annotation.Route;
import com.alibaba.android.arouter.launcher.ARouter;
import com.muxistudio.filmgragon.BaseActivity;
import com.muxistudio.filmgragon.R;
import com.muxistudio.filmgragon.data.user.User;
import com.muxistudio.filmgragon.data.user.UserAuth;
import com.muxistudio.filmgragon.net.MyRetrofit;
import com.muxistudio.filmgragon.utils.SharedPreferencesUtils;
import com.rengwuxian.materialedittext.MaterialEditText;

import org.jetbrains.annotations.Nullable;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;

/**
 * Created by zdf on 18-4-1.
 */
@Route(path = "/ui/LoginActivity")
public class LoginActivity extends AppCompatActivity {

    private static final String TAG = "login";
    private MaterialEditText numberText;
    private MaterialEditText passwordText;
    private Button loginButton;
    private TextView mTextView;
    private User mUser;
    private SharedPreferencesUtils mPreferenceUtils;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.activity_login);

        initView();
        setEditText();

        Window window = getWindow();
        window.addFlags(WindowManager.LayoutParams.FLAG_TRANSLUCENT_STATUS);
    }

    private void setEditText() {
        numberText.setBaseColor(getResources().getColor(R.color.colorGray));
        numberText.setFloatingLabel(MaterialEditText.FLOATING_LABEL_HIGHLIGHT);
        numberText.setHint("用户名");
        numberText.setHintTextColor(getResources().getColor(R.color.colorGray));

        numberText.setInputType(InputType.TYPE_TEXT_VARIATION_VISIBLE_PASSWORD);

        passwordText.setBaseColor(getResources().getColor(R.color.colorGray));
        passwordText.setFloatingLabel(MaterialEditText.FLOATING_LABEL_HIGHLIGHT);
        passwordText.setHint("密码");
        passwordText.setHintTextColor(getResources().getColor(R.color.colorGray));

        passwordText.setInputType(InputType.TYPE_TEXT_VARIATION_VISIBLE_PASSWORD);
        passwordText.setTransformationMethod(PasswordTransformationMethod.getInstance());

    }

    private void initView() {
        numberText = findViewById(R.id.login_number);
        passwordText = findViewById(R.id.login_password);

        loginButton = findViewById(R.id.login_login);
        loginButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                login();
            }
        });

        mTextView = findViewById(R.id.login_goto_register);
        mTextView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(getApplicationContext(),RegisterActivity.class);
                startActivity(i);
            }
        });
    }

    private void login() {
        final String name = numberText.getText().toString();
        String passWord = passwordText.getText().toString();
        mUser = new User(name,passWord);

        MyRetrofit mr = new MyRetrofit();

        mr.getQuest().login(mUser).enqueue(new Callback<UserAuth>() {
            @Override
            public void onResponse(Call<UserAuth> call, Response<UserAuth> response) {
                UserAuth auth = response.body();
                if(auth.getUid() == -1){
                    Toast.makeText(getBaseContext(),"忘记密码了?没事!再注册一个帐号吧!",Toast.LENGTH_SHORT).show();

                }else {
                    mPreferenceUtils = new SharedPreferencesUtils();
                    mPreferenceUtils.init(getBaseContext());
                    mPreferenceUtils.setStory("username", name);
                    mPreferenceUtils.setStory("token", auth.getToken());
                    mPreferenceUtils.setStory("uid", auth.getUid());
                    Intent i = new Intent(getApplicationContext(),PersonalActivity.class);
                    i.putExtra("type",2);
                    startActivity(i);
                }
            }

            @Override
            public void onFailure(Call<UserAuth> call, Throwable t) {
                Toast.makeText(getBaseContext(),"服务器爆炸",Toast.LENGTH_SHORT).show();

                Intent i = new Intent(getApplicationContext(),PersonalActivity.class);
                i.putExtra("type",2);
                startActivity(i);
            }
        });
    }
}
