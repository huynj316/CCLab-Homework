window.sr = new scrollReveal();

var heart = $('#heart');
var man = $('#man');
var audioElement = document.createElement('audio');
audioElement.setAttribute('src', 'audio/audio.mp3');

$(heart2).click(function(){
	$(heart2).animate({ 
		width: '120%',
		});
	$(heart).animate({ 
		left : '730px',
		top : '240px',
		});
	$(heart).css({ 
		position : 'fixed',
		});
	$(man).fadeOut(700);
	
	audioElement.play();


});