var marker;
var infowindow;

function initMap() {
  var customMapType = new google.maps.StyledMapType([
      {
        stylers: [
          {hue: '#00a79d'},
          {visibility: 'simplified'},
          {gamma: 0.5},
          {weight: 0.5}
        ]
      },
      {
        elementType: 'labels',
        stylers: [{visibility: 'off'}]
      },
      {
        featureType: 'water',
        stylers: [{color: '#00a79d'}]
      }
    ], {
      name: 'Custom Style'
  });
  var customMapTypeId = 'custom_style';
  var charlieLatLng = {lat: 40.727916, lng: -74.002922};
  var ippudoLatLng = {lat: 40.733540, lng: -73.990049};
  var mermaidLatLng = {lat:40.729119, lng:-74.001792};
  var primiLatLng = {lat:40.725867, lng:-73.991736};
  var eggLatLng = {lat: 40.720661, lng: -73.995285};

  var map = new google.maps.Map(document.getElementById('map'), {
    zoom: 14,
    center: {lat: 40.725242, lng: -73.999056},  
    mapTypeControlOptions: {
      mapTypeIds: [google.maps.MapTypeId.ROADMAP, customMapTypeId]
    }
  });

    var transitLayer = new google.maps.TransitLayer();
  transitLayer.setMap(map);


  var contentString = '<div id="content">'+
      '<div id="siteNotice">'+
      '</div>'+
      '<h3 id="firstHeading" class="firstHeading">Charlie Bird</h3>'+
      '<p><a href="http://charliebirdnyc.com/">'+
      'Website'+'</p>'+
      '</div>'+
      '</div>';

  var infowindow = new google.maps.InfoWindow({
    content: contentString
  });

  var marker = new google.maps.Marker({
    position: charlieLatLng,
    map: map,
    title: 'Chalrie Bird'
  });

  var contentString2 = '<div id="content">'+
      '<div id="siteNotice">'+
      '</div>'+
      '<h3 id="firstHeading" class="firstHeading">Egg Shop</h3>'+
      '</div>'+
      '</div>';

  var infowindow2 = new google.maps.InfoWindow({
    content: contentString2
  });

  var marker2 = new google.maps.Marker({
    position: eggLatLng,
    map: map,
    title: 'Egg Shop'
  });

   var contentString3 = '<div id="content">'+
      '<div id="siteNotice">'+
      '</div>'+
      '<h3 id="firstHeading" class="firstHeading">Ippudo</h3>'+
      '</div>'+
      '</div>';

  var infowindow3 = new google.maps.InfoWindow({
    content: contentString3
  });

  var marker3 = new google.maps.Marker({
    position: ippudoLatLng,
    map: map,
    title: 'Ippudo'
  });

  var contentString4 = '<div id="content">'+
      '<div id="siteNotice">'+
      '</div>'+
      '<h3 id="firstHeading" class="firstHeading">Mermaid Oyster Bar</h3>'+
      '</div>'+
      '</div>';

  var infowindow4 = new google.maps.InfoWindow({
    content: contentString4
  });

  var marker4 = new google.maps.Marker({
    position: mermaidLatLng,
    map: map,
    title: 'Mermaid'
  });

   var contentString5 = '<div id="content">'+
      '<div id="siteNotice">'+
      '</div>'+
      '<h3 id="firstHeading" class="firstHeading">Bar Primi</h3>'+
      '</div>'+
      '</div>';

  var infowindow5 = new google.maps.InfoWindow({
    content: contentString5
  });

  var marker5 = new google.maps.Marker({
    position: primiLatLng,
    map: map,
    title: 'Bar Primi'
  });

  //actions
  map.mapTypes.set(customMapTypeId, customMapType);
  map.setMapTypeId(customMapTypeId);

 marker.addListener('click', function() {
    infowindow.open(map, marker);
  });

 marker2.addListener('click', function() {
    infowindow2.open(map, marker2);
  });

  marker3.addListener('click', function() {
    infowindow3.open(map, marker3);
  });

  marker4.addListener('click', function() {
    infowindow4.open(map, marker4);
  });

  marker5.addListener('click', function() {
    infowindow5.open(map, marker5);
  });
}

// function initMap() {

//   var myLatLng = {lat: 40.725242, lng: -73.999056};

//   var map = new google.maps.Map(document.getElementById('map'), {
//     zoom: 14,
//     center: myLatLng
//   });

//   var transitLayer = new google.maps.TransitLayer();
//   transitLayer.setMap(map);



// var food = [
//   ['Mermaid Oyster Bar', 40.729119, -74.001792, 3],
//   ['Ippudo', 40.733540, -73.990049, 2],
//   ['Bar Primi', 40.725867, -73.991736, 1],
//   ['Num Pang', 40.734194, -73.993103, 4],
//   ['Shanghai Cafe Deluxe', 40.717487, -73.997207, 5],
//   ['Mighty Quinns Barbeque', 40.727790, -73.988670, 3],
//   ['Rissoteria', 40.731501, -74.003267, 2],
//   ['Joes Pizza', 40.730722, -74.002130, 1],
// ];

// for (var i = 0; i < food.length; i++) {
//     var food = beaches[i];
//     var marker = new google.maps.Marker({
//       position: {lat: food[1], lng: food[2]},
//       map: map,
//       title: food[0],
//       zIndex: food[7],
//     });
//   }
// }

