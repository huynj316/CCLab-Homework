$(document).ready(function() {

  $.YQL = function(query, callback) {
    var encodedQuery = encodeURIComponent(query.toLowerCase()),
        url = "http://query.yahooapis.com/v1/public/yql?" +
              "q=" + encodedQuery + "&format=json&callback=?";
    $.getJSON(url, callback);
  };
  
  var status = function (message) {
    $("#status").text(message);
  };
  
  var fetchWeatherForLatLon = function (lat, lon) {
    status("Finding woeid for (" +lat + ", " + lon + ")");
    $.YQL(
        "select place.woeid from flickr.places where " +
        "lat=" + lat + " and lon=" + lon,
      function (data) {
        fetchWeatherForWoeid(data.query.results.places.place.woeid);
      }
    );
  };
  
  var fetchWeatherForWoeid = function (w) {
    status("Fetching weather for woeid " + w);
    $.YQL(
      "select * from rss where " +
      "url='http://weather.yahooapis.com/forecastrss?p=UKXX0133",
      function (data) {
        displayWeatherForecast(data.query.results.item);
      }
    );
  };
  
  var displayWeatherForecast = function (weather) {
    status("Here is the weather!");
    var encodedclass = weather.condition.text.replace(/\s+/g, '-').toLowerCase();
    
    $('body').addClass(encodedclass);
    $('#weatherTemp').html(weather.condition.temp + "&deg;");
    $('#weatherText').html(weather.condition.text + "");
    $('#geolat').html(weather.title + "");
  };
  
  // Fetch the weather
  fetchWeatherForLatLon(34.45, -118.54);

});