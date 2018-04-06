package com.muxistudio.filmgragon.data.story;

import java.util.List;

/**
 * Created by zdf on 18-4-7.
 */

public class Storyc {


    private List<JoinBean> join;

    public List<JoinBean> getJoin() {
        return join;
    }

    public void setJoin(List<JoinBean> join) {
        this.join = join;
    }

    public static class JoinBean {
        /**
         * storyc : 谁敢反对后端，我就锤爆谁的狗头
         * storyckeyword : 后端牛逼
         * storyid : 1
         */

        private String storyc;
        private String storyckeyword;
        private int storyid;
        private int likenum;

        public int getLikenum() {
            return likenum;
        }

        public void setLikenum(int likenum) {
            this.likenum = likenum;
        }

        public String getStoryc() {
            return storyc;
        }

        public void setStoryc(String storyc) {
            this.storyc = storyc;
        }

        public String getStoryckeyword() {
            return storyckeyword;
        }

        public void setStoryckeyword(String storyckeyword) {
            this.storyckeyword = storyckeyword;
        }

        public int getStoryid() {
            return storyid;
        }

        public void setStoryid(int storyid) {
            this.storyid = storyid;
        }
    }
}
