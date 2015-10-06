// console.log("We asd;lfkjas;dlfjk");

// function printToday(name) {
// 	var today = new Date();
// 	alert("it's reading it" + name + "! the date is: " + today.toDateString());
// }

// printToday("Sarah");
// printToday("Jenny");




// <li class="circle1" input type="checkbox" id="check"><label for="check">Toggle</label></li>



// $(function() {
// 	$( "#check" ).button();
// 	$( "#circle1" ).buttonset();

// });


// var ims = document.getElementsByClassName("circle1");

// for ( var i=0 ; i<ims.length ; i++ ){
// 	ims[i].onclick=function() {
// 		if (this.className == "clicked") {
// 			this.className = "";
// 		} else {
// 		this.className = "clicked";
// 	}

// 	};
// }



$ ( "#circle1" ).one( "click", function() {
	$( this ).css( "border-color", "black");
});

// $( "#circle1").each(function () {
//     $(this).click(function () {

//         if ($(this).css("border-color") == "white") {
//             $(this).css('border-color', 'black');
//         } else {
//             $(this).css('border-color', 'white');
//         }
//     });
// });

$ ( "#circle2" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle3" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle4" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle5" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle6" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle7" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle8" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle9" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle10" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle11" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle12" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle13" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle14" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle15" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle16" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle17" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle18" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle19" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle20" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});

$ ( "#circle21" ).one( "click", function() {
	$( this ).css( "border-color", "#000");
});




$(function(){
  $('.like-toggle').click(function(){
    $(this).toggleClass('like-active');
    $(this).next().toggleClass('hidden');
  });
});








