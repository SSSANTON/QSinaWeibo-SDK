// import QtQuick 1.0 // to target S60 5th Edition or Maemo
import QtQuick 1.1
import QtWebKit 1.0

Rectangle {
    width: 480
    height: 848

    WebView {
        id: webView

        transformOrigin: Item.TopLeft

        preferredWidth: parent.width
        preferredHeight: parent.height
        contentsScale: 1
        smooth: true
        focus: true

        onUrlChanged: {
            console.debug(url);
            var urlStr = url.toString();
            if (urlStr.indexOf("?code=") != -1) {
                var index = urlStr.indexOf("?code=");
                var code = urlStr.substring(index + 6);
                console.debug(code);
                SinaWeibo.requestAccessToken(code);
            }
        }
    }

    Component.onCompleted: {
        webView.url = SinaWeibo.loginUrl;
    }
}
