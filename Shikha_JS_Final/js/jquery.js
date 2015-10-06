	
	function pause(){
	$("#play img").fadeOut();
	$("#mute img").fadeIn();

	 document.getElementById('sound').pause();
	

};


	function play(){
	$("#mute img").fadeOut();
	$("#play img").fadeIn();

	 document.getElementById('sound').play();

};

$("#play").click(pause);

$("#mute").click(play);