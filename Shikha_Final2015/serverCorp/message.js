
var PORT = 33333;
var HOST = '192.168.1.100'; //change to servers ip address

var dgram = require('dgram');

var message;
var bool = 0;

var client = dgram.createSocket('udp4');
var clientName="";

var express = require("express");
var app = express();
var eport = 3000;
var url='192.168.1.100'
var eserver = app.listen(eport);
var io = require("socket.io").listen(eserver);


///create server
app.use(express.static(__dirname + ''));
console.log('Simple static server listening at '+url+':'+eport);

app.get('', function (req, res) {
  res.setHeader('Content-Type', 'text/plain; charset=utf-8')
  res.end('YOUR SERVER IS RUNNING')

});


io.sockets.on('connection', function (socket) {
  

  // socket.on('sendMessage', function (data) {

  // message = new Buffer(data);
  // client.send(message, 0, message.length, PORT, HOST, function(err, bytes) {
  //           if (err) throw err;
  //           console.log('UDP message sent to ' + HOST +':'+ PORT); 


  //   console.log(message);
  // });

    socket.on('sendMessage', function(message){
    console.log('message: ' + message);
    client.send(message, 0, message.length, PORT, HOST, function(err, bytes) {
            if (err) throw err;
            console.log('UDP message sent to ' + HOST +':'+ PORT); 


    console.log(message);
  });


  });
});
