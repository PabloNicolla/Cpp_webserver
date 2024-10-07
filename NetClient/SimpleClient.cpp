#include <iostream>
#include <olc_net.h>

enum class CustomMessageTypes : uint32_t
{
  FireBullet,
  MovePlayer
};

int main()
{
  olc::net::message<CustomMessageTypes> msg;
  msg.header.id = CustomMessageTypes::FireBullet;

  int a = 1;
  bool b = true;
  float c = 3.14f;

  struct
  {
    float x;
    float y;
  } d[5];

  msg << a << b << c << d;

  a = 99;
  b = false;
  c == 99.0f;

  msg >> d >> c >> b >> a;

  return 0;
}