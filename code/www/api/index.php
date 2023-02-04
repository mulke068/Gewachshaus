<?php

ini_set('display_errors','1');
echo "<h3>Rest Api : PHP CLIENT</h3>";
echo "<hr>";
 
$url = "http://localhost/data.php";

$data = file_get_contents($url);

echo"$data";

$obj = json_decode($data,true);

$temperature=$obj['1']['temp'];
$humidity=$obj['1']['hum'];
$pressure=$obj['1']['pres'];
$test1=$obj['2']['aa'];
$test3=$obj['2']['cc'];

echo"Information Extracted:-<br><br>";

echo "<code>
		Timeline : <b>".$obj[0]['time_stamp']."</b><br>
		REQ-IP   : <b>".$obj[0]['req_ip']."</b><br>
	</code>";

echo"Temperature : <b>$temperature</b><br>
	 Humidity    : <b>$humidity</b><br>
	 Pressure    : <b>$pressure</b><br>";

echo"<hr>";


?>