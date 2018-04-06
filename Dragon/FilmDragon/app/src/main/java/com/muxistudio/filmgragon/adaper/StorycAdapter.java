package com.muxistudio.filmgragon.adaper;

import android.content.Context;
import android.content.Intent;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import android.widget.Toast;

import com.muxistudio.filmgragon.R;
import com.muxistudio.filmgragon.data.story.Storyc;
import com.muxistudio.filmgragon.ui.ContentActivity;

import org.w3c.dom.Text;

import java.util.List;

/**
 * Created by zdf on 18-4-7.
 */

public class StorycAdapter extends RecyclerView.Adapter {
    private List<Storyc.JoinBean> mList;
    private Context mContext;
    public StorycAdapter(List l,Context context){
        mList = l;
        mContext = context;
    }

    @Override
    public RecyclerView.ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View itemView = LayoutInflater.from(parent.getContext()).inflate(R.layout.view_storyc,parent,false);
        StorycAdapter.ViewHolder viewHolder = new StorycAdapter.ViewHolder(itemView,mContext);
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

    public class ViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener{

        private Context mContext;
        private TextView contentText;
        private TextView fireNumText;
        private int storyId;

        public ViewHolder(View itemView,Context context) {
            super(itemView);
            mContext = context;

            contentText =itemView.findViewById(R.id.card_storyc_content);
            fireNumText =itemView.findViewById(R.id.card_storyc_fireNum);
        }

        public void bind(Storyc.JoinBean s){
            contentText.setText(s.getStoryc());
            fireNumText.setText(s.getLikenum()+" ");
        }

        @Override
        public void onClick(View v) {
            Toast.makeText(mContext, "click", Toast.LENGTH_SHORT).show();
            Intent i = ContentActivity.newIntent(mContext,storyId);
            mContext.startActivity(i);
        }
    }
}
