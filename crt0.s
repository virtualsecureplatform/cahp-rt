.global _start
_start:
	lui sp, %hi(0x400-2)
	addi sp, sp, %lo(0x400-2)
	lw sp, 0(sp)
	lw a0, 0(sp)	# argc
	addi a1, sp, 2	# argv

	jsal main
	hlt
