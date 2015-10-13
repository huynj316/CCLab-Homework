new WOW().init();

$(document).ready(function initialize(){
//Initialize Map & Set Location Variables


var mapCanvas = document.getElementById('map');
var mapOptions = {
	center: new google.maps.LatLng(40.735532, -73.994512),
	zoom: 12,
	mapTypeId: google.maps.MapTypeId.ROADMAP,
	scrollwheel:false
}
var map = new google.maps.Map(mapCanvas, mapOptions);

var image = 'img/angryface.png';
	map.data.setStyle({
    strokeWeight: 1,
    icon: image
  });

//ACTIONS/METHODS
map.data.loadGeoJson('https://data.cityofnewyork.us/resource/fhrw-4uyv.geojson');
//wifi data https://data.cityofnewyork.us/resource/24t3-xqyv.geojson


// google.maps.event.addDomListener(window, 'load', initialize);

//Set mouseover event for each feature.
  map.data.addListener('mouseover', function(event) {
    document.getElementById('addressP').textContent = "Incident Address: " +
        event.feature.getProperty('incident_address');
  });


  map.data.addListener('click', function(event) {
  	document.getElementById('aboutP').innerHTML = "The type of complaint at this location is " + event.feature.getProperty('complaint_type') + "it took place on " + event.feature.getProperty('created_date') + "." + "The description of the complaint is " +
  	event.feature.getProperty('descriptor') + " and the current resolution status is " + event.feature.getProperty('status') + "." + " The description of the resolution is " + event.feature.getProperty('resolution_description') + ".";
  });


});