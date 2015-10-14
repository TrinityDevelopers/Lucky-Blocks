#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>
#include "lucky_blocks/blocks/LuckyBlockTiles.h"
#include "mcpe/item/Item.h"
#include "mcpe/tile/Tile.h"

#define LOG_TAG "luckyblocks"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

static void (*_Tile$initTiles)();
static void Tile$initTiles() {
	_Tile$initTiles();
	
	LuckyBlockTiles::initTiles();
}

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems() {
	_Item$initCreativeItems();
	
	LuckyBlockTiles::initCreativeItems();
}

static std::string (*_I18n$get)(std::string const&, std::vector<std::string,std::allocator<std::string>> const&);
static std::string I18n$get(std::string const& key, std::vector<std::string,std::allocator<std::string>> const& a) {
	if(key == "tile.lucky_block.name") return "Lucky Block";
	return _I18n$get(key, a);
};

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	void* I18n_get = dlsym(RTLD_DEFAULT, "_ZN4I18n3getERKSsRKSt6vectorISsSaISsEE");
    MSHookFunction((void*) &Tile::initTiles, (void*) &Tile$initTiles, (void**) &_Tile$initTiles);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction(I18n_get, (void*) &I18n$get, (void**) &_I18n$get);
	
	return JNI_VERSION_1_2;
}
