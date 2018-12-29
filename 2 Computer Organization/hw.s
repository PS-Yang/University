# UNTITLED PROGRAM

	.data	# Data declaration section
str1:   .asciiz "Please input n(1~9)="
strx:   .asciiz "x"
str2:   .asciiz "="
str3:   .asciiz "\n"
str4:   .asciiz "\t"
	.text

main:		# Start of code section
	
	jal func #跳到func
	
	li $v0, 4    
	la $a0, str1 #print str1
        syscall
	
	li $v0, 5 #get ready to read integer
	syscall 
	
	li $t0,1   #int i=1(i==$t0)
	li $t1,0   #int temp=0
	move $t2,$v0 #t2=n
	
	li $t9,10     #t9=10
	
	
	
Loopi:	li $t3,1   #int j=1(j==$t3)
        beq $t3,$t2,loop #判斷t2(n)是否等於1
Loopj:	
	li $v0, 4
	la $a0, str4  #print \t
        syscall
	addi $t3,$t3,1    #j=j+1
	blt $t3,$t2,Loopj #判斷j<=n
	
loop:	move $a0,$t2
	li $v0, 1     #print n
	syscall
	li $v0, 4
	la $a0, strx  #print x
        syscall
	move $a0,$t0
	li $v0, 1     #print i
	syscall
	li $v0, 4
	la $a0, str2  #print =
        syscall
	add $t1,$t1,$t2
	move $a0,$t1
	li $v0, 1     #print n*i(temp+n)
	syscall
        li $v0, 4
	la $a0, str3  #print \n
        syscall

	addi $t0,$t0,1  #i=i+1
	bne $t0,$t9,Loopi
	
 	li $v0,10 #exit program
	syscall
# END OF PROGRAM

###########################################################################################	
##func
func:   
	li $t2,1   #t2=1
	li $t9,10  #t9=10
	
loop2:	li $t0,1   #int i=1($t0,i)
        li $t1,0   #int temp=0
loop1:	move $a0,$t0
	li $v0, 1     #print t0(i)
	syscall
	li $v0, 4
	la $a0, strx  #print x
        syscall
	move $a0,$t2
	li $v0, 1     #print t2(j)
	syscall
	li $v0, 4
	la $a0, str2  #print =
        syscall
	add $t1,$t1,$t2
	move $a0,$t1
	li $v0, 1     #print n*i(temp+n)
	syscall
        li $v0, 4
	la $a0, str4  #print \t
        syscall
	
	addi $t0,$t0,1  #i=i+1
	bne $t0,$t9,loop1
	
	li $v0, 4
	la $a0, str3  #print \n
        syscall
	addi $t2,$t2,1  #j=j+1
	bne $t2,$t9,loop2
	
        jr $ra      #跳回main                                                  #######
######################################################################################
