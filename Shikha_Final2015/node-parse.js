///Parse data
var Parse = require('node-parse-api').Parse;
var APP_ID = "2S5fAxS5N1XtSBDGYamziCTaqDaVsQp3Ut3snbdW";
var MASTER_KEY = "rpuVyjap73RwHRSpU97U7fhor93Voq69wu46Tdcq";
var appParse = new Parse(APP_ID, MASTER_KEY);

var bodyParser = require('body-parser');
var express = require("express");
var app = express();
var port = 8000;
var url='localhost'
var server = app.listen(port);
var io = require("socket.io").listen(server);


///create server
app.use(express.static(__dirname + ''));
console.log('Simple static server listening at '+url+':'+port);

app.get('', function (req, res) {
  res.setHeader('Content-Type', 'text/plain; charset=utf-8')
  res.end('YOUR SERVER IS RUNNING')

})


io.sockets.on('connection', function (socket) {
  

  socket.on('sendToParse', function (data) {
    console.log(data);
    appParse.insert('WootWoot', { firstName: data.firstName,lastName:data.lastName,age:data.age,pet:data.pet,drake:data.drake }, function (err, response) {
  	// console.log(response);
  	console.log("entry made");
	});
  });


socket.on('getFromParse', function (data) {
    appParse.find('WootWoot', '', function (err, response) {
  console.log(response);
  socket.emit('toScreen',{ ParseData: response });
});
   
  });







});
///INSERT OBJECT
// appParse.insert('Students', { name: 'wole',age:"20" }, function (err, response) {
//   console.log(response);
// });

///FIND ONE
// appParse.find('Students', {objectId: 'rGP6EQe35h'}, function (err, response) {
//   console.log(response);
// });

///FIND MANY
// appParse.find('Students', {where: {name: 'ayo'}}, function (err, response) {
//   console.log(response);
// });

///FIND ALL
// appParse.find('Students', '', function (err, response) {
//   console.log(response);
// });

///DELEATE OBJECT
// appParse.delete('Students', 'rGP6EQe35h', function (err, response) {
//   // response = {} 
// });