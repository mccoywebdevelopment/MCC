.data
thearray: .word 1,2,5,7,9,11,13,15,17,19,21,23,25,27,29,31
.word 33,35,37,39,41,43,45,47,49,51,53,55,57,59,61,63
.word 65,67,69,71,73,75,77,79,81,83,85,87,89,91,93,95
.word 97,99,101,103,105,107,109,111,113,115,117,119,121,123,125,127

count: .word 64

passmsg: .asciiz "The test passed!"
failmsg: .asciiz "The test failed!"
.text

la $a0, thearray  # load array address
lw $a1, count # load number of elements


jal loop # call loop function

#t2 counter to 64
#t1 sum variable
#$ao array address(increment by four)
loop:
	bge $t2, $a1,Exit  #at count exit
	lw $t0, 0($a0)
	add $t1,$t1,$t0
	addi $a0,$a0,4 #(increment by four)
	addi $t2, $t2, 1 #increment counter
	
	
    	j loop #jumps back to the top of loop
    	

Exit:
	move $v0,$t1
	j compare

	
compare:
	addi	$t3, $zero, 0x1000
	la	$a0, failmsg
	bne	$t3, $v0, printmsg
	la	$a0, passmsg
	
printmsg:
	addi	$v0, $zero, 55
	syscall
	
halt:	j	halt




