﻿package {	import flash.display.MovieClip;	import flash.display.Loader;	import flash.display.DisplayObject;	import flash.display.Bitmap;	import flash.display.BitmapData;	import flash.geom.ColorTransform;	import flash.geom.Matrix;	import flash.geom.Point;	import flash.net.URLRequest;	import flash.external.ExternalInterface;	import flash.events.Event;	import flash.events.MouseEvent;	import flash.geom.Rectangle;	import flash.events.TimerEvent;	import flash.utils.Timer;	import flash.media.Sound;		public class Flag extends MovieClip {		// BEGIN FLAG PARAMETERS		// unique curlypage identifier		private var cpid:uint;				// peel position on page. Values: topleft || topright || bottomleft || bottomright		private var peelPosition:String;		// flag width and height. Suggested values 10-200		private var flagWidth:uint;		private var flagHeight:uint;		// mirror the image on peel. Values: true || false		private var mirror:Boolean;		// color of peel. Values: golden || silver || custom		private var peelColor:String;		// color of peel style. Values: flat || gradient		private var peelColorStyle:String = "gradient";		// red value of custom color. Values 0-255		private var redValue:uint;		// green value of custom color. Values 0-255		private var greenValue:uint;		// blue value of custom color. Values 0-255		private var blueValue:uint;        // load sound		private var loadSound:Sound;		// open on click. Values 0/1		private var open_onclick:uint;		// speed of flag movement. Values: 1-9		private var flagSpeed:uint;		// END FLAG PARAMETERS		// size of design flag		private const FLAGDESIGNSIZE:uint = 100;		private var imageLoader:Loader;		private var toScaleX:Number;		private var toScaleY:Number;				private var mirrorImageBitmap:Bitmap = new Bitmap();		private var updateMirrorImageTimer:Timer;		private const childNames = new Array("image_mask", "inner_shadow", "peel", "top_shadow", "mirror_image", "button");		// this flag controls the movement direction. False -> forward. True -> backward		private var moveBackwards:Boolean = false;		// tracking current frame of childs		private var flagCurrentFrame:uint;		private const FRAMESCOUNT:uint = 50;		/*		 * Constructor		 */		public function Flag(cpid:uint,							 peelPosition:String,							 mirror:Boolean,							 peelColor:String,							 peelColorStyle:String,							 redValue:uint,							 greenValue:uint,							 blueValue:uint,							 loadSound:Sound,							 open_onclick:uint,							 flagSpeed:uint,							 imageLoader:Loader,							 flagWidth:uint,							 flagHeight:uint							 )		{			this.cpid = cpid;			this.peelPosition = peelPosition;			this.mirror = mirror;			this.peelColor = peelColor;			this.peelColorStyle = peelColorStyle;			this.redValue = redValue;			this.greenValue = greenValue;			this.blueValue = blueValue;			this.loadSound = loadSound;			this.open_onclick = open_onclick;			this.flagSpeed = flagSpeed;						this.imageLoader = imageLoader;			this.flagWidth = flagWidth;			this.flagHeight = flagHeight;			this.toScaleX = flagWidth/FLAGDESIGNSIZE;			this.toScaleY = flagHeight/FLAGDESIGNSIZE;						if (loadSound != null) {				loadSound.play();			}						scaleMovie();						//set peel color			if (peelColor == "golden") {				setPeelColor(50, 100, 10);			} else if (peelColor == "silver") {				if (peelColorStyle == "flat") {					setPeelColor(192, 192, 192);				}			} else {				setPeelColor(redValue, greenValue, blueValue);			}			// add small image to its container			setImage();			// add mirror image to peel if configured to do so			if (mirror) {				setMirrorImage();			}            addEventToFlag();			this.flagCurrentFrame = 1;			this.addEventListener(Event.ENTER_FRAME, do_move);					}		/**		 * Add mouse event to flag		 */		private function addEventToFlag() {            if (this.open_onclick) {				// add click event to peel				MovieClip(getChildByName("button")).peelSmallButton.addEventListener(MouseEvent.CLICK, smallButtonAction);			} else {				// add mouse over event to peel				MovieClip(getChildByName("button")).peelSmallButton.addEventListener(MouseEvent.MOUSE_OVER, smallButtonAction);			}		}		/**		 * Remove mouse event from button		 */		private function removeEventFromFlag() {            if (this.open_onclick) {				// add click event to peel				MovieClip(getChildByName("button")).peelSmallButton.removeEventListener(MouseEvent.CLICK, smallButtonAction);			} else {				// add mouse over event to peel				MovieClip(getChildByName("button")).peelSmallButton.removeEventListener(MouseEvent.MOUSE_OVER, smallButtonAction);			}		}		/*		 * Sets color of peel.		 */		private function setPeelColor (redValue, greenValue, blueValue: uint) : void {			var peelTransform:ColorTransform;			if (this.peelColorStyle == "flat") {				peelTransform = new ColorTransform(0,0,0,1,redValue,greenValue,blueValue,0);			} else {				peelTransform = new ColorTransform(1,1,1,1,redValue,greenValue,blueValue,0);			}			MovieClip(getChildByName("peel")).transform.colorTransform = peelTransform;		}		/*		 * Move clips to specific frame		 */		private function gotoFrame (frame:uint) : void {			for each (var childname:String in childNames)  {				MovieClip(getChildByName(childname)).gotoAndStop(frame);			}			this.flagCurrentFrame = frame;		}		/*		 * Move clips forward		 */		private function goNext (speed:uint = 1) : void {			var frameToGo:uint;			frameToGo = this.flagCurrentFrame + speed;			if (frameToGo > this.FRAMESCOUNT - 1) {				frameToGo = this.FRAMESCOUNT - 1;			}			gotoFrame(frameToGo);		}		/*		 * Move clips backward		 */		private function goPrev (speed:uint = 1) : void {			var frameToGo:int;			frameToGo = this.flagCurrentFrame - speed;			if (frameToGo < 2) {				frameToGo = 2;			}			gotoFrame(frameToGo);		}		/*		 * Move clips		 */		private function do_move (e:Event) : void {			if (this.flagCurrentFrame == 2) {				// when flag is moving backward this makes it move forward again				moveBackwards = false;			}			if (this.flagCurrentFrame == this.FRAMESCOUNT - 1) {				// when movie reach here starts moving backward				moveBackwards = true;			}				if (moveBackwards) {				goPrev(flagSpeed);			} else {				goNext(flagSpeed);			}		}				/*		 * Scale All the flag movie		 */		private function scaleMovie () : void {			// scale the flag			if (peelPosition == "topleft" || peelPosition == "bottomleft") {				this.scaleX = -1 * toScaleX;				this.x += flagWidth;			} else {				this.scaleX = toScaleX;			}						if (peelPosition == "bottomleft" || peelPosition == "bottomright") {				this.scaleY = -1 * toScaleY;				this.y += flagHeight;			} else {				this.scaleY = toScaleY;			}		}		/*		 * Sets the image.		 */		private function setImage () : void {			MovieClip(getChildByName("small_image")).addChild(imageLoader);			// downscale the image, cause it has been scaled with the rest of the flag as it inherits its parent scales.			MovieClip(getChildByName("small_image")).scaleX = 1/toScaleX;			MovieClip(getChildByName("small_image")).scaleY = 1/toScaleY;			// mirror the image as needed in its corner			if (peelPosition == "topleft" || peelPosition == "bottomleft") {				MovieClip(getChildByName("small_image")).scaleX *= -1;				MovieClip(getChildByName("small_image")).x += FLAGDESIGNSIZE;			}						if (peelPosition == "bottomleft" || peelPosition == "bottomright") {				MovieClip(getChildByName("small_image")).scaleY *= -1;				MovieClip(getChildByName("small_image")).y += FLAGDESIGNSIZE;			}		}		/*		 * Updates the mirror image on flag when it is a clip		 */		private function updateMirrorImage(e:TimerEvent): void {  			//updates the reflection to visually match the movie clip			var mirrorBitmapData:BitmapData;			mirrorBitmapData = new BitmapData(imageLoader.width, imageLoader.height, true, 0xFFFFFF);  			mirrorBitmapData.draw(imageLoader);  			mirrorImageBitmap.bitmapData = mirrorBitmapData;		}		/*		 * Sets the mirror image on peel		 */		private function setMirrorImage () : void {			mirrorImageBitmap.bitmapData = new BitmapData(imageLoader.width, imageLoader.height, true, 0xFFFFFF);  			mirrorImageBitmap.bitmapData.draw(imageLoader);			MovieClip(getChildByName("mirror_image")).mirror_small_image_container.mirror_small_image.addChild(mirrorImageBitmap);						if (imageLoader.getChildAt(0) is MovieClip) {				// if the media on flag is a movieclip this reflection has to be updated every 100ms to				// properly display the current frame of the loading flash movie				updateMirrorImageTimer = new Timer(100, 0);				updateMirrorImageTimer.addEventListener(TimerEvent.TIMER, updateMirrorImage);				updateMirrorImageTimer.start();			}			// downscale the mirror image as it has been scaled with all the flag as it inherits its parent scales			MovieClip(getChildByName("mirror_image")).mirror_small_image_container.mirror_small_image.scaleX = 1/toScaleX;			MovieClip(getChildByName("mirror_image")).mirror_small_image_container.mirror_small_image.scaleY = 1/toScaleY;			// mirror the image as needed in its corner			if (peelPosition == "topright" || peelPosition == "bottomright") {				MovieClip(getChildByName("mirror_image")).mirror_small_image_container.mirror_small_image.scaleX *= -1;				MovieClip(getChildByName("mirror_image")).mirror_small_image_container.mirror_small_image.x += FLAGDESIGNSIZE;			}			if (peelPosition == "bottomleft" || peelPosition == "bottomright") {				MovieClip(getChildByName("mirror_image")).mirror_small_image_container.mirror_small_image.scaleY *= -1;				MovieClip(getChildByName("mirror_image")).mirror_small_image_container.mirror_small_image.y += FLAGDESIGNSIZE;			}		}		/*		 * open the peel		 */		private function do_peel () : void {			ExternalInterface.call("curlypage_do_peel", this.cpid, this.peelPosition);			addEventToFlag();		}		/*		 * mouse over event handler		 */		private function smallButtonAction (e:MouseEvent) : void {			removeEventFromFlag();			do_peel();		}	}}