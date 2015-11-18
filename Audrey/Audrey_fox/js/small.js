//var img;

//function init() {
	//wait for the image to load
	//img = new Image();
	//img.onload = handleImageLoad;
	//img.src = "../code/d1.jpg";
//}

//function handleImageLoad() {

	//var canvas = document.getElementById("testCanvas");
	//stage = new createjs.Stage(canvas);

//for (var i = Things.length - 1; i >= 0; i--) {
	//Things[i]
//};




function changeBg(){
		var rand = Math.random();
	  	console.log(rand);

	  	if (rand<0.25){
	  		$('#myCanvas').css({'background-image': 'url(0.JPG)'});
	  	}
	  	else if(rand<0.50){
	  		$('#myCanvas').css({'background-image': 'url(1.JPG)'});
	  	}
	  	else if(rand<0.75){
	  		$('#myCanvas').css({'background-image': 'url(2.JPG)'});
	  	}
	  	else{
	  		$('#myCanvas').css({'background-image': 'url(3.JPG)'});
	  	}
};

$('#myCanvas').click(changeBg);


