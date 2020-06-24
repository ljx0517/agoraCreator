cc.Class({
    extends: cc.Component,

    properties: {
        label: {
            default: null,
            type: cc.Label
        },
        // defaults, set visually when attaching this script to the Canvas
        text: 'Hello, World!'
    },

    // use this for initialization
    onLoad: function () {
        this.label.string = this.text;


        const rtmClient = new rtm.RtmClient()
        console.log(`[rtm] 0 rtmClient ${rtmClient}`);
        console.log(`[rtm] 1 rtmClient.login ${rtmClient.login}`);
        console.log(`[rtm] 2 initialize ${rtmClient.initialize}`);
        const handle = new rtm.IRtmServiceEventHandler();
        
        console.log(`0=======================================`);
        handle.onLoginSuccess = function () {
            console.log('[rtm] 3 onLoginSuccess');
        }
        rtmClient.initialize('115935fd38d74ce9b43b441117f4aa6a', handle);
        console.log(`1=======================================`);
        rtmClient.login('', '7654321');
        console.log(`2=======================================`);
        
    },

    // called every frame
    update: function (dt) {

    },
});
