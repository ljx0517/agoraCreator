window.__require = function e(o, n, t) {
function c(l, i) {
if (!n[l]) {
if (!o[l]) {
var s = l.split("/");
s = s[s.length - 1];
if (!o[s]) {
var u = "function" == typeof __require && __require;
if (!i && u) return u(s, !0);
if (r) return r(s, !0);
throw new Error("Cannot find module '" + l + "'");
}
l = s;
}
var g = n[l] = {
exports: {}
};
o[l][0].call(g.exports, function(e) {
return c(o[l][1][e] || e);
}, g, g.exports, e, o, n, t);
}
return n[l].exports;
}
for (var r = "function" == typeof __require && __require, l = 0; l < t.length; l++) c(t[l]);
return c;
}({
HelloWorld: [ function(e, o, n) {
"use strict";
cc._RF.push(o, "280c3rsZJJKnZ9RqbALVwtK", "HelloWorld");
cc.Class({
extends: cc.Component,
properties: {
label: {
default: null,
type: cc.Label
},
text: "Hello, World!"
},
onLoad: function() {
this.label.string = this.text;
var e = new rtm.RtmClient();
console.log("[rtm] 0 rtmClient ".concat(e));
console.log("[rtm] 1 rtmClient.login ".concat(e.login));
console.log("[rtm] 2 initialize ".concat(e.initialize));
var o = new rtm.IRtmServiceEventHandler();
console.log("0=======================================");
o.onLoginSuccess = function() {
console.log("[rtm] 3 onLoginSuccess");
};
e.initialize("115935fd38d74ce9b43b441117f4aa6a", o);
console.log("1=======================================");
e.login("", "7654321");
console.log("2=======================================");
},
update: function(e) {}
});
cc._RF.pop();
}, {} ],
"use_v2.1-2.2.1_cc.Toggle_event": [ function(e, o, n) {
"use strict";
cc._RF.push(o, "c067dP5v8hG+YeBNfDqH6PT", "use_v2.1-2.2.1_cc.Toggle_event");
cc.Toggle && (cc.Toggle._triggerEventInScript_isChecked = !0);
cc._RF.pop();
}, {} ]
}, {}, [ "HelloWorld", "use_v2.1-2.2.1_cc.Toggle_event" ]);