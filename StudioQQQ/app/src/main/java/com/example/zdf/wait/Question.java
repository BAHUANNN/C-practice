package com.example.zdf.wait;

/**
 * Created by zdf on 17-12-15.
 */

public class Question {

    private int mTextResId;
    private boolean mAnswerTrue;

    public Question (int textResId , boolean answerTure){
        mTextResId=textResId;
        mAnswerTrue=answerTure;
    }

    public int getTextResId() {
        return mTextResId;
    }

    public void setTextResId(int textResId) {
        mTextResId = textResId;
    }

    public boolean isAnswerTrue() {
        return mAnswerTrue;
    }

    public void setAnswerTrue(boolean answerTrue) {
        mAnswerTrue = answerTrue;
    }
}
