<?php
  require "thrift/LibraryLoad.php";

  use Thrift\Transport\TSocket;
  use Thrift\Protocol\TBinaryProtocol;
  use mancity\DBWorkerClient;

  if (!isset($_GET['team_id'])) {
    die("Please provide team_id.");
  }

  $transport = new TSocket("localhost", 9090);
  $transport -> open();

  $protocol = new TBinaryProtocol($transport);

  $client = new DBWorkerClient($protocol);

  $response = $client->teamPlayers($_GET['team_id']);

  echo json_encode($response);

  $transport->close();
?>