<?php
//header('Access-Control-Allow-Origin: *');
header('Content-Type: application/json');
//header('Access-Control-Allow-Headers: *');
//header('Access-Control-Allow-Methods: GET, PUT');
//header('Access-Control-Allow-Headers: Content-Type'); 
//header('Access-Control-Allow-Headers: X-API-Key');

define('API_KEY', "Xg9sAxtcD3xFu45AEWg4y3nffVRiq");
define('FILE_NAME', "data.json");

if (!file_exists(FILE_NAME)){
    file_put_contents(FILE_NAME, '[]');
}

$data = json_decode(file_get_contents(FILE_NAME),true);
$requestMethod = $_SERVER['REQUEST_METHOD'];
$apiKey = isset($_SERVER['HTTP_X_API_KEY']) ? $_SERVER['HTTP_X_API_KEY'] : '';


if($apiKey !== API_KEY){
    header('HTTP/1.1 401 Unauthorized');
    echo json_encode(array('error' => 'Unauthorized'));
    exit;
}


switch($requestMethod){
    case 'POST':
        handlePostRequest($data);
        break;
    case 'GET':
        handleGetRequest($data);
        break;
    case 'PUT':
        handlePutRequest($data);
        break;
    case 'DELETE':
        handleDeleteRequest($data);
        break;
    default:
        
        header('HTTP/1.1 400 Bad Request');
        echo json_encode(array('error'=> 'Method not allowed'));
}

function handlePostRequest($data){
    $requestBody = file_get_contents('php://input');
    $requestData = json_decode($requestBody, true);

    handleLogs($requestBody);

    array_push($data, $requestData);
    file_put_contents(FILE_NAME, json_encode($data));
    
    echo json_encode(array('status'=>'success', 'data'=>$data));
}

function handleGetRequest($data){
    handleLogs($data);

    header('Content-Type: application/json');
    echo json_encode($data);
}

function handlePutRequest($data){
    $requestBody = file_get_contents('php://input');
    $requestData = json_decode($requestBody, true);

    handleLogs($requestBody);
    
    foreach($data as &$item){
        if($item['id'] == $requestData['id']){
            $item = $requestData;

            file_put_contents(FILE_NAME, json_encode($data));
            
            echo json_encode(array('status'=>'success', 'data'=>$data));
            exit;
        }
    }
    
    
    header('HTTP/1.1 400 Bad Request');
    echo json_encode(array('error'=> 'ID not found'));
}

// function Handle Delete Request

function handleDeleteRequest($data){
    $requestBody = file_get_contents('php://input');
    $requestData = json_decode($requestBody, true);

    handleLogs($requestBody);

    foreach($data as &$item){
        if($item['id'] == $requestData['id']){
            unset($data[$item['id']-1]);

            file_put_contents(FILE_NAME, json_encode($data));
            
            echo json_encode(array('status'=>'success', 'data'=>$data));
            break;
        }
    }
    
    
    header('HTTP/1.1 400 Bad Request');
    echo json_encode(array('error'=> 'ID not found'));
}

function handleLogs($data){
    $time = date("Y-m-d H:i:s",$_SERVER['REQUEST_TIME_FLOAT']);
    $user_id = $_SERVER['REMOTE_ADDR'];
    $user_name = gethostbyaddr($_SERVER['REMOTE_ADDR']);
    $user_script = $_SERVER['QUERY_STRING'];
    $user_method = $_SERVER['REQUEST_METHOD'];
    $user_use = $_SERVER['SERVER_SOFTWARE'];
    //$test = $_SERVER[''];

    $log = json_encode(array( //'test'=>$test,
        'timestamp'=>$time,
        'user_id'=>$user_id,
        'user_name'=>$user_name,
        'user_method'=>$user_method,
        'user_script'=>$user_script,
        'user_use'=>$user_use,
        'request_data'=>$data
    ));
    file_put_contents('requests.log', $log . "\n",FILE_APPEND);
}