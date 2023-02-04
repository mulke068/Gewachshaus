<?php

$arr['1']['temp'] = random_int(0, 100); //a random value
$arr['1']['hum'] = random_int(101, 200); //a random value
$arr['1']['pres'] = random_int(201, 300); //a random value

$arr['2']['aa'] = random_int(301, 400); //a random value
$arr['2']['bb'] = random_int(401, 500); //a random value
$arr['2']['cc'] = random_int(501, 600); //a random value


$t = time();
$date_time = date('H:i:s', $t);
$ip = $_SERVER["REMOTE_ADDR"];

$arr[0]['time_stamp'] = $date_time;
$arr[0]['req_ip'] = $ip;

$json = json_encode($arr);

echo "$json";
$str = "Time:$date_time\n\nClient IP:$ip\n\n data:$json";
file_put_contents('res.txt', $str);

?>