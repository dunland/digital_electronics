/*

This is the script which implements the connect widget for the Connect Server.

To use the widget, clients should:

1. Include the script with GET-parameters
* client_id should be a string containing the application's id as registered in the Connect Server
* country should be a string containing the user's two letter ISO country code
* ui_locales is optional ISO language code for overriding the browser Accept language
2. Trigger the function connectServerWidget.start() to show the widget.

The widget should work in all A-grade browsers.

*/


var connectServerWidget = (function () {
var static_url = "https://account.sonymobile.com/api/static/";
var widget_resource = "connectwidget";

var country = "GB";
var direction = "ltr";
var somcSignupUrl = "https://account.sonymobile.com/en-GB/#/signup";
var signup_link_prefix = "or ";
var signup_link_url = "javascript:connectServerWidget.connectWithProvider('signup', 'Sony Mobile Signup');";
var signup_link_link = "sign up for a Sony account";
var signup_link_suffix = "";
var css_url = static_url + "css/widget-overlay" + (direction === "rtl" ? "-rtl" : "") + ".css";

var applicationName = "v2.developer.sony.com";
var google_analytics_ua_environment = "production";
var returningUserCookieName = "connect.returning-user";

var providers = [{"id_provider":"sonyericsson","name":"Sony","authorize_uri":"https://account.sonymobile.com/api/v2/oauth2/authorize?client_id=v2.developer.sony.com&country=GB&id_provider=sonyericsson&prompt=login&redirect_uri=https%3A%2F%2Fdeveloper.sony.com%2Foauth%2Fcallback&response_type=code&scope=profile+email&ui_locales=en"},{"id_provider":"google","name":"Google","authorize_uri":"https://account.sonymobile.com/api/v2/oauth2/authorize?client_id=v2.developer.sony.com&country=GB&id_provider=google&prompt=login&redirect_uri=https%3A%2F%2Fdeveloper.sony.com%2Foauth%2Fcallback&response_type=code&scope=profile+email&ui_locales=en"},{"id_provider":"facebook","name":"Facebook","authorize_uri":"https://account.sonymobile.com/api/v2/oauth2/authorize?client_id=v2.developer.sony.com&country=GB&id_provider=facebook&prompt=login&redirect_uri=https%3A%2F%2Fdeveloper.sony.com%2Foauth%2Fcallback&response_type=code&scope=profile+email&ui_locales=en"}];

//lang codes
var props_signin = "Connect";
var props_close = "Close";
var props_connect_with = "Connect with";
var signin_clarify = "Select one of the accounts below to sign in";

var redirectDirect_url = "";

// Append the widget's stylesheet
var widget_css = document.createElement('link');
widget_css.type = 'text/css';
widget_css.rel = 'stylesheet';
widget_css.href = css_url;
document.getElementsByTagName('head')[0].appendChild(widget_css);

var $id = function (id) {
return document.getElementById(id);
};

var addEvent = function (element, eventName, callback) {
if (element.attachEvent) { //until ie11
return element.attachEvent('on' + eventName, callback);
}
return element.addEventListener(eventName, callback, false);
};

var buildWidgetHTML = function () {

var markup = [];
markup.push('<div id="connect-widget" >');
markup.push('<div class="connect-widget-body">');
markup.push('<div id="connect-widget-close" ></div>');
markup.push('<div class="widget-header centered">');
markup.push('<div class="header-sony-logo"></div>');
markup.push('<h2>' + signin_clarify + '</h2>');
markup.push('</div>');

markup.push(buildProvidersMarkup());

markup.push('<div class="widget-signup centered">');
markup.push('<span>' + signup_link_prefix+'</span>');
markup.push('<a href="' + signup_link_url + '" class="bnw">' + signup_link_link + '</a>' + signup_link_suffix);
markup.push('</div>');
markup.push('</div>');
markup.push('</div>');

return markup.join('');

};

var buildProviderMarkup = function (provider) {

var markup = [];

markup.push('<a href="');

markup.push("javascript:connectServerWidget.connectWithProvider('" + provider.authorize_uri + "','" + provider.name + "')\">");
markup.push('<div class=\"provider ');
markup.push(provider.id_provider);
markup.push('">');
markup.push('<span>'+provider.name + '</span>');
markup.push('</div>');
markup.push('</a>');

return markup.join('');
};

var buildProvidersMarkup = function () {

var markup = [];
markup.push('<div id="providers" class="providers-' + providers.length + ' clearfix">');

for (var i = 0; i < providers.length; i++) {

var provider = providers[i];
provider.bigIcon = provider.id_provider == 'sonyericsson' || provider.id_provider == 'sen' || provider.id_provider == 'snei';

markup.push(buildProviderMarkup(provider));
}

markup.push('</div>');
if (providers.length == 0) {
markup.push('<div class="providers">');
markup.push('<p class="error" > Error, unable to fetch available providers </p> </div >');
}
return markup.join('');
};

var closeWidget = function (e) {
if (e.preventDefault) {
e.preventDefault();
} else {
window.event.returnValue = false;
}

var elem = $id('connect-widget-v2-outer');
if (elem.parentNode) {
elem.parentNode.removeChild(elem);
}
};

var createWidget = function () {

var widgetDiv = document.createElement('div');

widgetDiv.id = 'connect-widget-v2-outer';
widgetDiv.className = widget_resource;
widgetDiv.innerHTML = buildWidgetHTML();

document.getElementsByTagName('body')[0].appendChild(widgetDiv);

$id('connect-widget-v2-outer').style.position = "fixed";

addEvent($id('connect-widget-close'), 'click', closeWidget);
};


var showWidget = function () {
if ($id('connect-widget-v2-outer')) {
return;
}

if (providers && providers.length > 1) {
createWidget();
}
};

var start = function () {
if (redirectDirect_url) {
connectWithProvider(redirectDirect_url, '');
} else {
this.showWidget();
}
};

var connectWithProvider = function (url, trackEventProvider) {
window.dataLayer.push({
'event': 'Widget Provider ' + trackEventProvider,
'label': country.toLowerCase() + '_account',
'applicationName': applicationName
});

if (url == 'signup') {
url = somcSignupUrl;
}
window.location.href = url;
};

function URLDecode(psEncodeString) {
var lsRegExp = /\+/g;
return decodeURIComponent(String(psEncodeString).replace(lsRegExp, " "));
}

function getCookie(key, options) {
options = options ? options : {};
var result, decode = options.raw ? function (s) {
return s;
} : decodeURIComponent;
return (result = new RegExp('(?:^|; )' + encodeURIComponent(key) + '=([^;]*)').exec(document.cookie)) ? decode(result[1]) : null;
}

// Base 64 code humbly borrowed from
// http://www.webtoolkit.info/javascript-base64.html
var Base64 = {
// private property
_keyStr: "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=",
// public method for decoding
decode: function (input) {
var output = "";
var chr1, chr2, chr3;
var enc1, enc2, enc3, enc4;
var i = 0;
input = input.replace(/[^A-Za-z0-9\+\/\=]/g, "");
while (i < input.length) {
enc1 = this._keyStr.indexOf(input.charAt(i++));
enc2 = this._keyStr.indexOf(input.charAt(i++));
enc3 = this._keyStr.indexOf(input.charAt(i++));
enc4 = this._keyStr.indexOf(input.charAt(i++));
chr1 = (enc1 << 2) | (enc2 >> 4);
chr2 = ((enc2 & 15) << 4) | (enc3 >> 2);
chr3 = ((enc3 & 3) << 6) | enc4;
output = output + String.fromCharCode(chr1);
if (enc3 != 64) {
output = output + String.fromCharCode(chr2);
}
if (enc4 != 64) {
output = output + String.fromCharCode(chr3);
}
}
output = Base64._utf8_decode(output);
return output;
},
// private method for UTF-8 decoding
_utf8_decode: function (utftext) {
var string = "";
var i = 0;
var c = c1 = c2 = 0;
while (i < utftext.length) {
c = utftext.charCodeAt(i);
if (c < 128) {
string += String.fromCharCode(c);
i++;
} else if ((c > 191) && (c < 224)) {
c2 = utftext.charCodeAt(i + 1);
string += String.fromCharCode(((c & 31) << 6) | (c2 & 63));
i += 2;
} else {
c2 = utftext.charCodeAt(i + 1);
c3 = utftext.charCodeAt(i + 2);
string += String.fromCharCode(((c & 15) << 12) | ((c2 & 63) << 6) | (c3 & 63));
i += 3;
}
}
return string;
}
};

var returningUserCookie = getCookie(returningUserCookieName);

var jsonObject = null;
if (returningUserCookie != null) {
jsonObject = JSON.parse(URLDecode(Base64.decode(returningUserCookie)));
}

var initTracking = function () {

window.dataLayer = window.dataLayer || [];

var dataLayerObject = {
site: {
environment: google_analytics_ua_environment
},
page_category: {
siteSection: 'Account',
siteSubSection: 'Signin'
},
page_details: {
url: window.location.pathname
},
user: {
loginType: 'anon',
loginState: false
}
};

if (jsonObject != null) { // is returningUser
dataLayerObject.user.userId = jsonObject.trackingId;
dataLayerObject.user.loginState = true;
dataLayerObject.user.loginType = jsonObject.providerId;
}

window.dataLayer.push(dataLayerObject);

};

initTracking();

return {
showWidget: showWidget,
start: start,
connectWithProvider: connectWithProvider
};
}());
