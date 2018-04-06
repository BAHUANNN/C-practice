package com.muxistudio.filmgragon;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.widget.ProgressBar;

/**
 * Created by kolibreath on 18-3-31.
 */

public class BaseActivity extends AppCompatActivity {

  private LoadingDialog mDialog;
  private ActionBar mActionBar;
  //private AlertDialog.Builder mDialog;


  @Override
  protected void onCreate(@Nullable Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    mActionBar = getSupportActionBar();
    if(mActionBar!=null){
      mActionBar.setDisplayHomeAsUpEnabled(true);
    }
  }

  public void showLoadingDialog() {
    if (mDialog == null) {
      mDialog = new LoadingDialog();
    }
    mDialog.show(getSupportFragmentManager(),"LoadingFragment");
  }

  public   void hideLoadingDialog(){
    if(mDialog!=null){
      mDialog.dismissAllowingStateLoss();
    }
  }

  private void showDialog(){

  }

  private void setTitle(String title){
    mActionBar.setTitle(title);
  }
}
