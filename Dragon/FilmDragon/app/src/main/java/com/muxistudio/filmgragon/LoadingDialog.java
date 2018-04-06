package com.muxistudio.filmgragon;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.DialogFragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ProgressBar;

/**
 * Created by kolibreath on 18-3-31.
 */

public class LoadingDialog extends DialogFragment{

  public ProgressBar mProgressBar;

  @Nullable @Override
  public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container,
      @Nullable Bundle savedInstanceState) {
    View view = inflater.inflate(R.layout.view_dialog,container);
    mProgressBar = view.findViewById(R.id.dialog_progress_bar);
    return view;
  }




}
