var admin = require("firebase-admin");
var exec = require('child_process');

var serviceAccount = require("./serviceAccountKey.json");

admin.initializeApp({
  credential: admin.credential.cert(serviceAccount),
  databaseURL: "https://mirsctrl-js.firebaseio.com"
});

var mirsRunCmd
var mirsStopCmd = "./conv_stop"
var db = admin.database();
var MIRS = db.ref("MIRS");
var order = db.ref("MIRS/machineStatus");
var ball = db.ref("MIRS/selectedBall");
// order.set({"status":"run"});
ball.on("child_changed", function(snapshot){
  if (snapshot.val() == "tennisball"){
    mirsRunCmd = "./hoge";
    console.log("Execution: " + mirsRunCmd.toString());
  }
  else {
    mirsRunCmd = "./fuga";
    console.log("Execution: " + mirsRunCmd.toString());
  }
},
function(errorObject){
  console.log("failed:" + errorObject.code);
});

order.on("child_changed",function(snapshot){
  if (snapshot.val() == "go"){
    console.log(exec.exec(mirsRunCmd).toString());
  }
  else {
    console.log("Stopped.")
    exec.exec("killall " + mirsRunCmd.toString());
    console.log(exec.execSync(mirsStopCmd).toString());
  }
},
function(errorObject){
  console.log("failed: " + errorObject.code);
});
