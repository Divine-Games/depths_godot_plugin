extends Node2D


# Called when the node enters the scene tree for the first time.
func _ready():
	var test = divine_tools.get_sys_monitor_info(25,25, 1234)
	print(test)
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
