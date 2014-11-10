#include <hxcpp.h>

#ifndef INCLUDED_Coin
#include <Coin.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_addons_editors_ogmo_FlxOgmoLoader
#include <flixel/addons/editors/ogmo/FlxOgmoLoader.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif

Void PlayState_obj::__construct(Dynamic MaxSize)
{
HX_STACK_FRAME("PlayState","new",0xf8bf96cf,"PlayState.new","PlayState.hx",21,0xb30d7781)
HX_STACK_THIS(this)
HX_STACK_ARG(MaxSize,"MaxSize")
{
	HX_STACK_LINE(21)
	super::__construct(MaxSize);
}
;
	return null();
}

//PlayState_obj::~PlayState_obj() { }

Dynamic PlayState_obj::__CreateEmpty() { return  new PlayState_obj; }
hx::ObjectPtr< PlayState_obj > PlayState_obj::__new(Dynamic MaxSize)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(MaxSize);
	return result;}

Dynamic PlayState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(inArgs[0]);
	return result;}

Void PlayState_obj::create( ){
{
		HX_STACK_FRAME("PlayState","create",0x82220fed,"PlayState.create","PlayState.hx",34,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(35)
		::flixel::addons::editors::ogmo::FlxOgmoLoader _g = ::flixel::addons::editors::ogmo::FlxOgmoLoader_obj::__new(HX_CSTRING("assets/data/room-001.oel"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(35)
		this->_map = _g;
		HX_STACK_LINE(36)
		::flixel::tile::FlxTilemap _g1 = this->_map->loadTilemap(HX_CSTRING("assets/images/tiles.png"),(int)16,(int)16,HX_CSTRING("walls"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(36)
		this->_mWalls = _g1;
		HX_STACK_LINE(37)
		this->_mWalls->setTileProperties((int)1,(int)0,null(),null(),null());
		HX_STACK_LINE(38)
		this->_mWalls->setTileProperties((int)2,(int)4369,null(),null(),null());
		HX_STACK_LINE(39)
		this->add(this->_mWalls);
		HX_STACK_LINE(41)
		::flixel::group::FlxTypedGroup _g2 = ::flixel::group::FlxTypedGroup_obj::__new(null());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(41)
		this->_grpCoins = _g2;
		HX_STACK_LINE(42)
		this->add(this->_grpCoins);
		HX_STACK_LINE(45)
		::Player _g3 = ::Player_obj::__new(null(),null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(45)
		this->_Player = _g3;
		HX_STACK_LINE(47)
		this->_map->loadEntities(this->placeEntites_dyn(),HX_CSTRING("entities"));
		HX_STACK_LINE(49)
		this->add(this->_Player);
		HX_STACK_LINE(52)
		::flixel::FlxG_obj::camera->follow(this->_Player,(int)2,null(),(int)1);
		HX_STACK_LINE(54)
		this->super::create();
	}
return null();
}


Void PlayState_obj::playerTouchCoin( ::Player P,::Coin C){
{
		HX_STACK_FRAME("PlayState","playerTouchCoin",0x7f00763e,"PlayState.playerTouchCoin","PlayState.hx",67,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(P,"P")
		HX_STACK_ARG(C,"C")
		HX_STACK_LINE(67)
		if (((bool((bool((bool(P->alive) && bool(P->exists))) && bool(C->alive))) && bool(C->exists)))){
			HX_STACK_LINE(69)
			C->kill();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,playerTouchCoin,(void))

Void PlayState_obj::placeEntites( ::String entityName,::Xml entityData){
{
		HX_STACK_FRAME("PlayState","placeEntites",0x7e0a782e,"PlayState.placeEntites","PlayState.hx",81,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(entityName,"entityName")
		HX_STACK_ARG(entityData,"entityData")
		HX_STACK_LINE(82)
		::String _g = entityData->get(HX_CSTRING("x"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(82)
		Dynamic x = ::Std_obj::parseInt(_g);		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(83)
		::String _g1 = entityData->get(HX_CSTRING("y"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(83)
		Dynamic y = ::Std_obj::parseInt(_g1);		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(85)
		if (((entityName == HX_CSTRING("player")))){
			HX_STACK_LINE(87)
			this->_Player->set_x(x);
			HX_STACK_LINE(88)
			this->_Player->set_y(y);
		}
		HX_STACK_LINE(91)
		if (((entityName == HX_CSTRING("coin")))){
			HX_STACK_LINE(98)
			::Coin _g2 = ::Coin_obj::__new((x + (int)4),(y + (int)4));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(98)
			this->_grpCoins->add(_g2);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,placeEntites,(void))

Void PlayState_obj::destroy( ){
{
		HX_STACK_FRAME("PlayState","destroy",0x6ec756e9,"PlayState.destroy","PlayState.hx",108,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(108)
		this->super::destroy();
	}
return null();
}


Void PlayState_obj::update( ){
{
		HX_STACK_FRAME("PlayState","update",0x8d182efa,"PlayState.update","PlayState.hx",115,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(116)
		this->super::update();
		HX_STACK_LINE(119)
		::flixel::FlxG_obj::overlap(this->_Player,this->_mWalls,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(122)
		::flixel::FlxG_obj::overlap(this->_Player,this->_grpCoins,this->playerTouchCoin_dyn(),null());
	}
return null();
}



PlayState_obj::PlayState_obj()
{
}

void PlayState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PlayState);
	HX_MARK_MEMBER_NAME(_Player,"_Player");
	HX_MARK_MEMBER_NAME(_map,"_map");
	HX_MARK_MEMBER_NAME(_mWalls,"_mWalls");
	HX_MARK_MEMBER_NAME(_grpCoins,"_grpCoins");
	::flixel::FlxState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PlayState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Player,"_Player");
	HX_VISIT_MEMBER_NAME(_map,"_map");
	HX_VISIT_MEMBER_NAME(_mWalls,"_mWalls");
	HX_VISIT_MEMBER_NAME(_grpCoins,"_grpCoins");
	::flixel::FlxState_obj::__Visit(HX_VISIT_ARG);
}

Dynamic PlayState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_map") ) { return _map; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_Player") ) { return _Player; }
		if (HX_FIELD_EQ(inName,"_mWalls") ) { return _mWalls; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_grpCoins") ) { return _grpCoins; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"placeEntites") ) { return placeEntites_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"playerTouchCoin") ) { return playerTouchCoin_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PlayState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_map") ) { _map=inValue.Cast< ::flixel::addons::editors::ogmo::FlxOgmoLoader >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_Player") ) { _Player=inValue.Cast< ::Player >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_mWalls") ) { _mWalls=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_grpCoins") ) { _grpCoins=inValue.Cast< ::flixel::group::FlxTypedGroup >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PlayState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Player"));
	outFields->push(HX_CSTRING("_map"));
	outFields->push(HX_CSTRING("_mWalls"));
	outFields->push(HX_CSTRING("_grpCoins"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::Player*/ ,(int)offsetof(PlayState_obj,_Player),HX_CSTRING("_Player")},
	{hx::fsObject /*::flixel::addons::editors::ogmo::FlxOgmoLoader*/ ,(int)offsetof(PlayState_obj,_map),HX_CSTRING("_map")},
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,_mWalls),HX_CSTRING("_mWalls")},
	{hx::fsObject /*::flixel::group::FlxTypedGroup*/ ,(int)offsetof(PlayState_obj,_grpCoins),HX_CSTRING("_grpCoins")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_Player"),
	HX_CSTRING("_map"),
	HX_CSTRING("_mWalls"),
	HX_CSTRING("_grpCoins"),
	HX_CSTRING("create"),
	HX_CSTRING("playerTouchCoin"),
	HX_CSTRING("placeEntites"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#endif

Class PlayState_obj::__mClass;

void PlayState_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("PlayState"), hx::TCanCast< PlayState_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void PlayState_obj::__boot()
{
}

