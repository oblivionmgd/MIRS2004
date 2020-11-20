var admin = require("firebase-admin");

var serviceAccount = require("./serviceAccountKey.json");

admin.initializeApp({
  credential: admin.credential.cert(serviceAccount),
  databaseURL: "https://mirsctrl-js.firebaseio.com"
});

var db = admin.database();
var ref = db.ref("product/studio");

var usersRef = ref.child("sensor");
usersRef.set({
  "temperature":26,
  "humid":43
});

ref.on("value",function(snapshot){
  console.log("value Changed!");
  console.log(snapshot.val());
},
function(errorObject){
  console.log("failed: " + errorObject.code);
});
