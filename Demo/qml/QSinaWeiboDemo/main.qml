// import QtQuick 1.0 // to target S60 5th Edition or Maemo
import QtQuick 1.1
import QtWebKit 1.0

Rectangle {
    width: 500
    height: 500

    Rectangle {
        anchors.centerIn: parent
        width: 50
        height: 50
        color: "red"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                SinaWeibo.logIn();
            }
        }
    }

    /*
    WebView {
        id: webView

        transformOrigin: Item.TopLeft

        preferredWidth: 480//parent.width
        preferredHeight: 500//parent.height
        contentsScale: 1
        smooth: true
        focus: true

        onUrlChanged: {
            console.debug(url);
            var urlStr = url.toString();
            if (urlStr.indexOf("?code=") != -1) {
                var index = urlStr.indexOf("?code=");
                var code = urlStr.substring(index + 6);
                //console.debug(code);
                SinaWeibo.requestAccessToken(code);
            }
        }
    }

    Rectangle {
        anchors.bottom: webView.bottom
        width: 50
        height: 50
        color: "red"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                webView.url = SinaWeibo.loginUrl;
            }
        }
    }
    */

    /*
    Component.onCompleted: {
        webView.url = SinaWeibo.loginUrl;
    }
    */
}
