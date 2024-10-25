<?php

$server = "localhost:3306";    // Change this to correspond with your database port
$username = "root";            // Change if use webhost online
$password = "";
$DB = "robot";                 // Database name

$conn = new mysqli($server, $username, $password, $DB);    // Check database connection
if ($conn->connect_error) 
{
    die("Connection failed: " . $conn->connect_error);
}
// NHẬN DATA TỪ ESP32 VÀ GỬI LÊN CSDL
// Check if 'neck' and 'head' parameters are set in the GET request
if(isset($_GET['neck']) && isset($_GET['head'])) {
    $neck = $_GET['neck'];
    $head = $_GET['head'];

    // Update the data in the database
    $updateQuery = "UPDATE head_neck SET neck=?, head=?";
    $stmt = $conn->prepare($updateQuery);
    $stmt->bind_param("ss", $neck, $head); // 'ss' indicates that both parameters are strings
    if ($stmt->execute()) {
        echo "Data updated successfully. ";
    } else {
        echo "Error updating data: " . $stmt->error;
    }
    $stmt->close();
}

// GỬI DATA VỀ ESP32
// Select data from the table "head_neck"
$query = "SELECT neck, head FROM head_neck";
$result = $conn->query($query);

while($row = $result->fetch_assoc()) 
{
    echo "neck:" . $row["neck"] . "head:" . $row["head"];    // Echo data , equivalent to sending data to esp
}

$conn->close();

?>
