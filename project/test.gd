extends Control


func _ready(): 
	print_debug(divine_tools.generateMapFromSeed(25,25, 1234))
