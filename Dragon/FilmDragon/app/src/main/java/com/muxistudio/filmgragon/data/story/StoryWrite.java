package com.muxistudio.filmgragon.data.story;

/**
 * Created by yueuy on 18-2-3.
 */

public class StoryWrite {
    private String title;
    private int uid;
    private String storykeyword;
    private String storyc;

    public int getUid() {
        return uid;
    }

    public void setUid(int uid) {
        this.uid = uid;
    }

    public String getStorykeyword() {
        return storykeyword;
    }

    public void setStorykeyword(String storykeyword) {
        this.storykeyword = storykeyword;
    }

    public String getStoryc() {
        return storyc;
    }

    public void setStoryc(String storyc) {
        this.storyc = storyc;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }
}
