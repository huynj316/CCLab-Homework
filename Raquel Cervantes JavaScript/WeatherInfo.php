<?php
	/*
		http://developer.yahoo.com/weather/
		http://weather.yahooapis.com/forecastrss?p={$countryCode}&u={$format(c/f)}

		0  	tornado
		1 	tropical storm
		2 	hurricane
		3 	severe thunderstorms
		4 	thunderstorms
		5 	mixed rain and snow
		6 	mixed rain and sleet
		7 	mixed snow and sleet
		8 	freezing drizzle
		9 	drizzle
		10 	freezing rain
		11 	showers
		12 	showers
		13 	snow flurries
		14 	light snow showers
		15 	blowing snow
		16 	snow
		17 	hail
		18 	sleet
		19 	dust
		20 	foggy
		21 	haze
		22 	smoky
		23 	blustery
		24 	windy
		25 	cold
		26 	cloudy
		27 	mostly cloudy (night)
		28 	mostly cloudy (day)
		29 	partly cloudy (night)
		30 	partly cloudy (day)
		31 	clear (night)
		32 	sunny
		33 	fair (night)
		34 	fair (day)
		35 	mixed rain and hail
		36 	hot
		37 	isolated thunderstorms
		38 	scattered thunderstorms
		39 	scattered thunderstorms
		40 	scattered showers
		41 	heavy snow
		42 	scattered snow showers
		43 	heavy snow
		44 	partly cloudy
		45 	thundershowers
		46 	snow showers
		47 	isolated thundershowers
		3200 	not available
	*/

	function weatherInfo($countryId = "SWXX0031", $unit = "c")
	{
		$url = "http://weather.yahooapis.com/forecastrss?p=$countryId&u=$unit"; 
		//echo $url;
		
		$ch = curl_init();  
		$timeout = 5;  
		curl_setopt($ch,CURLOPT_URL,$url);  
		curl_setopt($ch,CURLOPT_RETURNTRANSFER,1);  
		curl_setopt($ch,CURLOPT_CONNECTTIMEOUT,$timeout);  
		$xml = curl_exec($ch);  
		curl_close($ch);  
		
		// Load RSS from yahoo-weather
		$doc = domxml_xmltree($xml);
		
		echo $doc->yweather->node_name();
			
		// Get all elements that have this namespace (the yweather-elements)
		$elements = $doc->get_elements_by_tagname("*");

		// Return array
		$info = array();
		
		// Get all yweather-elements and most of their attributes
		foreach($elements as $element)
		{
			// Condition
			if($element->localName == "condition")
			{
				$info['condition_text'] = $element->getAttribute("text");
				$info['condition_code'] = $element->getAttribute("code");
				$info['condition_temp'] = $element->getAttribute("temp");
			}
			// Location
			if($element->localName == "location")
			{
				$info['location_city'] = $element->getAttribute("city");
				$info['location_country'] = $element->getAttribute("country");
			}
			// Wind
			if($element->localName == "wind")
			{
				$info['wind_chill'] = $element->getAttribute("chill");
				$info['wind_direction'] = $element->getAttribute("direction");
				$info['wind_speed'] = $element->getAttribute("speed");
			}
			// Atmosphere
			if($element->localName == "atmosphere")
			{
				$info['atmosphere_humidity'] = $element->getAttribute("humidity");
				$info['atmosphere_visibility'] = $element->getAttribute("visibility");
				$info['atmosphere_pressure'] = $element->getAttribute("pressure");
				$info['atmosphere_rising'] = $element->getAttribute("rising");
			}
			// Astronomy
			if($element->localName == "astronomy")
			{
				$info['astronomy_sunrise'] = $element->getAttribute("sunrise");
				$info['astronomy_sunset'] = $element->getAttribute("sunset");
			}
			// Check the RSS-feed if you want to extend this
		}

		// Create weather-css-class
		$info['weather_css_class'] = strtolower(str_replace(array(" ", "(", ")"), array("-", "-", ""), $info['condition_text']));

		// Create time css-class
		// Get the lastBuildDate from the feed
		// (updates every 30 mins and is sure to be local time)
		// Fuck, this is gonna need a fix, it doesn't always update that often!
		//$lbds = $doc->get_elements_by_tagname("lastBuildDate");

		// Anyway not to loop this? I know there's only _one_ lastBuildDate-element
		foreach($lbds as $lbd)
		{
			$localTime = $lbd->firstChild->nodeValue;
		}

		// Generate timestamp
		$localTS = strtotime($localTime);

		$info['last_build_date'] = $localTime;
		
		// Get hour (only interested in what hour it is)
		$hour = date("H", $localTS);

		$info['hour_of_day'] = $hour;

		// Night (00:00 -> 05:00)
		if($hour >= 0 and $hour < 6)
		{
			$info['time_css_class'] = "night";
		}
		// Morning (06:00 -> 11:00)
		elseif($hour > 5 and $hour < 12)
		{
			$info['time_css_class'] = "morning";
		}
		// Day (12:00 -> 17:00)
		elseif($hour > 11 and $hour < 18)
		{
			$info['time_css_class'] = "day";
		}
		// Evening (18:00 -> 23:00)
		elseif($hour > 17 and $hour <= 23)
		{
			$info['time_css_class'] = "evening";
		}
		// WTF
		else
		{
			$info['time_css_class'] = "wtf?!";
		}
		// Extend if you want to be more specific

		return $info;
	}
?>