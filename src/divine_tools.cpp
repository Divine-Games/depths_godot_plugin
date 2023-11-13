#include "divine_tools.h"
#include "lib/divine_tools/libmapgen.h"
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/json.hpp>
#include <godot_cpp/variant/char_string.hpp>
divine_tools *divine_tools::singleton = nullptr;

void divine_tools::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("generate_perlin_map_from_seed", "mapSize", "seed", "theme"), &divine_tools::generatePerlinMapFromSeed);
    ClassDB::bind_method(D_METHOD("generate_prim_map_from_seed", "width", "seed", "theme"), &divine_tools::generatePrimMapFromSeed);
}

divine_tools *divine_tools::get_singleton()
{
    return singleton;
}
divine_tools::divine_tools()
{
    ERR_FAIL_COND(singleton != nullptr);
    singleton = this;
}
divine_tools::~divine_tools()
{
    ERR_FAIL_COND(singleton != this);
    singleton = nullptr;
}

Dictionary divine_tools::generatePrimMapFromSeed(int mapSize, int64_t seed, const godot::String &theme)
{
    char *result = GenerateMapWithRandomizedPrims(mapSize, seed, (char *) theme.utf8().get_data());
    return JSON::parse_string(result);
}

Dictionary divine_tools::generatePerlinMapFromSeed(int mapSize, int64_t seed, const godot::String &theme)
{
    char *result = GenerateMapWithPerlinNoise(mapSize, seed, (char *) theme.utf8().get_data());
    return JSON::parse_string(result);
}