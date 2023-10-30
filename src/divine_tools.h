#ifndef DIVINE_TOOLS_H
#define DIVINE_TOOLS_H

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

class divine_tools : public RefCounted
{
    GDCLASS(divine_tools, Object);

    static divine_tools *singleton;

protected:
    static void _bind_methods();

public:
    static divine_tools *
    get_singleton();

    divine_tools();
    ~divine_tools();

    Dictionary generateMapFromSeed(int width, int height, int64_t seed);
};
#endif