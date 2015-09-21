
$("#downButton").click(function(){
	$("body").animate({scrollTop: 1000}, '500');
	$("Layer_1")

});


$(document).ready(function() {
    var audioElement = document.createElement('audio');
    audioElement.setAttribute('src', 'assets/mumbai.mp3');
    
    // audioElement.addEventListener('ended', function() {
    //     this.play();
    // }, false);
    
    $('#play img').click(function() {
        audioElement.play();
        $("#city").fadeIn(10000);
   
    });
    
    $('#pause').click(function() {
        audioElement.pause();
    });
});


 

 