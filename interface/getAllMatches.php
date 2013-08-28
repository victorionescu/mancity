<?php
  require "../thrift/LibraryLoad.php";

  use Thrift\Transport\TSocket;
  use Thrift\Protocol\TBinaryProtocol;
  use mancity\DBWorkerClient;

  $transport = new TSocket("localhost", 9090);
  $transport -> open();

  $protocol = new TBinaryProtocol($transport);

  $client = new DBWorkerClient($protocol);

  $matches = $client->getAllMatches();

  $response_matches = array();

  for ($i = 0; $i < count($matches); $i++) {
    $match = array(
      "id" => $matches[$i]->id,
      "homeName" => $client->getTeamName($matches[$i]->homeId),
      "awayName" => $client->getTeamName($matches[$i]->awayId)
    );

    array_push($response_matches, $match);
  }

  echo json_encode($response_matches);

  $transport->close();
?>