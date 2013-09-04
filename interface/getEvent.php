<?php
  require "../thrift/LibraryLoad.php";

  use Thrift\Transport\TSocket;
  use Thrift\Protocol\TBinaryProtocol;
  use mancity\DBWorkerClient;

  $transport = new TSocket("localhost", 9090);
  $transport -> open();

  $protocol = new TBinaryProtocol($transport);

  $client = new DBWorkerClient($protocol);

  $event = $client->getEvent($_GET["matchId"], $_GET["eventId"]);
  $event->shirtNumber = $client->getPlayer($event->teamId, $event->playerId)->shirtNumber;

  echo json_encode($event);

  $transport->close();
?>