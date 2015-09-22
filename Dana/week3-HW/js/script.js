var info_landmarks = [
['Brooklyn Museum', 40.674371, -73.953568, 1],
['BAM', 40.671422, -73.963615, 2],
['Lazy Ibis', 40.675858, -73.955937, 3],
['CatFish', 40.673999, -73.952386]
];

$(document).ready(function initialize(){


var customMapType = new google.maps.StyledMapType([
		{
			stylers: [
			{hue: '#31A3A1'},
			{visibility: 'simplified'},
			{gamma: 0.5},
			{weight: 1.0}
			]
		}, 
		{elementType: 'labels',
		stylers: [{visibility: 'off'}]
		}, 
		{
			featureType: 'water',
			stylers: [{color: '#000000'}]

		}
		], {
			name: 'Custom Style'
	}
	);
	var customMapTypeId = 'custom_style';
	var myLatLng = {lat: 40.6631, lng: -73.9447};
	var map = new google.maps.Map(document.getElementById('map'), {
		zoom: 12,
		center: myLatLng,
		mapTypeControlOptions: {
			mapTypeIds: [google.maps.MapTypeId.ROADMAP, customMapTypeId]
		}
	});
	
var marker, iterate;
	for (iterate = 0; iterate < info_landmarks.length; iterate++) {
		marker = new google.maps.Marker({
			position: new google.maps.LatLng(info_landmarks[iterate][1], info_landmarks[iterate][2]),
			map: map,
			animation: google.maps.Animation.DROP,
			title: info_landmarks[iterate][0]
		});
	}


// = new google.maps.Marker({
// 		position: myLatLng,
// 		map: map,
// 		animation: google.maps.Animation.DROP,
// 		title: 'My first marker!'
// 	});



 $('button').click(function(){
        $('#map').toggle();
    });

//actions
	map.mapTypes.set(customMapTypeId, customMapType);
	map.setMapTypeId(customMapTypeId);

	map.addListener('center_changed', function(){
		window.setTimeout(function() {
			map.panTo(marker.getPosition());
		}, 3000);
	});

	marker.addListener('click', function(){
		map.setZoom(12);
		map.setCenter(marker.getPosition());

	});

});