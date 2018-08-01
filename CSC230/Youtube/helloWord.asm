#.data
# 	myMessage: .asciiz "Hello World \n"
 	

#.text
#	li $v0, 4
#	la $a0, myMessage
#	syscall
#--------------------------------------------------
#		To output a character
#--------------------------------------------------
#.data
# 	myMessage: .byte "c"
 	

#.text
#	li $v0, 4
#	la $a0, myMessage
#	syscall
#---------------------------------------------------
#		To output a integer
#---------------------------------------------------
.data
	age: .word 21
.text
	li $v0, 1
	lw $a0, age
	syscall