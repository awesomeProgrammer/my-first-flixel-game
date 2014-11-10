package ;

import flixel.FlxSprite;
import flixel.tweens.FlxTween;
import flixel.tweens.FlxEase;


/**
 * ...
 * @author ...
 */
class Coin extends FlxSprite
{

	public function new(X:Float=0, Y:Float=0) 
	{
		super(X, Y);
		
		loadGraphic(AssetPaths.coin__png, false, 8, 8);
	}
	
	/**
	 * override the kill funtions, so don't make the exists false just jet
	 */
	override public function kill():Void
	{
			alive = false;
			// this will make the coin fade out and rising up
			// the time is set to .33 seconds
			FlxTween.tween(this, { alpha:0, y:y - 16 }, .33, { ease:FlxEase.circOut, complete:finishKill } );
	}
	
	/**
	 * stop the coin from being drawn on the screen
	 * @param	_
	 * this tell the FlxTween.complete callback that we don't care about the parameter, that is being passed to it
	 */
	private function finishKill(_):Void
	{
		// object with exists = false, do not get drawn on the screen
		exists = false;
	}
	
}