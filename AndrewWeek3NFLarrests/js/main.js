$(document).ready(function(){

	$.getJSON('http://nflarrest.com/api/overall/daysSinceArrest.php', function(data){
		var daysSince = data.pop()['daysSinceArrest'],
				percent = parseInt(daysSince) / 64;
		$('#arrest_meter_text').html('It has been <b>'+ daysSince +'</b> Days since the last arrest.</p>');
		
	});
})

