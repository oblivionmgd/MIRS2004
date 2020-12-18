var admin = require("firebase-admin");
var exec = require('child_process');

var serviceAccount = require("./serviceAccountKey.json");

admin.initializeApp({
  credential: admin.credential.cert(serviceAccount),
  databaseURL: "https://mirsctrl-js.firebaseio.com"
});

var mirsRunCmd = "./Helloworld"
var db = admin.database();
var MIRS = db.ref("MIRS");
var order = db.ref("MIRS/machineStatus");
// order.set({"status":"run"});

order.on("child_changed",function(snapshot){
  if (snapshot.val() == "go"){
    //console.log(exec.execSync(mirsRunCmd).toString());
    console.log("got command:");
    console.log(snapshot.val());
  }
  else {
    //console.log(exec.execSync(mirsStopCmd).toString());
    console.log("got command:");
    console.log(snapshot.val());
  }
},
function(errorObject){
  console.log("failed: " + errorObject.code);
});
