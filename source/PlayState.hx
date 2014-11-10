package;

import flixel.addons.editors.ogmo.FlxOgmoLoader;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.group.FlxTypedGroup;
import flixel.text.FlxText;
import flixel.tile.FlxTilemap;
import flixel.ui.FlxButton;
import flixel.util.FlxAngle;
import flixel.util.FlxDestroyUtil;
import flixel.util.FlxMath;
import flixel.util.FlxPoint;
import flixel.FlxCamera;

/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{
	// this is a object of the type 'Player' class ...........................
	private var _Player:Player;
	private var _map:FlxOgmoLoader; // map handler
	private var _mWalls:FlxTilemap; // map, for the map handler
	private var _grpCoins:FlxTypedGroup<Coin>; // make a group/array, over all the coins // of type 'Coins' class
	private var _grpEnemies:FlxTypedGroup<Enemy>; // make a group/array, over all the enemyies // of type 'enemy' class

	
	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		// map
		_map = new FlxOgmoLoader("assets/data/room-001.oel"); // set the level to the map handler
		_mWalls = _map.loadTilemap("assets/images/tiles.png", 16, 16, "walls"); // set the art assetss
		_mWalls.setTileProperties(1, FlxObject.NONE); // set the tile of the floor // don't care about any collison
		_mWalls.setTileProperties(2, FlxObject.ANY); // set the tile of the walls // stop collision from all ways
		add(_mWalls); // add the walls/floors to the game
		
		// coins
		_grpCoins = new FlxTypedGroup<Coin>(); // create the value for the game
		add(_grpCoins); // add the object in to the game
		
		// enemyies
		_grpEnemies = new FlxTypedGroup<Enemy>(); // make the object ready for use
		add(_grpEnemies); // add them into the game
		
		
		// player and map
		// first makes the object
		_Player = new Player();
		// set the place of the player, on the map // by calling the "placeEntities" funtion
		_map.loadEntities(placeEntities, "entities");
		// now add it to the game
		add(_Player);
		
		// camera
		// make the camera follow the player object
		FlxG.camera.follow(_Player, FlxCamera.STYLE_TOPDOWN, 1);
		
		super.create();
	}
	
	
	/**
	 * an event handler for when the player touch a coin
	 * @param	P
	 * the player object
	 * @param	C
	 * the coin object
	 */
	private function playerTouchCoin(P:Player, C:Coin):Void
	{
		if (P.alive && P.exists && C.alive && C.exists)
		{
			C.kill();
		}
	}
	
	/**
	 * placeing the entity there where you are telling them to be
	 * @param	entityName
	 * the name of the entity
	 * @param	entityData
	 * the data of the entity (x and y)
	 */
	private function placeEntities(entityName:String, entityData:Xml):Void
	{
		var x = Std.parseInt(entityData.get("x"));
		var y = Std.parseInt(entityData.get("y"));
		
		if (entityName == "player")
		{
			_Player.x = x;
			_Player.y = y;
		}
		
		else if (entityName == "coin")
		{
			// this will add the coin to the array/group
			// it will also make the art be centered
				//every tile is 16x16 and the coin is 8x8
				// so 8 + 4 = 12 x 8 + 4 = 12
				// now the coin have a margin of 3 all around
			_grpCoins.add(new Coin(x + 4, y + 4));
		}
		
		else if (entityName == "enemy")
		{
			// gets call before we create the game
			// adds all the enemyies to the group/array
			//_grpEnemies.add(new Enemy(x + 4, y, Std.parseInt(entityData.get("etype"))));
		}
		
	}
	
	/**
	 * Function that is called when this state is destroyed - you might want to 
	 * consider setting all objects this state uses to null to help garbage collection.
	 */
	override public function destroy():Void
	{
		super.destroy();
	}

	/**
	 * Function that is called once every frame.
	 */
	override public function update():Void
	{
		super.update();
		
		// check every frame if the player hits the walls
		FlxG.collide(_Player, _mWalls);
		// check evert frame if the player hited a coin
		// if it did, call the coin event handler
		FlxG.overlap(_Player, _grpCoins, playerTouchCoin);
	}	
}