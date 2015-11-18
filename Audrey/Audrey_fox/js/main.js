//var stage = new createjs.Stage("myCanvas");

//var mouseTarget;	// the display object currently under the mouse, or being dragged
//var dragStarted;	// indicates whether we are currently in a drag operation
//var offset;
//var update = true;
//var images = [];


//initialize
//var init = function(){
	//canvas = document.getElementById("myCanvas");
	//stage = new createjs.Stage(canvas);

	//stage.enableMouseOver(10);
	//stage.mouseMoveOutside = true; // keep tracking the mouse even when it leaves the canvas

	//loadImages();
	//update();
//};

//var canvasBg = document.getElementById('myCanvas'),
//context = canvas.getContext('2d');

//makeBg();

//function makeBg(){
	//makeBg = new Image();
  	//makeBg.src = 'b1.JPG';
  	//makeBg.onload = function(){
    //context.drawImage(makeBg, 0, 0, 100, 100);
//};
$('#myCanvas').click(function(){
	$('#myCanvas').css({'background-image': 'url(images/' + (Math.random(0,3)) +'.JPG)'});
	// do my image switching logic here.
});


//var imagesSrc = [
//['d1.jpg', 'd2.jpg', 'd3.jpg'],
//['w1.jpg', 'w2.jpg', 'w3.jpg'],
//];//add array of imgs


//function loadImages() {
	//for (var i = 0; i < imagesSrc.length; i++) {
		//images[i] = [];

	//for (var j = 0; j < imagesSrc[i].length; j++) {
		//i//mages[i][j] = new Image();
		//images[i][j].onload = function(){};
		//images[i][j].src = imagesSrc[i][j];
	//}
	//push the randomized image into the html

//}

//var 