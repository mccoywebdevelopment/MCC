.data 
	num: .word 5
	ans: .word -1
	
.text 
	main:
		lw $a0,num
		jal fact
		sw $v0,ans
		move $a0,$v0
		
		li  $v0, 1           # service 1 is print integer
    		add $a0, $a0, $zero  # load desired value into argument register $a0, using pseudo-op
    		syscall
		j exit
	fact:
		subu $sp,$sp,8
		sw $ra,($sp)
		sw $s0,4($sp)
		
		li $v0,1
		beq $a0,$zero,done
		
		move $s0,$a0
		subi $a0,$a0,1
		jal fact
		
		mul $v0,$s0,$v0
	
	done:	
		lw $ra,($sp)
		lw $s0,4($sp)
		addu $sp,$sp, 8
		jr $ra
	exit:
