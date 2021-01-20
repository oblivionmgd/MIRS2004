var admin = require("firebase-admin");
var exec = require('child_process');

var serviceAccount = require("./serviceAccountKey.json");

admin.initializeApp({
  credential: admin.credential.cert(serviceAccount),
  databaseURL: "https://mirsctrl-js.firebaseio.com"
});

var mirsRunCmd = "./test_conv"
var mirsStopCmd = "./conv_stop"
var db = admin.database();
var MIRS = db.ref("MIRS");
var order = db.ref("MIRS/machineStatus");
// order.set({"status":"run"});

order.on("child_changed",function(snapshot){
  if (snapshot.val() == "go"){
    console.log("got command:");
    console.log(snapshot.val());
    console.log(exec.exec(mirsRunCmd).toString());
  }
  else {
    exec.exec("killall ./test_conv");
    console.log(exec.execSync(mirsStopCmd).toString());
  }
},
function(errorObject){
  console.log("failed: " + errorObject.code);
});
