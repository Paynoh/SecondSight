#include <cstdint>

struct Vec3
{
	public:
	float X,Y,Z;
};


enum class CameraEffect : int32_t
{
    Unk = 0,
    Dizzy = 1,
    Normal = 2,    
    UsingPower = 3,
    Unk2 = 4
};


class Player // Steam build [<secondsight.exe> + 0x61D604]
{
public:

	char pad_0000[8]; //0x0000
	class GameCamera *CameraOBJ; //0x0008
	char pad_000C[312]; //0x000C
    Vec3 PlayerPosition; //0x0144
	char pad_0150[3472]; //0x0150
	float Power; //0x0EE0
	char pad_0EE4[4]; //0x0EE4
	float PowerLimit; //0x0EE8
	float Power2; //0x0EEC
	char pad_0EF0[44]; //0x0EF0
	CameraEffect CurrentEffect; //0x0F1C
	char pad_0F20[300]; //0x0F20

public:
	Vec3 GetPlayerPosition() const
	{
		return {this->PlayerPosition.X, this->PlayerPosition.Y, this->PlayerPosition.Z};
	}

}; //Size: 0x104C
static_assert(sizeof(Player) == 0x104C);

class GameCamera
{
public:
	char pad_0000[128]; //0x0000
    Vec3 CameraPosition; //0x0080
	char pad_008C[4032]; //0x008C

public:
	Vec3 GetCameraPosition() const
	{
		return {this->CameraPosition.X, this->CameraPosition.Y, this->CameraPosition.Z};
	}

}; //Size: 0x104C
static_assert(sizeof(GameCamera) == 0x104C);
