package com.muxistudio.filmgragon.ui;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.widget.TextView;

import com.muxistudio.filmgragon.R;
import com.muxistudio.filmgragon.adaper.ContentAdapter;
import com.muxistudio.filmgragon.data.story.StoryData;
import com.muxistudio.filmgragon.net.MyRetrofit;

import java.util.ArrayList;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;

/**
 * Created by zdf on 18-4-3.
 */

public class ContentActivity extends AppCompatActivity{
    private RecyclerView mRecyclerView;
    private TextView titleText;
    private TextView fireText;
    private TextView numText;
    private Toolbar mToolbar;

    private int storyId;
    private List<StoryData.StoryclistBean> storyList = new ArrayList();


    public static Intent newIntent(Context context, int Id){
        Intent i = new Intent(context,ContentActivity.class);
        i.putExtra("Id",Id);
        return i;
    }

    @Override
    public void onResume() {

        super.onResume();
        getDragon();
    }

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_content);
        storyId = getIntent().getIntExtra("Id",-1);
        initView();
        getDragon();
    }

    private void initView() {
        titleText = findViewById(R.id.content_title);

        fireText = findViewById(R.id.content_fireNum);

        numText = findViewById(R.id.content_num);
        numText.setText(String.valueOf(storyList.size()));

        mRecyclerView = findViewById(R.id.content_rcv);
        mRecyclerView.setLayoutManager(new LinearLayoutManager(this));

        mToolbar = findViewById(R.id.content_toolbar);
        setSupportActionBar(mToolbar);
        mToolbar.setNavigationIcon(R.drawable.comeback2);

    }

    private void getDragon() {
        MyRetrofit mr = new MyRetrofit();
        mr.getQuest().showStory(storyId).enqueue(new Callback<StoryData>() {
            @Override
            public void onResponse(Call<StoryData> call, Response<StoryData> response) {
                StoryData s = response.body();
                titleText.setText(s.getTitle());
                fireText.setText(s.getLikenum()+" ");

                storyList = s.getStoryclist();
                mRecyclerView.setAdapter(new ContentAdapter(storyList,storyId,getBaseContext()));
            }

            @Override
            public void onFailure(Call<StoryData> call, Throwable t) {

            }
        });

    }

}
