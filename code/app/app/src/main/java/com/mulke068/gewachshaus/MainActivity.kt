package com.mulke068.gewachshaus

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.KeyEvent
import android.view.MotionEvent
import android.view.View
import android.webkit.WebSettings
import android.webkit.WebView
import android.webkit.WebViewClient

class MainActivity : AppCompatActivity() {
    var mWebView : WebView? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        mWebView = findViewById<View>(R.id.WebView) as WebView
        mWebView!!.webViewClient = object : WebViewClient(){
            @Deprecated("Deprecated in Java")
            override fun shouldOverrideUrlLoading(view: WebView?, url: String?): Boolean {
                if (url != null) {
                    view?.loadUrl(url)
                }
                return true
            }
        }

        //mWebView.loadUrl("https://kevbchef.com")

        val webSettings = mWebView!!.settings
        webSettings.javaScriptEnabled = true
        //mWebView.webViewClient = WebViewClient()

        mWebView!!.loadUrl("https://kevbchef.com")

        mWebView!!.canGoBack()
        mWebView!!.setOnKeyListener(View.OnKeyListener { _, keyCode, event ->
            if(keyCode == KeyEvent.KEYCODE_BACK
                && event.action == MotionEvent.ACTION_UP
                && mWebView!!.canGoBack()){
                  mWebView!!.goBack()
                  return@OnKeyListener true
                }
            false
        })


    }


}