#include "divine_tools.h"
#include "lib/divine_tools/mapgen.h"
#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#endif
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/json.hpp>
divine_tools *divine_tools::singleton = nullptr;

void divine_tools::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("generate_perlin_map_from_seed", "mapSize", "seed"), &divine_tools::generatePerlinMapFromSeed);
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

Dictionary divine_tools::generatePrimMapFromSeed(int mapSize, int64_t seed, const std::string& theme)
{
    char *result = GenerateMapWithRandomizedPrims(mapSize, seed, theme);
    return JSON::parse_string(result);
}

Dictionary divine_tools::generatePerlinMapFromSeed(int mapSize, int64_t seed, const std::string& theme)
{
    char *result = GenerateMapWithPerlinNoise(mapSize, seed, theme);
    return JSON::parse_string(result);
}