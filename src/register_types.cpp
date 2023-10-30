#include "register_types.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/godot.hpp>

#include "divine_tools.h"

using namespace godot;

static divine_tools *divinetools;

void initialize_divine_tools(ModuleInitializationLevel p_level)
{
    if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        ClassDB::register_class<divine_tools>();
        divinetools = memnew(divine_tools);
        Engine::get_singleton()->register_singleton("divine_tools", divine_tools::get_singleton());
    }
}

void uninitialize_divine_tools(ModuleInitializationLevel p_level)
{
    if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        Engine::get_singleton()->unregister_singleton("divine_tools");
        memdelete(divinetools);
    }
}

extern "C"
{
    // Initialization.
    GDExtensionBool GDE_EXPORT divine_tools_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
    {
        godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

        init_obj.register_initializer(initialize_divine_tools);
        init_obj.register_terminator(uninitialize_divine_tools);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}
