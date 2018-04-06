package com.muxistudio.filmgragon.ui;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import com.melnykov.fab.FloatingActionButton;
import com.muxistudio.filmgragon.BaseActivity;
import com.muxistudio.filmgragon.R;
import com.muxistudio.filmgragon.adaper.PersonalAdapter;
import com.muxistudio.filmgragon.adaper.StorycAdapter;
import com.muxistudio.filmgragon.data.story.StoryData;
import com.muxistudio.filmgragon.data.story.StoryMy;
import com.muxistudio.filmgragon.data.story.Storyc;
import com.muxistudio.filmgragon.net.MyRetrofit;
import com.muxistudio.filmgragon.utils.SharedPreferencesUtils;

import java.util.ArrayList;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

/**
 * Created by zdf on 18-4-2.
 */

public class PersonalActivity extends BaseActivity {
    private RecyclerView mRecyclerView;
    private Toolbar mToolbar;
    private List<StoryMy.StartBean> mStorycs;
    private List<Storyc.JoinBean> mStoryDatas;
    private SharedPreferencesUtils s = new SharedPreferencesUtils();

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_personal);

        s.init(getBaseContext());

        initView();
        initType();
    }

    private void initType() {

        int type = getIntent().getIntExtra("type",-1);
        if(type == 1){
            //我参与的
            getJoinStory();

        }else if(type == 2){
            //我发起的
            getMyStory();
        }else {
            String filmName = getIntent().getStringExtra("filmName");
            mRecyclerView.setAdapter(new PersonalAdapter(mStoryDatas,this));
        }
    }

    private void getJoinStory() {
        MyRetrofit mr = new MyRetrofit();
        mr.getQuest().cStory(s.getStory("token")).enqueue(new Callback<Storyc>() {
            @Override
            public void onResponse(Call<Storyc> call, Response<Storyc> response) {
                Storyc storyc = response.body();
                mStoryDatas = storyc.getJoin();
                mRecyclerView.setAdapter(new StorycAdapter(mStoryDatas,PersonalActivity.this));
            }

            @Override
            public void onFailure(Call<Storyc> call, Throwable t) {

            }
        });
    }

    private void getMyStory() {
        MyRetrofit mr = new MyRetrofit();
        Log.d("!!!!!!!!!!!!!!!!!!!!!!!",s.getStoryId("uid")+""+s.getStory("token"));
        mr.getQuest().myStory(s.getStoryId("uid"),s.getStory("token")).enqueue(new Callback<StoryMy>() {
            @Override
            public void onResponse(Call<StoryMy> call, Response<StoryMy> response) {
                StoryMy storyMy = response.body();
                mStorycs = storyMy.getStart();
                mRecyclerView.setAdapter(new PersonalAdapter(mStorycs,PersonalActivity.this));

            }

            @Override
            public void onFailure(Call<StoryMy> call, Throwable t) {

            }
        });
    }

    private void initView() {

        mToolbar = findViewById(R.id.personal_toolbar);
        mToolbar.setTitle("NeedKnowTheType");
        setSupportActionBar(mToolbar);
        mToolbar.setNavigationIcon(R.drawable.comeback);

        mRecyclerView = findViewById(R.id.rcv);
        mRecyclerView.setLayoutManager(new LinearLayoutManager(this));
    }


}
