package com.muxistudio.filmgragon.adaper;

import android.content.Context;
import android.content.Intent;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.muxistudio.filmgragon.R;
import com.muxistudio.filmgragon.data.story.StoryMy;
import com.muxistudio.filmgragon.ui.ContentActivity;

import java.util.List;
/**
 * Created by zdf on 18-4-3.
 */

public class PersonalAdapter extends RecyclerView.Adapter {
    private List<StoryMy.StartBean> mList;
    private Context mContext;

    public PersonalAdapter(List l,Context context){
        mList = l;
        mContext=context;
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View itemView = LayoutInflater.from(parent.getContext()).inflate(R.layout.card_view,parent,false);
        ViewHolder viewHolder = new ViewHolder(itemView,mContext);
        return viewHolder;
    }

    @Override
    public void onBindViewHolder(RecyclerView.ViewHolder holder, int position) {
        ((ViewHolder)holder).bind(mList.get(position));
    }

    @Override
    public int getItemCount() {
        return mList.size();
    }

    public static class ViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener{

        private ImageView fire;
        private TextView fireNum;
        private TextView louNum;
        private TextView content;
        private int storyId;
        private Context mContext;

        public ViewHolder(View itemView,Context context) {
            super(itemView);
            itemView.setOnClickListener(this);
            mContext=context;
            content = itemView.findViewById(R.id.card_view_content);
            louNum = itemView.findViewById(R.id.card_view_loushu);
            fireNum = itemView.findViewById(R.id.card_view_dianzan);
            fire = itemView.findViewById(R.id.fire);

        }

        public void bind(StoryMy.StartBean ss){
            storyId = ss.getStoryid();
            content.setText(ss.getTitle());
            fireNum.setText(ss.getLikenum()+" ");

        }

        @Override
        public void onClick(View v) {
            Toast.makeText(mContext, "click", Toast.LENGTH_SHORT).show();
            Intent i = ContentActivity.newIntent(mContext,storyId);
            mContext.startActivity(i);
        }
    }
}
