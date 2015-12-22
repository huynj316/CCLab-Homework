var Parse= require('node-parse-api').Parse;
var APP_ID="2S5fAxS5N1XtSBDGYamziCTaqDaVsQp3Ut3snbdW";
var MASTER_KEY = "rpuVyjap73RwHRSpU97U7fhor93Voq69wu46Tdcq";
var appParse = new Parse(APP_ID, MASTER_KEY);

///INSERT OBJECT
// appParse.insert('Students', { name: 'wole',age:"20" }, function (err, response) {
//   console.log(response);
// });

// appParse.find('Students', {objectId: 'GLUxY6vHwts'}, function (err, response) {
//   console.log(response);
// });

// ///FIND ONE
// appParse.find('Students', {objectId: 'GxHV8yVy9W'}, function (err, response) {
//   console.log(response);
// });

// appParse.find('Students', {where: {age2: 100}}, function (err, response) {
//   console.log(response);
// });


//DELEATE OBJECT
// appParse.delete('Students', '', function (err, response) {
// console.log(response);
// });