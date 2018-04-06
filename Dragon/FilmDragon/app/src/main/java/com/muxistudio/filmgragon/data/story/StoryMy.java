package com.muxistudio.filmgragon.data.story;

import java.util.List;

/**
 * Created by zdf on 18-4-7.
 */

public class StoryMy {


    private List<StartBean> start;

    public List<StartBean> getStart() {
        return start;
    }

    public void setStart(List<StartBean> start) {
        this.start = start;
    }

    public static class StartBean {
        /**
         * likenum : 1
         * storyid : 1
         * title : 后端最牛逼
         */

        private int likenum;
        private int storyid;
        private String title;

        public int getLikenum() {
            return likenum;
        }

        public void setLikenum(int likenum) {
            this.likenum = likenum;
        }

        public int getStoryid() {
            return storyid;
        }

        public void setStoryid(int storyid) {
            this.storyid = storyid;
        }

        public String getTitle() {
            return title;
        }

        public void setTitle(String title) {
            this.title = title;
        }
    }
}
