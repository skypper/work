.data
string1:	.asciiz "Dati numarul de elemente ale vectorului:"
string2:	.asciiz "Dati elementele vectorului.\n"
string3:	.asciiz "Vectorul este: \n"
blank:	.asciiz " "
menu_text:	.asciiz "\n\n1. Suma elementelor;\n2. Ultimul element;\n3. Elementele mai mari decat n;\n4. Iesire din program."
n:		.word 0
elem:		.space 64
.text
main:

li $v0, 4
la $a0, string1
syscall

li $v0, 5
syscall
sw $v0, n

lw $t0, n
li $t1, 0
la $t2, elem

li $v0, 4
la $a0, string2
syscall

loop:
	beq $t1, $t0, endloop
	
	li $v0, 5
	syscall
	sw $v0, 0($t2)	

	add $t2, 4
	add $t1, 1
	j loop
endloop:

li $v0, 4
la $a0, string3
syscall

li $t0, 0
lw $t1, n
la $t2, elem

loop2:
	beq $t0, $t1, endloop2
	lw $a0, 0($t2)
	li $v0, 1
	syscall
	li $v0, 4
	la $a0, blank
	syscall
	add $t0, 1
	add $t2, 4
	j loop2
endloop2:

li $v0, 4
la $a0, menu_text
syscall
menu:
	li $v0, 5
	syscall

	li $t0, 1
	beq $v0, $t0, suma
	li $t0, 2
	beq $v0, $t0, ultim
	li $t0, 3
	beq $v0, $t0, el_mai_mari
	li $t0, 4
	beq $v0, $t0, end

suma:
	li $t0, 0
	lw $t1, n
	la $t2, elem
	li $t3, 0	# suma
	
	loop_suma:
		beq $t0, $t1, afisare_suma
		lw $t4, 0($t2)
		add $t3, $t3, $t4
		add $t0, 1
		add $t2, 4
		j loop_suma
	afisare_suma:
		li $v0, 1
		la $a0, 0($t3)
		syscall
		j menu


ultim:
	lw $t0, n
	sub $t0, 1
	mul $t0, $t0, 4
	la $t1, elem
	add $t1, $t1, $t0
	li $v0, 1
	lw $a0, 0($t1)
	syscall
	j menu

el_mai_mari:
	li $t0, 0
	lw $t1, n
	la $t2, elem
	emm_loop:
		beq $t0, $t1, end_emm_loop
		lw $t3, 0($t2)
		sgt $t4, $t3, $t1
		bnez $t4, afisare_element
		returnero:
		add $t0, 1
		add $t2, 4
		j emm_loop
	end_emm_loop:
		j menu
	afisare_element:
		li $v0, 1
		move $a0, $t3
		syscall
		li $v0, 4
		la $a0, blank
		syscall
		j returnero

end:
li $v0, 10
syscall
