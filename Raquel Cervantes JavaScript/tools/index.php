<?php
	
	/* get xml, find match */
	
	/* get the weather from Yahoo */
	$data = get_data("http://weather.yahooapis.com/forecastrss?p=97211&u=f");
	
	$weather_class = format_result(get_match('/<yweather:condition  text="(.*)"/isU',$data));
		
	/* debug to see what we got back */
	//echo '<pre style="background:#fff;font-size:12px;">['; print_r($weather); echo ']</pre>';
	
	/* format the result */
	function format_result($input)
	{
		return strtolower(str_replace(array(' ', '(', ')'), array('-', '-', ''), $input));
	}
	
	/* helper:  does regex */  
	function get_match($regex,$content)  
	{  
		preg_match($regex,$content,$matches);  
		return $matches[1];  
	}
	
	/* gets the xml data from Alexa */
	function get_data($url)
	{
		$ch = curl_init();
		$timeout = 5;
		curl_setopt($ch,CURLOPT_URL,$url);
		curl_setopt($ch,CURLOPT_RETURNTRANSFER,1);
		curl_setopt($ch,CURLOPT_CONNECTTIMEOUT,$timeout);
		$xml = curl_exec($ch);
		curl_close($ch);
		return $xml;
	}
	
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<title>Weather Switcher</title>
	<link rel="stylesheet" type="text/css" href="style.css" />
</head>

<body>

	<div id="page-wrap">
		
		<div class="header header-<?php echo $weather_class; ?>">
			<!-- Change the second class above to change the header graphic -->
		</div>
		
		<div id="main-content">

			<div id="left-col">
				
				<h1>This website automatically changes it's appearance based on the current weather</h1>
				
				<p>Current condition: <strong><?php echo $weather_class; ?></strong></p>
				
				<p>Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu.</p>

				<p> In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus.</p>

				<p> Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit vel, luctus pulvinar, hendrerit id, lorem. Maecenas nec odio et ante tincidunt tempus. Donec vitae sapien ut libero venenatis faucibus. Nullam quis ante. Etiam sit amet orci eget eros faucibus tincidunt. Duis leo. Sed fringilla mauris sit amet nibh. Donec sodales sagittis magna. Sed consequat, leo eget bibendum sodales, augue velit cursus nunc.</p>
			</div>
			
			<div id="right-col">
				
				<div class="weather-box <?php echo $weather_class; ?>">
				</div>
				
				<img src="images/blogroll.png" alt="Blogroll" />
				<p>
					<a href="http://css-tricks.com">CSS-Tricks</a>
					<a href="http://davidwalsh.name">David Walsh</a>
				</p>
				
			</div>
			
			<div style="clear: both;"></div>
			
		</div>
		
		<img src="images/footer.png" alt="footer" />
	
	</div>
	

</body>

</html>