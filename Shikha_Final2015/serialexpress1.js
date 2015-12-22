//global variables

var hear;
var Parse = require('node-parse-api').Parse;
var APP_ID = "2S5fAxS5N1XtSBDGYamziCTaqDaVsQp3Ut3snbdW";
var MASTER_KEY = "rpuVyjap73RwHRSpU97U7fhor93Voq69wu46Tdcq";
var appParse = new Parse(APP_ID, MASTER_KEY);
var bodyParser = require('body-parser');

var PORT = 33333;
var HOST = '192.168.1.100';
var dgram = require('dgram');
var server = dgram.createSocket('udp4');
var express = require("express");
var app = express();
var eport = 8000;
var url='192.168.1.100';
var eserver = app.listen(eport);
var io = require("socket.io").listen(eserver);
var serialport = require("serialport");
var SerialPort = serialport.SerialPort;
var sport = new SerialPort("/dev/ttyAMA0", {
  baudrate: 9600,
  parser: serialport.parsers.readline("\n")
}, false); 

var statistics = require('math-statistics');
var usonic = require('r-pi-usonic');
var say = require('say');
// var Gpio = require('onoff').Gpio,
  
//  button = new Gpio(18, 'in', 'both');



app.use(express.static(__dirname + '/'));
console.log('Simple static server listening at '+url+':'+eport);

server.on('listening', function () {
    var address = server.address();
    console.log('UDP Server listening on ' + address.address + ":" + address.port);
});



//initialize socket
io.sockets.on('connection', function (socket) {

  console.log("socket on");


          


  server.on('message', function (message, remote) {  
    console.log(remote.address+","+remote.port+','+ message);
    console.log("message received");
    var mes=remote.address+","+remote.port+','+ message;
    var mes_array = mes.split(',');

    for(var i = 0; i < mes_array.length; i++) {
    mes_array[i] = mes_array[i].replace(/^\s*/, "").replace(/\s*$/, "");
 
    console.log(mes_array[2]);
    }

    // socket.emit('message', {mes:mes_array[2]});
    appParse.insert ('message', {mes:mes_array[2]}, function (err, response){
    console.log("message saved");
    });
    say.speak(null, "you have a message");
    });


    var dustValue = [];
    var dustValue = new Array(10);

    // var tempValue = [];
    // var tempValue = new Array(10);


  
  
  sport.open(function(error) {

        //initialize sensor library for reading

        if (error) {
        console.log('failed to open: ' + error);
       } else {
          // port.write("A");
          console.log('Serial open');





          // button.watch(function(err, value) {
          // console.log("button pressed");
          
          // appParse.find('message', '', function (err, response) {
          // for (var i = 0; i < response.results.length; ++i) {
          // var num=Object.keys(response.results).length;
          // console.log(response.results[parseInt(num)-1].mes);
          // hear = response.results[parseInt(num)-1].mes;

          // }
          // say.speak(null, hear);
          // });
          // });
          



          usonic.init(function(err){

          var init = function(config) {
            var sensor = usonic.createSensor(config.echoPin, config.triggerPin, config.timeout);
            
          var distances;

            (function measure() {
              if (!distances || distances.length === config.rate) {
                    if (distances) {
                      print(distances);
                  }
                    distances = [];
                }
       
                setTimeout(function() {
                  distances.push(sensor());
                    measure();
                  }, config.delay);
            }());
          };
     
          var print = function(distances) {
            var distance = statistics.median(distances);
         
            process.stdout.clearLine();
            process.stdout.cursorTo(0);
         
              if (distance < 0) {
                process.stdout.write('Error: Measurement timeout.\n');
              } else {
                process.stdout.write('Distance: ' + distance.toFixed(2) + ' cm');
                console.log(' Distance measured');
                socket.emit('distSent', { distance: distance.toFixed(2) });
              }

              if(distance < 3){
                say.speak(null, ('Human detected 4 metres away' ));
                console.log("speech complete");
              };

          };
     
          init({
              echoPin: 23, //Echo pin
              triggerPin: 22, //Trigger pin
              timeout: 1000, //Measurement timeout in µs
              delay: 200, //Measurement delay in ms
              rate: 5 //Measurements per sample
          }); 
      }); 
          
         
          sport.on('data', function(data) {
          console.log("data " + data);


          result = data.split(',');
          // result[2]
          // console.log(result);

          if(result[0] == "D"){
            socket.emit('dustInfo', { dust: result[1] });

            if (dustValue.length < 10 ){
              dustValue.push(result[1]);
              console.log("dust to array");
            } else{
              dustStuff();
              console.log("pushed dust");
            }
          }

          if((result[0] == "D" && result[1]) > 700){
            say.speak(null, 'Smog levels are high, Please wear a mask');
            console.log("SMOG ALERT");
          }



          // if(result[0] == "T"){
          //   socket.emit('tempInfo', { temp: result[1] });

          //   if (tempValue.length < 10 ){
          //     tempValue.push(result[1]);
          //     console.log("temp to array");
          //   }else{
          //     tempStuff();
          //     console.log("pushed temp");
          //   }
          // } 

          if(result[0] == "C" && result[1] > 100){
            console.log(result[1]);
            console.log("stroke bird");
            // socket.emit('tempInfo', { temp: result[1] });
              appParse.find('message', '', function (err, response) {
              for (var i = 0; i < response.results.length; ++i) {
              var num=Object.keys(response.results).length;
              // console.log(response.results[parseInt(num)-1].mes);
              hear = response.results[parseInt(num)-1].mes;
              }
              });
              say.speak(null, hear);
          }
          
  

          });

          }     
      });


        var dustStuff = function(){

            var sum = 0;
              for( var i = 0; i < dustValue.length; i++ ){
              sum += parseInt( dustValue[i], 10 ); //don't forget to add the base
              }

              var avg = sum/dustValue.length;


            appParse.insert ('dustpan', { airQuality: avg , location : url }, function (err, response){
            console.log("entry made");

            dustValue = [];

            });

          }

          //   var tempStuff = function(){

          //   var sum = 0;
          //     for( var i = 0; i < tempValue.length; i++ ){
          //     sum += parseInt( tempValue[i], 10 ); //don't forget to add the base
          //     }

          //     var avg = sum/tempValue.length;


          //   appParse.insert ('dustpan', { tempNow: avg , location : url}, function (err, response){
          //   console.log("entry made");

          //   tempValue = [];

          //   });
          // }


          socket.on('getFromParse', function (data) {
          appParse.find('HumanInfo', '', function (err, response) {
          console.log(response);
          socket.emit('toScreen',{ ParseData: response });
          
          });

          });

          // socket.on('getFromParse', function (data) {
          // appParse.find('message', '', function (err, response) {
          // console.log(response);
          
          // });

          // });           

  
  });

server.bind(PORT, HOST);


      


      




