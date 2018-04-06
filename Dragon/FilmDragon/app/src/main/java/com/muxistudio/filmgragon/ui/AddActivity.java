package com.muxistudio.filmgragon.ui;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.muxistudio.filmgragon.BaseActivity;
import com.muxistudio.filmgragon.R;
import com.muxistudio.filmgragon.data.story.StoryData;
import com.muxistudio.filmgragon.data.story.StoryId;
import com.muxistudio.filmgragon.data.story.StoryWrite;
import com.muxistudio.filmgragon.net.MyRetrofit;
import com.muxistudio.filmgragon.utils.SharedPreferencesUtils;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

/**
 * Created by zdf on 18-4-2.
 */

public class AddActivity extends BaseActivity {
    private Button mButton;
    private EditText titleView;
    private EditText keyView;
    private EditText contentView;
    private Toolbar mToolbar;



    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add);
        initView();
    }

    private void initView() {
        mButton = findViewById(R.id.add_add);
        mButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                addNew();
            }
        });

        titleView = findViewById(R.id.add_title);
        keyView = findViewById(R.id.add_key);
        contentView = findViewById(R.id.add_content);

        mToolbar = findViewById(R.id.add_toolbar);
        mToolbar.setTitle("TellMeYourStory");
        setSupportActionBar(mToolbar);
        mToolbar.setNavigationIcon(R.drawable.comeback2);
    }

    private void addNew() {
        SharedPreferencesUtils s = new SharedPreferencesUtils();
        s.init(getBaseContext());
        StoryWrite storyWrite = new StoryWrite();
        storyWrite.setStoryc(contentView.getText().toString());
        storyWrite.setStorykeyword(keyView.getText().toString());
        storyWrite.setTitle(titleView.getText().toString());
        storyWrite.setUid(s.getUserId("uid"));
        MyRetrofit mr = new MyRetrofit();
        mr.getQuest().newStory(storyWrite,s.getStory("token")).enqueue(new Callback<StoryId>() {
            @Override
            public void onResponse(Call<StoryId> call, Response<StoryId> response) {
                StoryId s = response.body();
                int i = s.getStoryid();
                Intent intent = ContentActivity.newIntent(getApplicationContext(),i);
                startActivity(intent);
                Toast.makeText(getApplicationContext(),"你发起了一个故事！",Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onFailure(Call<StoryId> call, Throwable t) {

            }
        });
    }

}
