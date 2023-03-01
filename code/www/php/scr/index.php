<?php

//require 'get.php';

ini_set('display_errors', '1');

$options = array(
    'http'=>array(
        'method'=>"GET",
        //'header'=>"X-API-Key: Xg9sAxtcD3xFu45AEWg4y3nffVRiq"
    )
);

$context=stream_context_create($options);
$data = file_get_contents('http://192.168.178.38/api',false,$context);

//echo $data;
//echo "<hr>";

$obj = json_decode($data,true);

$root_0 = $obj['0'];
$root_1 = $obj['1'];

$root_0_devices_esp32_1 = $obj['0']["devices"]["esp32"]['0']["connected"];
$root_0_devices_esp32_2 = $obj['0']["devices"]["esp32"]['1']["connected"];
$root_0_devices_raspberrypi = $obj['0']["devices"]["raspberrypi"]["connected"];

$root_1_tempHum_temperature_1 = $root_1["tempHum"]["temperature_1"];
$root_1_tempHum_humidity_1 = $root_1["tempHum"]["humidity_1"];
$root_1_tempHum_temperature_2 = $root_1["tempHum"]["temperature_2"];
$root_1_tempHum_humidity_2 = $root_1["tempHum"]["humidity_2"];

$root_1_waterSystem_sensor_1 = $root_1["waterSystem"]["sensor_1"];
$root_1_waterSystem_sensor_2 = $root_1["waterSystem"]["sensor_2"];
$root_1_waterSystem_pumpe = $root_1["waterSystem"]["pumpe"];

$root_1_lufterLeds_getLufter_1 = $root_1["lufterLeds"]["getLufter_1"];
$root_1_lufterLeds_setLufter_1 = $root_1["lufterLeds"]["setLufter_1"];
$root_1_lufterLeds_getLufter_2 = $root_1["lufterLeds"]["getLufter_2"];
$root_1_lufterLeds_setLufter_2 = $root_1["lufterLeds"]["setLufter_2"];
$root_1_lufterLeds_getLed = $root_1["lufterLeds"]["getLed"];
$root_1_lufterLeds_setLed = $root_1["lufterLeds"]["setLed"];

$root_1_energieStatus_solar_1 = $root_1["energieStatus"]["solar_1"]; 
$root_1_energieStatus_solar_2 = $root_1["energieStatus"]["solar_2"];  
$root_1_energieStatus_akku = $root_1["energieStatus"]["akku"]; 
$root_1_energieStatus_strom = $root_1["energieStatus"]["strom"]; 

$root_1_settings_brightness = $root_1["settings"]["brightness"];
$root_1_settings_sound = $root_1["settings"]["sound"];

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="icon" content="">
    <title>Home</title>
    <script src="https://cdn.tailwindcss.com"></script>
</head>
<body class="bg-black text-white">
    <div>
        <div class="text-3xl">Fetch Data</div>
        <div class="container mx-auto px-4">
            <div>
                <div class="text-xl">ESP32 1</div>
                <div><?php echo $root_0_devices_esp32_1!=true ? 'Disconnected':'Connected'; ?></div>
            </div>
            <div>
                <div class="text-xl">ESP32 2</div>
                <div><?php echo $root_0_devices_esp32_2!=true ? 'Disconnected':'Connected'?></div>
            </div>
            <div>
                <div class="text-xl">RasberryPI</div>
                <div><?php echo $root_0_devices_raspberrypi!=true ? 'Disconnected':'Connected'?></div>
            </div>
        </div>
    </div>
    

</body>
</html>