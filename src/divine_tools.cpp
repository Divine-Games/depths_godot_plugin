#include "divine_tools.h"
#include "lib/divine_tools/mapgen.h"
#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#endif
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/json.hpp>

#define BIND_METHOD(method, ...) godot::ClassDB::bind_method(D_METHOD(#method, #__VA_ARGS__), &divine_tools::method)

divine_tools *divine_tools::singleton = nullptr;

void divine_tools::_bind_methods()
{
    BIND_METHOD(generateMapFromSeed, width, height, seed);
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

Dictionary divine_tools::generateMapFromSeed(int32_t width, int32_t height, int64_t seed)
{
    char *result = GenerateMapJSON(width, height, seed);
    return JSON::parse_string(result);
}