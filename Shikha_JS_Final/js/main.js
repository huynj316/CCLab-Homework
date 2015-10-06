
// $("#text").click(function(){
// 	$("body").animate({scrollTop: 3000}, '500');
// 	$("impress");

// });





var init = function(){
	var button = document.getElementById('saveButton');
	saveButton.addEventListener('click', function(e){
		e.preventDefault();
		getStory();
	});
};

function getStory() {
    var storyText = document.getElementById('storyText').value;
    var generate = document.getElementById('generate');

    if (storyText.length < 1) {
        generate.textContent = 'You must complete the story to spook your friends out.';
        //alert('Username must contain at least 3 characters');
    } else {
    
        generate.textContent = 'I can\t move, breathe, speak or hear and it\s so dark all the time.' + "\n" + storyText;
    }
        
};
// use an eventlistener for the event

window.onload = init();

