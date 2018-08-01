.data 
	
	x_value: .float 3.0
	y_value: .word 5
	one_value: .float 1
	
.text
# compute x raised to the y where x 
# is in $a0 and y is in $a1
# return value in $v0
main:
	#l.s $f0,x_value
	l.s $f12,x_value
	lw $a1,y_value
	jal pow
	j exit
	

pow:
   # save return address on stack
   addi $sp, $sp, -4  
   sw $ra, 0($sp)

   # if y == 0 then return 1.0
   bne $a1, $zero, pow_elif
   lw $v0, one_value
   j pow_return    

   # else check if y is even
pow_elif:
   andi $t0, $a1, 1
   bne $t0, $zero, pow_else
   srl $a1, $a1, 1
   jal pow
   #mul $v0, $v0, $v0
   mtc1 $v0,$f0
   mul.s  $f0,$f0,$f0
   mfc1 $v0,$f0 
   j pow_return

   # else y must be odd
pow_else:
   addi $a1, $a1, -1
   jal pow
   #mul $v0, $a0, $v0
   mtc1 $v0,$f0
   mul.s $f0,$f12,$f0
   mfc1 $v0,$f0   

pow_return:
   lw $ra, 0($sp)
   addi $sp, $sp, 4
   jr $ra

exit:
