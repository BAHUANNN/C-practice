package com.muxistudio.filmgragon.adaper;

import android.content.Context;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.muxistudio.filmgragon.R;
import com.muxistudio.filmgragon.data.story.StoryContinue;
import com.muxistudio.filmgragon.data.story.StoryData;
import com.muxistudio.filmgragon.data.story.StoryLike;
import com.muxistudio.filmgragon.data.story.StorycId;
import com.muxistudio.filmgragon.net.MyRetrofit;
import com.muxistudio.filmgragon.utils.SharedPreferencesUtils;

import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

/**
 * Created by zdf on 18-4-4.
 */

public class ContentAdapter extends RecyclerView.Adapter {

    private static final int TYPE_HEAT = 0;
    private static final int TYPE_ITEM = 1;
    private static final int TYPE_FOOTER = 2;

    private List<StoryData.StoryclistBean> mList ;
    private int storyId;
    private Context mContext;

    public ContentAdapter(List l, int i, Context context){
        mList = l;
        storyId = i;
        mContext =context;
    }

    @Override
    public int getItemViewType(int position) {
        if (position == getItemCount() - 1 ) {
            return TYPE_FOOTER;
        } else if (position == 0){
            return TYPE_HEAT;
        }else {
            return TYPE_ITEM;
        }
    }

    @Override
    public RecyclerView.ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        if(viewType == TYPE_ITEM){
            View itemView = LayoutInflater.from(parent.getContext()).inflate(R.layout.card_continue,parent,false);
            ContentHolder contentHolder = new ContentHolder(itemView);
            return contentHolder;
        }else if(viewType == TYPE_HEAT){
            View itemView = LayoutInflater.from((parent.getContext())).inflate(R.layout.card_continue,parent,false);
            HeadHolder heatHolder = new HeadHolder(itemView);
            return heatHolder;
        }else {
            View footView = LayoutInflater.from(parent.getContext()).inflate(R.layout.card_footer,parent,false);
            FooterHolder footerHolder = new FooterHolder(footView);
            return footerHolder;
        }
    }

    @Override
    public void onBindViewHolder(RecyclerView.ViewHolder holder, int position) {
        if(holder instanceof FooterHolder){
            String key = mList.get(position-1).getStoryckeyword();
            ((FooterHolder) holder).footerBind(key);
        }else if(holder instanceof HeadHolder){
            String content = mList.get(position).getStoryctext();
            int fireNum = mList.get(position).getLikenumc();
            int id = mList.get(position).getStorycid();
            ((HeadHolder) holder).headBind(content,fireNum,id);
        }else {
            int fireNum = mList.get(position).getLikenumc();
            int id = mList.get(position).getStorycid();
            String key = mList.get(position-1).getStoryckeyword();
            String content = mList.get(position).getStoryctext();
            ((ContentHolder) holder).contentBind(content,key,fireNum,id);
        }
    }

    @Override
    public int getItemCount() {
        return mList.size()+1;
    }


    public class ContentHolder extends RecyclerView.ViewHolder{
        private ImageView fireView;
        private TextView fireText;
        private TextView keyText;
        private TextView contentText;
        private int storycId;

        public ContentHolder(View itemView) {
            super(itemView);
            fireView = itemView.findViewById(R.id.card_continue_fire);
            fireView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    setFire(storycId,fireText);
                }
            });
            fireText = itemView.findViewById(R.id.card_continue_fireNum);
            keyText = itemView.findViewById(R.id.card_continue_key);
            contentText = itemView.findViewById(R.id.card_continue_content);
        }

        public void contentBind(String content,String key,int fireNum,int id){

            contentText.setText(content);
            keyText.setText(key);
            fireText.setText(fireNum);
            storycId = id;
        }
    }


    public class FooterHolder extends RecyclerView.ViewHolder{
        private TextView keyText;
        private TextView contentText;
        private Button mButton;

        public FooterHolder(View itemView) {
            super(itemView);
            keyText = itemView.findViewById(R.id.card_footer_key2);
            contentText = itemView.findViewById(R.id.card_footer_content);
            mButton = itemView.findViewById(R.id.card_footer_add);
            mButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    MyRetrofit mr = new MyRetrofit();
                    SharedPreferencesUtils s = new SharedPreferencesUtils();
                    s.init(mContext);
                    StoryContinue storyContinue = new StoryContinue();
                    storyContinue.setStoryc(contentText.getText().toString());
                    storyContinue.setStoryckeyword(keyText.getText().toString());
                    storyContinue.setUid(s.getUserId("uid"));
                    mr.getQuest().continueStory(storyId,storyContinue,s.getStory("token")).enqueue(new Callback<StorycId>() {
                        @Override
                        public void onResponse(Call<StorycId> call, Response<StorycId> response) {

                        }

                        @Override
                        public void onFailure(Call<StorycId> call, Throwable t) {
                            Toast.makeText(mContext,"服务器爆炸",Toast.LENGTH_SHORT);
                        }
                    });
                }
            });
        }

        public void footerBind(String key){
            keyText.setText(key);
        }
    }


    public class HeadHolder extends RecyclerView.ViewHolder{
        private ImageView fireView;
        private ImageView keyView;
        private TextView fireText;
        private TextView keyText;
        private TextView contentText;
        private int storyId;

        public HeadHolder(View itemView) {
            super(itemView);
            fireView = itemView.findViewById(R.id.card_continue_fire);
            fireView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    setFire(storyId,fireText);
                }
            });
            fireText = itemView.findViewById(R.id.card_continue_fireNum);
            keyView = itemView.findViewById(R.id.card_continue_keyV);
            keyText = itemView.findViewById(R.id.card_continue_key);
            contentText = itemView.findViewById(R.id.card_continue_content);

            keyView.setVisibility(View.GONE);
            keyText.setVisibility(View.GONE);
        }

        public void headBind(String content,int fireNum,int id){
            contentText.setText(content);
            fireText.setText(fireNum+" ");
            storyId = id;
        }
    }

    public void setFire(int id, final TextView textView){
        MyRetrofit mr = new MyRetrofit();
        SharedPreferencesUtils s = new SharedPreferencesUtils();
        s.init(mContext);
        mr.getQuest().like(storyId,id,s.getUser("token") ).enqueue(new Callback<StoryLike>() {
            @Override
            public void onResponse(Call<StoryLike> call, Response<StoryLike> response) {
                StoryLike storyLike = response.body();
                if(storyLike.getLikenum() == -1){
                    Toast.makeText(textView.getContext(),"You have already fired it!",Toast.LENGTH_SHORT);
                }else {
                    textView.setText(storyLike.getLikenum()+" ");
                }
            }

            @Override
            public void onFailure(Call<StoryLike> call, Throwable t) {
            }
        });

    }

}
