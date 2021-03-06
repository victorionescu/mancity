/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "mancity_types.h"

#include <algorithm>

namespace mancity {

const char* Team::ascii_fingerprint = "3F5FC93B338687BC7235B1AB103F47B3";
const uint8_t Team::binary_fingerprint[16] = {0x3F,0x5F,0xC9,0x3B,0x33,0x86,0x87,0xBC,0x72,0x35,0xB1,0xAB,0x10,0x3F,0x47,0xB3};

uint32_t Team::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_id = false;
  bool isset_name = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->id);
          isset_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          isset_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_id)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_name)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t Team::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Team");

  xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Team &a, Team &b) {
  using ::std::swap;
  swap(a.id, b.id);
  swap(a.name, b.name);
}

const char* Player::ascii_fingerprint = "E162B1F7953C55D6B978645D745A3B90";
const uint8_t Player::binary_fingerprint[16] = {0xE1,0x62,0xB1,0xF7,0x95,0x3C,0x55,0xD6,0xB9,0x78,0x64,0x5D,0x74,0x5A,0x3B,0x90};

uint32_t Player::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_id = false;
  bool isset_firstName = false;
  bool isset_lastName = false;
  bool isset_shirtNumber = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->id);
          isset_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->firstName);
          isset_firstName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->lastName);
          isset_lastName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->shirtNumber);
          isset_shirtNumber = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_id)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_firstName)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_lastName)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_shirtNumber)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t Player::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Player");

  xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("firstName", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->firstName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("lastName", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->lastName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("shirtNumber", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->shirtNumber);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Player &a, Player &b) {
  using ::std::swap;
  swap(a.id, b.id);
  swap(a.firstName, b.firstName);
  swap(a.lastName, b.lastName);
  swap(a.shirtNumber, b.shirtNumber);
}

const char* Match::ascii_fingerprint = "6435B39C87AB0E30F30BEDEFD7328C0D";
const uint8_t Match::binary_fingerprint[16] = {0x64,0x35,0xB3,0x9C,0x87,0xAB,0x0E,0x30,0xF3,0x0B,0xED,0xEF,0xD7,0x32,0x8C,0x0D};

uint32_t Match::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_id = false;
  bool isset_homeId = false;
  bool isset_awayId = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->id);
          isset_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->homeId);
          isset_homeId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->awayId);
          isset_awayId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_id)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_homeId)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_awayId)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t Match::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Match");

  xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("homeId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->homeId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("awayId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->awayId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Match &a, Match &b) {
  using ::std::swap;
  swap(a.id, b.id);
  swap(a.homeId, b.homeId);
  swap(a.awayId, b.awayId);
}

const char* Event::ascii_fingerprint = "4C2C0E2B6917BEC89A0FAD82FCAA7A84";
const uint8_t Event::binary_fingerprint[16] = {0x4C,0x2C,0x0E,0x2B,0x69,0x17,0xBE,0xC8,0x9A,0x0F,0xAD,0x82,0xFC,0xAA,0x7A,0x84};

uint32_t Event::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_id = false;
  bool isset_eventType = false;
  bool isset_teamId = false;
  bool isset_playerId = false;
  bool isset_outcome = false;
  bool isset_startX = false;
  bool isset_startY = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->id);
          isset_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->eventType);
          isset_eventType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->teamId);
          isset_teamId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->playerId);
          isset_playerId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->outcome);
          isset_outcome = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->startX);
          isset_startX = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->startY);
          isset_startY = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->endX);
          this->__isset.endX = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->endY);
          this->__isset.endY = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->goalY);
          this->__isset.goalY = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->goalZ);
          this->__isset.goalZ = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->cross);
          this->__isset.cross = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_id)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_eventType)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_teamId)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_playerId)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_outcome)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_startX)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_startY)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t Event::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Event");

  xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("eventType", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->eventType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("teamId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->teamId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("playerId", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->playerId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("outcome", ::apache::thrift::protocol::T_I32, 5);
  xfer += oprot->writeI32(this->outcome);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("startX", ::apache::thrift::protocol::T_DOUBLE, 6);
  xfer += oprot->writeDouble(this->startX);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("startY", ::apache::thrift::protocol::T_DOUBLE, 7);
  xfer += oprot->writeDouble(this->startY);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.endX) {
    xfer += oprot->writeFieldBegin("endX", ::apache::thrift::protocol::T_DOUBLE, 8);
    xfer += oprot->writeDouble(this->endX);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.endY) {
    xfer += oprot->writeFieldBegin("endY", ::apache::thrift::protocol::T_DOUBLE, 9);
    xfer += oprot->writeDouble(this->endY);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.goalY) {
    xfer += oprot->writeFieldBegin("goalY", ::apache::thrift::protocol::T_DOUBLE, 10);
    xfer += oprot->writeDouble(this->goalY);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.goalZ) {
    xfer += oprot->writeFieldBegin("goalZ", ::apache::thrift::protocol::T_DOUBLE, 11);
    xfer += oprot->writeDouble(this->goalZ);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.cross) {
    xfer += oprot->writeFieldBegin("cross", ::apache::thrift::protocol::T_I32, 12);
    xfer += oprot->writeI32(this->cross);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Event &a, Event &b) {
  using ::std::swap;
  swap(a.id, b.id);
  swap(a.eventType, b.eventType);
  swap(a.teamId, b.teamId);
  swap(a.playerId, b.playerId);
  swap(a.outcome, b.outcome);
  swap(a.startX, b.startX);
  swap(a.startY, b.startY);
  swap(a.endX, b.endX);
  swap(a.endY, b.endY);
  swap(a.goalY, b.goalY);
  swap(a.goalZ, b.goalZ);
  swap(a.cross, b.cross);
  swap(a.__isset, b.__isset);
}

} // namespace
