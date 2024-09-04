.data
	str: .asciiz "Classic Ludo\n"
	out_text_0: .asciiz "\nMultiple rolles of the highest value detected!.\nRoll again.\n\n"
	out_text_1: .asciiz " player has the highest roll and will begin the game.\nThe Order of a single round is "
	
	yellow_name: .asciiz "Yellow"
	blue_name: .asciiz "Blue"
	red_name: .asciiz "Red"
	green_name: .asciiz "Green"
	
	rolled_str: .asciiz " rolled "
	spacer_comma: .asciiz ", "
	
	piece.map: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	piece.loc: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	
	player.x: .word 41, 2, 15, 28
	player.approach: .word 39, 52, 13, 26
	player.previousDice: .word 0, 0, 0, 0
	player.sixCount: .word 0, 0, 0, 0
	
	current_player: .word 0
	dice: .word 0
	current_piece: .word 0
	
	max1: .word 0
	max2: .word 0
	max_player: .word 0
	
	i: .word 0
.text
.globl main

main:
	li $t0, 0
	main_loop_1:
		sw $0, max1
		sw $0, max2
		sw $0, current_player
		
		main_loop_loop_1:
		
		lw $t0, current_player
		move $v0, $t0
		jal print_player_name
		
		la $a0, rolled_str
		li $v0, 4
		syscall
		
		jal roll_dice
		lw $t0, current_player
		
		lw $t1, dice
		lw $t2, max1
		ble $t1, $t2, main_else_1
		move $t2, $t1
		sw $t2, max1
		sw $t0, max_player
		sw $0, max2
		j main_else_2
		
		main_else_1:
		
		lw $t1, dice
		lw $t2, max1
		bne $t1, $t2, main_else_2
		sw $t1, max2
		
		main_else_2:				
		lw $t0, current_player		
		add $t0, $t0, 1
		sw $t0, current_player
		bne $t0, 4, main_loop_loop_1
	
		lw $t0, max1
		lw $t1, max2
		bgt $t0, $t1, main_loop_1_break
		
		la $a0, out_text_0
		li $v0, 4
		syscall
		j main_loop_1
		
	main_loop_1_break:
	
	lw $t0, max_player
	sw $t0, current_player
	
	li $a0, 10
	li $v0, 11
	syscall
	
	lw $v0, current_player
	jal print_player_name
	
	la $a0, out_text_1
	li $v0, 4
	syscall
	
	lw $t0, max_player
	li $t1, 0
	sw $t1, i
	main_loop_2:
		move $v0, $t0
		jal print_player_name
		
		lw $t0, max_player
		add $t0, $t0, 1
		li $t1, 4
		div $t0, $t1
		mfhi $t0
		
		sw $t0, max_player
		lw $t1, i
		add $t1, $t1, 1
		sw $t1, i
		li $t2, 4
		beq $t1, $t2, main_loop_2_break
		
		la $a0, spacer_comma
		li $v0, 4
		syscall
		
		j main_loop_2
	main_loop_2_break:
		
	li $a0, 10
	li $v0, 11
	syscall
	
	main_loop_3:
		
		
		
	li $v0, 10
	syscall
	
roll_dice:	
	li $a1, 6  #Here you set $a1 to the max bound.
    	li $v0, 42  #generates the random number.
    	syscall
    	add $a0, $a0, 1  #Here you add the lowest bound
    	sw $a0, dice
    	li $v0, 1   #1 print integer
    	syscall
    	
    	li $a0, 10
    	li $v0, 11
    	syscall
    	
    	jr $ra

print_player_name:
	move $t0, $v0
	beq $t0, 0, print_player_name_yellow
	beq $t0, 1, print_player_name_blue
	beq $t0, 2, print_player_name_red
	beq $t0, 3, print_player_name_green
	
	jr $ra
	
	print_player_name_yellow:
		la $a0, yellow_name
		li $v0, 4
		syscall
		jr $ra
	print_player_name_blue:
		la $a0, blue_name
		li $v0, 4
		syscall
		jr $ra
	print_player_name_red:
		la $a0, red_name
		li $v0, 4
		syscall
		jr $ra
	print_player_name_green:
		la $a0, green_name
		li $v0, 4
		syscall
		jr $ra

incPlayer:
	lw $t0, current_player
	add $t0, $t0, 1
	li $t1, 4
	div $t0, $t1
	mfhi $t0
	sw $t0, current_player
	
	jr $ra

checkMove:
	lw $t0, current_piece
	la $t1, piece.loc
	mul $t0, $t0, 4
	add $t1, $t1, $t0
	
	lw $t1, ($t1)
	li $t0, dice
	li $t2, 0
	bne $t1, $t2, checkMove_else_1
	li $t2, 6
	bne $t0, $t1, checkMove_else_1
	li $v0, 1
	jr $ra
	
	checkMove_else_1:
	
	