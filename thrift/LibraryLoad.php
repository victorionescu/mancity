<?php
  require_once 'phplib/type/TType.php';
  require_once 'phplib/type/TMessageType.php';
  
  require_once 'phplib/stringfunc/TStringFunc.php';
  require_once 'phplib/stringfunc/Core.php';
  
  require_once 'phplib/factory/TStringFuncFactory.php';
  
  require_once 'phplib/exception/TException.php';
  
  require_once 'phplib/Thrift.php';
  
  require_once 'phplib/transport/TTransport.php';
  require_once 'phplib/transport/TSocket.php'; 
  require_once 'phplib/transport/TFramedTransport.php';
  require_once 'phplib/transport/TBufferedTransport.php';

  require_once 'phplib/protocol/TBinaryProtocol.php';

  require_once 'gen-php/mancity/Types.php';
  require_once 'gen-php/mancity/DBWorker.php';
?>