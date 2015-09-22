//geolocation: https://www.youtube.com/watch?v=keO6egndYrE
//geocode: https://developers.google.com/maps/documentation/geocoding/intro?csw=1

    function initGeolocation()
    {
    	if( navigator.geolocation )
    	{
              // Call getCurrentPosition with success and failure callbacks
              navigator.geolocation.getCurrentPosition( success, fail );
          }
          else
          {
          	alert("Sorry, your browser does not support geolocation services.");
          }
      }


      function initMap() {
	// Define the coordinates as a Google Maps LatLng Object
	// var coords = new google.maps.LatLng(position.coords.latitude, position.coords.longitude);
	var map = new google.maps.Map(document.getElementById('map'), {
		zoom: 5,
		// center:coords
		center: {lat: 40.730610, lng: -73.935242}
	});
	var geocoder = new google.maps.Geocoder();


	document.getElementById('submit').addEventListener('click', function() {
		geocodeAddress(geocoder, map);
	});
}

function geocodeAddress(geocoder, resultsMap) {
	var address = document.getElementById('address').value;
	geocoder.geocode({'address': address}, function(results, status) {
		if (status === google.maps.GeocoderStatus.OK) {
			resultsMap.setCenter(results[0].geometry.location);
			var marker = new google.maps.Marker({
				map: resultsMap,
				position: results[0].geometry.location
			});
		} else {
			alert('Geocode was not successful for the following reason: ' + status);
		}
	});
}
