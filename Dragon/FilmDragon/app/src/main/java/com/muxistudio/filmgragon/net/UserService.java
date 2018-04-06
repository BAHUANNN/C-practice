package com.muxistudio.filmgragon.net;

import com.muxistudio.filmgragon.data.story.Keyword;
import com.muxistudio.filmgragon.data.story.StoryContinue;
import com.muxistudio.filmgragon.data.story.StoryData;
import com.muxistudio.filmgragon.data.story.StoryId;
import com.muxistudio.filmgragon.data.story.StoryLike;
import com.muxistudio.filmgragon.data.story.StoryMy;
import com.muxistudio.filmgragon.data.story.StoryWrite;
import com.muxistudio.filmgragon.data.story.Storyc;
import com.muxistudio.filmgragon.data.story.StorycId;
import com.muxistudio.filmgragon.data.user.*;

import retrofit2.Call;
import retrofit2.http.Body;
import retrofit2.http.GET;
import retrofit2.http.Header;
import retrofit2.http.POST;
import retrofit2.http.Path;

/**
 * Created by yueuy on 18-1-30.
 */

public interface UserService {

    //注册
    @POST("/api/signup/")
    Call<UserId> signup(@Body User user);
    //登录
    @POST("/api/signin/")
    Call<UserAuth> login(@Body User user);
    //查看故事详情
    @GET("/api/story/{storyid}/")
    Call<StoryData> showStory(@Path("storyid") int storyId);
    //点赞
    @GET("/api/story/{storyid}/{storycid}/like/")
    Call<StoryLike> like(@Path("storyid") int storyId,
                         @Path("storycid") int storycId,
                         @Header("token") String token);
    //发起故事
    @POST("/api/story/write/")
    Call<StoryId> newStory(@Body StoryWrite storyWrite,
                           @Header("token") String token);
    //续写故事
    @POST("/api/story/<storyid>/continue/")
    Call<StorycId> continueStory(@Path("storyid") int storyid,
                            @Body StoryContinue storyContinue,
                                 @Header("token") String token);


    //电影
    @POST("/api/search/detial/")
    Call<Storyc> filmStory(@Body Keyword keyword);
    //我参与的
    @GET("/api/user/{uid}/join/")
    Call<Storyc> cStory(@Header("token") String token );
    //我发起的
    @GET("/api/user/{uid}/write/")
    Call<StoryMy> myStory(@Path("uid") int uid,
            @Header("token") String token );


}