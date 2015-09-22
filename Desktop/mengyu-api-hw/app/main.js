$(function(){
var _tempF, _tempC;

function init(){
	$('#w-temperature a').click(onTempFormatClick);
	$('#l-city').click(onCityClick);
	assembleAutocomplete();
	// $('#l-query').click(onGetWeatherClick);
	//default
	parseInput($('#l-city').val());
}

function assembleAutocomplete(){
	$("#l-city").autocomplete({
    source: function(request, response) {
      $.ajax({
        url: "http://gd.geobytes.com/AutoCompleteCity",
        dataType: "jsonp",
        data: {
          q: request.term
        },
        success: response
      });
    },
    minLength: 3,
    select: function(event, ui) {
      // console.log(ui.item ? "Selected: " + ui.item.label : "Nothing selected, input was " + this.value);
			if(ui.item){
				parseInput(ui.item.label);
			}
    },
    open: function() {
      $(this).removeClass("ui-corner-all").addClass("ui-corner-top");
    },
    close: function() {
      $(this).removeClass("ui-corner-top").addClass("ui-corner-all");
    }
  });
}

function setCurrentWeather(location, weather){
	_tempF = weather['temp_f'];
	_tempC = weather['temp_c'];
	// console.log(location);
	// console.log(weather);
	$('#w-location').text(weather['display_location']['full']);
	$('#w-date').text(weather['observation_time']);
	$('#w-description').text(weather['weather']);
	$('#w-icon').prop('src', weather['icon_url']);
	//current format
	if($('#w-temperature span i').text() == '°F'){
		$('#w-temperature strong').text(_tempF);
	}else if($('#w-temperature span i').text() == '°C'){
		$('#w-temperature strong').text(_tempC);
	}
	$('#w-detail p').eq(0).text('Feel like: ' + weather['feelslike_string']);
	$('#w-detail p').eq(1).text('Humidity: ' + weather['relative_humidity']);
	$('#w-detail p').eq(2).text('Wind: ' + weather['wind_mph'] + ' mph');
}

function loadWeather(state, city, callback){
	//key from http://www.wunderground.com/weather/api/d/e228ab8671fb2e2e/edit.html
	$.ajax({
  url : 'http://api.wunderground.com/api/e228ab8671fb2e2e/geolookup/conditions/q/' + state + '/' + city + '.json',
  dataType : "jsonp",
  success : function(response) {
  	var location = response['location'];
  	var weather = response['current_observation'];
  	callback && callback(location, weather);
  	}
  });
}

function parseInput(str){
	var state, city;
	str = str || '';
	state = str.split(', ')[1];
	city = str.split(', ')[0];
	city = city.replace(' ', '_');
	loadWeather(state, city, setCurrentWeather);
}

function onGetWeatherClick(){
	var state = $('#l-state').val();
	var city = $('#l-city').val() || '';
	city = city.replace(' ', '_');
	// loadWeather(state, city, setCurrentWeather);
}

function onTempFormatClick(){
	var $parent = $(this).parent();
	$parent.empty();
	//
	if($(this).text() == '°F'){
		$parent.append('<i>°F</i>&nbsp;|&nbsp;<a href="javascript:void(0);">°C</a>');
		$('#w-temperature strong').text(_tempF);
	}else if($(this).text() == '°C'){
		$parent.append('<a href="javascript:void(0);">°F</a>&nbsp;|&nbsp;<i>°C</i>');
		$('#w-temperature strong').text(_tempC);
	}
	$('#w-temperature a').click(onTempFormatClick);
}

function onCityClick(){
	$('#l-city').select();
}

init();
});