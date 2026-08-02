<?php
// بيانات الاتصال بقاعدة البيانات - غيّرها ببياناتك من InfinityFree
$host = "localhost";      // اسم السيرفر (Hostname)
$user = "root";                // اسم المستخدم
$pass = "***";           // كلمة المرور
$dbname = "if0_42_control";   // اسم قاعدة البيانات

$conn = new mysqli($host, $user, $pass, $dbname);

if ($conn->connect_error) {
    die(json_encode(["status" => "error", "message" => "فشل الاتصال: " . $conn->connect_error]));
}
?>
