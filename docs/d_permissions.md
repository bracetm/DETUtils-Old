# d_permissions.inc

SA:MP Permissions - Control your players with new permissions, now with *d_permissions.inc* you can control who can send a message, use a command or even move!

[Go back to the home page](../README.md)

## How to start to use?

- All of the player permissions are off by default. To give the player certain permissions to do certain things, you need to use `SetPlayerPermissionInteger`.

- There are 3 permissions available for now, they are:

```pawn
#define PLAYER_PERMISSION_SENDMESSAGES 0x1
#define PLAYER_PERMISSION_USECOMMANDS 0x2
#define PLAYER_PERMISSION_USEDIALOGS 0x4
```

- There is also a definition for the default player permissions. It is:

```pawn
#define DEFAULT_PLAYER_PERMISSIONS \
 (PLAYER_PERMISSION_SENDMESSAGES | PLAYER_PERMISSION_USECOMMANDS | PLAYER_PERMISSION_USEDIALOGS)
 
```

- You can change player's permission anytime using the following function!

```pawn
SetPlayerPermissionInteger(playerid, PLAYER_PERMISSION_SENDMESSAGES | PLAYER_PERMISSION_USECOMMANDS);
```

**NOTE:** Make sure to use bitwise operators instead of `+`.

- If the player attempts to do something, without a certain permission to do so, you can let him know using the callback below.

```pawn
public OnPlayerInsufficientPermissions(playerid, missingpermission)
{
	if(missingpermission == PLAYER_PERMISSION_USECOMMANDS)
	{
		SendClientMessage(playerid, 0xFFFFFFFF, "You aren't allowed to use commands!");
	}
	if(missingpermission == PLAYER_PERMISSION_SENDMESSAGES)
	{
		SendClientMessage(playerid, 0xFFFFFFFF, "You aren't allowed to send messages!");
	}
	if(missingpermission == PLAYER_PERMISSION_USEDIALOGS)
	{
		SendClientMessage(playerid, 0xFFFFFFFF, "You aren't allowed to respond to dialogs!");
	}
	return 1;
}
```

- To let the staff know when player permissions change, you can use the following callback:

```pawn
public OnPlayerPermissionIntegerChange(playerid, oldpermissions, newpermissions)
{
	printf("Player : %i, oldperms : %i, newperms : %i", 
		playerid,
		oldpermissions,
		newpermissions);
	return 1;
}
```