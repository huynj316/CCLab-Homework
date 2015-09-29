var marker;
var infowindow;
var map = $('#map');
var button6 = $('#button6');
var wish = $('#wish');
var list = $('#list');
var button5 = $('#button5');
var insta = $('#insta');
var button2 = $('#button2');
var chart = $('#chart');

 // Load the Visualization API and the piechart package.
      google.load('visualization', '1.0', {'packages':['corechart']});

      // Set a callback to run when the Google Visualization API is loaded.
      google.setOnLoadCallback(drawChart);

      // Callback that creates and populates a data table,
      // instantiates the pie chart, passes in the data and
      // draws it.
      function drawChart() {

        // Create the data table.
        var data = new google.visualization.DataTable();
        data.addColumn('string', 'Cuisine');
        data.addColumn('number', 'Slices');
        data.addRows([
          ['Japanese', 1],
          ['Italian', 1],
          ['American', 1],
          ['Mediterranean', 1],
          ['French', 1],
        ]);

        // Set chart options
        var options = {
          'title':'NUMBER OF RESTAURANTS BY CUISINE',
          'width':1200,
          'height':600,
          'backgroundColor': '#00a79d',
          'colors':['coral','aquamarine','#FBB040','#00EDFF','#D0E669'],
          'fontName':'Gotham',
          'titleTextStyle': {color: 'white', fontSize: 25},
          'legend':{textStyle: {color: 'white', fontSize: 16}},
          'pieSliceText':'none',
        };

        // Instantiate and draw our chart, passing in some options.
        var chart = new google.visualization.PieChart(document.getElementById('chart'));
        chart.draw(data, options);
      }

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
      '<h3 id="firstHeading" class="firstHeading">Charlie Bird</h3>'+'<p>'+'Delicious Italian influenced,'
      +' American executed and entirely New York cuisine.'+'There space is local, spreading from the inside out;'
      +' they are organic in approach and delivery.'+'The Bird is the word!'+'Check out the '+
      '<a href="http://charliebirdnyc.com/">'+
      'Website'+'</a>'+'</p>'+
      '<img src="image/tweet.png" style="width:50%">'+
      '</div>'+
      '</div>';

  var infowindow = new google.maps.InfoWindow({
    content: contentString
  });

  var marker = new google.maps.Marker({
    position: charlieLatLng,
    map: map,
    // icon: image,
    // shape: shape,
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

$(document).ready(function(){
    $(button6).click(function(){
        $(map).toggle('slow');
        $(wish).toggle(700);
        $(list).toggle(1000);
    });
});

$(document).ready(function(){
    $(button5).click(function(){
        $(map).toggle('slow');
        $(insta).toggle(700);
    });
});

$(document).ready(function(){
    $(button2).click(function(){
        $(map).toggle('slow');
        $(chart).toggle(700);
    });
});