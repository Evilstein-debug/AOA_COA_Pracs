DATA SEGMENT
    msg1 db 0dh,0ah "Enter first BCD number: $"
    msg2 db 0dh,0ah "Enter second BCD number :$"
    msg3 db 0dh,0ah "BCD Addition result is: $"
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
    START:
    mov ax,DATA
    mov ds,ax

    mov dx,OFFSET msg1 ;printing first message
    mov ah,09h      ;09h - print instruction
    int 21h

    mov ah,01h      ;01h - read from keyboard instruction
    int 21h
    sub al,30h      ;converting ascii value of char to numeric value
    mov cl,04h
    rol al,cl       ;rotating al by 4 bits - making lower nibble the new upper nibble so that tens digit is the upper nibble of the packed BCD
    mov bl,al       ;save partially built packed bcd into bl

    mov ah,01h
    int 21h
    sub al,30h
    add bl,al       ;bl now has second input digit as the lower nibble and first input digit as upper nibble
                    ;these digits are of the same line and represent the first packed bcd number

    mov dx,OFFSET msg2
    mov ah,09h
    int 21h

    mov ah,01h
    int 21h
    sub al,30h
    mov cl,04h
    rol al,cl
    mov bh,al       ;save partially built packed bcd into bh

    mov ah,01h
    int 21h
    sub al,30h
    add bh,al       ;second packed bcd number is complete and stores in bh

    mov dx,OFFSET msg3
    mov ah,09h
    int 21h

    

    


