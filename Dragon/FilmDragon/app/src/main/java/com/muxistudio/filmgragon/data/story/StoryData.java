package com.muxistudio.filmgragon.data.story;

import java.util.List;

/**
 * Created by yueuy on 18-1-30.
 */

public class StoryData {

    /**
     * likenum : 0
     * storyclist : [{"likenumc":0,"storyckeyword":"后端牛逼","storyctext":"谁敢反对后端，我就锤爆谁的狗头","usernamec":"1"}]
     * title : 后端最牛逼
     * username : 1
     */

    private int likenum;
    private String title;
    private String username;
    private List<StoryclistBean> storyclist;

    public int getLikenum() {
        return likenum;
    }

    public void setLikenum(int likenum) {
        this.likenum = likenum;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public List<StoryclistBean> getStoryclist() {
        return storyclist;
    }

    public void setStoryclist(List<StoryclistBean> storyclist) {
        this.storyclist = storyclist;
    }

    public static class StoryclistBean {
        /**
         * likenumc : 0
         * storyckeyword : 后端牛逼
         * storyctext : 谁敢反对后端，我就锤爆谁的狗头
         * usernamec : 1
         */

        private int likenumc;
        private String storyckeyword;
        private String storyctext;
        private String usernamec;
        private int storycid;

        public int getStorycid() {
            return storycid;
        }

        public void setStorycid(int storycid) {
            this.storycid = storycid;
        }

        public int getLikenumc() {
            return likenumc;
        }

        public void setLikenumc(int likenumc) {
            this.likenumc = likenumc;
        }

        public String getStoryckeyword() {
            return storyckeyword;
        }

        public void setStoryckeyword(String storyckeyword) {
            this.storyckeyword = storyckeyword;
        }

        public String getStoryctext() {
            return storyctext;
        }

        public void setStoryctext(String storyctext) {
            this.storyctext = storyctext;
        }

        public String getUsernamec() {
            return usernamec;
        }

        public void setUsernamec(String usernamec) {
            this.usernamec = usernamec;
        }
    }
}
