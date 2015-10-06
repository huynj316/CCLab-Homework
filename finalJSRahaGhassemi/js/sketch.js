//Global Variables

//image placement
var x = 0; 
var y = 0;

var markerSize = 20;

//images
var map1;
var map2;
var APP_STATE = 0 ; // 0 is for initial state , 1 designer clicked , 2 ,3 
var latnp = [400, 220, 415, 110, 805, 425, 490];
var lonnp = [150, 282, 155, 175, 412, 138, 117];
var numElements = 7;
var nonprofitimages = [numElements];
var selected = false;
//////////////////////////////////////////

var designerimages = [numElements];
var latd = [517, 663, 583, 573, 220, 215, 220];
var lond = [197, 233, 225, 250, 340, 185, 165];

//////////////////////////////////////////
var displayingFlag=  [];
function preload(){
  map1 = loadImage("../images/data/worldmap.png");
  map2= loadImage("../images/data/worldmap2.png");
  
   //images loading
  designerimages[0] = loadImage("../images/data/zahra.png");
  designerimages[1] = loadImage("../images/data/qinzi.png");
  designerimages[2] = loadImage("../images/data/shikha.png");
  designerimages[3] = loadImage("../images/data/priyal.png");
  designerimages[4] = loadImage("../images/data/alonso.png");
  designerimages[5] = loadImage("../images/data/ana.png");
  designerimages[6] = loadImage("../images/data/mikei.png");

  nonprofitimages[0] = loadImage("../images/data/unesco.png");
  nonprofitimages[1] = loadImage("../images/data/bf.png");
  nonprofitimages[2] = loadImage("../images/data/dwb.png");
  nonprofitimages[3] = loadImage("../images/data/kiva.png");
  nonprofitimages[4] = loadImage("../images/data/gpp.png");
  nonprofitimages[5] = loadImage("../images/data/lvsd.png");
  nonprofitimages[6] = loadImage("../images/data/fm.png");
}


function setup () {
  for( var i=0; i < numElements ; i++)
    displayingFlag[i] = false;

  createCanvas(850, 621);
  console.log("hell");
  ellipseMode(CENTER);
  // createCanvas(windowWidth, windowHeight);
  // imageMode(CENTER);
  //drawing map background
  //image(map1, x, y);
  
}

function checkHover() {
  for( var i = 0 ; i < numElements ; i++){
     displayingFlag[i] = false;
    var distance = dist(mouseX, mouseY, latnp[i], lonnp[i] );
    if (distance < markerSize/2) {
      displayingFlag[i] = true;
    }
  }

  return -1;
}

function draw () {


  switch ( APP_STATE){
    case 0:
    selected = false;
      background(map1);
      for (var i = 0; i < numElements; i++) {
          //nonProfits
          // noFill();
          noStroke();
          fill(158, 218, 230);
          ellipse(latnp[i], lonnp[i], markerSize, markerSize);

          //designers
          // noFill();
          noStroke;
          fill(237, 194, 152);
          ellipse(latd[i], lond[i], markerSize, markerSize);
        }

        checkHover();
        for (var i= 0 ; i< numElements ; i++){
          if( displayingFlag[i]){
            image(nonprofitimages[i], latnp[i], lonnp[i], 60, 60);
            image(designerimages[i], latd[i], lond[i], 60, 60);
          }
        }
    break;
    case 1:
    break;
  }
  //console.log(mouseX + "*" + mouseY );
  
   
  /*if (millis()<1400) {
    noStroke();
    fill(0, 10);
    rect(0, 0, 850, 621);
  }*/

  

}
  function mousePressed () {

    if( APP_STATE  == 0 ){
      APP_STATE = 1;
    }
       if( APP_STATE == 1){
      if( selected ){
        APP_STATE = 0;
      }
      selected = true;
      checkHover();
      for( var i =0 ; i < numElements ; i++){
        if( displayingFlag[i] ){
          strokeWeight(2);
           stroke(136, 255, 192);
           line(latd[i], lond[i], latnp[i], lonnp[i]);
           image(designerimages[i], latd[i], lond[i], 60, 60);
        } 
      }

    }
   
    /*
    if (mouseX > latd[1] && mouseX < latd[1] + markerSize && mouseY > lond[1] && mouseY < lond[1] + markerSize){
       
    }
    
    if (mouseX > latd[2] && mouseX < latd[2] + markerSize && mouseY > lond[2] && mouseY < lond[2] + markerSize){
       strokeWeight(2);
       stroke(136, 255, 192);
       line(latd[2], lond[2], latnp[2], lonnp[2]);
       image(designerimages[2], latd[2], lond[2], 70, 70);
    }
    
    if (mouseX > latd[3] && mouseX < latd[3] + markerSize && mouseY > lond[3] && mouseY < lond[3] + markerSize){
       strokeWeight(2);
       stroke(136, 255, 192);
       line(latd[3], lond[3], latnp[3], lonnp[3]);
       image(designerimages[3], latd[3], lond[3], 70, 70);
    }
    
    if (mouseX > latd[4] && mouseX < latd[4] + markerSize && mouseY > lond[4] && mouseY < lond[4] + markerSize){
       strokeWeight(2);
       stroke(136, 255, 192);
       line(latd[4], lond[4], latnp[4], lonnp[4]);
       image(designerimages[4], latd[4], lond[4], 70, 70);
    }
    
    if (mouseX > latd[5] && mouseX < latd[5] + markerSize && mouseY > lond[5] && mouseY < lond[5] + markerSize){
       strokeWeight(2);
       stroke(136, 255, 192);
       line(latd[5], lond[5], latnp[5], lonnp[5]);
       image(designerimages[5], latd[5], lond[5], 70, 70);
    }
    
    if (mouseX > latd[6] && mouseX < latd[6] + markerSize && mouseY > lond[6] && mouseY < lond[6] + markerSize){
       strokeWeight(2);
       stroke(136, 255, 192);
       line(latd[6], lond[6], latnp[6], lonnp[6]);
       image(designerimages[6], latd[6], lond[6], 70, 70);
    }
    
    if (mouseX > latnp[0] && mouseX < latnp[0] + markerSize && mouseY > lonnp[0] && mouseY < lonnp[0] + markerSize){
       strokeWeight(2);
       stroke(136, 255, 192);
       line(latd[0], lond[0], latnp[0], lonnp[0]);
       image(nonprofitimages[0], latnp[0], lonnp[0], 70, 70);
    }
    
    if (mouseX > latnp[1] && mouseX < latnp[1] + markerSize && mouseY > lonnp[1] && mouseY < lonnp[1] + markerSize){
       strokeWeight(2);
       stroke(136, 255, 192);
       line(latd[1], lond[1], latnp[1], lonnp[1]);
       image(nonprofitimages[1], latnp[1], lonnp[1], 70, 70);
    }
    
    if (mouseX > latnp[2] && mouseX < latnp[2] + markerSize && mouseY > lonnp[2] && mouseY < lonnp[2] + markerSize){
       strokeWeight(2);
       stroke(136, 255, 192);
       line(latd[2], lond[2], latnp[2], lonnp[2]);
       image(nonprofitimages[2], latnp[2], lonnp[2], 70, 70);
    }
    
    if (mouseX > latnp[3] && mouseX < latnp[3] + markerSize && mouseY > lonnp[3] && mouseY < lonnp[3] + markerSize){
       strokeWeight(2);
       stroke(136, 255, 192);
       line(latd[3], lond[3], latnp[3], lonnp[3]);
       image(nonprofitimages[3], latnp[3], lonnp[3], 70, 70);
    }
    
    if (mouseX > latnp[4] && mouseX < latnp[4] + markerSize && mouseY > lonnp[4] && mouseY < lonnp[4] + markerSize){
       strokeWeight(2);
       stroke(136, 255, 192);
       line(latd[4], lond[4], latnp[4], lonnp[4]);
       image(nonprofitimages[4], latnp[4], lonnp[4], 70, 70);
    }
    
    if (mouseX > latnp[5] && mouseX < latnp[5] + markerSize && mouseY > lonnp[5] && mouseY < lonnp[5] + markerSize){
       strokeWeight(2);
       stroke(136, 255, 192);
       line(latd[5], lond[5], latnp[5], lonnp[5]);
       image(nonprofitimages[5], latnp[5], lonnp[5], 70, 70);
    }
    
    if (mouseX > latnp[6] && mouseX < latnp[6] + markerSize && mouseY > lonnp[6] && mouseY < lonnp[6] + markerSize){
       strokeWeight(2);
       stroke(136, 255, 192);
       line(latd[6], lond[6], latnp[6], lonnp[6]);
       image(nonprofitimages[6], latnp[6], lonnp[6], 70, 70);
    }

*/  

 }
 
 function keyPressed() {
   
   image(map1, 0, 0);

    noStroke();
    fill(0, 150);
    rect(0, 0, 850, 621);


 }


