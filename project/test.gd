extends Control


func _ready(): 
	print_debug(divine_tools.generate_perlin_map_from_seed(25, 25, "Meow"))
