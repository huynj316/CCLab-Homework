/*
GIPHY API: http://api.giphy.com/v1/gifs/search?q=
Public Beta Key: dc6zaTOxFJmzC

sample: http://api.giphy.com/v1/gifs/search?q=funny+cat&api_key=dc6zaTOxFJmzC 
*/

var app = app || {};
app.main = (function() {
	var attachEvents = function() {
		// console.log("attaching event listeners.");

		$('#search-button').off('click').on('click', function(){
			loadData($('#search-box').val());
		});

		$('#search-box').keypress(function(e) {
			if (e.keyCode == 13) {
				loadData($('#search-box').val());
			}
		});		
	};
	
		// loadData(type);
		
		var loadData = function(subject) {
			console.log('Searching for ' + subject + '...');
			var searchURL = 'http://api.giphy.com/v1/gifs/search?q=' + subject + '&api_key=dc6zaTOxFJmzC';
			$.getJSON(searchURL, function(json){
				console.log('Data received.');
				console.log(json);
				var results = json.data;
				console.log('Found ' + results.length + ' results.');
				appendData(results);
			});
		};

		var appendData = function(data){
			console.log('Appending Data');
			console.log(data);
			$('#view').empty();
			for(var i = 0; i < data.length; i++){
				$('#view').append('<img src="' + data[i].images.fixed_height.url + '" />');
			}
		}


		var init = function(){
			console.log('Initializing app.');
			attachEvents();
		};
		return {
			init: init
		};
	})();

	window.addEventListener('DOMContentLoaded', app.main.init);

//fancy Input

 // $('div :input').fancyInput();
