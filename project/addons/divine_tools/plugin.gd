@tool
extends EditorPlugin

const FUNNY_BUTTON_SCRIPT = preload("./nodes/funny_button.gd")
const FUNNY_BUTTON_ICON = preload("./nodes/FunnyButton.svg")

func _enable_plugin() -> void:
	pass
func _enter_tree():
	add_custom_type("FunnyButton","TextureButton",FUNNY_BUTTON_SCRIPT,FUNNY_BUTTON_ICON)

func _disable_plugin() -> void:
	pass

func _get_plugin_name() -> String:
	return "Divine Tools"
