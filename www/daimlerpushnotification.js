
/*

Daimler Base push notification Cordova plugin
Created by Mohamed ali Tlili & Joachim Schuster
mohamedali.tlili@esprit.tn

 */



    function daimlerPushSubscribe() {};

    daimlerPushSubscribe.prototype.subscribe = function(token, apiKey, baseUrl, username, userCategory, userTopics, UserLanguage) {
        cordova.exec(function () {
            console.log("DAIMLER BASE PUSH NOTIFICATION PLUGIN -> Success in launching registration process. " +
                "This does not mean that you registered successfully on BASE system." +
                "Please check on BASE platform. ")
        }, function () {
            console.log("DAIMLER BASE PUSH NOTIFICATION PLUGIN -> Failed to launch registration process. Don't sit there and cry, check what's wrong.")
        }, 'daimlerpushnotification', 'daimlerPushSubscribe', [token, apiKey, baseUrl, username, userCategory, userTopics, UserLanguage]);
    };


    window.daimlerPushSubscribe = new daimlerPushSubscribe();


