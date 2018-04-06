package com.muxistudio.filmgragon.net;

import java.util.concurrent.TimeUnit;

import okhttp3.OkHttpClient;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

/**
 * Created by zdf on 18-4-4.
 */

public class MyRetrofit {
    public static final String BASE_URL = "http://120.78.194.125:2000";
    private Retrofit mRetrofit;
    private UserService mQuest;

    public MyRetrofit(){
        OkHttpClient client = new OkHttpClient.Builder()
                .readTimeout(15, TimeUnit.SECONDS)
                .connectTimeout(15,TimeUnit.SECONDS)
                .writeTimeout(15,TimeUnit.SECONDS)
                .build();

        Retrofit mRetrofit = new Retrofit.Builder()
                .client(client)
                .addConverterFactory(GsonConverterFactory.create())
                .baseUrl(BASE_URL)
                .build();

        this.mRetrofit = mRetrofit;
        mQuest = mRetrofit.create(UserService.class);

    }

    public Retrofit getRetrofit(){
        return mRetrofit;
    }

    public UserService getQuest(){
        return mQuest;
    }

}
