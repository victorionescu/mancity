<?php
  require "../thrift/LibraryLoad.php";

  use Thrift\Transport\TSocket;
  use Thrift\Protocol\TBinaryProtocol;
  use mancity\DBWorkerClient;

  $transport = new TSocket("localhost", 9090);
  $transport -> open();

  $protocol = new TBinaryProtocol($transport);

  $client = new DBWorkerClient($protocol);

  $match = $client->getMatch($_GET['matchId']);

  $homePlayers = $client->getTeamPlayers($match->homeId);
  $awayPlayers = $client->getTeamPlayers($match->awayId);

  $response_match = array(
    "homePlayers" => $homePlayers,
    "awayPlayers" => $awayPlayers
  );

  echo json_encode($response_match);

  $transport->close();
?>