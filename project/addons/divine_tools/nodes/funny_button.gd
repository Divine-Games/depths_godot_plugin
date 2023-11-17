## This is a normal button BUT it changes font size for one pixel on button_down (thanks guys i know)

@tool
extends TextureButton

var label: Label

@export var text: String: 
	set(value):
		text = value.to_upper()
		_ready()
var font_size: int = 19

func _enter_tree() -> void:
	connect("button_down", _on_button_down)
	connect("button_up", _on_button_up)
	custom_minimum_size = Vector2(260,48)
	ignore_texture_size = true
	stretch_mode = STRETCH_SCALE
	label = preload("./funny_label.tscn").instantiate()
	label.label_settings = LabelSettings.new()
	if get_child_count() > 0:
		for child in get_children():
			child.queue_free()
	label.anchors_preset = PRESET_FULL_RECT
	label.layout_mode = 1
	label.horizontal_alignment = HORIZONTAL_ALIGNMENT_CENTER
	label.vertical_alignment = VERTICAL_ALIGNMENT_CENTER
	label.label_settings.font_size = font_size
	label.label_settings.line_spacing = 4
	add_child(label)

func _ready() -> void:
	if label != null:
		label.text = text

func _on_button_up() -> void:
	if label != null:
		label.label_settings.font_size = font_size
		var tween = self.create_tween()
		tween.set_ease(Tween.EASE_OUT)
		tween.tween_property(self, "modulate", Color(1, 1, 1), 0.1)

func _on_button_down() -> void:
	if label != null:
		label.label_settings.font_size = font_size - 1
		var tween = self.create_tween()
		tween.set_ease(Tween.EASE_OUT)
		tween.tween_property(self, "modulate", Color(0.9, 0.9, 0.9), 0.1)
