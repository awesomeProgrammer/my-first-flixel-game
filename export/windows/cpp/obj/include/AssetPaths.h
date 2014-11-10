#ifndef INCLUDED_AssetPaths
#define INCLUDED_AssetPaths

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(AssetPaths)


class HXCPP_CLASS_ATTRIBUTES  AssetPaths_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AssetPaths_obj OBJ_;
		AssetPaths_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< AssetPaths_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AssetPaths_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("AssetPaths"); }

		static ::String data_goes_here__txt;
		static ::String New Project__oep;
		static ::String room_001__oel;
		static ::String coin__png;
		static ::String enemy_0__png;
		static ::String enemy_1__png;
		static ::String images_go_here__txt;
		static ::String player__png;
		static ::String Thumbs__db;
		static ::String tiles__png;
		static ::String music_goes_here__txt;
		static ::String sounds_go_here__txt;
};


#endif /* INCLUDED_AssetPaths */ 
